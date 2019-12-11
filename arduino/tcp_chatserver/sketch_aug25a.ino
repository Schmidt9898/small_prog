#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>

File file;
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 123);
IPAddress myDns(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
EthernetServer server(12345);




void setup() {
  pinMode(53, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(49, OUTPUT);
  digitalWrite(53, HIGH);
  digitalWrite(47, HIGH);
  digitalWrite(49, HIGH);

  Serial.begin(9600);
  // while (!Serial) ;
  /*
    if(!SD.exists("beszelgetes.txt"))
    {
    Serial.println("Nincs meg a beszelgetes sorry :(");
    return;
    }*/
  Serial.print("Initializing SD card...");

  while (true)
  {
    if (!SD.begin(4))
    {
      Serial.println("initialization failed!");
      delay(1000);
    } else
      break;

  }/*
    Serial.println("initialization failed!");
    return;
  }*/
  Serial.println("initialization done.");
  /*
    file=SD.open("tabla.txt",FILE_WRITE);
    file.println("beleírom az hogy legyenjó");

    if(!file)
    {
    Serial.println("shit");
    return;
    }
    file.close();*/
  Ethernet.begin(mac, ip, myDns, gateway, subnet);
  server.begin();
  Serial.print("Chat server address:");
  Serial.println(Ethernet.localIP());
  digitalWrite(53, LOW);
  digitalWrite(47, LOW);
  digitalWrite(49, LOW);
}
void loop() {
  EthernetClient client = server.available();
  if (client.connected())
  {

    digitalWrite(53, HIGH);
    Serial.println("Valaki van itt");
    if (client.available() > 0)
    {
      byte buff[1];
      buff[0] = client.read();
      int flag = asscii_to_int(buff, 1);
      Serial.println(flag);
      switch (flag)
      {
        case 0:
          digitalWrite(49, HIGH);
          //  digitalWrite(53, HIGH);
          Serial.println("A beszelgetni akar");

          file = SD.open("tabla.txt", FILE_WRITE);
          if (file) {
            int i;
            i = client.available();
            byte buff[1024];
            client.read(buff, i);
            file.write(buff, i);
            file.close();
          } else
          {
            Serial.println("nincs file");
          }
          digitalWrite(49, LOW);
          break;
        case 1:
          digitalWrite(47, HIGH);
          Serial.println("Hallgatózni akar.");
          byte szambuff[8];
          client.read(szambuff, 8);
          unsigned long j;
          j = asscii_to_int(szambuff, 8);
          Serial.println(j);
          file = SD.open("tabla.txt");
          unsigned long filesize;
          filesize = file.size();

          if (!file)
          {
            Serial.println("baszódj meg");
          }
          Serial.print("ciklus elott: ");

          file.seek(j);

         // Serial.println(filesize);
          // filesize-=j;
          //Serial.println(filesize);
          while (file.available()) {
            filesize = file.available();
            Serial.println(filesize);
            if (filesize <= 2048) {

              byte filebuff[filesize];
              Serial.println("buffer:");
              file.read(filebuff, filesize);
              Serial.write(filebuff, filesize);
              client.write(filebuff, filesize);
              break;
            } else
            {
              byte filebuff[2048];
              file.read(filebuff, 2048);
              client.write(filebuff, 2048);

            }
            Serial.println("valami");
          }
          Serial.println("Elküldve.");
          file.close();
          digitalWrite(47, LOW);
          break;
        case 2:
          digitalWrite(47, HIGH);
          digitalWrite(49, HIGH);
          SD.remove("tabla.txt");

          break;
        default:
          client.println("Hibás a bemeneti csomag!");

      }
      client.stop();
      digitalWrite(53, LOW);
      digitalWrite(47, LOW);
      digitalWrite(49, LOW);
      Serial.println("BYE BYE!");
    }
  }


}

unsigned long tiza(int e)
{
  unsigned long tiz = 1;
  for (int i = 0; i < e; i++)
  {
    tiz *= 10;
  }
  return tiz;
}


unsigned long asscii_to_int(byte bufferem[], float meret)
{
  int i;
  int vege = meret;
  unsigned long temp = 0;
  unsigned long alma = 0;
  unsigned long po;
  unsigned long eredmeny = 0;
  Serial.println("------");
  meret -= 1;
  for (i = 0; i < vege; i++)
  {
    alma = (bufferem[i] - 48);
    po = tiza(meret);
    meret--;
    temp = alma * po;
    eredmeny += temp;
  }
  return eredmeny;
}



