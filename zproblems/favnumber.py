n = int(input())
stuff = list(map(int,input().split(" ")))
q = int(input())
stuff.sort()
for x in range(q):
    a = int(input())
    count = 0
    countingStuff = False
    lastThing = ""
    for thing in stuff:
        if thing >= a:
            lastThing = thing
            countingStuff = True
            count +=1
        else:
            if countingStuff:
                print(lastThing + " " + count)
