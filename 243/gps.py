from queue import PriorityQueue as PQ
from collections import defaultdict as DD

n_towns, n_roads, n_queries = map(int, input().split())
coords = dict()
adj = DD(list)

for _ in range(n_towns):
    name, x, y = input().split()
    x = int(x)
    y = int(y)
    coords[name] = (x, y)

for _ in range(n_roads):
    s, t, l = input().split()
    l = float(l)
    adj[s].append((t, l))
    adj[t].append((s, l))

for _ in range(n_queries):
    start, end = input().split()
    dists = dict()
    seen = set()
    queue = PQ()
    
    queue.put((0, 0, start, None))
    
    while not queue.empty():
        h, actual_dist, cursor, parent = queue.get()
        
        if cursor in seen:
            continue
        else:
            seen.add(cursor)
            dists[cursor] = (actual_dist, parent)
            
            if cursor == end:
                break

            for neighbor, weight in adj[cursor]:
                if neighbor not in seen:
                    heur = abs(coords[end][0] - coords[neighbor][0]) + abs(coords[end][1] - coords[neighbor][1])
                    actual_next_dist = actual_dist + weight
                    queue.put((heur + actual_next_dist, actual_next_dist, neighbor, cursor))
    path = []
    sum_dist = dists[end][0]
    path_cursor = end
    
    while True:
        
        path.append(path_cursor)
        path_cursor = dists[path_cursor][1]
        
        if not path_cursor:
            break

    print(sum_dist, end=' ')
    
    for town in path[::-1]:
        print(town, end=' ')
    print()

        
