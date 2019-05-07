from collections import deque
from collections import defaultdict as DD

def solve_path(n):
    seen = set()
    dists = dict()
    adj = DD(list)

    q = deque()

    x, y = 0, 0
    q.append((x, y))
    dists[(x, y)] = 0

    for _ in range(n):
        next_item = input()
        if next_item == "S":
            y -= 1
            adj[(x, y)].append((x, y + 1))
            adj[(x, y + 1)].append((x, y))
        elif next_item == "N":
            y += 1
            adj[(x, y)].append((x, y - 1))
            adj[(x, y - 1)].append((x, y))
        elif next_item == "W":
            x -= 1
            adj[(x, y)].append((x + 1, y))
            adj[(x + 1), y].append((x, y))
        elif next_item == "E":
            x += 1
            adj[(x, y)].append((x - 1, y))
            adj[(x - 1, y)].append((x, y))

    target = (x, y)

    while q:

        cursor = q.popleft()
        
        if cursor in seen:
            continue
        if cursor == target:
            break

        seen.add(cursor)
        
        for neighbor in adj[cursor]:
            if neighbor not in seen:
                dists[neighbor] = dists[cursor] + 1
                q.append(neighbor)
        
    print(dists[target])
    pass

r = int(input())
for _ in range(r):
    input()
    solve_path(int(input()))
