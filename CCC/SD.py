N = (int(raw_input()))
V = []
V = (map(int, raw_input().split()))
Jake = 0
Josh = 0

def take(lit):
	for i in lit:
		if lit[i] > lit[i + 1]:
			return True
		else:
			return False



