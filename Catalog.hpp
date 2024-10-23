#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include <iostream>

#include "Productos.hpp"

using namespace std;

class Catalog {
public:
    vector<Productos> productos;

    void loadProductsFromCSV(const string& filename);
    bool shouldDisplay(const Productos& product, const string& filter) const;
    void displayProducts(const string& filter) const;
};

#endif // CATALOG_H
