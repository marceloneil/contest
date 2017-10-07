"""n, m = map(int, input().split(" "))

hashmap = {}
visited = {}

for _ in range(m):
    a, b = map(int, input().split(" "))
    if a not in hashmap:
        hashmap[a] = []
        hashmap[a].append(b)
    if b not in hashmap:
        hashmap[b] = []
        hashmap[b].append(a)
    if a not in visited:
        visited[a] = False
    if b not in visited:
        visited[b] = False
x, y = map(int, input().split(" "))
#if the node has already been visited, then don'tdo anyhting
#at the end, count all of the nodes that made it to the end
#don't add to visited if the current nodei s the last node
#distance = {x : 0}
q = [x]
friendCount = 0
while q:
    cur = q[0]
    q = q[1:]
    if visited[cur] == True:
        continue
    else:
        if cur == y:
            friendCount +=1
            continue
        else:
            visited[cur] = True
    friends = hashmap[cur]
    for friend in friends:
        q.append(friend)
print(friendCount)
"""
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
root = [i for i in range(n + 1)]

def find(n):
    if root[n] != n:
        root[n] = find(root[n])
    return root[n]

def union(x, y):
    xr = find(x)
    yr = find(y)
    if xr != yr:
        root[xr] = yr

for _ in range(m):
    a, b = map(int, input().split())
    union(a, b)

x, y = map(int, input().split())
print(1 if find(x) == find(y) else 0)
