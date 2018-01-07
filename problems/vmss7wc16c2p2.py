thestring = []
thestring = list(input())
n = input()
#building the psa
psa = [0 for i in range(len(thestring))]
for i in range(len(thestring)):
    if i is 0:
        if thestring[0] == 'G':
            psa[i] = 1
        else:
            psa[i] = 0
    else:
        if thestring[i] == 'G':
            psa[i] = psa[i-1]+1
        else:
            psa[i] = psa[i-1]
for i in range(int(n)):
    a, b = map(int, input().split())
    l = psa[int(a)]
    r = psa[int(b)]
    print((r-l))
