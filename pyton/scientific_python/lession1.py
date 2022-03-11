import random as rng
import math
rand_max=100

print("lession 1 exercise")

print("1.")#Decide on an integer whether it is even
n=rng.randint(0,rand_max)
print(n,"is a(n)","even" if n%2==0 else "odd")

print("2.")#Decide on an integer whether it is between an interval
a=rng.randint(0,rand_max)
b=rng.randint(a,rand_max)

print(n,"is ","" if n>a and n<b else "not","between ",a,"and",b)

print("3.")#Decide on two integers whether the first divisor of the second.

print(a,"is" if b%a==0 else "is not","divisor of",b)

print("4.")#Decide from three numbers that they could be the sides of a triangle

c=rng.randint(0,rand_max)
print(a,b,c,"can" if a+b>=c and a+c>=b and b+c>=a else "can not","be a triangle.")

print("5.")#Calculate the area of a triangle from the length of its sides
if a+b>=c and a+c>=b and b+c>=a:
	s=(a+b+c)/2.0
	area=math.sqrt( s*(s-a)*(s-b)*(s-c) )
	print("The area of the triangle is:",area)
else:
	print("Not makes a triangle.")

print("6.")#Calculate the distance of a point (x;y) from the origo.
x=rng.random()*rand_max
y=rng.random()*rand_max
def distance(x,y):
	return math.sqrt(x*x+y*y)
print("The length of x:",x,"y:",y,"is",distance(x,y))

print("7.")#Calculate the distance of two points (x;y).
x2=rng.random()*rand_max
y2=rng.random()*rand_max
print("The distance of two point of x2",x2,"y2:",y2,"is",distance(x-x2,y-y2))


print("8.")# Decide on a string whether starts with white space.
my_str="5 This is my string."
if my_str[0] in ["\t","\n"," "]:
	print("\"",my_str,"\"","is start with a whitespace.")
else:
	print("\"",my_str,"\"","is not start with a whitespace.")

print("9.")# Decide on a string whether starts with capital character.
print("my_str","is" if my_str[0]==my_str[0].upper() else "is not","start with capital.")
print("10.")# Decide on a string whether starts with digit.
if my_str.split(" ")[0].isnumeric():
	print("Starts with a number.")
else:
	print("Does not starts with a number.")

print("11.")# Decide on a string whether starts and ends with the same character
print("my_string","does" if my_str[0]==my_str[-1] else "does not","starts and ends with the same character")

print("12.") #Decide on two strings whether their first five characters are equal.
str1="asdfg123"
str2="asdfg312"
print(str1,str2,"share" if str1[0:5]==str2[0:5] else "not share","the same first 5 character")
print("13.") #Get the first word of a string.
print(my_str.split(" ")[0])
print("14.") #Remove the first word of the string.
my_str=my_str.replace(my_str.split(" ")[0],"")
print(my_str)
print("15.") #Replace the first word of a string to an other.
my_str="This is an apple."
my_str=my_str.replace(my_str.split(" ")[0],"other")
print(my_str)

print("16.") #Get the second word of a string.
print(my_str.split(" ")[1])

print("17.") #Uppercase a string.
print(my_str.upper())
print("18.") #Make the string opposit case.
if my_str.isupper():
	my_str=my_str.lower()
else:
	my_str=my_str.upper()
print(my_str)


print("19.") #Decide on two strings whether the first is subpart of the second one.
str1="alma"
str2="apple is alma in hungarian"
print("is subpart" if str1 in str2 else "not a subpart")

print("20.") #Remove a string from an other one if exists.
str2=str2.replace(str1,"") if str1 in str2 else str2
print(str2)
print("21.") #Write a program that transforms number of days to number of month and the remaining number of days. For example 265 days = 8 month and 25 days. (Months can be 30 days long each.)
days=rng.randint(0,256)
def tomonth(n):
	month=int(n/30)
	n=n%30
	return month,n 
print("days",days)
months,days = tomonth(days)
print("months",months,"days",days)
print("22.") #Write N pieces of *.
N=rng.randint(2,10)
print("*" * N)
print("23.") #Draw a NxN from *-s.
#for i in range(N):
#	print("*" * N)
print(("*" * N +"\n")*N)

print("24.") #Draw a N-long equilateral rectangular triangle with *-s
for i in range(N):
	print("*" * i)
print("25.") #Draw a rhombus with side size N standing on its top.
for i in range(N):
	print("*" * i)
for i in range(N):
	print(" "* i +"*" * (N-i))
print("26.") #Draw an NxN sized chess table. Black be ** and white be spaces.
for i in range(N):
	sor=""
	for j in range(N):
		sor+="*" if (i*N+j+1)%2==0 else " "
	print(sor,"\n")
	

quit()
print("27.") #Give the largest of three integers

print("28.") #Add numbers in ascending order.

print("29.") #List the common divisors of two positive integers.

print("30.") #List the first N squared number.

print("31.") #List squares smaller than K.

print("32.") #Prepare N random numbers.

print("33.") #Enter the N. Fibonacci number. The Fibonacci sequence consists of integers, the first two being 0 and 1, and each other is the sum of the two previous two.

print("34.") #Modify any sequence of all triads in order for each triad to be in ascending order.

print("35.") #List the quadratic equations of all coefficients between 0 and 10 and have exactly one solution.

print("36.") #Enter the first row of the Pascal Triangle.

print("37.") #Enter repeating numbers in an arbitrary number sequence.

