using Kukac.enums;
using Kukac.interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
/**
 * Ez a megvalósítás BFS gráfot használ ütközés elkerüléssel 
 * és ellenfél lépés "predikcióval". (ez nem véletlenül idézőjeles) 
 * */
namespace Kukac.kukac.RudiAi
{
    class RudiAi : Ai//Az én AI megvalósításom
    {

        Adat adat;//amit a tudni lehet
        Test test;//az én testem 
        Iranyok irany=Iranyok.FEL; // az irány amibe nézek
        P Start;//itt vagyok éppen
        //kaja pozíciója
        P kaja;
        P lastkaja;//hol volt a kaja legutóbb
        //Merre lehet menni egy pontból
        //fel jobb le bal
        P[] Branches = {new P(0,-1),   new P(1,0), new P(0, 1), new P(-1,0) };
        //List<Iranyok> Path;
        List<P> Path;
        int mode = 0;//0 keress utat; // 1 menny végig az úton 2 éld túl


        public void initAdat(Adat adat)//interface implementáció
        {
            this.adat = adat;
        }

        public void initKukac(Test kukac)//interface implementáció
        {
            test = kukac;
            Path = new List<P>();//Path ürítése
            mode = 0;
        }

        /**egy kordináta eltárolása
        *eltárol 
        *id-t képez
        *és az alapvető vektorműveletek és összehasonlítás
        */
        public struct P 
        {
            public int x, y;
            public P(int x_,int y_)
            {
                x = x_;
                y = y_;
            }
            public int toInt()
            {
                return x + y * 120;
            }
        public static P operator +(P a,P b)
        {
                P c;
                c.x = a.x + b.x;
                c.y = a.y + b.y;
            return c;
        }
            public static P operator -(P a, P b)
            {
                P c;
                c.x = a.x - b.x;
                c.y = a.y - b.y;
                return c;
            }
            public static bool operator ==(P a, P b)
            {
                return a.x == b.x && a.y == b.y;
            }
            public static bool operator !=(P a, P b)
            {
                return a.x != b.x || a.y != b.y;
            }
        }
        /**
         * Súlyozott párok tárolása
         */
        struct Pair : IComparable{
            public double weight;//mennyibe kerül ide lépni
            public P point;//melyik pontba lépünk
            public Pair(double w,P p)
            {
                weight = w;point = p;
            }

            public int CompareTo(object obj)//alapvető összehasonlítás, végül nem használtam
            {
                var other = (Pair)obj;
                return point.toInt().CompareTo(other.point.toInt());
            }
        }
        public Iranyok setIrany()
        {
            kaja.x = (int)adat.getEtel().X;//hol a kaja
            kaja.y = (int)adat.getEtel().Y;

            Start.x = (int)test.getFej().X;//hol a fejem
            Start.y = (int)test.getFej().Y;

            //
            if (lastkaja != kaja)//elmozdult e a kaja
            {//ha igen akkor út ujratervezése
                mode = 0;
            }


                if (mode == 0)
            {
                GetnewPath();//út ujratervezése
                mode = 1;//follow path mode
                if (Path.Count < 2)//nem talált utat 
                    mode = 2;//survive mode
            }
            if(mode == 1)
            {
                if (isPValid(Path[0]) && !isDangerous(Path[0]))//Biztonságos e oda lépni
                {
                    irany = getnextIrany(Start, Path[0]);// merre kell lépnem
                    Path.RemoveAt(0);//ezt már meglépem ezért kiveszem az útból 
                    if (Path.Count < 2)//elfogyott az út
                        mode =0 ;//keressünk új utat
                }
                else//nem biztonságos oda lépni
                {
                    GetnewPath();//akkor út ujratervezése
                    if (Path.Count < 2)//nem talált utat 
                        mode = 2;//survive mode mert nem érhető el a kaja
                    else
                    {//erre mehetünk az első lépésnél biztos jó az út
                    irany = getnextIrany(Start, Path[0]);
                    Path.RemoveAt(0);
                    }
                }
            }
            if(mode == 2)//survive mode olyan helyre lépünk ami biztonságos
            {
                irany = getnextIrany(Start,Survive(Start));
                mode = 0;
            }
                return irany;
            //PalyaElemek[,] close= adat.getPalyaElem()

        }
        void GetnewPath()//megadja az új utat
        {
            lastkaja = kaja;//kaja helyének lementése
            Path.Clear();//régi út törlése
            //Path.AddRange(A_star());
            //Path.RemoveAt(0);
            Path.AddRange(BFS());//használjuk a BFS bejárást
        }

      /**
       * Megnézi, hogy az útunk minden pontja valid e még.
       * Végül nem ez lett használva.
       */
        bool isPathstillValid(List<P> path)
        {
            //if (lastkaja != kaja)
              //  return false;
            foreach(P p in path)
            {
                if (adat.getPalyaElem(p.x, p.y) == PalyaElemek.TEST)
                    return false;
            }
            return true;
        }
        /**
        * Megnézi, hogy az útunk következő pontja valid e még.
        */
        bool isPValid(P p)
        {
            //Valid ha nem fal és nem kukac test
            if (adat.getPalyaElem(p.x, p.y) == PalyaElemek.TEST || adat.getPalyaElem(p.x, p.y) == PalyaElemek.FAL)
                return false;
            return true;
        }
        /**
        * Survive mode 
        * fel le jobb bal (a sorrend fontos)
        * megnézzük h lehet e menni és ha igen akkor megyünk.
        */
        P Survive(P curent)
        {
            //fel le jobb bal
            P[] new_branches = (P[])Branches.Clone();
            
            P p = curent;
            for (int i = 0; i < 4; i++)
            {
                p = new_branches[i];
                p = p + curent;
                if (isPValid(p) && !isDangerous(p))
                    return p;


            }
            return p;
        }
        /**
         * Ha a következő lépésem 1 lépés távolságra van egy másik kukac fejétől
         * akkor nagy valószínüséggel oda fog lépni.
         * Ebben az esetben az a hely veszélyes és igaz értéket adunk
         */
        bool isDangerous(P curent)
        {
            int num_kukac = adat.getKukacDarab();//veszzük az összes kukacot
            for (int n = 0; n < num_kukac; n++)
            {
                
                var kukac_test = adat.getKukac(n);
                if (kukac_test.getHossz() <= 0)// ha nem él a kukac akkor nem nézzük
                    continue;
                var fej = kukac_test.getFej();
                if (fej.X == curent.x && fej.Y == curent.y)//ha a feje a következő lépésemen van akkor veszélyes (de nem is valid)
                    return true;

                
            }

            //megnézzük ugyan ezt a következő lépés minden környezetére is
            P[] new_branches = (P[])Branches.Clone();//vegyünk minden kövi lehetséges helyet
            P p = curent;
            for (int i = 0; i < 4; i++)
            {
                p = new_branches[i];
                p = p + curent;//eltolás
                for (int n = 0; n < num_kukac; n++)
                {
                    
                    var kukac_test = adat.getKukac(n);
                    if (kukac_test.getHossz() <= 0)
                        continue;//a kukac halott
                    var fej = kukac_test.getFej();
                        if (fej.X == p.x && fej.Y == p.y && !(fej.X == Start.x && fej.Y == Start.y))
                            return true;// veszélesen közel van
                }
            }
            //nincs veszély
            return false;
        }


        P[] BFS()//BEST First Search
        {
            //saját tábla
            int[,] tabla = new int[120, 120];//pont tábla
            for (int i = 0; i < 120; i++)
                for (int j = 0; j < 120; j++)
                    tabla[i, j] = int.MaxValue;

            /**
             * Elindítunk egy szélességi keresést a kajától a mi kukacuking.
             * Ha megtaláljuk a kukac fejét akkor van útvonal odáig.
             * Ha nem akkor üres path al térünk vissza.
             */

            //BFS kellékek
            var visited_list = new List<int>();//itt már voltunk
            var expand = new List<Pair>();//ezeket kell megnéznünk
            expand.Add(new Pair(0,kaja));//az első amit megnézünk
            Pair curent;//itt tartunk
            bool found = false;//megtalltuk e
            while (expand.Count > 0 && !found)
            {
                curent = expand[0];//mi a következő amit kifejtünk
                expand.RemoveAt(0);//mivel kifejtjük kivehetjük a listából
                if (visited_list.Contains(curent.point.toInt()))//ha már valimiért kifejtettük akkor mégegyszer ne
                    continue;

                
                visited_list.Add(curent.point.toInt());//tegyük be a már kifejtett listába
                tabla[curent.point.x, curent.point.y] = (int)curent.weight;//állítsuk be a táblán a pont súlyát
                
                //innen hova tudunk menni
                P[] new_branches = (P[])Branches.Clone();
                List<Pair> new_branches_with_weight = new List<Pair>();
                for (int i = 0; i < 4; i++)
                {
                    var p = new_branches[i];
                    p = p + curent.point;//képezzük le a kordinátákat
                    if (visited_list.Contains(p.toInt()))//ha az új pontot már kifejtettük akkor mégegyszer nem vesszük fel
                        continue;
                    
                    if (p==Start)//meg van az út
                    {
                        tabla[p.x,p.y] = (int)curent.weight+1;
                        found = true;
                        break;
                    }
                    if (adat.getPalyaElem(p.x, p.y) == PalyaElemek.FAL )//ha fal akkor nem foglalkozunk vele
                        continue;
                    if(adat.getPalyaElem(p.x, p.y) == PalyaElemek.TEST)// ha test
                    {

                        bool bajt_okoz = false;//bajt okoz ha mire odaérünk és még ott van
                        int num_kukac = adat.getKukacDarab();//Megkeressük melyik kukachoz tartozik
                        for(int n=0;n<num_kukac;n++)
                        {
                            var kukac_test = adat.getKukac(n);
                            for(int k=0;k<kukac_test.getHossz(); k++)//megnézzük mennyire van a végétől
                            {
                                if (kukac_test.getTestResz(k).Value.X == p.x && kukac_test.getTestResz(k).Value.Y == p.y)
                                    if (kukac_test.getHossz() - k + 10 > Math.Abs(Start.x - p.x) + Math.Abs(Start.y - p.y))
                                    {//a vége +10 nél kissebb az oda eljutás legrövidebb útja akkor nem jó és bajt okoz 
                                        bajt_okoz = true; break;
                                    }
                            }
                        }
                        if (bajt_okoz)//ezért nem használjuk
                            continue;
                    }

                    new_branches_with_weight.Add(new Pair(curent.weight+1, p));//Az új helyek súllyal való ellátása a mostani hely súlya plusz egy
                }
                //new_branches_with_weight.Sort();// rendezzük őket sorba de nem fontos
                expand.AddRange(new_branches_with_weight);



            }
            ////////////-------------------------
            ///a feltérépezett pontokon végigmegyünk úgy, hogy mindig a kissebbik felé megyünk 
            var path = new List<P>();
            if (!found)//ha nem találtuk meg akkor nem csinálunk semmit
                return Path.ToArray();
            found = false;// változó újrahasznosítása
            var act = Start;
            while(act!=kaja && !found)
            {
                
                P[] new_branches = (P[])Branches.Clone();//ugyan úgy megnézzük merre lehet menni
                //List<Pair> new_branches_with_weight = new List<Pair>();
                var min = new Pair(int.MaxValue,new_branches[0]);// a legkissebb súlyú 
                for (int i = 0; i < 4; i++)//minimum keresés
                {
                    var p = new_branches[i];
                    p = p + act;
                    if (p.x >= 120 || p.x < 0 || p.y >= 120 || p.y < 0)// ha nincs a pályán akkor nemfoglalkozunk vele
                        continue;
                    if (tabla[p.x, p.y]==0)//ez lessz a kaja
                    {
                        path.Add(kaja);
                        //act = min.point;
                        found = true;//megtaláltuk nincs több dolog
                        break;
                    }


                    if(tabla[p.x,p.y]<min.weight)//minimum keresés
                    {
                        min.point = p;
                        min.weight = tabla[p.x, p.y];
                    }
                }
                if(min.weight<int.MaxValue)//ha valamiért nincs minimum akkor nem adjuk hozzá
                    path.Add(min.point);
                act = min.point;//ezzel megyünk tovább
            }

            return path.ToArray();//legyen array
        }
        
        P[] A_star()//ez végül nem sikerült megcsinálni kellően jóra, ezért nem használtam de bent hagytam megtekintésre.
        {
            //A* kellékek
            var visited_list = new List<int>();
            //var visited_list = new List<int>();
            Stack<P> path = new Stack<P>();
            List<Pair> expand = new List<Pair>();
            List<int> expand_key = new List<int>();
            expand.Add(new Pair(0,Start));
            expand_key.Add(Start.toInt());
            P curent;
            //List<Pair> memory;
            while (expand.Count>0)
            {
                curent = expand.Last().point;
                int lastindx = expand.Count - 1;
                expand.RemoveAt(lastindx);
                expand_key.RemoveAt(lastindx);

                path.Push(curent);
                visited_list.Add(curent.toInt());

               /* if (curent == kaja)
                {
                    return path.ToArray();
                }*/

                var new_branches = (P[])Branches.Clone();
                List<Pair> new_branches_with_weight = new List<Pair>();
                for (int i=0;i<4;i++)
                {
                    var p = new_branches[i];
                    p = p + curent;

                    if (adat.getPalyaElem(p.x, p.y) == PalyaElemek.FAL || adat.getPalyaElem(p.x, p.y) == PalyaElemek.TEST)
                        continue;

                        if (visited_list.Contains(p.toInt()))
                        continue;

                    if (expand_key.Contains(p.toInt()))
                    {
                        int idx = expand_key.FindIndex(d => d == p.toInt());
                        if (expand[idx].weight > path.Count + Cost(p) + h(p))
                        {
                            expand.RemoveAt(idx);
                            expand_key.RemoveAt(idx);
                        }
                        else
                            continue;




                    }
                    



                        new_branches_with_weight.Add(new Pair(path.Count + Cost(p) + h(p), p));
                }
                foreach(Pair temp in new_branches_with_weight)
                {
                    if(temp.point==kaja)
                    {
                        path.Push(temp.point);
                        return path.ToArray();
                    }

                   
                }
                new_branches_with_weight.Sort();
                expand.AddRange(new_branches_with_weight);
                foreach (Pair p in new_branches_with_weight)
                    expand_key.Add(p.point.toInt());




            }
            Path.RemoveAt(0);
            return path.ToArray();
        }
        double h(P p)//heurisztika A* hoz
        {
            double distance = Math.Abs(kaja.x - p.x) + Math.Abs(kaja.y - p.y);
            //distance /= 599;
            return distance;
        }

        double Cost(P p)//költség A* hoz
        {
            //todo fejek környezete
            var item = adat.getPalyaElem(p.x, p.y);
            if (item == PalyaElemek.FAL || item == PalyaElemek.TEST)
            {
                return 10000;
            }
            else if (item == PalyaElemek.URES)
                return 1;
            else
                return 0;
        }
        Iranyok getnextIrany(P from,P to)//milyen irányban van a következő pont
        {

            var t=to - from;

            
            if (t.x > 0)
                return Iranyok.JOBB;
            if (t.x < 0)
                return Iranyok.BAL;
            if (t.y > 0)
                return Iranyok.LE;
            if (t.y < 0)
                return Iranyok.FEL;

            return Iranyok.BAL;
        }

        /*Első irányválasztóm de ezt csak az elején használtam
         * Bennehagyom megtekintésre.
        Iranyok int2irany(int i)
        {
            switch(i)
            {
                case 0:
                    return Iranyok.FEL;
                    break;
                case 1:
                    return Iranyok.LE;
                    break;
                case 2:
                    return Iranyok.JOBB;
                    break;
                case 3:
                    return Iranyok.BAL;
                    break;
                    
            }
            return Iranyok.FEL;
        }*/





    }
}
