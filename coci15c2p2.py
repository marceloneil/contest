#https://dmoj.ca/problem/coci15c2p2
n, m = map(int, input().split(" "))
ban = []
for _ in range(m):
    a, b = map(int, input().split(" "))
    ban.append((a,b))
    ban.append((b,a))
#print(ban)
list = []
if m > 0:
    list.append((0,0))
for x in range(n+1):
    for y in range(n+1):
        if (x,y) not in ban and (y,x) not in list:
            if x != y:
                list.append((x,y))
if m == 0:
    print(2**n)
else:
    print(len(list))
