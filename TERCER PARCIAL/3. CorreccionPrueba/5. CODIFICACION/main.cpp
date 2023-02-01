/*
	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	INTEGRANTES:
		- STEVEN POZO
		- JAIRO QUILUMBAQUIN
		- SEBASTIAN PAUCAR
	NRC: 7999
	FECHA DE ENTREGA: 30/01/2023
	TEMA: UBICAR ALFIL Y MARCAR SU TRAYECTORIA
	CORRECION
*/


#include <iostream>
#include "Solucion.cpp"
#define TAM 8
using namespace std;


int main(){
	
	Solucion *sol=new Solucion(TAM);
	sol->solucionReinas();
	sol->dibujarTabla();
	cout<<"Se creo el archivo txt"<<endl;
	
	return 0;
}