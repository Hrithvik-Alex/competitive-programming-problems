N = int(raw_input())

inputs = []
for x in range (N):
	inputs.append(int(raw_input()))

for num in inputs:
	total = 0
	y = 1
	while y < num:
		if num % y == 0:
			total += y
		y+= 1
	if total < num:
		print str(num) + " is a deficient number."
	elif total == num:
		print str(num) + " is a perfect number."
	else:
		print str(num) + " is an abundant number."
		