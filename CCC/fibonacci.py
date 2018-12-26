#Code will return fibonacci number at position requested.

amount = int(raw_input("which position in the fibonacci sequence would you like?: "))  #input
if amount<=0: 
	print "please enter a positive integer."
else:
	def fibonacci(n):
		if n == 0 or n == 1:
			return n  #first two values must be stated
		else:
			return fibonacci(n - 1) + fibonacci(n - 2)  #recursive implementation to obtain fibonacci number
  
	print fibonacci(amount)