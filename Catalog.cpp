#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Catalog.hpp"

using namespace std;

void Catalog::loadProductsFromCSV(const std::string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        return;
    }

    string line;
    // Omitir la primera línea (cabecera)
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string name, description, imagen, type, isSeasonal;
        double price;
        int cantidad;

        getline(ss, name, ',');
        getline(ss, description, ',');
        ss >> price;
        ss.ignore(); // Ignorar la coma
        getline(ss, imagen, ',');
        getline(ss, type, ',');
        getline(ss, isSeasonal);

        // Verificar si la línea se ha leído correctamente
        if (!name.empty() && !description.empty() && price >= 0) {
            productos.emplace_back(name, description, price, imagen, type, isSeasonal, cantidad);
        }
    }
}

bool Catalog::shouldDisplay(const Productos& product, const string& filter) const {
    if (filter == "frutas" && product.getType() != "Fruta") {
        return false;
    }
    if (filter == "verduras" && product.getType() != "Verdura") {
        return false;
    }
    if (filter == "temporada" && product.getIsSeasonal() != "Si") {
        return false;
    }
    return true;
}

void Catalog::displayProducts(const string& filter) const {
    if (productos.empty()) {
        cout << "No hay productos para mostrar." << endl;
        return;
    }

    for (const auto& product : productos) {
        if (shouldDisplay(product, filter)) {
            // Formato: Nombre | Precio | Imagen | Descripción
            cout << product.getNombre() << " | $" << product.getPrice() << endl;
            cout << product.getImagen()  << " | " << product.getDescription() << endl;
            cout << endl;
        }
    }
}
