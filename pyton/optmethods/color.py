import random
import copy
from solver import * 


print("Coloring graphs")

"""

Schmidt László FEBFR8
problems to solve:	13. Hypergraph coloring

Graph coloring is an NP complete problem. 
I can't prove that this program gives the minimal coloring number.
It is only an aproximation with Metaheuristic.
I wrote 3 solver
Trivial, Gready, and Tabu. Thay are in solver.py
The trivial and grady is preaty straight forward i won't explain.
For the Tabu search i commented the code in the solver.py 

ie. I write chromatic for the coloring number, but it is not proven that 
it is the cromatic number of the graph, it just a was a good name for the variable.


"""

C=30
Subs=[
[1,5,8,9,12,15],
[1,2,3,4,5,6,8,9,15,16,17,19],
[1,4,5,6,9,15,22,23,25,27,28],
[3,4,5,6,7,9,14,16,23,29],
[2,4,6,8,10,12],
[2,3,4,6,8,10],
[4,5,6,8,9,13],
[5,6,7,22,23,24,25,26,28],
[6,7,9,11,15,17,30],
[7,9,11,13,17,22],
[8,10,12,14,16,20,24],
[9,10,11,12,14],
[10,11,12,13,14,15,16,17,18,19,20],
[21,22,23,25],
[22,23,25,28,29,30],
[23,24,25,26,27,28],
[24,25,28,29,30],
[25,26,27,28],
[28,29,30],
[29,30]]


#generating Vertices from list
w= [Vertex(i+1) for i in range(C)]


#adding edges,neighbours
for i in range(len(w)):
	for s in Subs:
		if w[i].id in s:
			w[i].add_neighbours(s)

print("The uncolored graph")

print(w) # printing out the graph

print("-"*40)

print("Trivial solver output")
# Trivial solver assing new color for every vertices
tr=Trivial_solver(copy.deepcopy(w))
tr.Solve()

print(("vertice","color"))
for s in tr.solution:	# vertice id and color of the proper coloring
	print(s)

tr.isProper()

print("-"*40)
# Gready solver assing not used color to the vertices


gr=Gready_solver(copy.deepcopy(w))
gr.Solve()

print(("vertice","color"))
for s in gr.solution:	# vertice id and color of the proper coloring
	print(s)

gr.isProper()

# Meta heurisztic solver tabu search
tb=Tabu_solver(w)
#tb.useGready=True		# you can define to use gready pre search
#tb.doshufle=True		# you can define that use little shufle action to try push out from local minimum
tb.Solve()				
tb.isProper()	# 

print(("vertice","color"))
for s in tb.solution:	# vertice id and color of the proper coloring
	print(s)

print("-"*20)




