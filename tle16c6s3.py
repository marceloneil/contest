n = input()
#every coordinate in the dp array determines how far fax can go in that range
#when increasing the size of the range by one, if both sides can't be reached by fix then that answer at that point is 
dp = [n][n]
dis = []
ener = []
for a in range(n):
    x,d = map(int,input().split(" "))
    dis.append(x)
    ener.append(d)
for length in range(n):
    for i in range(n):
        for j in range(length):
