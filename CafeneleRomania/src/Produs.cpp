#include "../include/Produs.h"
#include <iostream>
#include <stdexcept> // pentru runtime_error

using namespace std;

// Constructor clasa de bază Produs
Produs::Produs(const string& nume, double pretVanzare, double costProductie, int stoc)
    : nume(nume), pretVanzare(pretVanzare), costProductie(costProductie), stoc(stoc) {}

// Metode accesor pentru clasa de bază
string Produs::getNume() const {
    return nume;
}

double Produs::getPret() const {
    return pretVanzare;
}

int Produs::getCantitate() const {
    return stoc;
}

// Metoda pentru reducerea stocului
void Produs::reduceStoc(int cantitate) {
    if (cantitate > stoc) {
        throw runtime_error("Stoc insuficient!"); // Aruncă excepție dacă stocul e insuficient
    }
    stoc -= cantitate; // Reduce cantitatea din stoc
}

// Implementare clasa derivată Bautura
Bautura::Bautura(const string& nume, double pretVanzare, double costProductie, int stoc)
    : Produs(nume, pretVanzare, costProductie, stoc) {}

// Suprascriere metoda afisareInformatii pentru Bautura
void Bautura::afisareInformatii() const {
    cout << "Bautura: " << nume 
         << ", Pret: " << pretVanzare 
         << ", Cost: " << costProductie 
         << ", Stoc: " << stoc << endl;
}

// Implementare clasa derivată Aliment
Aliment::Aliment(const string& nume, double pretVanzare, double costProductie, int stoc)
    : Produs(nume, pretVanzare, costProductie, stoc) {}

// Suprascriere metoda afisareInformatii pentru Aliment
void Aliment::afisareInformatii() const {
    cout << "Aliment: " << nume 
         << ", Pret: " << pretVanzare 
         << ", Cost: " << costProductie 
         << ", Stoc: " << stoc << endl;
}
