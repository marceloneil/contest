#https://dmoj.ca/problem/tle16c2p1
day = raw_input()
have = 0
maxday = 1;
maxamount = 0;
day = int(day)
for x in range(day):
  a, b = raw_input().split()
  b = int(b)
  if a == "borrow":
    have+=b
  else:
    have-=b
  if have > maxamount:
    maxday = x
    maxamount = have
print maxday+1

