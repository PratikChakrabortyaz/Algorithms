# Function to calculate the number of conflicts in the board configuration
def calculate_conflicts(board):
    conflicts = 0
    size = len(board)
    for i in range(size):
        for j in range(i + 1, size):
            if board[i] == board[j] or abs(board[i] - board[j]) == abs(i - j):
                conflicts += 1
    return conflicts

# Function to print the board configuration
def print_board(board):
    for row in board:
        print(" ".join(["Q" if col == row else "-" for col in range(len(board))]))
    print()

# Function to generate all possible neighbors for the current board
def generate_neighbors(board):
    neighbors = []
    size = len(board)
    for col in range(size):
        for row in range(size):
            if board[col] != row:
                neighbor = board.copy()
                neighbor[col] = row
                neighbors.append(neighbor)
    return neighbors

# Hill Climbing algorithm to solve the 8 Queens problem
def hill_climbing(initial_board):
    current_board = initial_board
    current_conflicts = calculate_conflicts(current_board)

    while current_conflicts > 0:
        neighbors = generate_neighbors(current_board)
        best_neighbor = min(neighbors, key=lambda neighbor: calculate_conflicts(neighbor))
        best_neighbor_conflicts = calculate_conflicts(best_neighbor)

        if best_neighbor_conflicts >= current_conflicts:
            break

        current_board = best_neighbor
        current_conflicts = best_neighbor_conflicts

    return current_board

# Main function
def main():
    size = 8  # Size of the chessboard (8x8 for 8 Queens)
    print("Enter the initial board configuration (row numbers separated by spaces):")
    initial_board = list(map(int, input().split()))

    solution = hill_climbing(initial_board)

    print("\nFinal goal board:")
    print_board(solution)

if __name__ == "__main__":
    main()
