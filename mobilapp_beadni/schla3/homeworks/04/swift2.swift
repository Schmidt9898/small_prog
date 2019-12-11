
enum Szin: Int ,CaseIterable{
  case Piros,Tok,Makk,Zold

}
enum Ertek: Int ,CaseIterable{
  case Het = 7
  case Nyolc = 8
  case Kilenc = 9
  case Tiz = 10
  case Also = 2
  case Felso = 3
  case Kiraly = 4
  case Asz = 11
  
}
class Kartya{
  let szin : Szin
  init(szin : Szin){
    self.szin=szin
  }

  func Leiras()-> String{return "Ez egy \(szin) kártya."}
}

// Formázás!

class Magyarkartya : Kartya
{
  let ertek : Ertek
  //let szin : Szin
init(szin : Szin,ertek : Ertek){
self.ertek = ertek
//self.szin = szin
super.init(szin : szin)
}
override func Leiras() -> String {
  return "Ez a \(szin) \(ertek)."
}
func getertek() -> Int {
  return self.ertek.rawValue
}

}

//let a = Szin.Piros 
//print(a)
//var card1 = Card(szin : Szin.Piros , ertek : Ertek.Tiz)
//print(card1.Leiras())
let kartya1 = Kartya(szin:Szin.Piros)
print(kartya1.Leiras())
let magyarkartya1 = Magyarkartya(szin: Szin.Piros,ertek:Ertek.Kiraly)
print(magyarkartya1.Leiras())

var kartyak = [Kartya]()
for szin in Szin.allCases {
kartyak.append(Kartya(szin:szin))
}

// OSZTÁLY!

var magyar_kartya_pakli = [Magyarkartya]()
for szin in Szin.allCases {
    for ertek in Ertek.allCases{
      magyar_kartya_pakli.append(Magyarkartya(szin:szin,ertek:ertek))
    }
}

print("sima kartya pakli..")
for kartya in kartyak{
print(kartya.Leiras())
}
print("Nem túl izgi.\n Magyarkártya pakli..")
for magyarkartya in magyar_kartya_pakli{
print(magyarkartya.Leiras())
}
print("Egy kis játék. 21")
var sum = 0
//let number = Int.random(in: 0 ..< 10)   .remove(at: 3) values.count   arr[]idx
while(true){
//kérünk lapot

let ridx = Int.random(in: 0 ..< magyar_kartya_pakli.count)
print(magyar_kartya_pakli[ridx].Leiras())
sum += magyar_kartya_pakli[ridx].getertek() 
magyar_kartya_pakli.remove(at:ridx)
print("eddig \(sum).")

if sum == 21 || sum == 22{
  print("Nyertem!")
  break
}else if sum>22{
  print("Túl sok.")
  break
} 
else if sum < 14{
print("Kérek még lapot.")
continue
}
else
{
print("Nem kockáztatok, befejezem.")
break
}
}
print("vége")





