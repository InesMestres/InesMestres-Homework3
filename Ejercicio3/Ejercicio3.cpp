#include "Ejercicio3.hpp"
using namespace std;

#include <sstream>
#include <vector>
#include <type_traits>
#include <string>
#include <map>

//Funciones Clase 1

template<typename T>
Clase1<T>::Clase1(): vectorExistente(){}

template<typename T>
Clase1<T>::Clase1(const vector<T>& vectorCreado): vectorExistente(vectorCreado){}

template<typename T>
void Clase1<T>::agregar(const T& valor){
    vectorExistente.push_back(valor);
    return;
}

template<typename T>
std::string Clase1<T>::procesar(){
    ostringstream stringOutput;

    if constexpr(is_same<T, string>:: value){
        stringOutput << "[";
        for(int i = 0; i < vectorExistente.size(); i++){
            stringOutput << vectorExistente[i];
        }
        stringOutput << "]";
    }

    if constexpr(is_same<T, double>:: value){
        stringOutput << "[";
        for(int i = 0; i < vectorExistente.size(), i++){
            stringOutput << vectorExistente[i];
        }
        stringOutput << "]";
    }

    if constexpr(is_same<T, vectorExistente<int>>:: value){
        for(int i = 0; i < vectorExistente.size(), i++){
            stringOutput << "[";
            for(int j = 0; j < vectorExistente[i].size(), j++){
                stringOutput << vectorExistente[i][j];
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
