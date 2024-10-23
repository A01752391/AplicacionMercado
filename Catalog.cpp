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

        getline(ss, name, ',');
        getline(ss, description, ',');
        ss >> price;
        ss.ignore(); // Ignorar la coma
        getline(ss, imagen, ',');
        getline(ss, type, ',');
        getline(ss, isSeasonal);

        productos.emplace_back(name, description, price, imagen, type, isSeasonal);
    }
}

void Catalog::displayProducts(const string& filter) const {
    if (productos.empty()) {
        cout << "No hay productos para mostrar." << endl;
        return;
    }

    for (const auto& product : productos) {
        bool show = true;

        if (filter == "frutas" && product.type != "Fruta") {
            show = false;
        } else if (filter == "verduras" && product.type != "Verdura") {
            show = false;
        } else if (filter == "temporada" && product.isSeasonal != "Si") {
            show = false;
        }

        if (show) {
            // Formato: Nombre | Precio | Imagen | Descripción
            cout << product.name << " | $" << product.price 
                 << " | " << product.imagen 
                 << " | " << product.description << endl;
        }
    }
}

