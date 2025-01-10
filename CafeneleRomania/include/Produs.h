#ifndef PRODUS_H
#define PRODUS_H

#include <string>
#include <memory>

class Produs {
protected:
    std::string nume;
    double pretVanzare;    // Prețul de vânzare
    double costProductie;  // Costul de producție
    int stoc;

public:
    Produs(const std::string& nume, double pretVanzare, double costProductie, int stoc);

    virtual ~Produs() = default;

    virtual void afisareInformatii() const = 0; // Clasă abstractă

    // Metode accesor
    std::string getNume() const;
    double getPret() const;        // Metodă nouă pentru a accesa prețul
    int getCantitate() const;      // Metodă nouă pentru a accesa stocul
    void reduceStoc(int cantitate);
};

// Clasă derivată pentru băuturi
class Bautura : public Produs {
public:
    Bautura(const std::string& nume, double pretVanzare, double costProductie, int stoc);
    void afisareInformatii() const override;
};

// Clasă derivată pentru alimente
class Aliment : public Produs {
public:
    Aliment(const std::string& nume, double pretVanzare, double costProductie, int stoc);
    void afisareInformatii() const override;
};

#endif
