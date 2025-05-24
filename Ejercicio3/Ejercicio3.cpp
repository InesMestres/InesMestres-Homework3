#include "Ejercicio3.hpp"
using namespace std;

#include <sstream>
#include <vector>
#include <type_traits>
#include <string>
#include <map>

//Funciones Clase 1

template<typename T>
Clase1<T>::Clase1(): vector(){}

template<typename T>
Clase1<T>::Clase1(const vector<T>& vectorExistente): vector(vectorExistente){}

template<typename T>
void Clase1<T>::agregar(const T& valor){
    Vector.push_back(valor);
    return;
}

template<typename T>
std::string Clase1<T>::procesar(){
    ostringstream stringOutput;

    if constexpr(is_same<T, string>:: value){
        stringOutput << "[";
        for(int i = 0; i < Vector.size(); i++){
            stringOutput << Vector[i];
        }
        stringOutput << "]";
    }

    if constexpr(is_same<T, double>:: value){
        stringOutput << "[";
        for(int i = 0; i < Vector.size(), i++){
            stringOutput << Vector[i];
        }
        stringOutput << "]";
    }

    if constexpr(is_same<T, Vector<int>>:: value){
        for(int i = 0; i < Vector.size(), i++){
            stringOutput << "[";
            for(int j = 0; j < Vector[i].size(), j++){
                stringOutput << Vector[i][j];
            }
        stringOutput << "]";
        }
    }
    return stringOutput.str();
}



//Funciones Clase 2

void Clase2::asociar(const std::string& etiqueta, const std::string& valor){
    etiquetaValor[etiqueta]= valor;
    return;
}

void Clase2::construir(){
    ostringstream stringOutput;
    stringOutput << "{\n";
    int contador = 0;
    for(const auto& [etiqueta, valor]: etiquetaValor){
        stringOutput << "[" << etiqueta << "] : " << valor << "\n";  
    }
    stringOutput << "}";
    return;
}

void Clase2::imprimir(){
    cout << construir() << endl;
}
