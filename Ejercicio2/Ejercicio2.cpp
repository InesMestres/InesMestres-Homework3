#include "Ejercicio2.hpp"
#define PI = 3.14159265


//Funciones Punto:

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



//Funciones Circulo:

Circulo::Circulo(){}

Circulo::Circulo(Punto posicionCirculo, int radioCirculo): posicion(posicionCirculo), radio(radioCirculo){}

void Circulo::set_radio(int radioCirculo){
    radio = radioCirculo;
}

Punto Circulo::get_posicion() const{
    return posicion;
}

int Circulo::get_radio() const{
    return radio;
}



//Funciones Elipse:

Elipse::Elipse() {}

Elipse::Elipse(Punto posicionCentro, int semiejeMayor, int semiejeMenor): posicion(posicionCentro), a(semiejeMayor), b(semiejeMenor) {}

void Elipse::set_a(int semiejeMayor) {
    a = semiejeMayor;
    return;
}

void Elipse::set_b(int semiejeMenor){
    b = semiejeMenor;
}

Punto Elipse::get_posicionCentro() const{
    return posicion;
}

int Elipse::get_a() const{
    return a;
}

int Elipse::get_b() const{
    return b;
}

//Rectangulo:
Rectangulo::Rectangulo(){}

Rectangulo::Rectangulo(Punto posicionVertice, int ancho_r, int largo_r): posicion(posicionVertice), ancho(ancho_r), largo(largo_r){}

void Rectangulo::set_ancho(int ancho_r){
    ancho = ancho_r;
    return;
}

void Rectangulo::set_largo(int largo_r){
    largo = largo_r;
    return;
}

Punto Rectangulo::get_vertice(){
    return posicion;
}

int Rectangulo::get_ancho(){
    return ancho;
}

int Rectangulo::get_largo(){
    return largo;
}

//Funciones template:

double ProcesadorFigura<Circulo>::calcularArea(const Circulo& circulo){
    return PI * circulo.get_radio() * circulo.get_radio();
}

double ProcesadorFigura<Elipse>::calcularArea(const Elipse& elipse){
    return PI * a * b;
}

double ProcesadorFigura<Rectangulo>::calcularArea(const Rectangulo& rectangulo){
    return rectangulo.get_ancho() * rectangulo.get_largo();
}
