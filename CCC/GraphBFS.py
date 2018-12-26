#Implementing a graph in python and performing a BFS search on the graph to find the shortest path.

class Node(object): #initializing each Node of the graph
	def __init__(self, node):
		self.name = node
		self.neighbors = []

	

class Graph(object): # creates the graph.
	def __init__(self, nodes = []):
		self.nodes = nodes

	def addnode(self, name): # adds nodes and their neighbors to the graph.
		newNode = Node(name)
		self.nodes.append(newNode)
	
	def addneighbors(self, node, node2):
		node.neighbors.append(node2)
		node2.neighbors.append(node)


	def bfs(self, start): # does a breath-first search.
		if self.nodes is None:
			return []
		explored, path = [], [start]
		while path:
			node = path.pop(0)#pops longest queue element
			explored.append(node)
			print node.name#prints each element in order
			for nd in node.neighbors:
				if nd not in explored and nd not in path:
					path.append(nd)#adds node to beginning of queue, repeats process
					




graph=Graph()
#Set up nodes
graph.addnode('A')
graph.addnode('B')
graph.addnode('C')
graph.addnode('D')
graph.addnode('E')
graph.addnode('F')
#Set up connections
graph.addneighbors(graph.nodes[0], graph.nodes[2])
graph.addneighbors(graph.nodes[0], graph.nodes[1])
graph.addneighbors(graph.nodes[1], graph.nodes[3])
graph.addneighbors(graph.nodes[1], graph.nodes[4])
graph.addneighbors(graph.nodes[2], graph.nodes[5])
graph.addneighbors(graph.nodes[4], graph.nodes[5])

# Graph Visualization
#      A
#     / \
#    C   B
#    |  / \
#    | D   E
#    |    /
#    --- F

print graph.bfs(graph.nodes[0])