Q = int(raw_input())
N = int(raw_input())
D = map(int, raw_input().split())
P = map(int, raw_input().split())

if Q == 1:
	D.sort()
	P.sort()
	i = 0
	total = 0
	while i < N:
		total += max(D[i], P[i])
		i += 1
	print total
else:
	allspeeds = D + P
	allspeeds.sort()
	total = 0
	i = 0
	while i < len(allspeeds) / 2:
		total += allspeeds[len(allspeeds) - 1 - i]
		i += 1
	print total