def aStarAlgo(start_node, stop_node_list):     
    open_set = set([start_node]) 
    closed_set = set()
    g = {} 
    parents = {}
    g[start_node] = 0
    parents[start_node] = start_node
         
    while len(open_set) > 0:
        n = None
        for v in open_set:
            if n == None or g[v] + heuristic(v) < g[n] + heuristic(n):
                n = v
                     
        if n in stop_node_list or Graph_nodes[n] == None:
            pass
        else:
            for (m, weight) in get_neighbors(n):
                if m not in open_set and m not in closed_set:
                    open_set.add(m)
                    parents[m] = n
                    g[m] = g[n] + weight
                else:
                    if g[m] > g[n] + weight:
                        g[m] = g[n] + weight
                        parents[m] = n
                        if m in closed_set:
                            closed_set.remove(m)
                            open_set.add(m)
 
        if n == None:
            print('Path does not exist!')
            return None
        if n in stop_node_list:
            path = []
            while parents[n] != n:
                path.append(n)
                n = parents[n]
            path.append(start_node)
            path.reverse()
            print('Path found:', path)
            # Calculate the cost of the path
            cost = g[path[-1]]
            print('Cost of the path:', cost)
            return path
 
        open_set.remove(n)
        closed_set.add(n)
 
    print('Path does not exist!')
    return None

def best_first_search(start_node, stop_node_list):     
    open_set = set([start_node]) 
    closed_set = set()
    g = {} 
    parents = {}
    g[start_node] = 0
    parents[start_node] = start_node
         
    while len(open_set) > 0:
        n = None
        for v in open_set:
            if n == None or heuristic(v) < heuristic(n):
                n = v
                     
        if n in stop_node_list or Graph_nodes[n] == None:
            pass
        else:
            for (m, weight) in get_neighbors(n):
                if m not in open_set and m not in closed_set:
                    open_set.add(m)
                    parents[m] = n
                    g[m] = g[n] + weight
                else:
                    if g[m] > g[n] + weight:
                        g[m] = g[n] + weight
                        parents[m] = n
                        if m in closed_set:
                            closed_set.remove(m)
                            open_set.add(m)
 
        if n == None:
            print('Path does not exist!')
            return None
        if n in stop_node_list:
            path = []
            while parents[n] != n:
                path.append(n)
                n = parents[n]
            path.append(start_node)
            path.reverse()
            print('Path found:', path)
            # Calculate the cost of the path
            cost = g[path[-1]]
            print('Cost of the path:', cost)
            return path
 
        open_set.remove(n)
        closed_set.add(n)
 
    print('Path does not exist!')
    return None

def ucs(start_node, stop_node_list):
    open_set = [(0, start_node)]
    closed_set = set()
    g = {start_node: 0}
    parents = {start_node: None}
    
    while open_set:
        cost, n = open_set.pop(0)
        
        if n in stop_node_list:
            path = []
            while n != start_node:
                path.append(n)
                n = parents[n]
            path.append(start_node)
            path.reverse()
            print('Path found:', path)
            # Calculate the cost of the path
            print('Cost of the path:', cost)
            return path
        
        closed_set.add(n)
        for m, weight in get_neighbors(n):
            new_cost = g[n] + weight
            if m not in closed_set and (m not in g or new_cost < g[m]):
                g[m] = new_cost
                parents[m] = n
                open_set.append((new_cost, m))
                open_set.sort(key=lambda x: x[0])
    
    print('Path does not exist!')
    return None

def get_neighbors(v):
    if v in Graph_nodes:
        return Graph_nodes[v]
    else:
        return None

def heuristic(n):
    H_dist = {
        'A': 7,
        'B': 3,
        'C': 4,
        'D': 6,
        'E': 5,
        'F': 6,
        'G1': 0,
        'G2': 0,
        'G3': 0,
        'S': 5            
    }
    return H_dist[n]

Graph_nodes = {
    'A':[('B',3),('G1',9)],
    'B':[('C',1),('A',2)],
    'C':[('G2',5),('F',7)],
    'D':[('C',2),('E',2)],
    'E':[('G3',7)],
    'F':[('G3',8),('D',2)],
    'G1':[None],
    'G2':[None],
    'G3':[None],
    'S':[('A',5),('D',6),('B',9)],
}

print("A* Algorithm:")
aStarAlgo('S', ['G1', 'G2', 'G3'])

print("\nBest-First Search:")
best_first_search('S', ['G1', 'G2', 'G3'])

print("\nUniform Cost Search:")
ucs('S', ['G1', 'G2', 'G3'])


