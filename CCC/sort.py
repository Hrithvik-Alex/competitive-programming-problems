numbers = []

amount = int(raw_input("Enter how many numbers you would like sorted: "))
if amount < 0:
	print "Invalid amount."  

for num in range(1):
	num = int(raw_input("Enter a number: "))
	if num > 100:
		print "First number cannot be greater than 100. Try again."
		break
	else:
		numbers.append(num)

for num in range(amount - 1):
	num = int(raw_input("Enter a number: "))
	if num < 0:
		print "Sorry, number must be positive. Try again."
		break 
	elif num > 32000:
		print "Sorry, numbers cannot be greater than 32000. Try again."
		break
	else:
		numbers.append(num)

numbers.sort()

for ints in numbers:
	print ints
