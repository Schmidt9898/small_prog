import kotlin.random.Random

// Angol azonosítók!

enum class Szin(val type: String)
{
    Piros("Piros"),Tok("Tok"),Makk("Makk"),Zold("Zold")
}

enum class Ertek(val value: Int) {
    Het(7),
    Nyolc(8),
    Kilenc(9),
    Tiz(10),
    Also(2),
    Felso(3),
    Kiraly(4),
    Asz(11),
}
open class Kartya{
    val szin: Szin
    constructor(szin_: Szin){
        szin=szin_;
    }
    open fun Leiras():String {
        return "Ez egy "+szin.type+" kártya."
    }

}

class Magyarkartya : Kartya
{
    val ertek : Ertek

    constructor(szin_ : Szin,ertek_ : Ertek) : super(szin_) {
    ertek = ertek_

}
    override fun Leiras():String {
    return "Ez a "+szin.type+" "+ertek.value+".";
}
    val getertek: Ertek
    get() = ertek;

}


///////////////MAIN////////////////////////


val kartya1:Kartya = Kartya(Szin.Piros)
print(kartya1.Leiras()+"\n")
val magyarkartya1 = Magyarkartya(Szin.Piros,Ertek.Kiraly)
print(magyarkartya1.Leiras())


//////

val kartyak = arrayListOf<Kartya>()
for (szin in Szin.values())  {
    var temp:Kartya = Kartya(szin)
    kartyak.add(temp)
}

// Külön osztályban, a feladatkiírás szerint.

val magyar_kartya_pakli = arrayListOf<Magyarkartya>()
for (szin in Szin.values()) {
    for (ertek in Ertek.values()){
        magyar_kartya_pakli.add(Magyarkartya(szin,ertek))
    }
}

print("sima kartya pakli..\n")
for (kartya in kartyak){
    print(kartya.Leiras()+"\n")
}
print("Nem túl izgi.\n Magyarkártya pakli..")
for (magyarkartya in magyar_kartya_pakli){
    print(magyarkartya.Leiras()+"\n")
}
print("Egy kis játék. 21\n")
var sum = 0
//let number = Int.random(in: 0 ..< 10)   .remove(at: 3) values.count   arr[]idx

while(true){
//kérünk lapot

    var ridx = Random.nextInt(0,magyar_kartya_pakli.size)
    print(magyar_kartya_pakli[ridx].Leiras()+"\n")
    sum += magyar_kartya_pakli[ridx].getertek.value
    magyar_kartya_pakli.removeAt(ridx)
    print("eddig "+sum+".\n")

    if (sum == 21 || sum == 22){
        print("Nyertem!\n")
        break
    }else if (sum>22){
        print("Túl sok.\n")
        break
    }
    else if (sum < 14){
        print("Kérek még lapot.\n")
        continue
    }
    else
    {
        print("Nem kockáztatok, befejezem.\n")
        break
    }
}

print("vége\n")


