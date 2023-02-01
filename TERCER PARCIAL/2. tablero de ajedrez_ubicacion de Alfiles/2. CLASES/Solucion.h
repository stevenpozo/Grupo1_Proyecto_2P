/*
	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	INTEGRANTES:
		- STEVEN POZO
		- JAIRO QUILUMBAQUIN
		- SEBASTIAN PAUCAR
	NRC: 7999
	FECHA DE ENTREGA: 30/01/2023
	TEMA: UBICAR LOS ALFILES EN POSICIONES SEGURAS
*/

#if !defined(__ObjectOrientedModel_1_Solucion_h)
#define __ObjectOrientedModel_1_Solucion_h

#include "Solucion_Interfaz.h"

class Solucion : public Solucion_Interfaz
{
public:
	
   void encerarTablero() override;
   void crearArchivo(void) override;
   void bloquear(int x, int y) override;
   void mostrar(void) override;
   void quitarRelleno(int x, int y) override;
   void solucionFinal(int x, int y, int n1) override;
   void solucionReinas(void) override;
   
   Solucion(int n);
protected:
private:

};

#endif
