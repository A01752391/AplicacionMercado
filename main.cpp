#include <iostream>
#include "Catalog.hpp"

using namespace std;

void showMenu() {
    cout << "Elige una opción:\n";
    cout << "1. Ver todo el inventario\n";
    cout << "2. Ver solo frutas\n";
    cout << "3. Ver solo verduras\n";
    cout << "4. Ver solo productos de temporada\n";
    cout << "0. Salir" << endl;
}

int main() {
    Catalog catalog;
    catalog.loadProductsFromCSV("/workspaces/AplicacionMercado/productos.csv");

    int choice;
    do {
        showMenu();
        cout << endl;
        cout << "Opción: ";
        cin >> choice;

        switch (choice) {
            case 1:
                catalog.displayProducts(""); // Mostrar todo
                cout << endl;
                break;
            case 2:
                catalog.displayProducts("frutas");
                cout << endl;
                break;
            case 3:
                catalog.displayProducts("verduras");
                cout << endl;
                break;
            case 4:
                catalog.displayProducts("temporada");
                cout << endl;
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }

    } while (choice != 0);

    return 0;
}
