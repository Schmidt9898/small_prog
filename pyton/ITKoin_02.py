from Crypto.PublicKey import RSA
from Crypto.Signature import pkcs1_15
from Crypto.Hash import SHA256
import json
from base64 import b64encode, b64decode
from pprint import pprint
import pickle



class ITKoin:
    def __init__ (self):
        self.chain_filename = 'chain_01.txt'
        self.pending_transactions_filename = 'pending_01.txt'
        self.unspent_outputs_filename = 'unspent_01.txt'
        self.my_privatekey_filename = 'csmkey_00_priv.pem'
        self.chain = []
        self.pending_transactions = []
        self.unspent_outputs = []
        self.my_unspent_outputs = []
#        self.my_privatekey
#        self.my_publickey
#        self.my_id
        self.ITKoin_users = ['csmkey_03_id.txt', 'csmkey_01_id.txt', 'csmkey_02_id.txt'] # Ez egy lista, ahovĂĄ s rĂŠsztvevĹk id-jait tartalmazĂł file-neveket kell felsorolni
        self.initial_csaposhi_offering = 100
        self.validated_transactions=[]


    def generate_rsa_key(self, filename): # a filenĂŠv tĂśvĂŠvel kell meghĂ­vni ĂŠs hĂĄrom file-t generĂĄl: a privĂĄt ĂŠs publikus kulcsoknak, ill. az ID-nak
        key = RSA.generate(2048)
        publickey = key.publickey()
        privatekey_filename = filename + '_priv.pem'
        f = open(privatekey_filename, 'wb')
        f.write(key.export_key())
        f.close()
        publickey_filename = filename + '_pub.pem'
        f = open(publickey_filename, 'wb')
        f.write(publickey.export_key())
        f.close()
        publickey_string = publickey.export_key().decode('ascii') # binĂĄris stringet karakter stringgĂŠ konvertĂĄljuk, hogy a json.dumps mĹąkĂśdjĂśn rajta
        recipient_id_filename = filename + '_id.txt'
        f = open(recipient_id_filename, 'wb')
        f.write(self.create_hashhexvalue(publickey_string).encode('ascii')) # a hexa string hash ĂŠrtĂŠket binĂĄris stringgĂŠ konvertĂĄljuk a file-ba Ă­rĂĄshoz
        print('-----recipients:')
        print(self.create_hashhexvalue(publickey_string).encode('ascii'))
        print('-----recipient end-----')
        f.close()
        return

    def load_my_private_key (self,mykey_pem):
        self.my_privatekey_filename = mykey_pem+'_priv.pem'
        fileobject = open(self.my_privatekey_filename, 'r')
        self.my_privatekey = RSA.import_key(fileobject.read())
        self.my_publickey = self.my_privatekey.publickey()
        publickey_string = self.my_publickey.export_key().decode('ascii') # binĂĄris stringet karakter stringgĂŠ konvertĂĄljuk, hogy a json.dumps mĹąkĂśdjĂśn rajta
        self.my_id = self.create_hashhexvalue(publickey_string) # a hexa string hash ĂŠrtĂŠket binĂĄris stringgĂŠ konvertĂĄljuk a file-ba Ă­rĂĄshoz
        #pprint(self.my_id)
        return

    @staticmethod
    def load_public_key (filename):
        fileobject = open(filename, 'r')
        key = RSA.import_key(fileobject.read())
        return key.publickey()

    @staticmethod
    def load_id (filename):
        fileobject = open(filename, 'r')
        id = fileobject.read()
        return id

    @staticmethod
    def create_hashobject (data):
        stringdump = json.dumps(data)
        hashobject = SHA256.new(stringdump.encode())
        return hashobject

    @staticmethod
    def create_hashhexvalue (data):
        stringdump = json.dumps(data)
        hashobject = SHA256.new(stringdump.encode())
        return hashobject.hexdigest()

    @staticmethod
    def create_hashvalue (data):
        stringdump = json.dumps(data)
        hashobject = SHA256.new(stringdump.encode())
        return hashobject.digest()

    def create_signature (self, data):
        signatureobject = pkcs1_15.new(self.my_privatekey) # hozz lĂŠtre egy signature objektumot
        hashobject = self.create_hashobject(data) # az adatot tĂśltsd be egy hash objektumba a create_hashobject(data) hasznĂĄlatĂĄval
        signaturevalue = signatureobject.sign(hashobject) # kĂŠszĂ­tsd el az alĂĄĂ­rĂĄs ĂŠrtĂŠket a sign fĂźggvĂŠnnyel
        #print(signaturevalue)
        b64signaturevalue = b64encode(signaturevalue) # kĂłdold base64 kĂłdolĂĄssal
        #print(b64signaturevalue)
        #print(b64signaturevalue.decode())
        return b64signaturevalue.decode()

    def verify_signature(self, data, b64signaturevalue, rsapublickey):
        verifyobject = pkcs1_15.new(rsapublickey) # hozz lĂŠtre egy verify objektumot
        hashobject = self.create_hashobject(data) # az adatot tĂśltsd be egy hash objektumba a create_hashobject(data) hasznĂĄlatĂĄval
        signaturevalue = b64decode(b64signaturevalue.encode()) # dekĂłdold base64 kĂłdolĂĄssal az alĂĄĂ­rĂĄs ĂŠrtĂŠket
        try:
            verifyobject.verify(hashobject, signaturevalue)
            #print("The signature is valid.")
            return True
        except (ValueError, TypeError):
            print("ERRor ----The signature is not valid.-----")
            return False


    @staticmethod
    def save_list(list, filename):
        f = open(filename, 'wb')
        pickle.dump(list, f)
        f.close()
        return

    def load_chain(self):
        try:
            fileobject = open(self.chain_filename, 'rb')
            self.chain = pickle.load(fileobject)
        except FileNotFoundError:
            self.chain=[]
        print('________Your Chain_________')
        pprint(self.chain)

        print("________chain END__________\n")
        if self.test_chain():
            print("The chain is valid.")
        else:
            print("The chain is invalid!!!!")

        return

    def test_chain(self):
        previous_block_header_hash = 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
        for block in self.chain[0:]:
            if previous_block_header_hash != block['block_header']['previous_block_header_hash']:
                return False
            previous_block_header_hash = self.create_hashhexvalue(block['block_header'])
            if previous_block_header_hash[:4]!="0000":
                return False


        return True


    def check_duplicate_transactions(self,transactions):#true if it has duplicate
        #Megnézi hogy van e olyan tranzakció ami ugyan ezeket az outputokat hasznélja e
        for transaction in transactions:
            for input in transaction['inputs']:
                f_count = 0  # duplikátumok száma
                for another_transaction_ in transactions:
                    for another_input in transaction['inputs']:
                        if input == another_input:
                            f_count+=1
                if f_count>1:
                    return True
        return False

    def is_this_input_has_duplicate_in_valid(self,input):
        #megnézi hogy van e az inputok között olyan a ami már fel lett használva
        for valid_transaction in self.validated_transactions:
            for valid_input in valid_transaction['inputs']:
                        if input == valid_input:
                            return True
        return False



    def test_transactions(self,test_block):#megnézi hogy a blokkban minden tranzakció helyes e de ez elavult és nem használom
        for transaction in test_block['transactions']:
            for input in transaction['inputs']:
                if self.verify_signature(input[0], input[3], RSA.import_key(input[4])):
                    isfound = False
                    recipient = self.create_hashhexvalue(RSA.import_key(input[4]).publickey().exportKey().decode('ascii'))
                    for prev_block in self.chain:
                        if prev_block == test_block:
                            break
                        for output_trans in prev_block['transactions']:
                            for output in output_trans['outputs']:
                                if output['recipient'] == recipient and output['csaposhi'] == input[2]:
                                    isfound = True
                                    break
                    if isfound:
                        for another_block in self.chain[1:]:
                            if another_block == test_block:
                                break
                            for another_trans in another_block['transactions']:
                                for another_input in another_trans['inputs']:
                                    if another_input == input:
                                        return False
                    else:
                        return False
        return True


    def test_transaction(self,transaction):#valid = true
        #megnézi hogy valid e a tranzakció az az elvégezhető e
        for input in transaction['inputs']:
            if self.verify_signature(input[0], input[3], RSA.import_key(input[4])):# aláírás ellenörzés
                isfound = False
                recipient = self.create_hashhexvalue(RSA.import_key(input[4]).publickey().exportKey().decode('ascii'))
                for prev_block in self.chain:
                    for output_trans in prev_block['transactions']:
                        for output in output_trans['outputs']:
                            if output['recipient'] == recipient and output['csaposhi'] == input[2]: # további tagok ellenörzése
                                isfound = True
                                break
                if isfound:
                    for another_block in self.chain[1:]:
                        for another_trans in another_block['transactions']:
                            for another_input in another_trans['inputs']:
                                if another_input == input:
                                    print(transaction+' is invalid, already used')
                                    return False
                else:
                    print('transaction is not valid, not found the output in chain')
                    return False
        summ = 0 # kimenet bemenet meg kell hogy eggyezzen
        for input in transaction['inputs']:
            summ += int(input[2])
        for output in transaction['outputs']:
            value = int(output['csaposhi'])
            if value<0:# kimenet nem lehet negatív
                return False
            summ -= value
        return summ == 0














    def load_pending_transactions(self):
        try:
            fileobject = open(self.pending_transactions_filename, 'rb')
            self.pending_transactions = pickle.load(fileobject)
        except FileNotFoundError:
            self.pending_transactions = []
        #pprint(self.pending_transactions)
        validated_pending_transactions = []
        while len(self.pending_transactions) != 0:
            transaction = self.pending_transactions.pop()
            if True: # itt validĂĄlni kellene az adott tranzakciĂłt, a nem ĂŠrvĂŠnyeseket eldobja, de nem ĂĄll le
                validated_pending_transactions.append(transaction)
        self.pending_transactions = validated_pending_transactions
        return

    def find_unspent_outputs(self):
        self.unspent_outputs = []
        self.my_unspent_outputs = []
        for transaction in self.chain[0]['transactions']:
            for output in transaction['outputs']:
                self.unspent_outputs.append([transaction['txid'], 0, output['csaposhi']])
                if output['recipient']==self.my_id:
                    self.my_unspent_outputs.append([transaction['txid'], 0, output['csaposhi']])
        for block in self.chain[1:]:
            for transaction in block['transactions']:
                for output in transaction['outputs']:
                    self.unspent_outputs.append([transaction['txid'], transaction['outputs'].index(output), output['csaposhi']])
                    if output['recipient'] == self.my_id:
                        self.my_unspent_outputs.append([transaction['txid'], transaction['outputs'].index(output), output['csaposhi']])
                    #pprint(self.unspent_outputs)
                for input in transaction['inputs']:
                    self.unspent_outputs.remove(input[0:3]) # minden input biztosan szerepelt a lĂĄnc korĂĄbbi outputjakĂŠnt
                    if input[0:3] in self.my_unspent_outputs: # a remove() hibĂĄt dob, ha Ăşgy tĂśrlĂźnk a listĂĄbĂłl valamit, hogy nem is volt benne
                        self.my_unspent_outputs.remove(input[0:3])
                    #pprint(self.unspent_outputs)


        print('_____all unspend outputs____')
        pprint(self.unspent_outputs)
        print("__________________________\n")
        print('_____my unspend outputs____')
        pprint(self.my_unspent_outputs)
        print("__________________________\n")
        #pprint(self.my_unspent_outputs)
        return

    def test_pending_transactions(self):
        # a pending transaction eket megnézzük hogy jók e és ha igen áttesszük a validated listába
        self.validated_transactions=[]
        for transaction in self.pending_transactions:
            is_transaction_good = True
            for input in transaction['inputs']:
                if self.is_this_input_has_duplicate_in_valid(input):
                    is_transaction_good = False
                    print(input)
                    print(' is a duplicate, the transaction not valid')
                    break
            if is_transaction_good:
                self.validated_transactions.append(transaction)
        for transaction in self.validated_transactions:
            if not self.test_transaction(transaction):
                self.validated_transactions.remove(transaction)
                print('.......................')
                pprint(transaction)
                print('transaction is not not valid,removed')
                print('.......................')





    def mine(self):
        isfirst = False
        if len(self.chain) == 0:
            previous_block_header_hash = 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
            isfirst = True
            self.validated_transactions = self.pending_transactions
        else:
            previous_block = self.chain[-1]
            previous_block_header = previous_block['block_header']
            previous_block_header_hash = self.create_hashhexvalue(previous_block_header)
            self.load_pending_transactions()
            self.test_pending_transactions()



        if len(self.validated_transactions)==0 and not isfirst:
            print("there is no valid transaction we quit!!! and also clear pending file")
            self.save_list(self.pending_transactions, self.pending_transactions_filename)
            return

        nonce = 0

        block_header = {
            'nonce': nonce,
            'previous_block_header_hash': previous_block_header_hash,
            'transactions_hash' : self.create_hashhexvalue(self.validated_transactions),
        }
        while True:
            block_header_hash = self.create_hashhexvalue(block_header)
            if block_header_hash[:4] == "0000":
                break
            block_header['nonce'] += 1

        block = {
            'block_header': block_header,
            'transactions': self.validated_transactions
        }
        pprint(block)

        self.chain.append(block)
        #pprint (self.chain)
        self.save_list(self.chain, self.chain_filename)
        self.pending_transactions = []
        self.validated_transactions = []
        self.save_list(self.pending_transactions, self.pending_transactions_filename)

        return

    def generate_first_block(self):
        self.pending_transactions = []
        while len(self.ITKoin_users) > 0:
            recipient_id = self.load_id (self.ITKoin_users.pop()) # elĹveszi a kĂśvetkezĹ id file nevĂŠt ĂŠs beolvassa az id-t
            for tr in self.pending_transactions: # nem szerepelhet kĂŠtszer ugyanaz a recipient, mert akkor a txid azonos lesz
                for op in tr['outputs']:
                    if recipient_id == op['recipient']:
                        #pprint ('HIBA: IsmĂŠtlĹdĹ recipient adatok az elsĹ blokk generĂĄlĂĄsakor.')
                        return False
            outputs = [
                {
                'csaposhi': self.initial_csaposhi_offering,
                'recipient': recipient_id
                }
            ]

            transaction = {
                'inputs': [],
                'outputs': outputs}
            transaction ['txid'] = self.create_hashhexvalue(transaction) # a tranzakciĂł lenyomata lesz az azonosĂ­tĂłja egyben
            self.pending_transactions.append(transaction)
            #self.save_list(self.pending_transactions, self.pending_transactions_filename)

        #pprint(self.pending_transactions)
        self.mine()
        return



    def new_transaction(self, csaposhi, recipient): # a megadott Ăśsszeg ĂĄtadĂĄsa recipientnek, a maradĂŠk visszautalĂĄsa
        try:
            sum = 0
            used_outputs = []
            while (sum < csaposhi):
                next_output = self.my_unspent_outputs.pop()
                # pprint(next_output)
                used_outputs.append(next_output)
                # pprint(next_output)
                sum += next_output[2]  # ebben a listapozĂ­ciĂłban van a hivatkozott outputban kapott Ăśsszeg
                # pprint(sum)
            inputs = used_outputs
            # pprint(inputs)
            for input in inputs:  # az inputsban szĂĄndĂŠkosan nincs benne az akkori recipient, mert ezt abbĂłl a tranzakciĂłbĂłl kell kivenni ĂŠs ellenĹrizni
                input.append(self.create_signature(input[0]))  # input[3] az alĂĄĂ­rĂĄs ĂŠrtĂŠk base64 kĂłdolĂĄssal
                input.append(
                    self.my_publickey.export_key().decode('ascii'))  # input[4] a publikus kulcsom PEM formĂĄtumban
                # pprint(self.verify_signature(input[0], input[3], RSA.import_key(input[4])))
            outputs = [{
                'csaposhi': csaposhi,
                'recipient': recipient}]
            if sum > csaposhi:  # ha van visszajĂĄrĂł, azt visszautaljuk magunknak
                outputs.append({
                    'csaposhi': sum - csaposhi,
                    'recipient': self.my_id})
            transaction = {
                'inputs': inputs,
                'outputs': outputs}
            transaction['txid'] = self.create_hashhexvalue(
                transaction)  # a tranzakciĂł lenyomata lesz az azonosĂ­tĂłja egyben
            self.load_pending_transactions();
            self.pending_transactions.append(transaction)
            self.save_list(self.pending_transactions, self.pending_transactions_filename)
            print('___________ Pending transaction ____________')
            pprint(self.pending_transactions)
            print('_____________ transaction end ______________')
        except IndexError:
            print('Transaction cannot be made, not enough csaposhi')
        return



mycoin=ITKoin()
#generáljunk kulcsokat
#mycoin.generate_rsa_key('csmkey_01')
#mycoin.generate_rsa_key('csmkey_02')
#mycoin.generate_rsa_key('csmkey_03')

#az első láncszem
mycoin.generate_first_block()

#töltsük is be
mycoin.load_chain()

#vegyük kézbe az első kulcsot
mycoin.load_my_private_key('csmkey_01')
#hozzunk létre tranzakcióket magunknak
mycoin.find_unspent_outputs()
mycoin.new_transaction(10, mycoin.load_id('csmkey_01_id.txt'))
#vegyük kézbe a második kulcsot
mycoin.load_my_private_key('csmkey_02')
#hozzunk létre tranzakcióket magunknak
mycoin.find_unspent_outputs()
mycoin.new_transaction(10, mycoin.load_id('csmkey_02_id.txt'))
#vegyük kézbe a harmadik kulcsot
mycoin.load_my_private_key('csmkey_03')
#hozzunk létre tranzakcióket magunknak
mycoin.find_unspent_outputs()
mycoin.new_transaction(10, mycoin.load_id('csmkey_03_id.txt'))

#biztos ami biztos de e nélkül is törlődik
mycoin.pending_transactions=[]

#bányásszuk ki őket ezzel eggyütt be is töltjük a tranzakciókat és le is ellenőrizzük
mycoin.mine()

#mycoin.load_chain()


#vegyük kézbe az első kulcsot
mycoin.load_my_private_key('csmkey_01')
#hozzunk létre tranzakcióket magunknak
mycoin.find_unspent_outputs()
mycoin.new_transaction(10, mycoin.load_id('csmkey_02_id.txt'))
#vegyük kézbe a második kulcsot
mycoin.load_my_private_key('csmkey_02')
#hozzunk létre tranzakcióket magunknak
mycoin.find_unspent_outputs()
mycoin.new_transaction(10, mycoin.load_id('csmkey_03_id.txt'))
#vegyük kézbe a harmadik kulcsot
mycoin.load_my_private_key('csmkey_03')
#hozzunk létre tranzakcióket magunknak
mycoin.find_unspent_outputs()
mycoin.new_transaction(10, mycoin.load_id('csmkey_01_id.txt'))


#biztos ami biztos de e nélkül is törlődik
mycoin.pending_transactions=[];

#bányásszuk ki őket ezzel eggyütt be is töltjük a tranzakciókat és le is ellenőrizzük
mycoin.mine()
print('_______FULL Chain_______')
pprint(mycoin.chain)
print('________chain end_________')

#signature = mycoin.create_signature(2)
#pprint(signature)
#pprint(mycoin.my_publickey)
#print(mycoin.verify_signature(2, signature, mycoin.my_publickey))

#mycoin.mine()


