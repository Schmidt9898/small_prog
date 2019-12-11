using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Mail;
using System.Net;

namespace emailküldés
{
    class Program
    {
        static void Main(string[] args)
        {
            new SmtpClient
            {
                Host = "Smtp.Gmail.com",
                Port = 587,
                EnableSsl = true,
                Timeout = 10000,
                DeliveryMethod = SmtpDeliveryMethod.Network,
                UseDefaultCredentials = false,
                Credentials = new NetworkCredential("eszkozelso@gmail.com", "eszkoz12345")
            }.Send(new MailMessage { From = new MailAddress("eszkozelso@gmail.com", "FBI"), To = { "schmidtlacus@gmail.com" }, Subject = "Státusz", Body = "Még semmi ez csak tesztelés része.", BodyEncoding = Encoding.UTF8 });
        }
    }
}
