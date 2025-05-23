#include "Ejercicio2.hpp"

int main(){

    Circulo circuloOrigen;
    Elipse elipseOrigen;
    Rectangulo rectanguloOrigen;

    ProcesadorFigura<Circulo> procesadorCirculo;
    double areaCirculo = procesadorCirculo.calcularArea(circuloOrigen);

    ProcesadorFigura<Elipse> procesadorElipse;
    double areaElipse = procesadorElipse.calcularArea(elipseOrigen);

    ProcesadorFigura<Rectangulo> procesadorRectangulo;
    double areaRectangulo = procesadorRectangulo.calcularArea(rectanguloOrigen);


    Punto punto;


    return 0;
}