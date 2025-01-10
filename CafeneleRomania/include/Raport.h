#ifndef RAPORT_H
#define RAPORT_H

#include <iostream>
#include <vector>
#include <memory>
#include "Comanda.h"
#include "Angajati.h"
#include "Produs.h"

using namespace std;

// Clasa Raport: Generarea raportului zilnic
class Raport {
private:
    vector<Comanda> comenzi;                        // Lista comenzilor din ziua respectivă
    vector<Angajat*> angajati;                      // Lista angajaților
    vector<shared_ptr<Produs>> produse;             // Lista produselor utilizate

public:
    // Constructor
    Raport(const vector<Comanda>& comenzi, const vector<Angajat*>& angajati, const vector<shared_ptr<Produs>>& produse);

    // Metode
    double calculeazaVenituri() const;              // Calcularea veniturilor totale
    double calculeazaSalarii() const;               // Calcularea salariilor totale
    double calculeazaCheltuieliStoc() const;        // Calcularea cheltuielilor pentru stocuri
    double calculeazaProfitNet() const;             // Calcularea profitului net
    void genereazaRaport() const;                   // Generarea raportului detaliat
};

#endif
