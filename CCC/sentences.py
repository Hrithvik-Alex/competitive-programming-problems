N = int(raw_input())
for x in range(N):
	subjects = []
	verbs = []
	objects = []
	subject = int(raw_input())
	verb = int(raw_input())
	objec = int(raw_input())
	for y in range(subject):
		subjects.append(raw_input())
	for w in range(verb):
		verbs.append(raw_input())
	for z in range(objec):
		objects.append(raw_input())
	for s in subjects:
		for v in verbs:
			for o in objects:
				print s + " " + v + " " + o + "."