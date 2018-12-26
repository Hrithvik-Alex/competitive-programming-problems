start = map(int, raw_input().split())
end = map(int, raw_input().split())
charge = int(raw_input())

def distance(coord1, coord2):
	distance = 0
	distance += abs(coord1[0] - coord2[0])
	distance += abs(coord1[1] - coord2[1])
	return distance

dis = distance(start, end)

def isEven(num):
	if num % 2 == 0:
		return True
	else:
		return False
if charge >= dis:
	if dis > 0:
		if isEven(dis) == isEven(charge):
			print "Y"
		else:
			print "N"
	else:
		if isEven(charge):
			print "Y"
		else:
			print "N"
else:
	print "N"