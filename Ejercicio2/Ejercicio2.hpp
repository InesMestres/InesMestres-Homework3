#ifndef PROCESADOR_FIGURA_HPP
#define PROCESADOR_FIGURA_HPP


class Punto{
    protected:
        int x;
        int y;
    public:
        Punto();
        Punto(int valor_x, int valor_y);
        void set_x(int valor_x);
        void set_y(int valor_y);
        int get_x() const;
        int get_y() const;
};


class Circulo{
    protected:
        Punto posicion;
        int radio;
    public:
        Circulo();
        Circulo(Punto posicionCirculo, int radioCirculo);
        void set_radio(int radioCirculo);
        Punto get_posicion() const;
        int get_radio() const;
};

class Elipse{
    protected:
        Punto posicion;
        int a; //semieje mayor
        int b; //semieje menor
    public:
        Elipse();
        Elipse(Punto posicionCentro, int a, int b);
        void set_a(int semiejeMayor);
        void set_b(int semiejeMenor);
        Punto get_posicionCentro() const;
        int get_a() const;
        int get_b() const;
};

class Rectangulo{
    protected:
        Punto posicion;
        int ancho;
        int largo;
    public:
        Rectangulo();
        Rectangulo(Punto posicionVertice, int ancho_r, int largo_r);
        void set_ancho(int ancho_r);
        void set_largo(int largo_r);
        Punto get_vertice();
        int get_ancho() const;
        int get_largo() const;
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

#endif
