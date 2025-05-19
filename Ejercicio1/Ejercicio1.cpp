#include "Ejercicio1.hpp"

//FUNCIONES Interfaz IMediciones:

virtual void serializar(out: of_stream&){
        out.write(reinterpret_cast<char*>(x), sizeof(int));
}

virtual void deserializar(in: of_stream&){
        in.read(reinterpret_cast<char*>(x), sizeof(int));
}


//FUNCIONES Clase abstracta MedicionBase

float MedicionBase::getTiempo(){
    return tiempo;
}

void MedicionBase::imprimir(){
    cout << "El tiempo de medición fue " << tiempo << endl;
}


//FUNCIONES Clase SaveFlightData
   
SaveFlightData(p: const Posicion&, q: const Presion&);

void saveFlightData::serializar(out: ofstream&){
    out.write(reinterpret_cast<const char*>())
}

void saveFlightData::deserializar(in: ofstream&){

}

void saveFlightData::imprimir(){
    cout << "Los datos del vuelo son: Posición: " << posicion << " . Presión: " << presion << ". El tiempo de estas mediciones es: " << tiempo << endl;
}
