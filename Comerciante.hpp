#ifndef COMERCIANTE_HPP
#define COMERCIANTE_HPP

#include <iostream>
#include <string>
using namespace std;

class Comerciante {
private:
    int id;
    string nombreComercio;
    double ganancias;

public:
    // Constructor
    Comerciante(int id, const std::string& nombreComercio)
        : id(id), nombreComercio(nombreComercio), ganancias(0) {}

    // Métodos para acceder a los atributos
    int getId() const { return id; }
    string getNombreComercio() const { return nombreComercio; }
    double getGanancias() const { return ganancias; }

    // Método para agregar ganancias
    void agregarGanancias(double cantidad) {
        if (cantidad > 0) {
            ganancias += cantidad;
        }
    }

    // Método para mostrar información del comerciante
    void mostrarInformacion() const {
        cout << "ID: " << id << ", Comercio: " << nombreComercio 
             << ", Ganancias: " << ganancias << endl;
    }
};

#endif
