n, m = map(int, input().split())

"""s = 0
d = {}
f = {}

for i in range(m):
    u, v, w = map(int, input().split())
    if u in d:
        u = d[u]
    else:
        d[u] = s
        s += 1
        u = d[u]
    if v in d:
        v = d[v]
    else:
        d[v] = s
        s += 1
        v = d[v]
    f[u] = v
print(d)
print(f)"""

visited = [False for i in range m]
distance = [99999 for i in range m]

for i in range(n):
    visited[i] = False
    distance[i] = 99999
adjm = []
for i in range(m):
    for j in range(m):
        adjm[i][j] = -1;
for i in range(m):
    u, v, w = map(int, raw_input().split())
    adjm[u][v] = w

for i in range(m):
    for j in range(m):
        print(adjm[i][j])
