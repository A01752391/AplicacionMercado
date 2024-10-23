#ifndef PRODUCTOS_HPP
#define PRODUCTOS_HPP

#include <iostream>
using namespace std;

class Productos {
public:
    string name;
    string description;
    double price;
    string imagen;
    string type;       // Fruta o Verdura
    string isSeasonal; // Si o No

    Productos(const string& name, string& description, double price,
              const string& imagen, const string& type, const string& isSeasonal)
        : name(name), description(description), price(price),
          imagen(imagen), type(type), isSeasonal(isSeasonal) {}
};

#endif // PRODUCTOS_HPP

