#include "../include/Eveniment.h"
#include <iostream>

using namespace std;

// Constructor: Inițializează evenimentul cu nume, dată, costuri și venituri
Eveniment::Eveniment(const string& nume, const string& data, double costuri, double venituri)
    : nume(nume), data(data), costuri(costuri), venituri(venituri) {}

// Metodă pentru calcularea profitului
double Eveniment::calculeazaProfit() const {
    return venituri - costuri;
}

// Metodă pentru afișarea detaliilor evenimentului
void Eveniment::afiseazaDetalii() const {
    cout << "Eveniment: " << nume << endl;
    cout << "Data: " << data << endl;
    cout << "Costuri: " << costuri << " lei" << endl;
    cout << "Venituri: " << venituri << " lei" << endl;
    cout << "Profit: " << calculeazaProfit() << " lei" << endl;
}

// Getter pentru nume
string Eveniment::getNume() const {
    return nume;
}

// Getter pentru data
string Eveniment::getData() const {
    return data;
}

// Setter pentru costuri
void Eveniment::setCosturi(double noiCosturi) {
    costuri = noiCosturi;
}

// Setter pentru venituri
void Eveniment::setVenituri(double noiVenituri) {
    venituri = noiVenituri;
}
