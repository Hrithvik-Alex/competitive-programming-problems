Tides = []

N = int(raw_input())
Tides = (map(int, raw_input().split()))
if N != len(Tides):
	print "Invalid number of measurments."
else:
	if len(Tides) < 1 or len(Tides) > 100:
		print "Invalid Output."
	else:
		STides = sorted(Tides)
		x = 0

		LTides = []
		HTides = []
		if N % 2 == 0:
			while x <= len(STides) - 1:
				if x < (len(STides) / 2):
					LTides.append(STides[x])
				else: 
					HTides.append(STides[x])
				x+= 1
		else:
			while x <= len(STides) - 1:
				if x < ((len(STides) + 1)/ 2):
					LTides.append(STides[x])
				else:
					HTides.append(STides[x])
				x += 1

		LTides.sort(reverse=True)

		Fout = ''
		z = 0
		if N % 2 != 0:
			Fout += str(LTides[0]) + ' ' 
			for y in HTides:
				Fout += str(y) + ' '
				Fout += str(LTides[z + 1]) + ' '
				
				z += 1	
		else:
			for w in LTides:
				Fout += str(w) + ' '
				Fout += str(HTides[z]) + ' '
				z += 1

		print Fout



