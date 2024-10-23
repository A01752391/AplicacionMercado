#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include "Usuario.hpp"
#include "Productos.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pedido {
private:
    int id;
    Usuario usuario;
    vector<Productos> productosComprados;
    string estado; // e.g., "Pendiente", "Completado", "Cancelado"
    string metodoPago;

public:
    // Constructor
    Pedido(int id, const Usuario& usuario, const vector<Productos>& productosComprados,
           const string& estado, const string& metodoPago)
        : id(id), usuario(usuario), productosComprados(productosComprados),
          estado(estado), metodoPago(metodoPago) {}

    // Métodos de acceso
    int getId() const { return id; }
    const Usuario& getUsuario() const { return usuario; }
    const vector<Productos>& getProductosComprados() const { return productosComprados; }
    string getEstado() const { return estado; }
    string getMetodoPago() const { return metodoPago; }

    // Método para actualizar el estado del pedido
    void actualizarEstado(const string& nuevoEstado) {
        estado = nuevoEstado;
    }

    // Método para mostrar información del pedido
    void mostrarInformacion() const {
        cout << "ID del Pedido: " << id << endl;
        cout << "Usuario: " << usuario.getNombre() << endl; // Asumiendo que Usuario tiene un método getNombre()
        cout << "Estado: " << estado << endl;
        cout << "Método de Pago: " << metodoPago << endl;
        cout << "Productos Comprados: ";
        for (const auto& producto : productosComprados) {
            cout << producto.getNombre() << " "; // Asumiendo que Producto tiene un método getNombre()
        }
        cout << endl;
    }
};

#endif
