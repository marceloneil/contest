#https://dmoj.ca/problem/tle16c2p2
n = int(input())
x,y,z = map(int,raw_input().split())
a,b,c = map(int,raw_input().split())
max = 0
if (int(a/x) * int(b/y) * int(c/z)) > max:
    max = int(a/x) * int(b/y) * int(c/z)
if (int(a/x) * int(c/y) * int(b/z)) > max:
    max = int(a/x) * int(c/y) * int(b/z)
if (int(b/x) * int(a/y) * int(c/z)) > max:
    max = int(b/x) * int(a/y) * int(c/z)
if (int(b/x) * int(c/y) * int(a/z)) > max:
    max = int(b/x) * int(c/y) * int(a/z)
if (int(c/x) * int(b/y) * int(a/z)) > max:
    max = int(c/x) * int(b/y) * int(a/z)
if (int(b/x) * int(a/y) * int(b/z)) > max:
    max = int(b/x) * int(a/y) * int(b/z)
if max is 0:
    print "SCAMMED"
else:
    print max/n
