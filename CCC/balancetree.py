N = int(raw_input())

def findMaxAtSubtreeAmount(amount, weight):
	return (weight / amount)


def findBalance(num):
	balance=0
	balancecache={}
	amount=num
	if num==1:
		return 1
	else:
		while amount>=2:
			commonweight = findMaxAtSubtreeAmount(amount, num)
			if commonweight>2:
				if commonweight in balancecache:
					balance+=balancecache[commonweight]
				else:
					balancecache[commonweight]=findBalance(commonweight)
					balance+=balancecache[commonweight]
			else:
				balance+=1
			amount-=1
		balancecache[num]=balance
		return balance

print findBalance(N)
