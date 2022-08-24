import copy
import random


class Vertex():
	def __init__(self,id):
		self.id=id
		self.neighbours=[]
		self.color=-1
	
	def __repr__(self):
		s="vertex: "+str(self.id)+" color: "+str(self.color)+" | "
		for n in self.neighbours:
			s+=str(n)+", "
		return s+"\n"

	def add_neighbours(self,N):
		for n in N:
			if n!=self.id and not n in self.neighbours:
				self.neighbours.append(n)
	def get_state(self):
		return (self.id,self.color)


	
	#def __deepcopy__(self,memo):
	#	return Vertex(self.id,self.color,self.neighbours.copy())


class Solver(): # base class for the solvers OOP
	def __init__(self,graph_):
		self.graph=graph_
		#self.issolved=False
		self.solution=None
		self.chromatic=-1

	def Solve(self):
		print("Base class")
	
	def isProper(self): # checks if the coloring is proper or not
		isproper=True
		colnum=0
		error=0
		for v in self.graph:
			colnum= max(v.color,colnum)
			for i in v.neighbours:
				if v.color == self.graph[i-1].color:
					isproper=False
					error+=1
					pass
		if isproper:
			#self.solution=[(v.id,v.color) for v in self.graph]			
			print("it is a proper coloring with ",colnum+1,"color")
		else:
			print("not proper coloring, error:",error)

		return isproper,error




class Trivial_solver(Solver):
	def __init__(self,graph_):
		super(Trivial_solver, self).__init__(graph_)
		#self.graph=graph_

	def Solve(self):
		for i,item in enumerate(self.graph):
			item.color=i
			self.chromatic=i
		self.solution=[(v.id,v.color) for v in self.graph]


class Gready_solver(Solver):
	def __init__(self,graph_):
		super(Gready_solver, self).__init__(graph_)

	def Solve(self):
		for i,item in enumerate(self.graph):
			nono=[self.graph[n-1].color for n in item.neighbours]
			nono=list(filter(lambda x : x!=-1,nono))
			color=0
			while 1:
				if color not in nono:
					item.color=color
					break
				else:
					color+=1
					self.chromatic=max(self.chromatic,color)
					#print(color)
			self.solution=[(v.id,v.color) for v in self.graph]



"""

Tabu solver. 
1. get lover and upperbound for the coloring.
2. start from the upper bound and run the algoryth
3. if we fount proper coloring we save it
4. if not and runing out of iterations we exit the search and the last 
saved proper coloring will be the answer

"""


class Tabu_solver(Solver):
	def __init__(self,graph_):
		super(Tabu_solver, self).__init__(graph_)
		self.best_bad_vertices=[]
		self.error=99999
		self.doshufle=False
		self.useGready=False


	def Solve(self):
		#get loverbound
		loverbound=1 # can be improved
		#for i,item in enumerate(self.graph):
		#	loverbound=max(loverbound,len(item.neighbours))

		if self.useGready:
			gr=Gready_solver(self.graph)
			gr.Solve()
			self.chromatic=gr.chromatic
			#for i,item in enumerate(self.graph):
			#	item.color=random.randrange(0,self.chromatic) if item.color>self.chromatic else item.color
		else:
			self.chromatic=len(self.graph)
			#get random colors
			for i,item in enumerate(self.graph):
				item.color=random.randrange(0,self.chromatic)

		print("loverbound",loverbound,"using",self.chromatic+1,"color")


		#print(self.graph)
		#check what coloring number we can find proper coloring
		for C in range(self.chromatic,loverbound,-1):
			print("trying",C,"color")
	
			C_best_bad_vertices=[]
			C_best_error=99999
			C_best_solution=None
			#randomly assigne colors to the graph
			for i,item in enumerate(self.graph):
				item.color=random.randrange(0,C) if item.color>C else item.color
			
			#print(self.graph)

			iterations = 0
			max_iterations=100000
			shufle_count=10000

			while iterations < max_iterations:
				iterations+=1
				error=0
				bad_vertices={} # calculating and collecting vertices that are not proper
				for v in self.graph:
					for i in v.neighbours:
						if v.color == self.graph[i-1].color:
							bad_vertices[v.id]=1 # 1 is not matter just using this for the dictionary keys
							error+=1
				
				#print(bad_vertices)

				if error == 0:#proper coloring found
					C_best_solution=[(v.id,v.color) for v in self.graph]	
					C_best_error=error
					C_best_bad_vertices=bad_vertices
					for i,c in C_best_solution:
						self.graph[i-1].color=c
					self.solution=C_best_solution
					self.best_bad_vertices=C_best_bad_vertices
					self.error=C_best_error
					self.chromatic=C
					break
				if error < C_best_error: # better coloring found
					C_best_solution=[(v.id,v.color) for v in self.graph]	
					C_best_error=error
					C_best_bad_vertices=bad_vertices
					shufle_count=10000
				else: # coloring worse than last time reseting graph to previous state
					shufle_count-=1
					for i,c in C_best_solution:
						self.graph[i-1].color=c
					for k,_ in C_best_bad_vertices.items():
						self.graph[k-1].color=random.randrange(0,C)
				if iterations%10000==0: # simple print
					print("Error",C_best_error,"iteration",iterations)
				
				if self.doshufle: # if error is not changed in a last 10000 try, double the error, this may push it out the local minima
					if shufle_count<=0:
						print("shufle")
						shufle_count=10000
						for i,item in enumerate(self.graph):
							item.color=random.randrange(0,C)
						C_best_solution=[(v.id,v.color) for v in self.graph]	
						C_best_error+=C_best_error
						#for i in range(10):
						#	self.graph[random.randrange(0,len(self.graph))].color=random.randrange(0,C)
					#for k,_ in C_best_bad_vertices.items():
			if iterations >= max_iterations:
				#cant go further
				# if we run out the iteration that means we can stop and reseting the graph to previous proper coloring
				for i,c in self.solution: # reset graph
					self.graph[i-1].color=c
				break

	
		print("Done",self.error,"error,chromatic number =",self.chromatic+1)
		#print(self.solution)

			
				
			

