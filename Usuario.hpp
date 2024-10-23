#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Usuario {
private:
    int id;
    string nombre;
    string direccion;
    vector<string> historialCompras;

public:
    // Constructor
    Usuario(int id, const std::string& nombre, const std::string& direccion)
        : id(id), nombre(nombre), direccion(direccion) {}

    // Métodos para acceder a los atributos
    int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getDireccion() const { return direccion; }
    const vector<string>& getHistorialCompras() const { return historialCompras; }

    // Método para agregar una compra al historial
    void agregarCompra(const string& compra) {
        historialCompras.push_back(compra);
    }

    // Método para mostrar información del usuario
    void mostrarInformacion() const {
        cout << "ID: " << id << ", Nombre: " << nombre 
             << ", Dirección: " << direccion << endl;
        cout << "Historial de Compras: ";
        for (const auto& compra : historialCompras) {
            cout << compra << " ";
        }
        cout << endl;
    }
};

#endif
