N = (int(raw_input()))

skilllevels = []
skilllevels = (map(int, raw_input().split())) 

skilllevels.sort()

teamcombos = []

i=0
while i <= (len(skilllevels) / 2) - 1:
	teamcombos.append(skilllevels[i] + skilllevels[len(skilllevels) - i - 1])
	i += 1

teamcombos.sort()

print teamcombos[len(teamcombos)-1] - teamcombos[0]