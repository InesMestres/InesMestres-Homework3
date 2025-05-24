#include "Ejercicio3.hpp"
using namespace std;

#include <vector>
#include <type_traits>
#include <string>
#include <map>

//Funciones Clase 1

template<typename T>
Clase1<T>::Clase1(): vector(){}

template<typename T>
Clase1<T>::Clase1(const vector<T> vectorExistente): vector(vectorExistente){}

template<typename T>
void Clase1<T>::agregar(const T& valor){
    Vector.push_back(valor);
    return;
}

template<typename T>
std::string Clase1<T>::procesar(){
    string ostringstream stringOutput;

    if constexpr(is_same<T, string>:: value){
        for(int i = 0; i < Vector.size(); i++){
            stringOutput << vector[i];
        }
    }

     if constexpr(is_same<T, double>:: value){
        for(int i = 0; i < Vector.size(), i++){
            stringOutput << vector[i];
        }
     }

    if constexpr(is_same<T, vector<int>>:: value){
        for(int i = 0; i < Vector.size(), i++){
            stringOutput += "[";
            for(int j = 0; j < Vector[i].size(), j++){
                stringOutput << vector[i][j];
            }
            stringOutput << "]";
        }
        return stringOutput;
    }
}



//Funciones Clase 2

void Clase2::asociar(const std::string& etiqueta, const std::string& valor){
    etiquetaValor[etiqueta]=valor;
    return;
}

string Clase2::construir(){
    ostringstream stringOutput = "{\n";
    int contador = 0;
    for(const auto& [etiqueta, valor]: etiquetaValor){
        stringOutput << "[" << clave << "] : " << valor << "\n";  
    }
    stringOutput << "}";
    return stringOutput.str();
}

void Clase2::imprimir(){
    cout << construir() << endl;
}
