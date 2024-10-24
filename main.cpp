#include <iostream>
#include <vector>
#include "Catalog.hpp"
#include "Usuario.hpp"
#include "Comerciante.hpp"
#include "Pedido.hpp"

using namespace std;

void showMainMenu() {
    cout << "Elige tu rol:\n";
    cout << "1. Usuario\n";
    cout << "2. Comerciante\n";
    cout << "0. Salir" << endl;
}

void showUserMenu(Catalog& catalog) {
    int choice;
    do {
        cout << "Elige una opción:\n";
        cout << "1. Ver todo el inventario\n";
        cout << "2. Ver solo frutas\n";
        cout << "3. Ver solo verduras\n";
        cout << "4. Ver solo productos de temporada\n";
        cout << "5. Crear un pedido\n";
        cout << "0. Salir" << endl;

        cout << "Opción: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                cout << " ****** Todo el inventario ****** " << endl;
                catalog.displayProducts(""); // Mostrar todo
                cout << endl;
                break;
            case 2:
                cout << " ****** Frutas ****** " << endl;
                catalog.displayProducts("frutas");
                cout << endl;
                break;
            case 3:
                cout << " ****** Verduras ****** " << endl;
                catalog.displayProducts("verduras");
                cout << endl;
                break;
            case 4:
                cout << " ****** De temporada ****** " << endl;
                catalog.displayProducts("temporada");
                cout << endl;
                break;
            case 5: {
                // Crear un pedido
                int userId;
                cout << "Ingrese ID de usuario: ";
                cin >> userId;

                string pedido;
                cout << "Producto elegido: ";
                cin >> pedido;

                int cant;
                cout << "Cantidad: ";
                cin >> cant;

                // Aquí se debería buscar el usuario y sus productos
                vector<Productos> productosComprados; // Implementar la lógica para seleccionar productos...

                Pedido newOrder(1, Usuario(userId, "Nombre Usuario", "Dirección Usuario"), productosComprados, "Pendiente", "Tarjeta");
                cout << "Pedido creado.\n" << endl;
                break;
            }
            case 0:
                cout << "Saliendo como usuario...\n";
                cout << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (choice != 0);
}

void showMerchantMenu() {
    int choice;
    do {
        cout << "Elige una opción:\n";
        cout << "1. Ver ganancias\n";
        cout << "2. Ver inventario\n";
        cout << "0. Salir" << endl;

        cout << "Opción: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                cout << "Aquí se mostrarían las ganancias del comerciante.\n";
                cout << endl;
                break;
            case 2:
                cout << "Aquí se mostraría el inventario del comerciante.\n";
                // Crear un pedido
                int userId;
                cout << "Ingrese ID de usuario: ";
                cin >> userId;
                
                catalog.displayProducts("temporada");
                cout << endl;
                break;
            case 0:
                cout << "Saliendo como comerciante...\n";
                cout << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (choice != 0);
}

int main() {
    Catalog catalog;
    catalog.loadProductsFromCSV("/Users/mirandaurbansolano/App/AplicacionMercado/productos.csv");

    int roleChoice;
    do {
        showMainMenu();
        cout << "Opción: ";
        cin >> roleChoice;
        cout << endl;

        switch (roleChoice) {
            case 1:
                cout << " -------- Bienvenido, Usuario ------- " << endl;
                cout << endl;
                showUserMenu(catalog);
                break;
            case 2:
                cout << " -------- Bienvenido, Comerciante ------- " << endl;
                showMerchantMenu();
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (roleChoice != 0);

    return 0;
}
