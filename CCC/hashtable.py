#Hash table in python to store string along with a hash function to calculate value of string in table

class HashTable(object):
	def __init__(self):
		self.table = [None] * 1000 # creates empty table

	def hashfunction(self, string):
		value = (ord(string[0]) * 88 + ord(string[1]) * 10) # function calculates ASCII value of first letter times 88 plus second letter times 10. 
		return value

	def store(self, string): 
		self.table.append(string) # put value in table

	def search(self, string):
		for word in self.table: # searches for value in table
			if word == string:
				return self.hashfunction(string) # returns hash value of stirng in table

hash_table = HashTable()

word = raw_input("Enter a string: ")
hash_table.store(str(word))
print "Hash value is " + str(hash_table.search(word))