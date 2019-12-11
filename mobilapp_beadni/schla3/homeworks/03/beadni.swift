// Ez a hunglish programozási megközelítés nem az igazi ...

func legnagyobb_elem (sztar: [Int:Double]) -> Double{
  let values = sztar.values
  if values.isEmpty
  {
    return 0
  }
  var max = Array(sztar.values)[0]
  for value in values
  {
    if value > max
    {
      max = value
    }
  }
  return max
}


func legkisseb_kulcs (sztar: [Int:Double]) -> Int{
  let keys = sztar.keys
  if keys.isEmpty
  {
    return -1
  }
  var min = Array(sztar.keys)[0]
  for key in keys
  {
    if key < min
    {
      min = key
    }
  }
  return min
}

func megszerez_elem_ha_kulcs_filterez(sztar: [String:Int] , filter:((String)->(Bool))) -> [String:Int]
{
  var returnelem = [String:Int]()
for elem in sztar
{
  if filter(elem.key)
  {
    returnelem[elem.key] = elem.value
  }
  else{
   
  }

}

return returnelem
}


var szotar = [Int : Double]()

// feltöltés pár elemmel

szotar[1] = 10
szotar[3] = 30
szotar[2] = 20
szotar[5] = 50
szotar[4] = 40
var legnagyobb = legnagyobb_elem(sztar: szotar)
var kulcs = legkisseb_kulcs(sztar: szotar)
print("legnagyobb elem \(legnagyobb)")
print("legkissebb kulcs \(kulcs)")
print("eltávolít legkisseb kulcs")
szotar.removeValue(forKey: kulcs)

// -s
kulcs = legkisseb_kulcs(sztar: szotar)
print("legkissebb kulcs \(kulcs)")

var szotar2 = [String : Int]()

szotar2["egy"] = 1
szotar2["ketto"] = 2
szotar2["harom"] = 3
szotar2["negy"] = 4
szotar2["ot"] = 5

func van_benn_o (abban: String)  -> Bool {
if abban.contains("o"){
  return true
}

return false
}

// A filtert a fenti függvényekre érdemes alkalamzni, ez lóg a levegõben
var szotar_szurt = megszerez_elem_ha_kulcs_filterez(sztar:szotar2,filter:van_benn_o)
for elem in szotar_szurt
{
  print(elem)
}
