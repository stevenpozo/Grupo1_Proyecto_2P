/***********************************************************************
 * Module:  Solucion.h
 * Author:  steve
 * Modified: viernes, 3 de febrero de 2023 20:41:08
 * Purpose: Declaration of the class Solucion
 ***********************************************************************/

#if !defined(__GraficoAlfil_Solucion_h)
#define __GraficoAlfil_Solucion_h

class SolucionAlfil
{
public:
   char** creartableroArchivo(void);
   void encerarTablero(void);
   void mostrarTableroConsola(void);
   bool crearArchivo(void);
   char** leerArchivo(void);
   void generarTrayectoria(int posicionX, int posicionY);
   void generarPosicionesAleatorias();
   void mostrarTableroArchivo(void);
   void dibujarTablero();
   void dibujarTableroArchivo();
   void mostrarCoordenadas();
   SolucionAlfil();
   ~SolucionAlfil();

protected:
private:

};

#endif