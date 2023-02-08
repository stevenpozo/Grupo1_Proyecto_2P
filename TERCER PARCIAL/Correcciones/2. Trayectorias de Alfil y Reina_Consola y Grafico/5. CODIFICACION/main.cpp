/*
	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	INTEGRANTES:
		- STEVEN POZO
		- JAIRO QUILUMBAQUIN
		- SEBASTIAN PAUCAR
	NRC: 7999
	FECHA DE ENTREGA: 27/01/2023
	TEMA: CREAR UN TABLERO DE AJEDREZ DE 1 Y 0 QUE SEA LEIDO DESDE UN ARCHIVO DE TEXTO
*/

#include "Matriz.h"
#include <iostream>
#include <graphics.h>

using namespace std;

int main(){
	
	//GENERAR TABLA DE AJEDREZ EN TIEMPO DE EJECUCION
	Matriz T;
	int **matriz;
	system("color E4"); 
    matriz = T.crearMatriz();
    T.rellenarTablero(matriz);
    cout<<"Tabla en tiempo de ejecucion"<<endl;
    T.mostrarTablero(matriz); 
    T.crearArchivo(matriz); 
    cout<<endl;
    
    //GENERAR TABLA DE AJEDREZ DESDE ARCHIVO DE TEXTO
    cout<<"Tabla desde archivo txt"<<endl;
    T.generarTablero();
    T.graficarTableroAjedrez();
    
    return 0;
}