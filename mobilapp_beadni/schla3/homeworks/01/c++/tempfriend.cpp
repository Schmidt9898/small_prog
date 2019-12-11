
struct Bor{
    void barat(){cout<<"Lengyel, magyar - ke't jo' bara't, egyutt harcol, s issza bora't."<<endl;}
};

class Magyar{
private:
Bor bor;
void magyar(){bor.barat();}

// Is this the appropiate usage?
friend class Lengyel;

};
class Lengyel{

public :
    void ket_jo(Magyar &M){
    M.magyar();
    }
};

