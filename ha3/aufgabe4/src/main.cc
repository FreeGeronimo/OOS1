#include <iostream>
#include <string>
using namespace std;

class Duck
{
    friend void zaster(Duck &p, long n);
    friend void kontoauszug(const Duck& p);
    friend void panzerknacker(Duck &p, long n);

  public:
    Duck();

  private:
    long bankkonto;
    string waehrung; //Symbol für Währung
    static long familienbesitz;
};

long Duck::familienbesitz = 0;

Duck::Duck()
{
    bankkonto = 0;
    waehrung = "$";
}

void zaster(Duck &p, long money)
{
    p.bankkonto += money; // bankkonto um money erhöhen
    p.familienbesitz += money; // familienbesitz um money erhöhen
    cout << "Hier ist zaster, zaster eine "
            "Freund-Funktion der Klasse Duck"
         << endl;
    cout << "Die Einnahme ist " << money << " " << p.waehrung << endl;
};

void panzerknacker(Duck &p, long money)
{
    p.bankkonto -= money; //bankkonto um money erniedrigen
    p.familienbesitz -= money; //familenbesitz um money erniedrigen
    cout << "panzerknacker eine Freund-Funktion ?!" << endl;
    cout << "Die Panzerknacker waren da" << endl;
    cout << "Sie haben " << money << " " << p.waehrung
         << " geraubt" << endl;
};

void kontoauszug(const Duck& p)
{
    cout << "Kontoauszug: " << p.bankkonto << " "
         << p.waehrung << endl;
    cout << "Familienbesitz: " << p.familienbesitz
         << " " << p.waehrung << endl;
}

int main(void)
{
    Duck dagobert;
    cout << "dagobert bekommt Geld" << endl;
    zaster(dagobert, 1000000);
    Duck daisy;
    cout << "daisy bekommt Geld" << endl;
    zaster(daisy, 100);

    cout << "Der Besitz von dagobert ist ";
    kontoauszug(dagobert);
    cout << endl;
    cout << "Der Besitz von daisy ist ";
    kontoauszug(daisy);
    cout << endl;
    cout << "armer dagobert" << endl;
    panzerknacker(dagobert, 1000000);
    cout << "Der Besitz von dagobert ist ";
    kontoauszug(dagobert);
    return 0;
}
