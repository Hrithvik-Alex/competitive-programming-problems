#Code will return as many fibonacci numbers in the sequence as requested

n = int(raw_input)  #input

def fibonacci(x):
	fiblist = []
	if x == 0:
		fiblist.append(0)
	elif x == 1:
		fiblist.append(1) 
	else:
		fiblist.append(fibonacci(x-1) + fibonacci(x-2))  #using recursion to generate fibonacci numbers
	for number in fiblist:
		return fiblist,  #returning all numbers on the same line

print fibonacci(n)