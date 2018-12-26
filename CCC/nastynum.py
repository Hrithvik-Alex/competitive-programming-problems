N = int(raw_input())
numbers = []
for x in range(N):
	numbers.append(int(raw_input()))

def factors(num):
	factors = []
	for i in range(1, num/2 + 1):
		if num % i == 0:
			if i not in factors:
				factors.append(i)
				factors.append(num/i)
	return factors

def isNasty(num):
	x = 0
	sums = []
	diffs = []
	facs = factors(num)
	while x < len(facs):
		sums.append(facs[x] + facs[x+1])
		diffs.append(facs[x+1] - facs[x])
		x += 2
	for s in sums:
		for d in diffs:
			if s == d:
				return True 
	return False

for n in numbers:
	if isNasty(n) == True:
		print str(n) + " is nasty"
	else:
		print str(n) + " is not nasty"
