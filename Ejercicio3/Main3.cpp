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
    claseString.agregar({1, 2});
    claseString.agregar({3, 4});
    string vectorVector = claseVector.procesar();

    Clase2 constructorJSON;
    constructorJSON.asociar("Vector Dobles", vectorDobles);
    constructorJSON.asociar("Vector String", vectorString);
    constructorJSON.asociar("Matriz", vectorVector);
    
    constructorJSON.imprimir();
    


}