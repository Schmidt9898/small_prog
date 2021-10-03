print("csá")
hat=128
count=0
while hat<=1024:
    for x in range(4,64,2):
        for y in range(4,64,2):
            for z in range(4,64,2):
                v=x*y*z
                if v == hat :
                    print("-D TSIZE="+str(hat)+"-D x="+str(x)+"-D y="+str(y)+"-D z="+str(z))
                    count+=1
    hat*=2
print("done "+str(count))
    
