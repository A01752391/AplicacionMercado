#ifndef PRODUCTOS_HPP
#define PRODUCTOS_HPP

#include <iostream>
#include <string>
using namespace std;

class Productos {
private:
    string name;        // Nombre
    string description; // Descripción
    double price;       // Precio
    string imagen;      // Archivo del producto
    string type;        // Fruta o Verdura
    string isSeasonal;  // Sí o No
    int cantidad;       // Cantidad en inventario

public:
    // Constructor
    Productos(const string& name, const string& description, double price,
              const string& imagen, const string& type, const string& isSeasonal, int cantidad)
        : name(name), description(description), price(price),
          imagen(imagen), type(type), isSeasonal(isSeasonal), cantidad(cantidad) {}

    // Métodos de acceso
    string getNombre() const { return name; }
    string getDescription() const { return description; }
    double getPrice() const { return price; }
    string getImagen() const { return imagen; }
    string getType() const { return type; }
    string getIsSeasonal() const { return isSeasonal; }
    int getCantidad() const { return cantidad; }

    // Método para mostrar información del producto
    void mostrarInformacion() const {
        cout << "Nombre: " << name << endl;
        cout << "Descripción: " << description << endl;
        cout << "Precio: " << price << endl;
        cout << "Imagen: " << imagen << endl;
        cout << "Tipo: " << type << endl;
        cout << "¿Es de temporada? " << isSeasonal << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
};

#endif // PRODUCTOS_HPP

