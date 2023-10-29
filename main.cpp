#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Produs
{
private:
    string nume;
    string marime;
    string tip_sport;
    double pret;

public:
    Produs(const string& nume, double pret,const string& marime,const string& tip_sport) : nume(nume), pret(pret) ,marime(marime), tip_sport(tip_sport){}
    Produs(const Produs& other) : nume(other.nume), pret(other.pret) ,marime(other.marime), tip_sport(other.tip_sport) {}
    Produs& operator=(const Produs& other)
    {
        if (this != &other)
        {
            nume = other.nume;
            pret = other.pret;
            marime=other.marime;
            tip_sport=other.tip_sport;
        }
        return *this;
    }

    ~Produs() {}

     const string& getNume() const { return nume; }
     double getPret() const { return pret; }
     const string& getMarime() const { return marime; }
     const string& getTip_sport() const { return tip_sport; }

     friend ostream& operator<<(ostream& os, const Produs& produs)
     {
        os <<"Tip echipament:"<< produs.nume <<endl<< "  -Pret: " << produs.pret << " RON "<<endl;
        os<<"  -Marime aleasa:"<<produs.marime<<endl<<"  -Sport: "<<produs.tip_sport<<endl;
        return os;
     }
};

class Client {
private:
    string nume;
    vector<Produs> cosCumparaturi;
public:

    Client(const string& nume) : nume(nume) {}
    Client(const Client& other) : nume(other.nume), cosCumparaturi(other.cosCumparaturi) {}

    Client& operator=(const Client& other) {
        if (this != &other) {
            nume = other.nume;
            cosCumparaturi = other.cosCumparaturi;
        }
        return *this;
    }

    // Destructorul clasei Client. Este generat implicit.Deoarece nu utilizam
    //alocare dinamică de resurse sau alte acțiuni speciale care să necesite un destructor definit explicit
    ~Client() {}

    void adaugaProdusInCos(const Produs& produs) {
        cosCumparaturi.push_back(produs);
    }

    const string& getNume() const
    {
        return nume;
    }

    friend ostream& operator<<(ostream& os, const Client& client)
    {
        os << "Client: " << client.nume << "\nCos de cumparaturi:\n";
        for (const Produs& produs : client.cosCumparaturi)
        {
            os << "  -" << produs << "\n";
        }
        return os;
    }
};

class CosCumparaturi {
private:
    vector<Produs> produse;
public:
    CosCumparaturi() {}
    CosCumparaturi(const CosCumparaturi& other) : produse(other.produse) {}
    CosCumparaturi& operator=(const CosCumparaturi& other)
    {
        if (this != &other)
        {
            produse = other.produse;
        }
        return *this;
    }
    ~CosCumparaturi() {}

    void adaugaProdus(const Produs& produs)
    {
        produse.push_back(produs);
    }

    void afiseazaCos() const
    {
        cout << "Cos de cumparaturi:\n";
        for (const Produs& produs : produse)
        {
            cout << "  -" << produs << "\n";
        }
    }
};

int main() {
   
    Produs produs1("Minge de fotbal", 50.0, "L", "Fotbal");
    Produs produs2("Tricou sport", 25.0, "M", "Fitness");
    Produs produs3("Racheta tenis", 120.0, "M", "Tenis");
    Produs produs4("Manusi de box", 35.0, "M", "Boxing");
    Produs produs5("Pantaloni scurti", 15.0, "S", "Fitness");

    
    vector<Client> clienti;

  
    Client client1("Ionescu Mihnea");
    client1.adaugaProdusInCos(produs1);
    client1.adaugaProdusInCos(produs3);
    client1.adaugaProdusInCos(produs4);
    clienti.push_back(client1);

    
    Client client2("Vlad Raluca");
    client2.adaugaProdusInCos(produs2);
    client2.adaugaProdusInCos(produs4);
    clienti.push_back(client2);

  
    Client client3("Patrascu Alexandru");
    client3.adaugaProdusInCos(produs1);
    client3.adaugaProdusInCos(produs5);
    clienti.push_back(client3);

    // Afișarea informațiilor despre fiecare client și conținutul coșului său
     
    for (size_t i = 0; i < clienti.size(); ++i) {
    	const Client& client = clienti[i];
        cout << "Informații despre " << client.getNume() << ":\n" << client << endl;
        cout << "-----------------------------------" << endl;
    }

    return 0;
}
