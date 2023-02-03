/*
	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	INTEGRANTES:
		- STEVEN POZO
		- JAIRO QUILUMBAQUIN
		- SEBASTIAN PAUCAR
	NRC: 7999
	FECHA DE ENTREGA: 3/02/2023
	TEMA: GENERAR UN CUADRADO MAGICO
*/



#include <iostream>
#include "CuadradoM.cpp"
#include "Validaciones.h"

using namespace std;

int main(){
	
	Validaciones validar;
	int valorInicial;
	int valorDeProgresion;
	int dimension;

	dimension=validar.pedirDimension();
	valorInicial=validar.pedirValorInicial();
	valorDeProgresion=validar.pedirProgresionAritmetica();
	

	CuadradoM *cuadrado= new CuadradoM(valorInicial,valorDeProgresion,dimension);
	cuadrado->mostrarDatosIngresados();
	cuadrado->sumatoriaDiagonal();
	cuadrado->mostrarCuadrado();
	cuadrado->sumaTotal();
	return 0;
	
}