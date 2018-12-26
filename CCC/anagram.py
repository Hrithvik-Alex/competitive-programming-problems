string = raw_input()
check = raw_input()

a = (sorted(string))
b = (sorted(check))

astericks = 0
x = 0
while x<len(b):
	if b[x]=="*":
		astericks +=1
	x+=1

y=0
new=""
while y<len(a):
	z=0
	while z<len(b):
		if a[y] == b[z]:
			new+=a[y]
			b[z]="!"
			break
		z+=1
	y+=1

if len(new) == (len(b) - astericks):
	print "A"
else:
	print "N"
