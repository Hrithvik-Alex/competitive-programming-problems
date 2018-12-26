N = int(raw_input())
readings = [0 for i in range(1000)]
for i in range(N):
	i = int(raw_input())
	readings[i-1] += 1
maxx = max(readings)
moremax = [i for i,m in enumerate(readings) if maxx==m]
moremax.sort()

if len(moremax) > 1:
	print (moremax[-1] - moremax[0])
else:
	x=0
	while x <len(readings):
		if readings[x]==maxx:
			readings[x]=0
		x+=1

	maxxnew = max(readings)
	moremax2 = [i for i,m in enumerate(readings) if maxxnew==m]
	
	y = 0
	while y<len(moremax2):
		moremax2[y] = abs(moremax[0]-moremax2[y])
		y+=1

	moremax2.sort()

	if len(moremax2) > 1:
		print moremax2[-1]
	else:
		print moremax2[0] 

