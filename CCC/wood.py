
N = (int(raw_input()))
if N < 2 or N > 1000000:
	print "Invalid input."
else:
	Wood = (map(int, raw_input().split()))
	count = [0] * 2001
	for woods in Wood:
		count[woods] += 1
	
	def boardsAtHeight(height):
		copy = list(count)
		a = max(1, height - 2000)
		b = height - a
		numboards = 0

		while a <= height/2:
			if a == b:
				boards = copy[a] / 2
				copy[a] -= boards * 2
				numboards += boards
			else:
				boards = min(copy[a], copy[b])
				copy[a] -= boards
				copy[b] -= boards
				numboards += boards

			a += 1
			b -= 1

		return numboards

	maxBoards = 0
	heightsAtMaxBoards = 0

	i = 2
	while i <= 4000:
		boards = boardsAtHeight(i)
		if boards > maxBoards:
			maxBoards = boards
			heightsAtMaxBoards = 0
		if boards == maxBoards:
			heightsAtMaxBoards += 1
		i+=1
	print maxBoards, heightsAtMaxBoards




		






		


