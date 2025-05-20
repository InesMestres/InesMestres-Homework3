#include "Ejercicio1.hpp"



//FUNCIONES CLASE ABSTRACTA MEDICIONBASE

MedicionBase::MedicionBase(): tiempoMedicion(std::make_unique<float>(0)){}

MedicionBase::MedicionBase(float tiempo): tiempoMedicion(make_unique<float>(tiempo)){}

float MedicionBase::getTiempo() const{
    return *tiempoMedicion;
}

void MedicionBase::imprimir() const{
    cout << "El tiempo de medición fue " << getTiempo() << endl;
}



//FUNCIONES PRESION

Presion::Presion(): presionEstatica(0), presionDinamica(0), MedicionBase(0){}

Presion::Presion(float p, float q, float t): presionEstatica(p), presionDinamica(q), MedicionBase(t){}

void Presion::serializar(ofstream& out) const{
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(float));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(float));
    out.write(reinterpret_cast<const char*>(&tiempoMedicion.get()), sizeof(float));
}

void Presion::deserializar(ifstream& in) override{
    in.read(reinterpret_cast<const char*>(&presionEstatica), sizeof(float));
    in.read(reinterpret_cast<const char*>(&presionDinamica), sizeof(float));
    float tiempo;
    in.read(reinterpret_cast<const char*>(&tiempo), sizeof(float));
    tiempoMedicion = make_unique<float>(tiempo);
}

void Presion::imprimir() const override{
    cout << "Presión Estática: " << presionEstatica << ", Presión Dinámica: " << presionDinamica << ", Tiempo de Medición: " << getTiempo() << endl;
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
