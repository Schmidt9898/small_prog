using FuzzyString;
using MinimumEditDistance;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace level
{
    [Serializable]
    public class Level
    {
#pragma warning disable IDE0044 // Add readonly modifier
        private string code;
#pragma warning restore IDE0044 // Add readonly modifier

        private string prolog;

        private string complement;


        private List<string> question = null, answer = null, dono=null;


        public Action action = null;

        public string Prolog { get => prolog; set => prolog = value; }
        public string Complement { get => complement; set => complement = value; }
        public string Code { set => code=value.ToLower(); }
        public List<string> setQuestion { set => question = value; get => question; }
        public List<string> setAnswer { set => answer = value; get => answer; }
        public List<string> setDono { set => dono = value; get => dono; }

        public Level()
        {

        }
        public Level Loadlevel(string path)
        {
            byte[] tomb = File.ReadAllBytes(path);

            int h = tomb.GetLength(0);

            for (int i = 0; i < h; i++)
            {
                tomb[i] = unchecked((byte)(tomb[i] - h));
            }
            MemoryStream memStream = new MemoryStream();
            BinaryFormatter binForm = new BinaryFormatter();
            memStream.Write(tomb, 0, tomb.Length);
            memStream.Seek(0, SeekOrigin.Begin);

            return (Level)binForm.Deserialize(memStream);
        }
        public bool Savetofile(string path)
        {
            BinaryFormatter bf = new BinaryFormatter();

            MemoryStream ms = new MemoryStream();
            bf.Serialize(ms, this);

            byte[] byteArray = ms.ToArray();

            int h = byteArray.GetLength(0);

            for (int i = 0; i < h; i++)
            {
                byteArray[i] = unchecked((byte)(byteArray[i] + h));

            }
            try
            {
                using (var fs = new FileStream(path, FileMode.Create, FileAccess.Write))
                {
                    fs.Write(byteArray, 0, byteArray.Length);
                    return true;
                }
            }
            catch (Exception)
            {
                // Console.WriteLine("Exception caught in process: {0}", ex);
                return false;
            }

        }

        public string Questionnull(string que)
        {
            List<FuzzyStringComparisonOptions> lista = new List<FuzzyStringComparisonOptions>();
            
            lista.Add(FuzzyStringComparisonOptions.UseLongestCommonSubstring);
            lista.Add(FuzzyStringComparisonOptions.UseRatcliffObershelpSimilarity);

            if (que.Equals(""))
                return "Enter";

            int indexlength = 100;
            int index = -1;
            for (int i = 0; i < question.Count; i++)
            {
                if (ComparisonMetrics.ApproximatelyEquals(question[i], que, lista, FuzzyStringComparisonTolerance.Normal))
                {
                    int temp = Levenshtein.CalculateDistance(question[i], que, 1);
                    if (temp < indexlength)
                    {
                        index = i;
                        indexlength = temp;
                    }
                    // return answer[i];
                }
            }
            if (index != -1)
            {
                return answer[index];
            }

            return null;

        }
        public string Question(string que)
        {
            List<FuzzyStringComparisonOptions> lista = new List<FuzzyStringComparisonOptions>();

            lista.Add(FuzzyStringComparisonOptions.UseLongestCommonSubstring);
            lista.Add(FuzzyStringComparisonOptions.UseRatcliffObershelpSimilarity);

            if (que.Equals(""))
                return "Enter";

            int indexlength = 100;
            int index = -1;
            for (int i = 0; i < question.Count; i++)
            {
                if (ComparisonMetrics.ApproximatelyEquals(question[i], que, lista, FuzzyStringComparisonTolerance.Normal))
                {
                    int temp = Levenshtein.CalculateDistance(question[i], que, 1);
                    if (temp < indexlength)
                    {
                        index = i;
                        indexlength = temp;
                    }
                    // return answer[i];
                }
            }
            if (index != -1)
            {
                return answer[index];
            }
            Random rand = new Random();
            return dono[rand.Next(0, dono.Count - 1)];

        }
        public bool Ispassok(string precode)
        {
            string iscode = precode.ToLower();
            if (iscode.Equals(code))
                return true;
            return false;
        }
    }



















    public class Levelgetter
    {
        public static Level Loadlevel(string path)
        {
            byte[] tomb = File.ReadAllBytes(path);

            int h = tomb.GetLength(0);

            for (int i = 0; i < h; i++)
            {
                tomb[i] = unchecked((byte)(tomb[i] - h));
            }
            MemoryStream memStream = new MemoryStream();
            BinaryFormatter binForm = new BinaryFormatter();
            memStream.Write(tomb, 0, tomb.Length);
            memStream.Seek(0, SeekOrigin.Begin);

            return (Level)binForm.Deserialize(memStream);

        }
    }
    
    
}
