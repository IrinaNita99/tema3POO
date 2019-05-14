#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Produs
{
    string denumire;
    double pret;
    int cantitate;
public:
    virtual void citeste()
    {
        cin>>*this;
    }
    void setDenumire(string);
    void setPret(double);
    void setCantitate(int);
    string getDenumire();
    int getCantitate();
    double getPret();
    Produs();
    Produs(string,double,int);
    virtual ~Produs();
    Produs operator= (Produs &b);
    friend istream& operator>> (istream &input, Produs &x);
    friend ostream& operator<< (ostream&, Produs&);
    virtual void afiseaza()
    {
        cout<<*this;
    }
};

Produs::Produs()
{
    //denumire=" ";
    //cantitate=0;
    // pret=0;
}

Produs::Produs(string numeProdus,double pretProdus,int cantitateProdus)
{
    setDenumire(numeProdus);
    setPret(pretProdus);
    setCantitate(cantitateProdus);
}

istream &operator>> (istream &input,Produs &produs)
{
    cout<<"Reintroduceti tipul produsului: ";
    input>>produs.denumire;
    //getline(input,produs.denumire,',');
    cout<<"Pretul produsului este ";
    input >>produs.pret;
    //produs.setPret(250);
    cout<<"Dati cantitatea : ";
    input >>produs.cantitate;

    return input;
}

ostream& operator<< (ostream& output,Produs &y)
{
    output<<y.denumire<<" ";
    output<<y.pret<<" ";
    output<<y.cantitate<<endl;
    return output;
}


void Produs::setDenumire(string numeProdus)
{
    denumire=numeProdus;
}

void Produs::setPret(double pretProdus)
{
    pret=pretProdus;
}

void Produs::setCantitate(int cantitateProdus)
{
    cantitate=cantitateProdus;
}

string Produs::getDenumire()
{
    return denumire;
}

double Produs::getPret()
{
    return pret;
}

int Produs::getCantitate()
{
    return cantitate;
}


Produs::~Produs()
{
    //dtor
}

class Varza : public Produs
{
    string nume;
public:
    void citeste()
    {
        cin>>*this;
    }
    Varza()
    {
    }
    Varza(string nume_varza)
    {
        setNumeVarza(nume_varza);
    }
    string getNumeVarza()
    {
        return nume;
    }
    string setNumeVarza(string numeVarza)
    {
        nume=numeVarza;
    }
    Varza& operator= (Varza &v)
    {
        nume=v.nume;
    }
    ~Varza()
    {

    }
    friend istream& operator>> (istream& input, Varza& x);
    friend ostream& operator<< (ostream& output,Varza& y);
};

istream& operator>> (istream& input, Varza& x)
{
    input>>dynamic_cast<Produs&>(x);
    cout<<"Dati tipul de varza( verde / rosie / kale ): ";
    input>>x.nume;
    //x.setPretVarza(15);
    //cout<<"Pretul unei verze per cantitate este "<<x.getPretVarza();
    return input;
}

ostream& operator<< (ostream& output,Varza& y)
{
    output<<dynamic_cast<Produs&>(y);
    output<<y.nume<<" ";
    return output;
}

class Faina : public Produs
{
    string nume;
    int calitate;
public:
    void citeste()
    {
        cin>>*this;
    }
    Faina()
    {
        nume=" ";
        calitate=0;
    }
    Faina(string nume_faina,int calitate_faina)
    {
        setNumeFaina(nume_faina);
        setCalitateFaina(calitate_faina);
    }
    string getNumeFaina()
    {
        return nume;
    }
    int getCalitateFaina()
    {
        return calitate;
    }
    string setNumeFaina(string numeFaina)
    {
        nume=numeFaina;
    }
    int setCalitateFaina(int calitateFaina)
    {
        calitate=calitateFaina;
    }
    Faina& operator= (Faina &v)
    {
        nume=v.nume;
        calitate=v.calitate;
    }
    ~Faina()
    {

    }
    friend istream& operator>> (istream& input, Faina& x);
    friend ostream& operator<< (ostream& output,Faina& y);

};


istream& operator>> (istream& input, Faina& x)
{
    input>>dynamic_cast<Produs&>(x);
    cout<<"Tip faina (alba / neagra): ";
    input>>x.nume;
    try
    {
        cout<<"Calitatea faina(1, 2 sau 3): ";
        input>>x.calitate;
        if(x.calitate<1 || x.calitate>3)
            throw x.calitate;
    }
    catch(int i)
    {
        while(i<1 || i>3)
        {
            cout<<"Calitatea trebuie sa fie intre 1 si 3.Alegeti din nou : ";
            input>>i;
        }
        x.calitate=i;
    }
    return input;
}

ostream& operator<< (ostream& output,Faina& y)
{
    output<<dynamic_cast<Produs&>(y);
    output<<y.nume<<" ";
    output<<y.calitate<<endl;
    return output;
}


class Bere : public Produs
{
    string brand;
    string tip; //blonda,bruna
public:
    void citeste()
    {
        cin>>*this;
    }
    Bere()
    {
        //brand=" ";
        //tip=" ";
    }
    Bere(string brand_bere,string tip_bere)
    {
        setBrandBere(brand_bere);
        setTipBere(tip_bere);
    }
    string getBrandBere()
    {
        return brand;
    }
    string getTipBere()
    {
        return tip;
    }
    string setBrandBere(string brandBere)
    {
        brand=brandBere;
    }
    int setTipBere(string tipBere)
    {
        tip=tipBere;
    }
    Bere& operator= (Bere &v)
    {
        brand=v.brand;
        brand=v.brand;
    }
    ~Bere()
    {

    }
    friend istream& operator>> (istream& input, Bere& x);
    friend ostream& operator<< (ostream& output,Bere& y);
};

istream& operator>> (istream& input, Bere& x)
{
    input>>dynamic_cast<Produs&>(x);
    cout<<"Brand-ul berii(Bergenbier / Holshtein / etc): ";
    input>>x.brand;
    cout<<"Tip de bere( blonda / bruna ): ";
    input>>x.tip;
    return input;
}

ostream& operator<< (ostream& output,Bere& y)
{
    output<<dynamic_cast<Produs&>(y);
    output<<y.brand<<" ";
    output<<y.tip<<endl;
    return output;
}

class Vin_varsat : public Produs
{
    string tip; //rosu sec,alb sec
public:
    void citeste()
    {
        cin>>*this;
    }
    Vin_varsat()
    {
        //tip= " ";
    }
    Vin_varsat(string tipVinVarsat)
    {
        setTipVinVarsat(tipVinVarsat);
    }
    string getTipVinVarsat()
    {
        return tip;
    }
    string setTipVinVarsat(string tipVinVarsat)
    {
        tip=tipVinVarsat;
    }
    Vin_varsat& operator= (Vin_varsat &v)
    {
        tip=v.tip;
    }
    ~Vin_varsat()
    {

    }
    friend istream& operator>> (istream& input,Vin_varsat& x);
    friend ostream& operator<< (ostream& output,Vin_varsat& y);
};

istream& operator>> (istream& input,Vin_varsat& x)
{
    input>>dynamic_cast<Produs&>(x);
    cout<<"Tip de vin varsat(rosu sec / alb sec ','): ";
    getline(input,x.tip,',');
    return input;
}

ostream& operator<< (ostream& output,Vin_varsat& y)
{
    output<<dynamic_cast<Produs&>(y);
    output<<y.tip;
    return output;
}

class VinDeSoi : public Produs
{
    string tip;  //rosu sec,rosu dulce
    string denumire;
    int an_culegere;
    string tara;
public:
    void citeste()
    {
        cin>>*this;
    }
    VinDeSoi()
    {
        //tip=" ";
        //denumire=" ";
        //an_culegere=0;
        //tara=" ";
    }
    VinDeSoi(string tipVinSoi,string denumireVinSoi,int an_culegereVinSoi,string taraVinSoi):
        tip(tipVinSoi),denumire(denumireVinSoi),an_culegere(an_culegereVinSoi),tara(taraVinSoi)
    {    }
    ~VinDeSoi()
    {

    }
    string getTipVinSoi()
    {
        return tip;
    }
    string getDenumireVinSoi()
    {
        return denumire;
    }
    int getAn_culegereVinSoi()
    {
        return an_culegere;
    }
    string getTaraVinSoi()
    {
        return tara;
    }
    string setTipVinSoi(string tipVinSoi)
    {
        tip=tipVinSoi;
    }
    string setDenumireVinSoi(string denumireVinSoi)
    {
        denumire=denumireVinSoi;
    }
    int setAn_culegereVinSoi(int an_culegereVinSoi)
    {

        an_culegere=an_culegereVinSoi;
    }
    string setTaraVinSoi(string taraVinSoi)
    {
        tara=taraVinSoi;
    }
    friend istream& operator>> (istream& input,VinDeSoi& x);
    friend ostream& operator<< (ostream& output,VinDeSoi& y);
};

istream& operator>> (istream& input,VinDeSoi& x)
{
    input>>dynamic_cast<Produs&>(x);
    cout<<"Tip de vin soi(rosu sec / rosu dulce ','): ";
    getline(input,x.tip,',');
    cout<<"Denumire vin soi(Cabernet Savignon / Merlot ','): ";
    getline(input,x.denumire,',');
    cout<<"An culegere: ";
    input>>x.an_culegere;
    cout<<"Tara fabricatie: ";
    input>>x.tara;

    return input;
}

ostream& operator<< (ostream& output,VinDeSoi& y)
{
    output<<dynamic_cast<Produs&>(y);
    output<<y.tip;
    output<<y.denumire;
    output<<y.an_culegere;
    output<<y.tara;

    return output;
}

class Cartofi : public Produs
{
    string tip; //rosii sau albi
public:
    void citeste()
    {
        cin>>*this;
    }
    Cartofi()
    {
        //tip= " ";
    }
    Cartofi(string tipCartofi)
    {
        setTipCartofi(tipCartofi);
    }
    string getTipCartofi()
    {
        return tip;
    }
    string setTipCartofi(string tipCartofi)
    {
        tip=tipCartofi;
    }
    Cartofi& operator= (Cartofi &v)
    {
        tip=v.tip;
    }
    ~Cartofi()
    {

    }
    friend istream& operator>> (istream& input,Cartofi& x);
    friend ostream& operator<< (ostream& output,Cartofi& y);
};

istream& operator>> (istream& input,Cartofi& x)
{
    input>>dynamic_cast<Produs&>(x);
    cout<<"Tip cartofi(rosii / albi / noi / vechi): ";
    input>>x.tip;
    return input;
}

ostream& operator<< (ostream& output,Cartofi& y)
{
    output<<dynamic_cast<Produs&>(y);
    output<<y.tip;
    return output;
}


class Jucarii : public Produs
{
    string denumire;
public:
    void citeste()
    {
        cin>>*this;
    }
    Jucarii()
    {
        //denumire= " ";
    }
    Jucarii(string denumireJucarii):denumire(denumireJucarii)
    {

    }
    string getDenumireJucarii()
    {
        return denumire;
    }
    string setDenumireJucarii(string denumireJucarii)
    {
        denumire=denumireJucarii;
    }
    Jucarii& operator= (Jucarii &v)
    {
        denumire=v.denumire;
    }
    ~Jucarii()
    {

    }
    friend istream& operator>> (istream& input,Jucarii& x);
    friend ostream& operator<< (ostream& output,Jucarii& y);

};

istream& operator>> (istream& input,Jucarii& x)
{
    input>>dynamic_cast<Produs&>(x);
    cout<<"Ce fel de jucarie doriti? ";
    input>>x.denumire;
    return input;
}

ostream& operator<< (ostream& output,Jucarii& y)
{
    output<<dynamic_cast<Produs&>(y);
    output<<y.denumire;
    return output;
}


int pretTotal(vector <Produs*> produse)
{
    int i=0;
    int prettotal=0;
    for(i=0; i<produse.size(); i++)
    {
        prettotal += produse[i]->getPret()*produse[i]->getCantitate();
    }
    return prettotal;
}

int main()
{
    int caz;
    int numar_plati=0;
    int suma_totala=0;
    vector <int> s;
    vector <Produs*> produse; //vector ce memoreaza toate produsele
    do
    {
        cout<<" ---  Meniu  --- ";
        cout<<endl;
        cout<<"  1.Ce produse doriti a cumparati? "<<endl;
        cout<<"  2.Afisare pret produse. "<<endl;
        cout<<"  3.Inchiderea zilei."<<endl;
        cout<<"  4.Iesi din program."<<endl;
        cout<<"Optiunea aleasa: ";

        cin>>caz;


        switch(caz)
        {
        case 1:

        {
            int caz2;
            do
            {
                cout<<endl;
                cout<<"1.Introdu un produs tip Varza"<<endl;
                cout<<"2.Introdu un produs tip Faina"<<endl;
                cout<<"3.Introdu un produs tip Bere"<<endl;
                cout<<"4.Introdu un produs tip Vin Varsat"<<endl;
                cout<<"5.Introdu un produs tip Vin de Soi"<<endl;
                cout<<"6.Introdu un produs tip Cartofi"<<endl;
                cout<<"7.Introdu un produs tip Jucarie"<<endl;
                cout<<"9.INTOARCERE LA MENIU"<<endl;
                cout<<"Optiunea aleasa: ";

                cin>>caz2;
                switch(caz2)
                {
                case 1:
                {
                    Produs *a=new Varza();
                    a->citeste();
                    produse.push_back(a);
                    break;
                }
                case 2:
                {
                    Produs *a=new Faina();
                    a->citeste();
                    produse.push_back(a);
                    break;
                }
                case 3:

                {
                    Produs *a=new Bere();
                    a->citeste();
                    produse.push_back(a);
                    break;
                }
                case 4:
                {
                    Produs *a=new Vin_varsat();
                    a->citeste();
                    produse.push_back(a);
                    break;
                }
                case 5:
                {
                    Produs *a=new VinDeSoi();
                    a->citeste();
                    produse.push_back(a);
                    break;
                }
                case 6:
                {
                    Produs *a=new Cartofi();
                    a->citeste();
                    produse.push_back(a);
                    break;
                }
                case 7:
                {
                    Produs *a=new Jucarii();
                    a->citeste();
                    produse.push_back(a);
                    break;
                }
                case 9:
                    break;
                }
            }
            while(caz2<=7);

            break;

        }
        case 2:
        {
            cout<<"Pretul total al produselor este: "<<pretTotal(produse)<<" lei";
            cout<<endl;
            s.push_back(pretTotal(produse));
            bool raspuns;
            cout<<"Doriti sa cumparati produsele?     - 0 : DA, 1: NU - ";
            cin>>raspuns;
            if(raspuns==0)
            {
                cout<<"Plata efectuata cu succes!"<<endl;
                produse.erase(produse.begin(),produse.end());
                numar_plati++;
            }
            else if(raspuns==1)
            {
                produse.erase(produse.begin(),produse.end());
                cout<<"Plata neefectuata!"<<endl;
            }
            break;
        }
        case 3:
        {
            for(int i=0; i<numar_plati; i++)
            {
                suma_totala += s[i];
            }
            cout<<"Suma totala dintr-o zi este: "<<suma_totala;
        }
        case 4:
        {
            break;

        }

        }
    }
    while(caz != NULL);
}


