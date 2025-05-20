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

//FUNCIONES POSICION

Posicion::Posicion(): latitud(0), longitud(0), altitud(0), MedicionBase(0){}

Posicion::Posicion(float lat, float lon, float alt, float t): latitud(lat), longitud(lon), altitud(alt), MedicionBase(t){}

void Posicion::serializar(ofstream& out) const{
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&tiempoMedicion.get()), sizeof(float));
}

void Posicion::deserializar(ifstream& in) override{
    in.read(reinterpret_cast<const char*>(&latitud), sizeof(float));
    in.read(reinterpret_cast<const char*>(&longitud), sizeof(float));
    in.read(reinterpret_cast<const char*>(&altitud), sizeof(float));
    float tiempo;
    in.read(reinterpret_cast<const char*>(&tiempo), sizeof(float));
    tiempoMedicion = make_unique<float>(tiempo);
}

void Posicion::imprimir() const override{
    cout << "Latitúd: " << latitud << ", Longitud: " << longitud << ", Altitud: " << altitud << ", Tiempo de Medición: " << getTiempo() << endl;
}




//FUNCIONES Clase SaveFlightData
   
SaveFlightData(const Posicion& p, const Presion& q): posicion(p), presion(q);

void saveFlightData::serializar(ofstream& out) const {
    posicion.serializar(out);
    presion.serializar(out);
}

void saveFlightData::deserializar(ofstream& in){
    posicion.deserializar(in);
    presion.deserializar(in);
}

void saveFlightData::imprimir(){
    cout << "Los datos del vuelo son:" << endl;
    posicion.imprimir();
    presion.imprimir();
}
