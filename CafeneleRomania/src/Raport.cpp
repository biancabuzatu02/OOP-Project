#include "../include/Raport.h"

// Constructor: Inițializează raportul cu datele cafenelei
Raport::Raport(const vector<Comanda>& comenzi, const vector<Angajat*>& angajati, const vector<shared_ptr<Produs>>& produse)
    : comenzi(comenzi), angajati(angajati), produse(produse) {}

// Calcularea veniturilor totale din comenzi
double Raport::calculeazaVenituri() const {
    double venituri = 0;
    for (const auto& comanda : comenzi) {
        venituri += comanda.getTotal();
    }
    return venituri;
}

// Calcularea salariilor totale ale angajaților
double Raport::calculeazaSalarii() const {
    double salarii = 0;
    for (const auto& angajat : angajati) {
        salarii += angajat->getSalariu();
    }
    return salarii;
}

// Calcularea cheltuielilor pentru stocuri
double Raport::calculeazaCheltuieliStoc() const {
    double cheltuieli = 0;
    for (const auto& produs : produse) {
        cheltuieli += produs->getPret() * produs->getCantitate();
    }
    return cheltuieli;
}

// Calcularea profitului net
double Raport::calculeazaProfitNet() const {
    return calculeazaVenituri() - (calculeazaSalarii() + calculeazaCheltuieliStoc());
}

// Generarea raportului detaliat
void Raport::genereazaRaport() const {
    cout << "----- Raport Zilnic -----" << endl;
    cout << "Venituri totale: " << calculeazaVenituri() << " lei" << endl;
    cout << "Salarii angajati: " << calculeazaSalarii() << " lei" << endl;
    cout << "Cheltuieli stocuri: " << calculeazaCheltuieliStoc() << " lei" << endl;
    cout << "Profit net: " << calculeazaProfitNet() << " lei" << endl;
    cout << "-------------------------" << endl;
}
