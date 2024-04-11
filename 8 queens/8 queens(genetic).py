import random

# Function to calculate fitness of a chromosome
def fitness(chromosome):
    size = len(chromosome)
    non_attacking_queens = 0

    for i in range(size):
        for j in range(i + 1, size):
            if chromosome[i] != chromosome[j] and abs(chromosome[i] - chromosome[j]) != abs(i - j):
                non_attacking_queens += 1

    return non_attacking_queens

# Function to perform selection (selects top 3 highest fitness)
def selection(population):
    population.sort(key=lambda x: fitness(x), reverse=True)
    selected = population[:3]
    print("Selected boards:")
    for i, chromosome in enumerate(selected):
        print(f"Board {i+1}: {chromosome} (Fitness: {fitness(chromosome)})")
    return selected

# Function to perform crossover (one-point crossover between 2nd highest and 3rd highest)
def crossover(selected):
    highest = selected[0]
    second_highest = selected[1]
    third_highest = selected[2]

    child1 = highest[:len(highest)//2] + second_highest[len(second_highest)//2:]
    child2 = second_highest[:len(second_highest)//2] + highest[len(highest)//2:]
    child3 = second_highest[:len(second_highest)//2] + third_highest[len(third_highest)//2:]
    child4 = third_highest[:len(third_highest)//2] + second_highest[len(second_highest)//2:]

    print("\nBoards after crossover:")
    print("Child 1:", child1)
    print("Child 2:", child2)
    print("Child 3:", child3)
    print("Child 4:", child4)

    return [child1, child2, child3, child4]

# Function to solve N queens problem using genetic algorithm
def solve_n_queens(size, population):
    print("Initial population:")
    for i, chromosome in enumerate(population):
        print(f"Board {i+1}: {chromosome} (Fitness: {fitness(chromosome)})")
    selected = selection(population)
    new_population = crossover(selected)
    print("\nFitness functions after crossover:")
    for i, chromosome in enumerate(new_population):
        print(f"Board {i+1}: {fitness(chromosome)}")

# Example usage
if __name__ == "__main__":
    size = int(input("Enter the size of the chessboard: "))
    population_size = 4  # Changed population size to 4

    print("Enter the positions of each queen for each board:")
    population = []
    for i in range(population_size):
        positions = list(map(int, input(f"Enter positions for board {i+1} (separated by space): ").split()))
        population.append(positions)

    solve_n_queens(size, population)
