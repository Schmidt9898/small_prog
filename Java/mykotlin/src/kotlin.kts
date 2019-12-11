 fun oke(){
     print("ok\n");
 }


val a: Int =100

oke()
 var b : Int =2

 val max = if(a>b){
     print ("a is selected\n")
     a
 }else{
     print("b is selected\n")
     b
 }
print(max)
print("\n")
 /*when (x) {
     6->print("6666666666\n")
     7->print("7777777777\n")

 }*/
 //var collectoin : Set<String> = {"a","s","f"}


 //for(item in collection) print (item)
 var r: Int =30
 var x: Int =50
 var y: Int =50
 var t:Int=0
print("\n")
 for(j in 1..100) {
     for (i in 1..100) {
        t= ((i-x)*(i-x)+(j-y)*(j-y))
        if(t<=(r*r)+30 && t>=(r*r)-30)
         print(" o")
         else
            print("  ")
     }
     print("\n")
 }

