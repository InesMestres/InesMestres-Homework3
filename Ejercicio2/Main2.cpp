#include "Ejercicio2.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main(){

    Circulo circuloOrigen(Punto(0, 0), 7);
    Elipse elipseOrigen(Punto(0, 0), 6, 7);
    Rectangulo rectanguloOrigen(Punto(0, 0), 8, 4);

    ProcesadorFigura<Circulo> procesadorCirculo;
    double areaCirculo = procesadorCirculo.calcularArea(circuloOrigen);

    ProcesadorFigura<Elipse> procesadorElipse;
    double areaElipse = procesadorElipse.calcularArea(elipseOrigen);

    ProcesadorFigura<Rectangulo> procesadorRectangulo;
    double areaRectangulo = procesadorRectangulo.calcularArea(rectanguloOrigen);

    cout << "Área del círculo: " << areaCirculo << endl;
    cout << "Área de la elipse: " << areaElipse << endl;
    cout << "Área del rectángulo: " << areaRectangulo << endl;

    return 0;
}