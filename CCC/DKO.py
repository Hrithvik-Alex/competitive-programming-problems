N = int(raw_input())
for x in range(N):
	undefeated = int(raw_input())
	onelosses = 0
	elim = 0
	rounds = 0
	while undefeated > 2:
		print "Round:" + str(rounds) + " " + str(undefeated) + " undefeated, " + str(onelosses) + " one-loss, " + str(elim) + " eliminated"
		if onelosses % 2 == 0:
			onelosses /= 2
			elim += onelosses/2
		else:
			onelosses = onelosses/2 + 1
			elim += onelosses/2 + 1

		if undefeated % 2 == 0:
			undefeated = undefeated/2
			onelosses += undefeated/2
		else:
			undefeated = undefeated/2 + 1
			onelosses += undefeated/2 + 1
		rounds += 1
		
	if (undefeated + onelosses) == 2:
		print "Round:" + str(rounds) + " " + str(undefeated) + " undefeated, " + str(onelosses) + " one-loss, " + str(elim) + " eliminated"
		undefeated -= 1
		onelosses += 1
		rounds += 1
		if undefeated == 1:
			print "Round:" + str(rounds) + " " + str(undefeated) + " undefeated, " + str(onelosses) + " one-loss, " + str(elim) + " eliminated"
			undefeated -= 1
			rounds += 1
		print "Round:" + str(rounds) + " " + str(undefeated) + " undefeated, " + str(onelosses) + " one-loss, " + str(elim) + " eliminated"
		onelosses -= 1
		elim += 1
		rounds += 1
		print "Round:" + str(rounds) + " " + str(undefeated) + " undefeated, " + str(onelosses) + " one-loss, " + str(elim) + " eliminated"
		print "There are " + str(rounds) + " rounds."



		


	
