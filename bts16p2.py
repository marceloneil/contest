n = input();
items = set()
for x in range(n):
    string = raw_input()
    a = int(string.split(" ")[0])
    b = string.split(" ")[1]
    if a == 1:
        items.add(b)
    elif a == 2:
        if b.issubset(items):
            items.remove(b)
            print "true"
        else:
            print "false"
    elif a == 3:
        
