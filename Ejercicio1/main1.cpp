#include "Ejercicio1.hpp"

int main(){

    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3);
    Presion presion(101.3f, 5.8f, 6.1f);
    SaveFlightData DataVuelo (posicion, presion);
    
    ofstream out("Data.bin", ios::binary);
    if (out.is_open()){
        DataVuelo.serializar(out);
    }
    else{
        cout << "Error al abrir archivo para serializar." << endl;
        return 0;
    }

    out.close();

    ifstream in("Data.bin", ios::binary);
    if (in.is_open()){
        DataVuelo.deserializar(in);
    }
    else{
        cout << "Error al abrir archivo para deserializar." << endl;
        return 0;
    }

    in.close();
    
    Data.imprimir();

}