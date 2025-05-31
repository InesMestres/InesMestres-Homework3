#ifndef CLASES1Y2_HPP
#define CLASES1Y2_HPP

#include <iostream>
#include <sstream>
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


template<typename T>
Clase1<T>::Clase1(): vectorExistente(){}

template<typename T>
Clase1<T>::Clase1(const std::vector<T>& vectorCreado): vectorExistente(vectorCreado){}

template<typename T>
void Clase1<T>::agregar(const T& valor){
    vectorExistente.push_back(valor);
    return;
}

template<typename T>
std::string Clase1<T>::procesar(){
    std::ostringstream stringOutput;

    if constexpr(std::is_same<T, std::string>::value){
        stringOutput << "[";
        for(int i = 0; i < vectorExistente.size(); i++){
            if (i > 0) stringOutput << ",";
            stringOutput << "\"" << vectorExistente[i];
        }
        stringOutput << "]";
    }

    if constexpr(std::is_same<T, double>:: value){
        stringOutput << "[";
        for(int i = 0; i < vectorExistente.size(); i++){
            if(i > 0) stringOutput << ", ";
            stringOutput << vectorExistente[i];
        }
        stringOutput << "]";
    }

    if constexpr(std::is_same<T, std::vector<int>> ::value){
        stringOutput << "[\n";
        for(int i = 0; i < vectorExistente.size(); i++){
            stringOutput << "[";
            for(int j = 0; j < vectorExistente[i].size(); j++){
                if(j > 0) stringOutput << ", ";
                stringOutput << vectorExistente[i][j];
            }
            stringOutput << "]";
            if(i < vectorExistente.size() - 1) stringOutput << ","; 
            stringOutput << "\n";
        }
        stringOutput << "]";
    }

    return stringOutput.str();
};

//Clase 2


class Clase2{
    private:
        std::map<std::string, std::string> etiquetaValor;
    public:
        void asociar(const std::string& etiqueta, const std::string& valor);
        std::string construir();
        void imprimir();
};

#endif
