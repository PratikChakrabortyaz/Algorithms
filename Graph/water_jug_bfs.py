from collections import deque
def bfs_water_jug_solver(jug1_capacity, jug2_capacity, target):
    visited = set()
    queue = deque([((0, 0), [])])

    while queue:
        (jug1, jug2), actions = queue.popleft()
        current_state = (jug1, jug2)

        if jug1 == target:
            actions.append(current_state)
            return actions

        if current_state in visited:
            continue

        visited.add(current_state)

        # Fill jug 1
        if jug1 < jug1_capacity:
            queue.append(((jug1_capacity, jug2), actions + [current_state]))
        # Fill jug 2
        if jug2 < jug2_capacity:
            queue.append(((jug1, jug2_capacity), actions + [current_state]))
        # Empty jug 1
        if jug1 > 0:
            queue.append(((0, jug2), actions + [current_state]))
        # Empty jug 2
        if jug2 > 0:
            queue.append(((jug1, 0), actions + [current_state]))
        # Pour from jug 1 to jug 2
        pour = min(jug1, jug2_capacity - jug2)
        queue.append(((jug1 - pour, jug2 + pour), actions + [current_state]))
        # Pour from jug 2 to jug 1
        pour = min(jug2, jug1_capacity - jug1)
        queue.append(((jug1 + pour, jug2 - pour), actions + [current_state]))

    return None

def main_q1():
    jug1_capacity = 4  # 4-gallon jug
    jug2_capacity = 3  # 3-gallon jug
    target = 2  # Target to get 2 gallons in jug1
    solution = bfs_water_jug_solver(jug1_capacity, jug2_capacity, target)
    if solution:
        print("Solution found in {} steps:".format(len(solution)))
        for step in solution:
            print(f"Jug1: {step[0]}, Jug2: {step[1]}")
    else:
        print("No solution found.")

main_q1()
