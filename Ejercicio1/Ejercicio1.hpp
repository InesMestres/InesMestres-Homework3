#ifndef IMEDICIONES_HPP
#define IMEDICIONES_HPP
#include <iostream>
#include <fstream>
#include <memory>
using namespace std;


//interfaz IMediciones

class IMediciones{
    public:
        virtual void serializar(std::ofstream& out) const = 0;
        virtual void deserializar(std::ifstream& in) = 0;
        virtual ~IMediciones() = default;
};


//Clase abstracta MedicionBase

class MedicionBase: public IMediciones{
    protected:
        unique_ptr<float> tiempoMedicion;
    public:
        MedicionBase();
        MedicionBase(float tiempo);
        MedicionBase(const MedicionBase& nuevo);
        float getTiempo() const;
        virtual void imprimir() const = 0;
        virtual ~MedicionBase() = default;
};

//Class Presion

class Presion: public MedicionBase{
    protected:
        float presionEstatica;
        float presionDinamica;
    public:
        Presion();
        Presion(float p, float q, float t);
        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in) override;
        void imprimir() const override;
};

//Clase Posicion

class Posicion: public MedicionBase{
    protected:
        float latitud;
        float longitud;
        float altitud;
    public:
        Posicion();
        Posicion(float lat, float lon, float alt, float t);
        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in) override;
        void imprimir() const override;
};

//Clase SaveFlightData

class SaveFlightData{
    private: 
        unique_ptr<Posicion> posicion;
        unique_ptr<Presion> presion;
    public:
        SaveFlightData();
        SaveFlightData(const Posicion& p, const Presion& q);
        void serializar(ofstream& out) const;
        void deserializar(ifstream& in);
        void imprimir() const;
};

#endif
