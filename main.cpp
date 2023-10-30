#include <iostream>
#include <string>
#include <utility>
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
    Produs(string nume, double pret,string  marime,string  tip_sport) : nume(std::move(nume)), marime(std::move(marime)) ,tip_sport(std::move(tip_sport)), pret(pret){}
    Produs(const Produs& other) : nume(other.nume), marime(other.marime) ,tip_sport(other.tip_sport), pret(other.pret) {}
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

    ~Produs() = default;

    [[nodiscard]] const string& getNume() const { return nume; }
    [[maybe_unused]] [[nodiscard]] double getPret() const { return pret; }

    [[maybe_unused]] [[nodiscard]] const string& getMarime() const { return marime; }

    [[maybe_unused]] [[nodiscard]] const string& getTip_sport() const { return tip_sport; }

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
public:

    explicit Client(string  nume) : nume(std::move(nume)) {}
    Client(const Client& other) : nume(other.nume), cosCumparaturi(other.cosCumparaturi) {}

    Client& operator=(const Client& other) {
        if (this != &other) {
            nume = other.nume;
            cosCumparaturi = other.cosCumparaturi;
        }
        return *this;
    }


    ~Client() = default;

    void adaugaProdusInCos(const Produs& produs) {
        cosCumparaturi.push_back(produs);
    }

    [[nodiscard]] const string& getNume() const
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

    vector<Produs> cosCumparaturi;
};

class [[maybe_unused]] CosCumparaturi {
private:
    vector<Produs> produse;
public:
    CosCumparaturi() = default;
    CosCumparaturi(const CosCumparaturi& other) : produse(other.produse) {}
    CosCumparaturi& operator=(const CosCumparaturi& other)
    {
        if (this != &other)
        {
            produse = other.produse;
        }
        return *this;
    }
    ~CosCumparaturi() = default;

    [[maybe_unused]] void adaugaProdus(const Produs& produs)
    {
        produse.push_back(produs);
    }

    [[maybe_unused]] void afiseazaCos() const
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


    for (const auto & client : clienti) {
        cout << "Informații despre clientul: " << client.getNume() << ":\n";
        cout << "Cos de cumparaturi:\n";
        for (const Produs& produs : client.cosCumparaturi) {
            cout << "  -" << produs.getNume() << ", Pret: " << produs.getPret() << " RON, Sport: " << produs.getTip_sport() << "\n";
        }
        cout << "-----------------------------------" << endl;
    }

    return 0;
}
