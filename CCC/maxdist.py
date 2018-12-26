N = int(raw_input())
listx = []
listy = []
for x in range(N):
	y = int(raw_input())
	listx.append(map(int, raw_input().split()))
	listy.append(map(int, raw_input().split()))

def elemdistance(list1, list2):
	x = 0
	distances = []
	while x < len(list1):
		y = 0
		while y < len(list2):
			if list1[x] == list2[y]:
				distances.append(y-x)
				break
			y += 1
		x += 1
	distances.sort()
	if len(distances) == 0:
		return 0
	else:
		return distances[len(distances)-1]

equat = 0
while equat < N:
	print "The maximum distance is " + str(elemdistance(listx[equat], listy[equat]))
	equat += 1