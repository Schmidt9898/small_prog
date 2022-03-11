print("lession 2")




print("1. Write a program that transforms number of days to number of month and the remaining number of days. For example 265 days = 8 month and 25 days. (Months can be 30 days long each.)")
days=265
month=int(days/30)
days-=month*30
print("Months {0} Days {1}".format(month,days))



print("2. Draw a N-long rectangular triangle with *-s")
N=9
for i in range(N):
	print("*" * i)

print("3. Draw an NxN sized chess table. Black be ** and white be spaces.")
a=True
for x in range(N):
	s=""
	for y in range(N):
		if a:
			s+="*"
		else:
			s+=" "
		a = not a
	print(s)

print("4. Give the largest of three integers")
print(max(1,2,3))


print("5. Add numbers in ascending order.")
array=[1,4,2,6,8,2]
array.sort()
print(array)
print("6. List the common divisors of two positive integers.")
a=202 
b=128
for i in range(1,int(max(a,b)/2)):
	if a%i==0 and b%i==0:
		print(i)
print("7. List squares smaller than K.")
K=100
i=0
while i < K:
	if i*i<K:
		print(i)
	else:
		break
	i+=1

print("8. Prepare N random numbers.")
rand_max=10000
import random as rng
N=10
array=[]
for i in range(N):
	array.append(rng.randint(0,rand_max))
print(array)

print("9. Enter the N. Fibonacci number. The Fibonacci sequence consists of integers, the first two being 0 and 1, and each other is the sum of the two previous two.")
fib=[0,1]
for i in range(2,N):
	fib.append(fib[i-1]+fib[i-2])
print(fib)

print("10. Enter the first row of the Pascal Triangle.")

rows=[[1],[1,1]]
for i in range(1,N):
	new_row=[1]
	for x in range(len(rows[i])-1):
		new_row.append(rows[i][x]+rows[i][x+1])
	new_row.append(1)
	rows.append(new_row)
for i in rows:
	print(i)

print("11. Add the monogram for several names.")
name="Schmidt László harmadiknév"
name=name.split(" ")
m=""
for i in name:
	m+=i[0]
print(m)
print("12. In an arbitrary text, find the first occurrence of the word 'apple' and replace it with the word 'pear'.")
sentence="12. In an arbitrary text, find the first occurrence of the word 'apple' and replace it with the word 'pear'."
print(sentence.replace("apple","pear",1))
print("13. Give the half of each elements of a list of even numbers.")
array=[]
for i in range(50):
	array.append(i)
print(array)

print("14. Write a function that decides on two lists whether there is overlap between them (at least one common element)!")
def metset(a,b):
	val=False
	for i in a:
		if i in b:
			print(i)
			val=True
	return val

print(metset([1,2,3],[5,4,3]))

print("15. Write a function that returns the biggest element of a list of numbers!")
def bigest(a):
	max_=a[0]
	for i in a:
		if max_<i:
			max_=i
	return max_

print(bigest(array))

print("16. Write a function that returns the longest element of a list of words!")

def longest(list_):
	word=list_[0]
	for s in list_:
		if len(word)<len(s):
			word=s
	return word

print(longest(sentence.split(" ")))

print("17. Write a function which calculates the geometrical mean of a variable number of values")
def geometrical_mean(nums):
	val=1
	for n in nums:
		val*=n
	return val ** (1/len(nums))

print(geometrical_mean([1,2,3,4,5]))

print("18. Implement a function that receives a matrix and returns the transposed matrix.")
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

print("19. Implement the Matrix Multiply Operation as a function.")

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

quit()


print("20. Implement a function that converts a text, which replaces multiple whitespace characters to single one")