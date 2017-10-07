#http://wcipeg.com/problem/ccc08s3
t = int(input())
#for z in range(t):
r = int(input())
c = int(input())
#if node in distance = check to see if it has bee nvisited before
arr = [0 for x in range(r)]
visited = [[False for x in range(c)] for y in range(r)]

q = []
q.append([(0,0)])
#visited set() 
visited[0][0] = True
while q:
    curx, cury = q[0] # append to
    #pop
    q = q[1:]

    if not (curx-1 is -1 or cury-1 is -1 or curx is r or cury is c):
        if visited[curx][cury] is False:
            visited[curx][cury] = True;
            if not arr[curx][cury] == "*":
                if arr[curx][cury] == "-":
                    q.append(arr[curx-1][cury])
                    q.append(arr[curx+1][cury])
                if arr[curx][cury] == "|":
                    q.append(arr[curx][cury-1])
                    q.append(arr[curx][cury+1])
                if arr[curx][cury] == "+":
                    q.append(arr[curx][cury-1])
                    q.append(arr[curx][cury+1])
                    q.append(arr[curx-1][cury])
                    q.append(arr[curx+1][cury])















"""counter = 0
arr = [0 for x in range(r)]
visited = [[False for x in range(c)] for y in range(r)]
for i in range(r):
    arr[i] = list(input())
def dfs(point1,point2):
    global counter
    if(point1 is -1 or point2 is -1 or point1 is r or point2 is c):
        return False
    if visited[point1][point2] is True:
        return False
    if point1 is r-1 and point2 is c-1:
        counter +=1
        return True
    visited[point1][point2] = True;
    if arr[point1][point2] == "*":
        return False
    elif arr[point1][point2] == "-":
        if(dfs(point1,point2-1) or dfs(point1,point2+1)):
            counter +=1
            return True
    elif arr[point1][point2] == "|":
        if(dfs(point1-1,point2) or dfs(point1+1,point2)):
            counter +=1
            return True
    elif arr[point1][point2] == "+":
        if(dfs(point1-1,point2) or dfs(point1+1,point2) or dfs(point1,point2-1) or dfs(point1,point2+1)):
            counter +=1
            return True
    return False
if dfs(0,0):
    print(counter)
else:
    print("-1")"""
