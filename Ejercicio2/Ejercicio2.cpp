#include "Ejercicio2.hpp"

Punto::Punto(): x(0), y(0) {};

Punto::Punto(int valor_x, int valor_y): x(valor_x), y(valor_y) {};

void Punto::set_x(int valor_x){
    x = valor_x;
}

void Punto::set_y(int valor_y){
    y = valor_y;
}

int Punto::get_x() const{
    return x;
}

int Punto::get_y() const{
    return y;
}



class Circulo{
    protected:
        Punto posicion;
        int radio;
    public:
        Circulo();
        Circulo(Punto posicionCirculo, int radioCirculo);
        void set_radio();
        Punto get_posicion() const;
        int get_radio() const;
};

class Elipse{
    protected:
        Punto posicionCentro;
        int a; //semieje mayor
        int b; //semieje menor
    public:
        Elipse();
        Elipse(Punto posicionCentro, int a, int b);
        void set_a();
        void set_b();
        Punto get_posicionCentro() const;
        int get_a() const;
        int get_b() const;
};

class Rectangulo{
    protected:
        Punto posicionVertice;
        int ancho;
        int largo;
    public:
        Rectangulo();
        Rectangulo(Punto posicionVertice, int ancho, int largo);
        Punto get_vertice();
        int get_ancho();
        int get_largo();
};


template <class T>
class ProcesadorFigura{
    public:
        double calcularArea();
};

template <>
class ProcesadorFigura<Circulo>{
    public:
        double calcularArea(const Circulo& circulo);
};

template <>
class ProcesadorFigura<Elipse>{
    public:
        double calcularArea(const Elipse& elipse);
};

template <>
class ProcesadorFigura<Rectangulo>{
    public:
        double calcularArea(const Rectangulo& rectangulo);
};

#endif PROCESADOR_FIGURA_HPP
