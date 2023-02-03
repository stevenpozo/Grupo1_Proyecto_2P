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

#include "CuadradoM.h"
#include <iostream>

using namespace std;

CuadradoM::CuadradoM(int valorInicial, int progresionAritmetica, int newTamanio)
{
	this->progresion = progresionAritmetica;
	this->tamanio = newTamanio;
	valor = new int[tamanio * tamanio];
	valorInicio=valorInicial;

	for (int i=0; i < tamanio * tamanio; i++)
	{
		valor[i] = valorInicial;
		valorInicial += progresionAritmetica;
	}

	generarMatriz();
	
}

void CuadradoM::generarMatriz(){
	matriz = new int *[tamanio];
	
	for (int i = 0; i < tamanio; i++)
	{

		matriz[i] = new int[tamanio];
	}
}

CuadradoM::~CuadradoM()
{
}

int **CuadradoM::getMatriz(void)
{
	return matriz;
}

void CuadradoM::setMatriz(int **newMatriz)
{
	matriz = newMatriz;
}

int *CuadradoM::getValor(void)
{
	return valor;
}

void CuadradoM::setValor(int *newValor)
{
	valor = newValor;
}

int CuadradoM::getTamanio(void)
{
	return tamanio;
}

void CuadradoM::setTamanio(int newTamanio)
{
	tamanio = newTamanio;
}

void CuadradoM::mostrarCuadrado()
{
	for (int i=0; i < tamanio; i++)
	{
		for (int j=0; j < tamanio; j++)
		{
			if (!*(*(matriz + i) + j) ==0)
			{
				cout << *(*(matriz + i) + j) << " ";
			}else{
				*(*(matriz + i) + j)=valorInicio;
				cout << *(*(matriz + i) + j) << " ";
			}
		}
		cout << endl;
	}
}


void CuadradoM::sumatoriaDiagonal(void)
{

	int auxTam{static_cast<int>(2 * tamanio - 1)};
	int **auxCuadrado = new int *[auxTam];
	
	for (int i=0; i < auxTam; ++i)
	{
		auxCuadrado[i] = new int[auxTam];
		for (int j = 0; j < auxTam; ++j)
		{
			*(*(auxCuadrado+i)+j)=0;
			
		}
		
	}

	int diagonalPrincipalFilas;
	int diagonalPrincipalColumnas{static_cast<int>(auxTam / 2)};
	int i=0;
	

	while (i < (tamanio * tamanio))
	{
		int diagonalActualFilas{diagonalPrincipalFilas};
		int diagonalActualColumnas{diagonalPrincipalColumnas};

;
		for (int j=0; j < tamanio; ++j)
		{
			
			*(*(auxCuadrado + diagonalActualFilas) + diagonalActualColumnas) = *(valor + i);
			
			++i;
			++diagonalActualFilas;
			++diagonalActualColumnas;
		}

		++diagonalPrincipalFilas;
		--diagonalPrincipalColumnas;
	}

	
	for (int i=0; i < tamanio / 2; ++i)
	{
		for (int j; j < auxTam; ++j)
		{
			if (*(*(auxCuadrado + i) + j) != 0)
				*(*(auxCuadrado + (i + tamanio)) + j) = *(*(auxCuadrado + i) + j);
		}
	}

	for (int i=0; i < tamanio / 2; ++i)
	{
		for (int j=0; j < auxTam; ++j)
		{
			if (*(*(auxCuadrado + (i + tamanio / 2 + tamanio)) + j) != 0)
				*(*(auxCuadrado + (i + tamanio / 2)) + j) = *(*(auxCuadrado + (i + tamanio / 2 + tamanio)) + j);
		}
	}

	for (int i=0; i < auxTam; ++i)
	{
		for (int j=0; j < tamanio / 2; ++j)
		{
			if (*(*(auxCuadrado + i) + j) != 0)
			{
				*(*(auxCuadrado + i) + (j + tamanio)) = *(*(auxCuadrado + i) + j);
			}
		}
	}

	for (int i=0; i < auxTam; ++i)
	{
		for (int j=0; j < tamanio / 2; ++j)
		{
			if (*(*(auxCuadrado + i) + (j + tamanio / 2 + tamanio)) != 0)
				*(*(auxCuadrado + i) + (j + tamanio / 2)) = *(*(auxCuadrado + i) + (j + tamanio / 2 + tamanio));
		}
	}
	

	for (int i=0; i < tamanio; i++)
	{
		for (int j=0; j < tamanio; j++)
		{
			*(*(matriz + i) + j) = *(*(auxCuadrado + (i + tamanio/2)) + (j+tamanio/2 ));

		}

	}
	

	for (int i; i < auxTam; ++i)
	{
		delete[] auxCuadrado[i];
	}

	delete[] auxCuadrado;
	 
}

void CuadradoM::sumaTotal(){
	int sumaFila = 0;
	for (int i=0; i < tamanio; i++)
	{
		sumaFila+=*(*(matriz + i) + 0) ;
	}


	int sumaColumna = 0;
	for (int j=0; j < tamanio; j++)
	{
		sumaColumna+=*(*(matriz + 0) + j) ;
	}

	int sumaDiagonal = 0;
	for (int i=0; i < tamanio; i++)
	{
		sumaDiagonal+=*(*(matriz + i) + i) ;
	}
	cout<<"----------------------------------------------------------"<<endl;
	cout<<"Suma de Filas: "<< sumaFila <<endl;
	cout<<"Suma de Columnas: "<< sumaColumna <<endl;
	cout<<"Suma de Diagonales: "<< sumaDiagonal <<endl;
	cout<<"----------------------------------------------------------"<<endl;
} 

void CuadradoM::mostrarDatosIngresados(){
	cout<<"----------------------------------------------------------"<<endl;
	cout<<"Usted ha generado un cuadrado magico de:"<<endl;
	cout<<"Dimension: "<< tamanio<<"x"<<tamanio <<endl;
	cout<<"Con un valor inicial de: "<< valorInicio <<endl;
	cout<<"Con una suma  progresiva de: "<< progresion <<endl;
	cout<<"----------------------------------------------------------"<<endl;
}
