using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Keywithtargetconv
{
    public class keywitktargetconv
    {
        
        public string keytargetconv(string key_,string target_)
        {
            if (key_.Length < 1)
                return target_;
            byte[] key = Encoding.Default.GetBytes(key_);
            byte[] target = Encoding.Default.GetBytes(target_);
            if (key.Length>target.Length)
            {
                for(int i=0;i<target.Length;i++)
                {
                    target[i] = unchecked ((byte)(target[i] + key[i]));
                }
            }
            else
            {
                int ii = 0, k = key.Length,t=target.Length;
                while(t>k)
                {
                    for (int i=0; i < k; i++)
                    {
                        target[i+ii] = unchecked((byte)(target[i+ii] + key[i]));
                    }
                    ii += k;
                    t -= k;
                }
                for (int i = 0; i < t; i++)
                {
                    target[i + ii] = unchecked((byte)(target[i + ii] + key[i]));
                }

            }
          
            return Encoding.Default.GetString(target);
        }



        public string DEkeywithtarget(string key_, string target_)
        {

            if(key_.Length < 1)
                return target_;
            byte[] key = Encoding.Default.GetBytes(key_);
            byte[] target = Encoding.Default.GetBytes(target_);
            if (key.Length > target.Length)
            {
                for (int i = 0; i < target.Length; i++)
                {
                    target[i] = unchecked((byte)(target[i] - key[i]));
                }
            }
            else
            {
                int ii = 0, k = key.Length, t = target.Length;
                while (t > k)
                {
                    for (int i = 0; i < k; i++)
                    {
                        target[i + ii] = unchecked((byte)(target[i + ii] - key[i]));
                    }
                    ii += k;
                    t -= k;
                }
                for (int i = 0; i < t; i++)
                {
                    target[i + ii] = unchecked((byte)(target[i + ii] - key[i]));
                }

            }

            return Encoding.Default.GetString(target);
        }


    }
}
