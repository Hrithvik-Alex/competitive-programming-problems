N=int(raw_input())
villages=[int(raw_input()) for i in range(N)]
villages.sort()
villagesize=[]

x=1
while x<len(villages)-1:
	size = float(villages[x]-villages[x-1])/2 + float(villages[x+1]-villages[x])/2
	villagesize.append(size)
	x+=1

villagesize.sort()
print villagesize[0]
