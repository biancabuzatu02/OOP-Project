#ifndef EVENIMENT_H
#define EVENIMENT_H

#include <string>
#include <iostream>

using namespace std;

// Clasa Eveniment: Gestionarea evenimentelor speciale
// **Concept OOP: Encapsulare** - Atributele clasei sunt private și accesibile prin metode publice.
class Eveniment {
private:
    string nume;         // Numele evenimentului
    string data;         // Data evenimentului
    double costuri;      // Costurile organizării
    double venituri;     // Veniturile generate

public:
    // **Constructor**: Inițializează evenimentul cu nume, dată, costuri și venituri.
    Eveniment(const string& nume, const string& data, double costuri, double venituri);

    // **Metodă pentru calcularea profitului**
    double calculeazaProfit() const;

    // **Metodă pentru afișarea detaliilor evenimentului**
    void afiseazaDetalii() const;

    // **Getter** pentru numele evenimentului
    string getNume() const;

    // **Getter** pentru data evenimentului
    string getData() const;

    // **Setter** pentru costuri
    void setCosturi(double noiCosturi);

    // **Setter** pentru venituri
    void setVenituri(double noiVenituri);
};

#endif
