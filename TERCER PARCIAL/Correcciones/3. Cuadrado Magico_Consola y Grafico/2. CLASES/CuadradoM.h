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

#if !defined(__cuadradoMagico_CuadradoM_h)
#define __cuadradoMagico_CuadradoM_h

class CuadradoM
{
public:
	int valorInicio;
   //funciones
   void sumatoriaDiagonal(void);
   void mostrarCuadrado(void);
   void generarMatriz(void);
   void sumaTotal(void);
   void mostrarDatosIngresados();
   
   //graficos
   void graficarNumeros();
   void graficarMatriz();
   void graficarSumatoria(int sumaFila, int sumaColumna, int sumaDiagonal);
   
   //getters y setters
   int** getMatriz(void);
   void setMatriz(int** newMatriz);
   int* getValor(void);
   void setValor(int* newValor);
   int getTamanio(void);
   void setTamanio(int newTamanio);
   
   //constructor
   CuadradoM(int valorInicial, int progresionAritmetica, int _tamanio=3);
   
   //destructor
   ~CuadradoM();

protected:
private:
   int** matriz;
   int* valor;
   int tamanio;
   int progresion;
   int valorIni;


};

#endif