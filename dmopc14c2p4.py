#https://dmoj.ca/problem/dmopc14c2p4
#not finished
n = input()
#create prefix sum array
arr = [0]*n
for x in range(n):
    i = input()
    if x == 0:
        arr[x] = i
    else:
        arr[x] = arr[x-1] + i
q = input()
for x in range(q):
    a, b = map(int, input().split(" "))
    print arr[b] + " " + arr[a]
