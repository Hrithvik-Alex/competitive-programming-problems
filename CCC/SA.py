inputnumber = raw_input()
output1 = []
output = []
multiplier = 0
multiplier1 = 0

lowerstring = ""

for i in inputnumber:
	if i != 0:
		multiplier1 = len(inputnumber) - 1 - i
		multiplier = 10 ** multiplier1
		output1[i] = int(lowerstring[i]) * multiplier

for i in inputnumber:
	if i == len(inputnumber) - 1:
		if output1[i] != 0:
			print output1[i]
	else:
		if output1 != 0:
			print output1[i] + " + "




