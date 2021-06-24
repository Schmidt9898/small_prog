//document.write("asdasd")
/*
function object2console(obj)
{
	
	var tomb = Object.getOwnPropertyNames(obj);
	
	for(P_name in tomb)
	{
			
		let descriptor = Object.getOwnPropertyDescriptor(obj, tomb[P_name]);
		if(descriptor.configurable)
		{
			console.log(tomb[P_name]+" : "+descriptor.value);
		}

		
	}
	


}

function param2console()
{
for (i = 0; i < arguments.length; i++) {
    console.log(arguments[i])
  }
}





const obj = {
  a: 1,
  b: 2,
  c: 3
};
object2console(obj)
console.log(window.navigator)


for(i=1;i<=100;i++)
{
	szo=""
	if(i%3==0)
		szo+="fizz";
	if(i%5==0)
		szo+="fuzz";
	if(i%5==0 && i%3==0)
		szo="fizzbuzz";
	if(szo=="")
		szo+=i
	
	console.log(szo)
	
}

*/

//window = window.open("main2.html");






 var person = {

  name: "John Doe",

  showName: function () {

    console.log(this.name);

  }

}

var obj = { 

  showName: person.showName

}

obj. showName ();



var person = {

  name: "John Doe",

  showName: function () {

    console.log(this.name);

  }

}

var obj = {

  showName: () => { person.showName () }

}

obj.showName ();
















