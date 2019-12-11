namespace usingfile
{
    enum nem { ferfi,no};
     class Person
    {
        public nem neme;
        public string csalad;
        string nev;
        int irany;
        string varos;


        public Person(string data)
        {
            string[] dataT = data.Split(',');
            
            neme = (dataT[0].Equals("0")) ? nem.ferfi : nem.no;

            string[] nevt = dataT[1].Split(' ');


            csalad = nevt[0];
            nev = nevt[1];

            int.TryParse( dataT[2],out irany);

            varos = dataT[3];




            

        }
        public string ToString()
        {
            return csalad +" "+ nev; 

        }
     } 
}