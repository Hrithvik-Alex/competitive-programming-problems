Njersey = int(raw_input())
Nathlete = int(raw_input())
jerseys = [raw_input() for i in range(Njersey)]
athletes = [raw_input().split() for i in range(Nathlete)]
sizeval = {"XS":0, "S":100, "M":200, "L": 300}

satisfied = 0

x = 0
while x < len(athletes):
	if sizeval[athletes[x][0]] <= sizeval[jerseys[int(athletes[x][1]) - 1]]:
		satisfied += 1
		jerseys[int(athletes[x][1]) - 1] = "XS"
	x+=1

print satisfied
