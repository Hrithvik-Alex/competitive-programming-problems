G = int(raw_input())
P = int(raw_input())
dock = 0
gates = list("O" * G)
for i in range(P):
	i = int(raw_input())
	ind = i-1
	while ind>=0:
		if gates[ind]:
			dock+=1
			gates[ind]=None
			break
		else:
			ind-=1
	if ind<0:
		break

print dock


