#ifndef COMANDA_H
#define COMANDA_H

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "Produs.h"

class Comanda {
private:
    std::string client;                                   // Numele clientului
    std::vector<std::pair<std::shared_ptr<Produs>, int>> produse; // Produse și cantități
    double total;                                         // Totalul comenzii
    double reducere;                                      // Reducerea aplicată
    bool clientFidel;                                     // Statusul de client fidel

public:
    // Constructor
    Comanda(const std::string& client, bool clientFidel = false);

    // Adăugare produs
    void adaugaProdus(const std::shared_ptr<Produs>& produs, int cantitate);

    // Aplicare reduceri
    void aplicaReducereProcentuala(double procent);
    void aplicaReducereFideli();

    // Calcul total cu reducere
    double calculeazaTotalCuReducere() const;

    // Afișare comandă
    void afiseazaComanda() const;

    // Getteri și setteri
    double getTotal() const;
    std::string getClient() const;
    void setClientFidel(bool fidelitate);
};

#endif
