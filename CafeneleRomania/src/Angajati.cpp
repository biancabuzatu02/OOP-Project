#include "../include/Angajati.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
#include "../include/Angajati.h"

// Constructor pentru Barista
Barista::Barista(const string& nume, double salariu, int oraInceput, int oraSfarsit)
    : Angajat(nume, "Barista", salariu, oraInceput, oraSfarsit) {}

// Constructor pentru Manager
Manager::Manager(const string& nume, double salariu, int oraInceput, int oraSfarsit)
    : Angajat(nume, "Manager", salariu, oraInceput, oraSfarsit) {}

// Constructor pentru Ospatar
Ospatar::Ospatar(const string& nume, double salariu, int oraInceput, int oraSfarsit)
    : Angajat(nume, "Ospatar", salariu, oraInceput, oraSfarsit) {}
string Angajat::getNume() const { return nume; }
string Angajat::getFunctie() const { return functie; }
double Angajat::getSalariu() const { return salariu; }
void Barista::afisareInformatii() const {
    cout << "Barista: " << nume << ", Salariu: " << salariu 
         << ", Program: " << oraInceput << "-" << oraSfarsit << endl;
}

void Manager::afisareInformatii() const {
    cout << "Manager: " << nume << ", Salariu: " << salariu 
         << ", Program: " << oraInceput << "-" << oraSfarsit << endl;
}

void Ospatar::afisareInformatii() const {
    cout << "Ospatar: " << nume << ", Salariu: " << salariu 
         << ", Program: " << oraInceput << "-" << oraSfarsit << endl;
}

// Funcție pentru gestionarea angajaților
void gestioneazaAngajati(const string& oras) {
    vector<shared_ptr<Angajat>> angajati;
    string fisierAngajati = "CafeneleRomania/data/" + oras + "/Angajati.csv";

    // Citirea datelor din CSV
    ifstream fisierCitire(fisierAngajati);
    if (fisierCitire.is_open()) {
        string linie;
        getline(fisierCitire, linie); // Ignorăm antetul

        while (getline(fisierCitire, linie)) {
            stringstream ss(linie);
            vector<string> valori;
            string valoare;

            while (getline(ss, valoare, ',')) {
                valori.push_back(valoare);
            }

            if (valori.size() < 5) continue;

            string nume = valori[0];
            string functie = valori[1];
            double salariu = stod(valori[2]);
            int oraInceput = stoi(valori[3]);
            int oraSfarsit = stoi(valori[4]);

            if (functie == "Barista") {
                angajati.push_back(make_shared<Barista>(nume, salariu, oraInceput, oraSfarsit));
            } else if (functie == "Manager") {
                angajati.push_back(make_shared<Manager>(nume, salariu, oraInceput, oraSfarsit));
            } else if (functie == "Ospatar") {
                angajati.push_back(make_shared<Ospatar>(nume, salariu, oraInceput, oraSfarsit));
            }
        }
        fisierCitire.close();
    } else {
        cout << "Fișierul CSV pentru angajați nu a fost găsit. Se va crea unul nou." << endl;
    }

    int optiune = 0;
    while (optiune != 4) {
        cout << "\n=== Gestionare Angajati ===" << endl;
        cout << "1. Adaugare angajat" << endl;
        cout << "2. Stergere angajat" << endl;
        cout << "3. Listare angajati" << endl;
        cout << "4. Inapoi la meniul principal" << endl;
        cout << "Selectati o optiune: ";
        cin >> optiune;

        switch (optiune) {
            case 1: { // Adaugare angajat
    string nume, functie;
    double salariu;
    int oraInceput, oraSfarsit;

    cout << "Introduceti numele angajatului: ";
    cin >> nume;
    cout << "Introduceti functia (Barista, Manager, Ospatar): ";
    cin >> functie;
    cout << "Introduceti salariul: ";
    cin >> salariu;
    cout << "Introduceti ora de inceput: ";
    cin >> oraInceput;
    cout << "Introduceti ora de sfarsit: ";
    cin >> oraSfarsit;

    shared_ptr<Angajat> angajat;
    if (functie == "Barista") {
        angajat = make_shared<Barista>(nume, salariu, oraInceput, oraSfarsit);
    } else if (functie == "Manager") {
        angajat = make_shared<Manager>(nume, salariu, oraInceput, oraSfarsit);
    } else if (functie == "Ospatar") {
        angajat = make_shared<Ospatar>(nume, salariu, oraInceput, oraSfarsit);
    } else {
        cout << "Functie invalida! Angajatul nu a fost adaugat." << endl;
        break;
    }

    angajati.push_back(angajat);

    // Scriere în CSV
    ofstream fisierScriere(fisierAngajati, ios::app);
    if (fisierScriere.is_open()) {
        fisierScriere << nume << "," << functie << "," << salariu << ","
                      << oraInceput << "," << oraSfarsit << endl;
        fisierScriere.close();
        cout << "Angajatul " << nume << " a fost adaugat cu succes in fisierul CSV." << endl;
    } else {
        cout << "Eroare la deschiderea fișierului pentru scriere." << endl;
    }
    break;
}

            case 2: { // Stergere angajat
                string nume;
                cout << "Introduceti numele angajatului de sters: ";
                cin >> nume;

                auto it = remove_if(angajati.begin(), angajati.end(),
                    [&nume](const shared_ptr<Angajat>& angajat) {
                        return angajat->getNume() == nume;
                    });

                if (it != angajati.end()) {
                    angajati.erase(it, angajati.end());
                    cout << "Angajatul a fost șters." << endl;

                    // Rescriere în CSV
                    ofstream fisierScriere(fisierAngajati);
                    if (fisierScriere.is_open()) {
                        fisierScriere << "Nume,Functie,Salariu,OraInceput,OraSfarsit\n";
                        for (const auto& angajat : angajati) {
                            fisierScriere << angajat->getNume() << "," << angajat->getFunctie() << ","
                                          << angajat->getSalariu() << "," << angajat->getOraInceput() << ","
                                          << angajat->getOraSfarsit() << endl;
                        }
                        fisierScriere.close();
                    } else {
                        cout << "Eroare la deschiderea fișierului pentru rescriere." << endl;
                    }
                } else {
                    cout << "Angajatul nu a fost găsit." << endl;
                }
                break;
            }
            case 3: { // Listare angajati
                if (angajati.empty()) {
                    cout << "Nu există angajați." << endl;
                } else {
                    for (const auto& angajat : angajati) {
                        angajat->afisareInformatii();
                    }
                }
                break;
            }
            case 4:
                cout << "Revenire la meniul principal..." << endl;
                break;
            default:
                cout << "Optiune invalida. Va rugam sa incercati din nou." << endl;
        }
    }
}

int Angajat::getOraInceput() const {
    return oraInceput;
}

int Angajat::getOraSfarsit() const {
    return oraSfarsit;
}
Angajat::Angajat(const string& nume, const string& functie, double salariu, int oraInceput, int oraSfarsit)
    : nume(nume), functie(functie), salariu(salariu), oraInceput(oraInceput), oraSfarsit(oraSfarsit) {}

