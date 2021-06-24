print("heurisztika: ")

import math 
print("ld calculating..")

p=[0.86,0.14]

for i in range(len(p)):
    print(p[i],end =" ")
print("")
print("--------------")
for i in range(len(p)):
    print(math.log2(1/p[i]),end =" ")
print("")
 
print("--------------")

for i in range(len(p)):
    print(p[i]*math.log2(1/p[i]),end =" ")

print("")

print("heurisztik ")
p_x=[1/2,1/4,1/8,1/8]
p_y=[1/4,1/4,1/4,1/4]

HX=0
for i in range(len(p_x)):
    HX+=p_x[i]*math.log2(1/p_x[i])
print("H(x) = "+str(HX))

HY=0
for i in range(len(p_y)):
    HY+=p_y[i]*math.log2(1/p_y[i])
print("H(y) = "+str(HY))

