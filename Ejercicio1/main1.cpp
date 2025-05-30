#include "Ejercicio1.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main(){

    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3);
    Presion presion(101.3f, 5.8f, 6.1f);
    SaveFlightData DataVuelo(posicion, presion);
    
    ofstream out("Data.bin", ios::binary);
    if (out.is_open()){
        DataVuelo.serializar(out);
        out.close();
    }
    else{
        cout << "Error al abrir archivo para serializar." << endl;
        return 1;
    }

    SaveFlightData DataVueloLeida;
    ifstream in("Data.bin", ios::binary);
    if (in.is_open()){
        DataVueloLeida.deserializar(in);
        in.close();
    }
    else{
        cout << "Error al abrir archivo para deserializar." << endl;
        return 1;
    }

    cout << "Datos del vuelo deserializados: " << endl;
    DataVueloLeida.imprimir();
    return 0;

}