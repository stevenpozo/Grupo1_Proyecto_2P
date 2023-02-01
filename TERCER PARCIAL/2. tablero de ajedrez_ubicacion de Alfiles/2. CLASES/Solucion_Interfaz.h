/***********************************************************************
 * Module:  Solucion_Interfaz.h
 * Author:  steve
 * Modified: viernes, 27 de enero de 2023 8:53:45
 * Purpose: Declaration of the class Solucion_Interfaz
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_1_Solucion_Interfaz_h)
#define __ObjectOrientedModel_1_Solucion_Interfaz_h

class Solucion_Interfaz
{
public:
   virtual void encerarTablero() =0;
   virtual void crearArchivo(void) =0;
   virtual void bloquear(int x, int y)=0;
   virtual void mostrar(void)=0;
   virtual void quitarRelleno(int x, int y)=0;
   virtual void solucionFinal(int x, int y, int n1)=0;
   virtual void solucionReinas(void)=0;

protected:
private:

};

#endif