#Binary search for multiples of 13 implementation using iteration

thirteenslist = [x for x in range(100000) if x % 13 == 0] #creating a list of multiples of thirteen using list comprehension
n = int(raw_input("Is your number a multiple of 13?: ")) #input

if n > 100000 or n < 0:
	print "Invalid input. number must be within 0 and 100,000."
else:
	def binarysearch(array, value):
		lowest = 0
		highest = len(array) - 1
		
		while lowest <= highest: #while loop will either return Yes when value equals middle or will exit the loop and return No if it isn't found.
			middle = (lowest + highest)/2
			if value == array[middle]:
				return "Yes it is!"
			elif value < array[middle]:
				highest = middle - 1
			else:
				lowest = middle + 1
		return "Nope. Sorry!"

	print binarysearch(thirteenslist, n)
