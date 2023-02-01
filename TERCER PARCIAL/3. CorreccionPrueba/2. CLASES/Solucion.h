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

#if !defined(__ObjectOrientedModel_1_Solucion_h)
#define __ObjectOrientedModel_1_Solucion_h

#include "Solucion_Interfaz.h"

class Solucion : public Solucion_Interfaz
{
public:
	
   void encerarTablero() override;
   void crearArchivo(void) override;
   void mostrar(void) override;
   void solucionFinal(int x, int y, int n1) override;
   void solucionReinas(void) override;
   void dibujarTabla() override;
   Solucion(int n);
protected:
private:

};

#endif