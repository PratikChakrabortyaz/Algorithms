class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.adj_list = {v: [] for v in range(self.V)}

    def add_edge(self, src, dest):
        self.adj_list[src].append(dest)
        
    def dfs(self,visited,start):
        visited[start]=True
        print(start,end=" ")
        for neighbour in self.adj_list[start]:
            if(visited[neighbour]==False):
                self.dfs(visited,neighbour)
        
        

    def dfs_util(self,start):
        visited=[False]*self.V
        self.dfs(visited,start)



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

    graph.dfs_util(start)

        
