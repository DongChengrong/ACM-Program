s = raw_input()
li = s.split('WUB')
n = 0
while '' in li:
    li.remove('') 
for e in li:
    n = n + 1
for i in range (0, n - 1):
    print li[i]+' ',
print li[n - 1]
