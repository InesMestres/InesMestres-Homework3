#include "Ejercicio3.hpp"
using namespace std;

#include <sstream>
#include <vector>
#include <type_traits>
#include <string>
#include <map>

//Funciones Clase 2

void Clase2::asociar(const std::string& etiqueta, const std::string& valor){
    etiquetaValor[etiqueta]= valor;
    return;
}

string Clase2::construir(){
    ostringstream stringOutput;
    stringOutput << "{\n";
    int contador = 0;
    int total = etiquetaValor.size();
    for(const auto& [etiqueta, valor]: etiquetaValor){
        stringOutput << "\"" << etiqueta << "\"  : " << valor;  
        if(contador < total - 1){
            stringOutput << ",";
        }
        stringOutput << "\n";
        contador++;
    }
    stringOutput << "}";
    return stringOutput.str();
}

void Clase2::imprimir(){
    cout << construir() << endl;
}
