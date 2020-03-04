'''from Crypto.PublicKey import RSA
import json
from base64 import b64encode, b64decode
from pprint import pprint

class ITKoin:
    def __init__ (self):
        self.pending_transactions = []
        self.unspent_transactions = []
        self.sender_inputs = []
        self.chain = []

    @staticmethod
    def generate_rsa_key(filename):
        rsakey = RSA.generate(2048)# generálj 2048 bites RSA kulcsot
        rsapublickey = rsakey.publickey()# a kulcs publikus része kerüljön ide
        # print(rsakey)
        # pprint(rsakey)
        # print(vars(rsakey))
        # pprint(vars(rsakey))
        pprint(vars(rsakey))
        pprint(vars(rsapublickey))
        PEMrsakey = rsakey.export_key()# PEM formátumra alakítsd az RSA kulcsot
        pprint(PEMrsakey)
        PEMrsapublickey = rsapublickey.export_key()# PEM formátumra alakítsd a kulcs publikus részét
        pprint(PEMrsapublickey)
        privatekeyfilename = filename + 'priv.pem'
        f = open(privatekeyfilename, 'wb')
        f.write(PEMrsakey)
        f.close()
        publickeyfilename = filename + 'pub.pem'
        f = open(publickeyfilename, 'wb')
        f.write(PEMrsapublickey)
        f.close()
        return

ITKoin.generate_rsa_key("file")'''

print("csá világ")

from Crypto.PublicKey import RSA
from Crypto.Hash import SHA256
from Crypto.Signature import pkcs1_15
from base64 import b64encode, b64decode
from pprint import pprint

class ITKoin:


    def __init__ (self):
        self.pending_transactions = []
        self.unspent_transactions = []
        self.sender_inputs = []
        self.chain = []




    @staticmethod
    def generate_rsa_key(filename):
        rsakey = RSA.generate(2048) # generálj 2048 bites RSA kulcsot
        rsapublickey = rsakey.publickey()# a kulcs publikus része kerüljön ide
        #print(rsakey)
        #pprint(rsakey)

        # print(vars(rsakey))
        # pprint(vars(rsakey))
        pprint(vars(rsakey))   # n = p * q
        print("\n")
        pprint(vars(rsapublickey))

        PEMrsakey = rsakey.exportKey() # PEM formátumra alakítsd az RSA kulcsot
        #pprint(PEMrsakey)
        PEMrsapublickey = rsapublickey.exportKey()# PEM formátumra alakítsd a kulcs publikus részét
       # pprint(PEMrsapublickey)
        privatekeyfilename = filename + 'priv.pem'
        f = open(privatekeyfilename, 'wb')
        f.write(PEMrsakey)
        f.close()
        publickeyfilename = filename + 'pub.pem'
        f = open(publickeyfilename, 'wb')
        f.write(PEMrsapublickey)
        f.close()
        return

    def load_key (self, filename):
        privatekeyfilename = filename+'priv.pem'
        privatekeyfileobject = open(privatekeyfilename, 'r')
        privatekeyfilecontent = privatekeyfileobject.read()
        #pprint(privatekeyfilecontent)
        rsakey = RSA.importKey(privatekeyfilecontent)# olvasd be a kulcsot
        self.rsakey = rsakey
        pprint(vars(self.rsakey))
        rsapublickey = rsakey.publickey()# a kulcs publikus része kerüljön ide
        self.rsapublickey = rsapublickey
        pprint(vars(self.rsapublickey))
        return

    def load_public_key (self, filename):
        publickeyfilename = filename+'pub.pem'
        publickeyfileobject = open(publickeyfilename, 'r')
        publickeyfilecontent = publickeyfileobject.read()

        #pprint(publickeyfilecontent)
        rsakey = RSA.importKey(publickeyfilecontent)# olvasd be a kulcsot
        self.rsakey = rsakey
        pprint(vars(self.rsakey))
        rsapublickey = rsakey.publickey()# a kulcs publikus része kerüljön ide
        self.rsapublickey = rsapublickey
        pprint(vars(self.rsapublickey))
        return
    @staticmethod
    def create_hashobject(data):
        #stringdump = json.dumps(data)  # ez nem teljesen korrekt megoldás, de így egyszerű mindent byte stringgé konvertálni
        #binarydump = stringdump.encode()
        hashobject = SHA256.new(data.encode())# hozz létre egy hash objektumot
        # töltsd be az objektumba a lenyomatolni kívánt byte stringet
        hashhexvalue = hashobject.hexdigest()# számítsd ki a lenyomatot, hexa kódolással
        #print(hashhexvalue)
        return hashobject

    def create_signature(self, data):
        signatureobject = pkcs1_15.new(self.rsakey)# hozz létre egy signature objektumot
        hashobject = self.create_hashobject(data)# az adatot töltsd be egy hash objektumba a create_hashobject(data) használatával
        signaturevalue = signatureobject.sign(hashobject)# készítsd el az aláírás értéket a sign függvénnyel
        print("Signiturevalue: ")
        print(signaturevalue)
        b64signaturevalue = b64encode(signaturevalue)  # kódold base64 kódolással
        #print("b64code: ")
        #print(b64signaturevalue)
        #print("with decode ")
        #print(b64decode(b64signaturevalue.decode()))
        return b64signaturevalue

    def verify_signature(self, data, b64signaturevalue):
        verifyobject = pkcs1_15.new(self.rsakey)# hozz létre egy verify objektumot
        print("asdasd")
        pprint(vars(self.rsakey))
        hashobject = self.create_hashobject(data)# az adatot töltsd be egy hash objektumba a create_hashobject(data) használatával
        #signaturevalue = verifyobject.verify(hashobject,b64signaturevalue)# dekódold base64 kódolással az aláírás értéket


        try:
            signaturevalue = verifyobject.verify(hashobject,b64decode(b64signaturevalue))  # dekódold base64 kódolással az aláírás értéket
            #signatureerror = signaturevalue==data# ellenőrizd az aláírást
            #validsignature = "true" # értéke: True, ha az aláírás érvényes
            return signaturevalue
        except(ValueError, TypeError):
            return "false"



mycoin = ITKoin()
data="helo en vagyok az"
#mycoin.generate_rsa_key("laci")

mycoin.load_key("laci")


#mycoin.create_hashobject("data")
sig = mycoin.create_signature("data")
mycoin.load_public_key("laci")
print(mycoin.verify_signature(data,sig));


message = "To be signed"
key = RSA.import_key(open('lacipriv.pem').read())
h = SHA256.new(message.encode())
signature = pkcs1_15.new(key).sign(h)
b64sig= b64encode(signature)
print(signature)
print(b64sig)
sigvissza= b64decode(b64sig)
print(sigvissza)



key = RSA.import_key(open('lacipub.pem').read())
h = SHA256.new(message.encode())
try:
    print(pkcs1_15.new(key).verify(h, sigvissza))
    print ("The signature is valid.")
except (ValueError, TypeError):
    print ("The signature is not valid.")
'''
str = "Ez a szöveg"
str64=b64encode(str.encode())
strde=b64decode(str64);
print(str)
print(str.encode())
print(str64.decode())
print(strde)
'''