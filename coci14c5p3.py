#https://dmoj.ca/problem/coci14c5p3
n,k = map(int,input().split(" "))
#visited = [[False for x in range(c)] for y in range(r)]
visited = set()
visited.add((0,2))
visited.add((2,6))
print(visited)
arr = [[False for _ in range(300)]False for _ in range(300)]
distance = {(0,0):0}
#place mushrooms into array
q = []
for _ in range(n)
    x,y = map(int,input().split(" "))
    arr[x][y] = True
    q.append([(x,y)])
#now do the recursive function that checks each of the node's 8 directions
while q:
    cur = arr[q[0][0]][q[0][1]]
    while cur != len(arr):
        #I really messed up this index stuff, it's supposed to auto increment as it checks
        if arr[q[0][0]][q[0][1]] == False:
            curr
            continue
        else
            count+=1
