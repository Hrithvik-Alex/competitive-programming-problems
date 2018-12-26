#Python implementation of quick sort.

array = map(int, raw_input("Enter numbers in random order: ").split()) #input

def quicksort(numbers):
	below = []
	equal = []
	above = []
	if len(numbers) < 2:
		return numbers
	else:
		checker = numbers[0]  #checker is used to sort numbers by checking every number and whether is greater or lesser
		for x in numbers:
			if x < checker:
				below.append(x)
			if x == checker:
				equal.append(x)
			if x > checker:
				above.append(x)
		return quicksort(below) + equal + quicksort(above)  #recursion is used to assign new checker to sort the below and above lists

print quicksort(array)