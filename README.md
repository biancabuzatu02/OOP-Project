# OOP-Project
Proiect la materia POO, pentru gestionarea rețelei de cafenele în România

CafeneleRomania/
├── include/                 # Fișierele de antet (.h)
│   ├── PersonalCafenea.h    # Clasa de bază pentru personalul cafenelei
│   ├── Barista.h            # Clasa derivată pentru Barista
│   ├── ManagerCafenea.h     # Clasa derivată pentru Manager
│   ├── Ospatar.h            # Clasa derivată pentru Ospătar
│   ├── Produs.h             # Clasa de bază pentru produse
│   ├── Cafea.h              # Clasa derivată pentru tipuri de cafea
│   ├── Desert.h             # Clasa derivată pentru deserturi
│   ├── Comanda.h            # Gestionarea comenzilor
│   ├── Eveniment.h          # Gestionarea evenimentelor
│   ├── Stoc.h               # Gestionarea stocurilor
│   ├── Raport.h             # Generarea rapoartelor financiare
│   ├── CSVManager.h         # Import/export fișiere CSV
│   └── Util.h               # Funcții generale (dacă sunt necesare)
├── src/                     # Fișierele sursă (.cpp)
│   ├── PersonalCafenea.cpp  # Implementarea clasei de bază PersonalCafenea
│   ├── Barista.cpp          # Implementarea clasei Barista
│   ├── ManagerCafenea.cpp   # Implementarea clasei Manager
│   ├── Ospatar.cpp          # Implementarea clasei Ospătar
│   ├── Produs.cpp           # Implementarea clasei Produs
│   ├── Cafea.cpp            # Implementarea clasei Cafea
│   ├── Desert.cpp           # Implementarea clasei Desert
│   ├── Comanda.cpp          # Implementarea clasei Comanda
│   ├── Eveniment.cpp        # Implementarea clasei Eveniment
│   ├── Stoc.cpp             # Implementarea clasei Stoc
│   ├── Raport.cpp           # Implementarea clasei Raport
│   ├── CSVManager.cpp       # Implementarea funcțiilor pentru CSV-uri
│   └── main.cpp             # Punctul de intrare al aplicației
├── data/                    # Fișierele CSV pentru datele aplicației
│   ├── personal_ro.csv      # Personal - Limba română
│   ├── produse_ro.csv       # Produse - Limba română
│   ├── comenzi_ro.csv       # Comenzi - Limba română
│   ├── evenimente_ro.csv    # Evenimente - Limba română
│   ├── personal_en.csv      # Personal - Limba engleză
│   ├── produse_en.csv       # Produse - Limba engleză
│   ├── comenzi_en.csv       # Comenzi - Limba engleză
│   └── evenimente_en.csv    # Evenimente - Limba engleză
├── tests/                   # Teste unitare și matrice de testare
│   ├── test_PersonalCafenea.cpp  # Teste pentru PersonalCafenea
│   ├── test_Produs.cpp          # Teste pentru Produs
│   ├── test_Comanda.cpp         # Teste pentru Comanda
│   ├── test_Stoc.cpp            # Teste pentru Stoc
│   ├── test_CSVManager.cpp      # Teste pentru CSVManager
│   └── matrice_testare.txt      # Detalii ale matricei de testare
├── video/                   # Fișierul demo video
│   └── demo.mp4
├── doc/                     # Documentație și diagrama arhitecturii
│   ├── arhitectura_diagrama.png  # Diagramă arhitectură
│   ├── raport_financiar_exemplu.pdf # Exemplu raport financiar
│   └── README.md            # Documentație generală a proiectului
├── .gitignore               # Fișiere și directoare de exclus din Git
└── README.md                # Fișier principal de descriere pe GitHub
