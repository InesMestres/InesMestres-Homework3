#include "Ejercicio3.hpp"
using namespace std;

#include <vector>
#include <type_traits>
#include <string>
#include <map>

int main(){

    Clase1<double> claseDobles;
    claseDobles.agregar(1.3);
    claseDobles.agregar(2.1);
    claseDobles.agregar(3.2);
    string vectorDobles = claseDobles.procesar();

    Clase1<string> claseString;
    claseString.agregar("Hola");
    claseString.agregar("Mundo");
    string vectorString = claseString.procesar();

    Clase1<vector<int>> claseVector;
    claseVector.agregar({1, 2});
    claseVector.agregar({3, 4});
    string vectorVector = claseVector.procesar();

    Clase2 constructorJSON;
    constructorJSON.asociar("vec_doubles", vectorDobles);
    constructorJSON.asociar("palabras", vectorString);
    constructorJSON.asociar("listas", vectorVector);
    
    constructorJSON.imprimir();

    return 0;

}