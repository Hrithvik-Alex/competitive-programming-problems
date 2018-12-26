N=int(raw_input())
flowers=[map(int, raw_input().split()) for i in range(N)]
def rotate(data):
	newdata = [[] for i in range(len(data))]
	z = -1
	w=0
	while z>(0-len(data))-1 and w<len(data):
		y=0
		while y<len(data):
			newdata[w].append(data[y][z])
			y+=1
		z-=1
		w+=1
	return newdata
def print2DArray(array):
	x=0
	newarray=['' for i in range(len(array))]
	while x<len(array):
		y=0
		while y<len(array):
			newarray[x]+=str(array[x][y]) + ' '
			y+=1
		x+=1
	for i in newarray:
		print i



flower90=rotate(flowers)
flower180=rotate(flower90)
flower270=rotate(flower180)

if flowers[0][1]>flowers[0][0] and flowers[1][0] > flowers[0][0]:
	print2DArray(flowers)
elif flowers[0][1]<flowers[0][0] and flowers[1][0] > flowers[0][0]:
	print2DArray(flower90)
elif flowers[0][1]>flowers[0][0] and flowers[1][0]<flowers[0][0]:
	print2DArray(flower270)
else:
	print2DArray(flower180)
