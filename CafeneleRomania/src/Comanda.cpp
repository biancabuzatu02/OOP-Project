#include "../include/Comanda.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor
Comanda::Comanda(const string& client, bool clientFidel)
    : client(client), total(0.0), reducere(0.0), clientFidel(clientFidel) {}

// Adăugare produs în comandă
void Comanda::adaugaProdus(const std::shared_ptr<Produs>& produs, int cantitate) {
    produse.emplace_back(produs, cantitate);
    total += produs->getPret() * cantitate; // Calculăm totalul comenzii
}


// Aplicare reducere procentuală
void Comanda::aplicaReducereProcentuala(double procent) {
    if (procent < 0 || procent > 100) {
        throw invalid_argument("Procentul reducerii trebuie să fie între 0 și 100.");
    }
    reducere += total * (procent / 100);
}

// Aplicare reducere pentru clienți fideli
void Comanda::aplicaReducereFideli() {
    if (clientFidel) {
        reducere += total * 0.1; // Reducere de 10% pentru clienți fideli
    }
}

// Calcul total cu reducere
double Comanda::calculeazaTotalCuReducere() const {
    return total - reducere;
}

// Afișare comandă
void Comanda::afiseazaComanda() const {
    cout << "Client: " << client << endl;
    cout << "Produse comandate:" << endl;
    for (const auto& p : produse) {
        cout << "- " << p.first->getNume() << " x" << p.second
             << " = " << p.first->getPret() * p.second << " lei" << endl;
    }
    cout << "Total (fără reduceri): " << total << " lei" << endl;
    cout << "Reduceri aplicate: " << reducere << " lei" << endl;
    cout << "Total (cu reduceri): " << calculeazaTotalCuReducere() << " lei" << endl;
}

// Getter pentru total
double Comanda::getTotal() const {
    return total;
}

// Getter pentru numele clientului
string Comanda::getClient() const {
    return client;
}

// Setter pentru statusul de client fidel
void Comanda::setClientFidel(bool fidelitate) {
    clientFidel = fidelitate;
}
