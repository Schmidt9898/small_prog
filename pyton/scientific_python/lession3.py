print("lession 3")

print("1. Write a function which calculates the geometrical mean of a variable number of values")
def geometrical_mean(nums):
	val=1
	for n in nums:
		val*=n
	return val ** (1/len(nums))

print(geometrical_mean([1,2,3,4,5]))

print("2. Implement a function that receives a matrix and returns the transposed matrix.")
def T(m):
	#print(m)
	#result=[([0]*len(m))]*len(m[0])# this is bad
	result=[]
	for i in range(len(m[0])):
		result.append([0]*len(m))
	#print(result)
	for x in range(len(m)):
		for y in range(len(m[0])):
			result[y][x]=m[x][y]
			#print(int(result[y][x]))

	#for x in result:
	#	print(x)
	return result


print(T([[1,2,3],[3,4,5]]))

print("3. Implement the Matrix Multiply Operation as a function.")

def Mul(A,B):
	N=len(A)
	c=[]
	for i in range(N):
		c.append([0]*N)
	
	for i in range(N):
		for j in range(N):
			for k in range(N):
				c[i][j] = c[i][j]+(A[i][k] * B[k][j])
	return c
print(Mul([[1,0],[0,1]],[[1,2],[2,4]]))


print("4. Create a database for cities' name, region, type,area, and population based on city.txt")

class Entry:
	def __init__(self,n,r,t,a,p):
		self.name=n
		self.region=r
		self.type=t
		self.area=int(a)
		self.population=int(p)
	
	def load(line: str):
		fields=line.split(",")
		return Entry(fields[0],fields[1],fields[2],fields[3],fields[4])

	def __str__(self):
		return self.name+","+self.region+","+self.type+","+str(self.area)+","+str(self.population)

lines=[]
with open("city") as file:
	lines=file.readlines()
#print(lines)
cities=map(Entry.load,lines)
cities=list(cities)


print("5. Write a function which give me the most populous settlement.")
import functools
def most_pop(cities):
	return functools.reduce(lambda x,y : x if x.population > y.population else y,cities)

print(most_pop(cities.copy()))

#for c in cities:
#	print(c)

print("Write a function which give the number of cities of a region.")

def num_regions(cities):
	regions={}
	for c in cities:
		if c.region in regions.keys():
			regions[c.region]+=1
		else:
			regions[c.region]=1
	for k,v in regions.items():
		print(k,":",v)

print("The number of cities of a region: ")
num_regions(cities)


print("Write a function which give the average area of settlements.")

def average_area(cities):
	return sum(map(lambda x:x.area,cities))/len(cities)

print("The average area of settlements: ",average_area(cities))


print("Write a function which give the smallest population density from the settlements.")

def smallest_set(c):
	return min(c,key=lambda x:x.area/x.population )

print(smallest_set(cities))

print("Given an list of integers, return True if the array contains a 2 next to a 2 somewhere. 2 should be a (default) parameter.")
int_list=[0,0,0,0,0,1,2,2,0,2,2,2,2,4,5,5,6,6,7]
def task_9(int_list):
	for i in range(len(int_list)-1):
		if int_list[i]==2 and int_list[i+1]==2:
			return True
	return False

print("task 9: ",task_9(int_list))



print("Write a function shiftByTwo(*args) that accepts a variable number of arguments and returns a tuple with the argument list shifted to the right by two indices.")
def shift2(*kwargs):
	kwargs=list(kwargs)
	a=kwargs[-2:]
	a.extend(kwargs[0:-2])
	return tuple(a)

print(shift2(1,2,3,5,7,"asd","dssdadadssd"))

print("11. Write a function sortByIndex(aList) that takes in a list of tuples in the following format: (index, value) and returns a new tuple with its elements sorted based by their index.")
def sortByIndex(aList):
	aList.sort(key=lambda x:x[0])
	return aList

alist=[(3,1),(2,["asd","s"]),(1,"as")]
print(sortByIndex(alist))


print("12. Write a recursive function countX that takes a string and returns the number of uppercase 'X' characters in the string.")
def countX(str_: str):
	return 0 if not len(str_) else (1 if str_[0]=='X' else 0 ) + countX(str_[1:])

print("XSSDxxXX",countX("XSSDxxXX"))
print("XSSDxX",countX("XSSDxX"))
print(countX(""))


print("13. Write a function numbersInbetween(start, end) that takes in two numbers and returns a comma- separated string with all the numbers in between the start and end number inclusive of both numbers.")
def numbersInbetween(start, end):
	return str(start) if start==end else str(start)+","+numbersInbetween(start+1,end-1)+","+str(end) if (end-start)!=1 else str(start)+","+str(end)

print(numbersInbetween(3,5))
print(numbersInbetween(1,1))
print(numbersInbetween(1,4))


print("14. Write a recursive function that traverses the tree given below and appends a new left node with the name 42 to each leaf node!")

class Node:
	def __init__(self,name_):
		self.name=name_
		self.l=None
		self.r=None
	def add_l(self,n):
		self.l=Node(n)
	def add_r(self,n):
		self.r=Node(n)
	def __str__(self):
		return self.name+" L ->["+str(self.l)+"] R->["+str(self.r)+"]"
	def _42(self):
		if self.l==None and self.r==None:
			self.l=Node("42")
		else:
			if self.l!= None:
				self.l._42()
			if self.r!= None:
				self.r._42()
			

a=Node("root")
a.add_l("left")
a.add_r("right")
print(a) 
a._42()
print(a) 

		













