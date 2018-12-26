class Node(object):
	def __init__(self):
		self.isPho = False
		self.connections = []

class Graph(object):
	def __init__(self):
		nodes = []
	def addConnect(self, node1, node2):
		node1.connections.append(node2)
		node2.connections.append(node1)

tree = Graph()

inits = map(int, raw_input().split())
Nrests = inits[0]
Npho = inits[1]

phorests = map(int, raw_input().split())

for i in range(Nrests - 1):
	inp = map(int, raw_input().split())
	if inp[0] not in tree.nodes:
		inp[0] = Node()
		tree.nodes.append(inp[0])
	if inp[1] not in tree.nodes:
		inp[1] = Node()
		tree.nodes.append(inp[1])
	tree.addConnect(inp[0], inp[1])









