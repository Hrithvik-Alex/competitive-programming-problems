N = int(raw_input())

inputs = []
for x in range (N):
	inputs.append(raw_input())
romanbases = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
def intize(romnum):
	num = 0
	x = 0
	while x < len(romnum):
		if x < len(romnum) - 1:
			if romanbases[romnum[x]] < romanbases[romnum[x + 1]]:
				num -= romanbases[romnum[x]]
			else:
				num += romanbases[romnum[x]]
		else:
			num += romanbases[romnum[x]]
		x += 1
	return num

def romanize(num):
	rom = ""
	while num > 0:
		if num >= 1000:
			rom+="M"
			num -= 1000
		elif num >= 500:
			rom+="D"
			num -= 500
		elif num >= 100:
			rom+="C"
			num -= 100
		elif num >= 50:
			rom+="L"
			num -= 50
		elif num >= 10:
			rom+="X"
			num -= 10
		elif num >= 5:
			rom+="V"
			num -= 5
		elif rom >= 1:
			rom+="I"
			num -= 1
	x = 0
	newrom = ""
	while x < len(rom):
		if rom.count(rom[x]) > 3:
			if rom[x] == "I":
				if rom[x - 1] == "V":
					newrom += "IX"
					newrom = newrom.replace("V", "")
					x+=3
				else:
					newrom += "IV"
					x+=3
			if rom[x] == "X":
				if rom[x - 1] == "L":
					newrom += "XC"
					newrom = newrom.replace("L", "")
					x+=3
				else:
					newrom += "XL"
					x+=3
			if rom[x] == "C":
				if rom[x - 1] == "D":
					newrom += "CM"
					newrom = newrom.replace("D", "")
					x+=3
				else:
					newrom += "CD"
					x+=3
		else:
			newrom += rom[x]
		x += 1
	return newrom

for equat in inputs:
	x = 0
	firstnum = 0
	secondnum = 0
	while x < len(equat):
		if equat[x] == "+":
			firstromnum = equat[0:x]
			firstnum += intize(firstromnum)
			secondromnum = equat[(x+1):(len(equat)-1)]
			secondnum += intize(secondromnum)
		x += 1
	summ = firstnum + secondnum
	if summ > 1000:
		print equat + "CONCORDIA CUM VERITATE"
	else:
		print equat + romanize(summ)









