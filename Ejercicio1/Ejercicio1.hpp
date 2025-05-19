#ifndef IMEDICIONES_HPP
#define IMEDICIONES_HPP
#include <iostream>
#include <fstream>
#include <memory>
using namespace std;


//interfaz IMediciones

class IMediciones{
    public:
        virtual void serializar(of_stream& out) const = 0;
        virtual void deserializar(of_stream& in) = 0;
        virtual ~IMediciones() = default;
}


//Clase abstracta MedicionBase

class MedicionBase:: public IMediciones{
    protected:
        std::unique_ptr<float> tiempoMedicion;
    public:
        MedicionBase(float tiempo);
        float getTiempo() const;
        virtual void imprimir() = 0;
}

//Class Presion

class Presion: public MedicionBase{
    protected:
        float presionEstatica;
        float presionDinamica;
    public:
        Presion(float p, float q, float t);
        void serializar(stream& out) override;
        void deserializar(stream& in) override;
        void imprimir() override;
}

//Clase Posicion

class Posicion{
    protected:
        float latitud;
        float longitud;
        float altitud;
    public:
        Posicion(lat: float, lon: float, alt: float, t: float);
        void serializar(stream& out) override;
        void deserializar(stream& in) override;
        void imprimir() override;
}

//Clase SaveFlightData

class saveFlightData: posicion, presion{
    private: 
        unique_ptr<string> Posicion;
        unique_ptr<string> Presión;
    public:
        SaveFlightData(const Posicion& p, const Presion& q);
        void serializar(ofstream& out);
        void deserializar(ofstream& in);
        void imprimir();
}

#endif