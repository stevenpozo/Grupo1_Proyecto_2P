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

#if !defined(__ObjectOrientedModel_1_Solucion_Interfaz_h)
#define __ObjectOrientedModel_1_Solucion_Interfaz_h

class Solucion_Interfaz
{
public:
   virtual void encerarTablero() =0;
   virtual void crearArchivo(void) =0;
   virtual void mostrar(void)=0;
   virtual void solucionFinal(int x, int y, int n1)=0;
   virtual void solucionReinas(void)=0;
   virtual void dibujarTabla()=0;

protected:
private:

};

#endif