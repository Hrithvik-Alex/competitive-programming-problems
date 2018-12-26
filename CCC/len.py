
N = int(raw_input())
if N < 1 or N > 100000:
	print "Invalid Output."
else:
	Swifts = []
	Semaphores = []

	Swifts = (map(int, raw_input().split()))
	Semaphores = (map(int, raw_input().split()))
		

	def cumulfreq(lits):
		Sumlits = []
		total = 0
		for x in lits:
			total += x
			Sumlits.append(total)
		return Sumlits

	SumSwifts = cumulfreq(Swifts)
	SumSephamores = cumulfreq(Semaphores)

	SameScores = []
	i = 0
	while i <= len(SumSwifts) - 1:
		if SumSwifts[i] == SumSephamores[i]:
			SameScores.append(i + 1)
		i+= 1

	if len(SameScores) ==  0:
		print 0
	else:
		print SameScores[len(SameScores) - 1]










