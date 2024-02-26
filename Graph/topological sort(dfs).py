class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.adj_list = {v: [] for v in range(self.V)}

    def add_edge(self, src, dest):
        self.adj_list[src].append(dest)
    
    def topsort(self,visited,start,stack):
        visited[start]=True

        for neighbour in self.adj_list[start]:
            if(visited[neighbour]==0):
                self.topsort(visited,neighbour,stack)
        stack.append(start)
        
    def topsort_util(self,start):
        visited=[False]*self.V
        stack=[]
        for neighbour in range(self.V):
            if(visited[neighbour]==0):
                self.topsort(visited,neighbour,stack)
        print(stack[::-1])


# Example usage with user input:
if __name__ == "__main__":
    num_vertices = int(input("Enter the number of vertices: "))
    graph = Graph(num_vertices)
    num_edges = int(input("Enter the number of edges: "))
    print("Enter edges in the format 'source destination':")
    for _ in range(num_edges):
        src, dest = map(int, input().split())
        graph.add_edge(src, dest)

    start = int(input("Enter the starting vertex: "))

    graph.topsort_util(start)

        
