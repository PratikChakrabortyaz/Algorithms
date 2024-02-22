
goal_state = [[1, 2, 3],
              [8, 0, 4],
              [7, 6, 5]]


initial_state = [[2, 8, 3],
                 [1, 6, 4],
                 [7, 0, 5]]


N = 3


def find_blank_tile(state):
    for i in range(N):
        for j in range(N):
            if state[i][j] == 0:
                return i, j


def misplaced_tiles(state):
    count = 0
    for i in range(N):
        for j in range(N):
            if state[i][j] != goal_state[i][j]:
                count += 1
    return count


def A_star(initial_state):
    moves = [(0, -1), (0, 1), (-1, 0), (1, 0)] 

    visited = set()
    open_list = [(misplaced_tiles(initial_state), 0, initial_state, 0, None)]  

    while open_list:
        open_list.sort()
        _, g, current_state, h, parent = open_list.pop(0)
        
        if current_state == goal_state:
            return current_state, g

        visited.add(tuple(map(tuple, current_state)))

        i, j = find_blank_tile(current_state)

        for move in moves:
            di, dj = move
            new_i, new_j = i + di, j + dj

            if 0 <= new_i < N and 0 <= new_j < N:
                new_state = [row[:] for row in current_state]
                new_state[i][j], new_state[new_i][new_j] = new_state[new_i][new_j], new_state[i][j]

                if tuple(map(tuple, new_state)) not in visited:
                    new_g = g + 1
                    new_h = misplaced_tiles(new_state)
                    open_list.append((new_g + new_h, new_g, new_state, new_h, current_state))

    return None, None  


final_state, nodes_traversed = A_star(initial_state)


if final_state is not None:
    print("Solution found in", nodes_traversed, "nodes:")
    for row in final_state:
        print(row)
else:
    print("No solution found!")
