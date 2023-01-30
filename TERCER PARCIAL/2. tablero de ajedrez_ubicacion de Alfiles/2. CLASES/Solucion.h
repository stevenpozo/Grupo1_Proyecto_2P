/***********************************************************************
 * Module:  Solucion.h
 * Author:  steve
 * Modified: viernes, 27 de enero de 2023 8:54:02
 * Purpose: Declaration of the class Solucion
 ***********************************************************************/

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