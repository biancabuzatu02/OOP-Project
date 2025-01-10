#ifndef ANGAJATI_H
#define ANGAJATI_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>

using namespace std;

// Clasa de bază: Angajat (Abstractă)
class Angajat {
protected:
    string nume;
    string functie;
    double salariu;
    int oraInceput;
    int oraSfarsit;

public:
    Angajat(const string& nume, const string& functie, double salariu, int oraInceput, int oraSfarsit);
    virtual ~Angajat() = default; // Destructor virtual pentru distrugerea corectă a obiectelor derivate

    virtual void afisareInformatii() const = 0; // Funcție virtuală pură

    // Getters
    string getNume() const;
    string getFunctie() const;
    double getSalariu() const;
    int getOraInceput() const;
    int getOraSfarsit() const;
};

// Clase derivate
class Barista : public Angajat {
public:
    Barista(const string& nume, double salariu, int oraInceput, int oraSfarsit);
    void afisareInformatii() const override;
};

class Manager : public Angajat {
public:
    Manager(const string& nume, double salariu, int oraInceput, int oraSfarsit);
    void afisareInformatii() const override;
};

class Ospatar : public Angajat {
public:
    Ospatar(const string& nume, double salariu, int oraInceput, int oraSfarsit);
    void afisareInformatii() const override;
};

// Gestionare Angajati
void gestioneazaAngajati(const string& oras);

#endif // ANGAJATI_H
