from Crypto.PublicKey import RSA
from Crypto.Hash import SHA256
from Crypto.Signature import pkcs1_15
from base64 import b64encode, b64decode
import json
from pprint import pprint

class ITKoin:
    def __init__(self):
        print("new coin")
        self.pending_transactions = []
        self.unspent_transactions = []
        self.sender_inputs = []
        self.chain = []

    @staticmethod
    def generate_rsa_key(filename):#ez egy ronda megoldás
        rsakey = RSA.generate(2048) # generálj 2048 bites RSA kulcsot értelem szerüen
        rsapublickey = rsakey.publickey()# a kulcs publikus része kerüljön ide
        #pprint(vars(rsakey))   # n = p * q
        PEMrsakey = rsakey.exportKey() # PEM formátumra alakítsd az RSA kulcsot

        PEMrsapublickey = rsapublickey.exportKey()# PEM formátumra alakítsd a kulcs publikus részét

        privatekeyfilename = filename + 'priv.pem'
        f = open(privatekeyfilename, 'wb')
        f.write(PEMrsakey)
        f.close()
        publickeyfilename = filename + 'pub.pem'
        f = open(publickeyfilename, 'wb')
        f.write(PEMrsapublickey)
        f.close()
        return

    @staticmethod
    def create_hashobject(data):#olyan fölösleges erre fügvényt írni
        return SHA256.new(data.encode())

    def new_rsa_key(self):# nem is hosszú mi?
        print("creating")
        self.priv_key=RSA.generate(2048)
        return
    def save_keys(self,filename):
        print("saving")
        PEMrsakey = self.priv_key.exportKey()  # PEM formátumra alakítsd az RSA kulcsot
        PEMrsapublickey = self.priv_key.publickey().exportKey()  # PEM formátumra alakítsd a kulcs publikus részét
        f = open(filename+".priv", 'wb')
        f.write(PEMrsakey)
        f.close()
        f = open(filename+".pub", 'wb')
        f.write(PEMrsapublickey)
        f.close()
        return

    def use_key(self,filename):
        print("using")
        self.priv_key = RSA.importKey(open(filename+".priv").read())
        return
    @staticmethod
    def load_public_key(filename):
        print("loading")
        return RSA.importKey(open(filename+".pub").read())

    def use_public_key(self,filename):
        print("saving public")
        self.priv_key=RSA.importKey(open(filename + ".pub").read())
        return self.priv_key

    def create_b64signature(self,data):
        print("b64 sinature")
        h=self.create_hashobject(data) # h=self.create_hashobject(data)
        signiture=pkcs1_15.new(self.priv_key).sign(h)
        return b64encode(signiture)

    def create_signature(self, data):
        print("sinature")
        h = self.create_hashobject(data)
        return pkcs1_15.new(self.priv_key).sign(h)

    def I_verify_b64signature(self,data,b64signature):
        print("verify b64 sinature")
        h = SHA256.new(data.encode()) # h=self.create_hashobject(data)
        signature =  b64decode(b64signature)
        try:
            pkcs1_15.new(self.priv_key).verify(h, signature)
            print("The signature is valid.")
            return True
        except (ValueError, TypeError):
            print("The signature is not valid.")
            return False
    def I_verify_signature(self,data,signature):
        print("verify sinature")
        h = SHA256.new(data.encode()) # h=self.create_hashobject(data)
        try:
            pkcs1_15.new(self.priv_key).verify(h, signature)
            print("The signature is valid.")
            return True
        except (ValueError, TypeError):
            print("The signature is not valid.")
            return False
    @staticmethod
    def verify_b64signature(data,b64signature,key):
        print("verify b64")
        h = SHA256.new(data.encode()) # h=self.create_hashobject(data)
        signature =  b64decode(b64signature)
        try:
            pkcs1_15.new(key).verify(h, signature)
            print("The signature is valid.")
            return True
        except (ValueError, TypeError):
            print("The signature is not valid.")
            return False
    @staticmethod
    def verify_signature(data,signature,key):
        print("verify")
        h = SHA256.new(data.encode()) # h=self.create_hashobject(data)
        try:
            pkcs1_15.new(key).verify(h, signature)
            print("The signature is valid.")
            return True
        except (ValueError, TypeError):
            print("The signature is not valid.")
            return False





print("main")
coin = ITKoin()

coin.new_rsa_key()

coin.save_keys("key")

coin.use_key("key")
data = "I love TEA"
b64signo = coin.create_b64signature(data)

coin.I_verify_b64signature(data, b64signo)
ITKoin.verify_b64signature(data, b64signo, ITKoin.load_public_key("key"))

'''

message = "To be signed"
key = RSA.import_key(open('key.priv').read())
h = SHA256.new(message.encode())
signature = pkcs1_15.new(key).sign(h)
b64sig= b64encode(signature)
print(signature)
print(b64sig)
sigvissza= b64decode(b64sig)
print(sigvissza)



key = RSA.import_key(open('key.pub').read())
h = SHA256.new(message.encode())
try:
    print(pkcs1_15.new(key).verify(h, sigvissza))
    print ("The signature is valid.")
except (ValueError, TypeError):
    print ("The signature is not valid.")
'''