#include <iostream>
#include <string>
#include "../include/Angajati.h" // Assuming you have this header for managing employees.

using namespace std;

void gestionareProduse() {
    int optiuneProduse = 0;
    while (optiuneProduse != 4) {
        cout << "\n=== Gestionare Produse si Stocuri ===" << endl;
        cout << "1. Adauga produs" << endl;
        cout << "2. Listare produse" << endl;
        cout << "3. Sterge produs" << endl;
        cout << "4. Inapoi la meniul principal" << endl;
        cout << "Selectati o optiune: ";
        cin >> optiuneProduse;

        switch (optiuneProduse) {
            case 1:
                cout << "Adauga produs in stoc..." << endl;
                // Add your logic for adding a product here
                break;
            case 2:
                cout << "Listare produse disponibile..." << endl;
                // Add your logic for listing products here
                break;
            case 3:
                cout << "Sterge produs din stoc..." << endl;
                // Add your logic for deleting a product here
                break;
            case 4:
                cout << "Revenire la meniul principal..." << endl;
                break;
            default:
                cout << "Optiune invalida!" << endl;
        }
    }
}

void gestionareComenzi() {
    int optiuneComenzi = 0;
    while (optiuneComenzi != 4) {
        cout << "\n=== Gestionare Comenzi ===" << endl;
        cout << "1. Plaseaza comanda" << endl;
        cout << "2. Vizualizeaza comenzi" << endl;
        cout << "3. Modifica comanda" << endl;
        cout << "4. Inapoi la meniul principal" << endl;
        cout << "Selectati o optiune: ";
        cin >> optiuneComenzi;

        switch (optiuneComenzi) {
            case 1:
                cout << "Plaseaza o noua comanda..." << endl;
                // Add your logic for placing an order here
                break;
            case 2:
                cout << "Vizualizeaza comenzile plasate..." << endl;
                // Add your logic for viewing orders here
                break;
            case 3:
                cout << "Modifica o comanda existenta..." << endl;
                // Add your logic for modifying an order here
                break;
            case 4:
                cout << "Revenire la meniul principal..." << endl;
                break;
            default:
                cout << "Optiune invalida!" << endl;
        }
    }
}

void organizareEvenimente() {
    int optiuneEvenimente = 0;
    while (optiuneEvenimente != 4) {
        cout << "\n=== Organizare Evenimente Speciale ===" << endl;
        cout << "1. Adauga eveniment" << endl;
        cout << "2. Vizualizeaza evenimente" << endl;
        cout << "3. Modifica eveniment" << endl;
        cout << "4. Inapoi la meniul principal" << endl;
        cout << "Selectati o optiune: ";
        cin >> optiuneEvenimente;

        switch (optiuneEvenimente) {
            case 1:
                cout << "Adauga un nou eveniment..." << endl;
                // Add your logic for adding an event here
                break;
            case 2:
                cout << "Vizualizeaza evenimentele programate..." << endl;
                // Add your logic for viewing events here
                break;
            case 3:
                cout << "Modifica detaliile evenimentului..." << endl;
                // Add your logic for modifying an event here
                break;
            case 4:
                cout << "Revenire la meniul principal..." << endl;
                break;
            default:
                cout << "Optiune invalida!" << endl;
        }
    }
}

void generareRaport() {
    int optiuneRaport = 0;
    while (optiuneRaport != 3) {
        cout << "\n=== Generare Raport Financiar ===" << endl;
        cout << "1. Generare raport zilnic" << endl;
        cout << "2. Generare raport lunar" << endl;
        cout << "3. Inapoi la meniul principal" << endl;
        cout << "Selectati o optiune: ";
        cin >> optiuneRaport;

        switch (optiuneRaport) {
            case 1:
                cout << "Generare raport zilnic..." << endl;
                // Add your logic for generating daily report here
                break;
            case 2:
                cout << "Generare raport lunar..." << endl;
                // Add your logic for generating monthly report here
                break;
            case 3:
                cout << "Revenire la meniul principal..." << endl;
                break;
            default:
                cout << "Optiune invalida!" << endl;
        }
    }
}

int main() {
    string oras;
    cout << "Introduceti orasul (Bucuresti, Cluj-Napoca, Timisoara, Iasi, Brasov): ";
    cin >> oras;

    int optiune = 0;
    while (optiune != 6) {
        cout << "\n=== Meniu Principal ===" << endl;
        cout << "1. Gestionare Angajati" << endl;
        cout << "2. Gestionare Produse si Stocuri" << endl;
        cout << "3. Gestionare Comenzi" << endl;
        cout << "4. Organizare Evenimente Speciale" << endl;
        cout << "5. Generare Raport Financiar" << endl;
        cout << "6. Iesire" << endl;
        cout << "Selectati o optiune: ";
        cin >> optiune;

        switch (optiune) {
            case 1:
                gestioneazaAngajati(oras); // Funcția de gestionare angajați
                break;
            case 2:
                gestionareProduse(); // Function for managing products and stock
                break;
            case 3:
                gestionareComenzi(); // Function for managing orders
                break;
            case 4:
                organizareEvenimente(); // Function for organizing events
                break;
            case 5:
                generareRaport(); // Function for generating financial reports
                break;
            case 6:
                cout << "Iesire din program. La revedere!" << endl;
                break;
            default:
                cout << "Optiune invalida. Incercati din nou!" << endl;
        }
    }

    return 0;
}
