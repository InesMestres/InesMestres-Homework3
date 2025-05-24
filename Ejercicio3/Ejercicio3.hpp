#ifndef CLASES1Y2_HPP
#define CLASES1Y2_HPP

#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
#include <map>

//Clase 1

template <class T>
class Clase1{
    private:
        std::vector<T> vectorExistente;
    public:
        Clase1();
        Clase1(const std::vector<T>& vectorCreado);
        void agregar(const T& valor);
        std::string procesar();
};


//Clase 2

class Clase2{
    private:
        std::map<std::string, std::string> etiquetaValor;
    public:
        void asociar(const std::string& etiqueta, const std::string& valor);
        string construir();
        void imprimir();
};

#endif