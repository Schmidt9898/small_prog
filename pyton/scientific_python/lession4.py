print("lession 4")

# 1.

def transmogr(values,predicate,transforms=[]):
	ret=[]
	ret=list(filter(predicate,values)) #  [i if predicate(i) for i in values]
	for i in range(len(ret)):
		for f in transforms:
			ret[i]=f(ret[i])
	print(ret)
	return ret

a=[1,2,3,4,5,5,5]
print(a)
transmogr(a,lambda x: x==5,[lambda x: x*2,lambda x: x*3])


# 2.

#i will not write a tree structure for this here
# i dont want to care for tree rotating rebalancing.
class mymap:
	def __init__(self):
		self._keys=[]
		self._values=[]
	def add(self,key_,value_):
		if key_ in self._keys:
			return False
		self._keys.append(key_)
		self._values.append(value_)
	def remove(self,key_):
		id = self._keys.index(key_)
		#print(id)
		self._keys[id]=self._keys[-1]
		self._values[id]=self._values[-1]
		self._keys.pop()
		self._values.pop()

	def __getitem__(self,key):
		id = self._keys.index(key)
		return self._values[id]
	def print(self):
		print([x for x in self._keys])
		print([x for x in self._values])

m=mymap()
m.add(1,"egy")
m.add(2,"egy2")
m.add(2,"egy2")
m.add(3,"egy3")

print(m[3])
m.remove(1)

m.print()



def myfilter(fun,iter):
	ret=[]
	for i in iter:
		if fun(i):
			ret.append(i)
	return ret

def myreduce(fun,iter):
	if len(iter)==1:
		return iter[0]
	ret=iter[0]
	for i in range(1,len(iter)):
		ret=fun(ret,iter[i])
	return ret

print(myfilter(lambda x: x>2,a))
print(myreduce(lambda x,y: x+y,a))

# 3.

def max_in_list(nums):
	return myreduce(lambda x,y:x if x>y else y,nums)

print(max_in_list(a))


# 4.
memo_func=lambda x:x
def memorize(func):
	global memo_func
	temp = memo_func
	memo_func=func
	return temp

b=1
funcs=[lambda x:x*2,lambda x:x*3,lambda x:x*4]

for f in funcs:
	print(memorize(f)(b))

# 5.
print(len("ASDASDAD"))


def d(l1,l2):
	c=0
	for i in range(len(l1)):
		if l1[i]>=l2[i]:
			c+=1
	return c >= len(l1)/2


a=[1,2,3,4]
b=[0,1,5,6]
print(d(b,a))



s="a asdf sfg as fasf wfas  a"
print(len([i for i in s if i == " "]))


strings=["Asd","ACs","ASD"]
print( {strings[i]: len([s for s in strings[i] if s == s.upper()]) for i in range(len(strings))} )


pi = 6*sum([1/i**2 for i in range(1,3)]) 
print(pi)













# 6.

# 7.

# 8.

