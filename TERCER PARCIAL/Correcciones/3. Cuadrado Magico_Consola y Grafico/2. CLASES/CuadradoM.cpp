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
#include <graphics.h>

using namespace std;

CuadradoM::CuadradoM(int valorInicial, int progresionAritmetica, int newTamanio)
{
	this->tamanio = newTamanio;
	this->valorIni = valorInicial;
	this->progresion=progresionAritmetica;

	valor = new int[tamanio * tamanio];

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

			cout << *(*(matriz + i) + j) << ' ';
		}
		cout << endl;
	}
}


void CuadradoM::sumatoriaDiagonal(void)
{

	int auxiliarTamanio { static_cast<int>(2 * tamanio - 1) };
    int** auxiliarMatriz  = new int* [auxiliarTamanio]{};

    for (int i{}; i < auxiliarTamanio; ++i)
        auxiliarMatriz [i] = new int[auxiliarTamanio]{};

    int diagonal_FilaPrincipal{};
    int diagonal_ColumnaPrincipal{ static_cast<int>(auxiliarTamanio / 2) };
    
    int i{};
    while (i < tamanio * tamanio) {
        int diagonal_FilaActual { diagonal_FilaPrincipal };
        int diagonal_ColumnaActual { diagonal_ColumnaPrincipal };
        
        for (int j{}; j < tamanio; ++j) {

            *(*(auxiliarMatriz  + diagonal_FilaActual)+diagonal_ColumnaActual) = *(valor+ i);
            ++i;
            ++diagonal_FilaActual;
            ++diagonal_ColumnaActual;
        }

        ++diagonal_FilaPrincipal;
        --diagonal_ColumnaPrincipal;
    }

    for (int i{}; i < tamanio / 2; ++i) {
        for (int j{}; j < auxiliarTamanio; ++j) {
            if (*(*(auxiliarMatriz +i)+j) != 0)
                *(*(auxiliarMatriz+(i+tamanio))+j) = *(*(auxiliarMatriz+i)+j);
        }
    }


    for (int i{}; i < tamanio / 2; ++i) {
        for (int j{}; j < auxiliarTamanio; ++j) {
            if (*(*(auxiliarMatriz +(i + tamanio / 2 + tamanio))+j) != 0)
                *(*(auxiliarMatriz+(i + tamanio / 2))+j) = *(*(auxiliarMatriz+(i + tamanio / 2 + tamanio))+j);
        }
    }

    for (int i{}; i < auxiliarTamanio; ++i) {
        for (int j{}; j < tamanio / 2; ++j) {
            if (*(*(auxiliarMatriz +i)+j) != 0)
                *(*(auxiliarMatriz+i)+(j+tamanio)) = *(*(auxiliarMatriz+i)+j);
        }
    }


    for (int i{}; i < auxiliarTamanio; ++i) {
        for (int j{}; j < tamanio / 2; ++j) {
            if (*(*(auxiliarMatriz+i)+(j+tamanio/2+ tamanio))!= 0)
               *(*(auxiliarMatriz+i)+(j+tamanio/2)) = *(*(auxiliarMatriz+i)+(j+tamanio/2+ tamanio));
        }
    }


   for (int i{}; i < tamanio; ++i) {
        for (int j{}; j < tamanio; ++j) {
            *(*(matriz+i)+j)  = *(*(auxiliarMatriz+(i+tamanio / 2))+(j+tamanio / 2)) ;
        }
    }


    for (int i{}; i < auxiliarTamanio; ++i) {
        delete[] auxiliarMatriz [i];
    }

    delete[] auxiliarMatriz ;
	 
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
	graficarSumatoria(sumaFila,sumaColumna, sumaDiagonal);
} 

void CuadradoM::mostrarDatosIngresados(){
	cout<<"----------------------------------------------------------"<<endl;
	cout<<"Usted ha generado un cuadrado magico de:"<<endl;
	cout<<"Dimension: "<< tamanio<<"x"<<tamanio <<endl;
	cout<<"Con un valor inicial de: "<< valorIni <<endl;
	cout<<"Con una suma  progresiva de: "<< progresion <<endl;
	cout<<"----------------------------------------------------------"<<endl;
}

void CuadradoM::graficarSumatoria(int sumaFila, int sumaColumna, int sumaDiagonal){
	char numFila[8];	
	char numColumna[8];
	char numDiagonal[8];
	char numDimension[8];
	char numValorInicial[8];
	char numProgresion[8];
	
	int x=600;
	int y=50;
	
	sprintf(numFila,"%d",sumaFila);
	sprintf(numColumna,"%d",sumaColumna);
	sprintf(numDiagonal,"%d",sumaDiagonal);
	
	sprintf(numDimension,"%d",tamanio);
	sprintf(numValorInicial,"%d",valorIni);
	sprintf(numProgresion,"%d",progresion);
	
	
	if(tamanio==3){
		//datos calculados
		setcolor(CYAN);
	    outtextxy(x-250, y, numFila);
	    outtextxy(x-250, y+50, numColumna);
	    outtextxy(x-250, y+100, numDiagonal);
	   
	    setcolor(YELLOW);
	    outtextxy(x-340, y, "Suma Fila =");
	    outtextxy(x-370, y+50, "Suma Columna =");
	    outtextxy(x-370, y+100, "Suma Diagonal =");
	    
	    //datos ingresado
	    setcolor(RED);
	    outtextxy(x-370, y+130,"---------------------------------------" );
	    setcolor(CYAN);
	    outtextxy(x-250, y+150,numDimension );
	    outtextxy(x-250, y+200,numValorInicial);
	    outtextxy(x-250, y+250,numProgresion);
	    
	    setcolor(YELLOW);
	    outtextxy(x-370, y+150, "Dimension:");
	    outtextxy(x-370, y+200, "Valor inicial: ");
	    outtextxy(x-370, y+250, "Progresion :");
		
	}else if(tamanio==5){
		
		//datos calculados
		setcolor(CYAN);
	    outtextxy(x-180, y, numFila);
	    outtextxy(x-180, y+50, numColumna);
	    outtextxy(x-180, y+100, numDiagonal);
	   
	    setcolor(YELLOW);
	    outtextxy(x-270, y, "Suma Fila =");
	    outtextxy(x-300, y+50, "Suma Columna =");
	    outtextxy(x-300, y+100, "Suma Diagonal =");
	    
	    //datos ingresado
	    setcolor(RED);
	    outtextxy(x-300, y+130,"---------------------------------------" );
	    setcolor(CYAN);
	    outtextxy(x-180, y+150,numDimension );
	    outtextxy(x-180, y+200,numValorInicial);
	    outtextxy(x-180, y+250,numProgresion);
	    
	    setcolor(YELLOW);
	    outtextxy(x-300, y+150, "Dimension:");
	    outtextxy(x-300, y+200, "Valor inicial: ");
	    outtextxy(x-300, y+250, "Progresion :");
		
	}else if(tamanio == 7){
		//datos calculados
		setcolor(CYAN);
	    outtextxy(x-100, y, numFila);
	    outtextxy(x-100, y+50, numColumna);
	    outtextxy(x-100, y+100, numDiagonal);
	   
	    setcolor(YELLOW);
	    outtextxy(x-190, y, "Suma Fila =");
	    outtextxy(x-220, y+50, "Suma Columna =");
	    outtextxy(x-220, y+100, "Suma Diagonal =");
	    
	    //datos ingresado
	    setcolor(RED);
	    outtextxy(x-220, y+130,"---------------------------------------" );
	    setcolor(CYAN);
	    outtextxy(x-98, y+150,numDimension );
	    outtextxy(x-100, y+200,numValorInicial);
	    outtextxy(x-100, y+250,numProgresion);
	    
	    setcolor(YELLOW);
	    outtextxy(x-220, y+150, "Dimension:");
	    outtextxy(x-220, y+200, "Valor inicial: ");
	    outtextxy(x-220, y+250, "Progresion :");
	}else if(tamanio==9){
		
		//datos calculados
		setcolor(CYAN);
	    outtextxy(x, y, numFila);
	    outtextxy(x, y+50, numColumna);
	    outtextxy(x, y+100, numDiagonal);
	   
	    setcolor(YELLOW);
	    outtextxy(x-90, y, "Suma Fila =");
	    outtextxy(x-120, y+50, "Suma Columna =");
	    outtextxy(x-120, y+100, "Suma Diagonal =");
	    
	    //datos ingresado
	    setcolor(RED);
	    outtextxy(x-120, y+130,"---------------------------------------" );
	    setcolor(CYAN);
	    outtextxy(x, y+150,numDimension );
	    outtextxy(x, y+200,numValorInicial);
	    outtextxy(x, y+250,numProgresion);
	    
	    setcolor(YELLOW);
	    outtextxy(x-120, y+150, "Dimension:");
	    outtextxy(x-120, y+200, "Valor inicial: ");
	    outtextxy(x-120, y+250, "Progresion :");
		
	}
    
}

void CuadradoM::graficarNumeros(){
	char num[8];
	int valor;
	int x = 60, y = 60;
    for (int i = 0; i < tamanio; i++)
    {
        for (int j = 0; j < tamanio; j++)
        {	
        	valor= *(*(matriz + i) + j);
			sprintf(num,"%d",valor);
    		setcolor(WHITE);
            outtextxy(x, y, num);
           x += 47; //distancia entre los numeros de cada fila
        }                                                     
       y += 47; //distancia entre los numeros de cada columna
       x = 60; //posicion incial de cada fila despues de cada iteracion
    }	
}
void CuadradoM::graficarMatriz(){
	
	outtextxy(200, 20, "Grafico de cuadrado Magico");
	
	int x=47, y=47;
	for(int i=0; i<tamanio; i++){
		for(int j=0; j<tamanio; j++){
			if((i+j)%2==0){
				setfillstyle(SOLID_FILL, LIGHTBLUE);
				setcolor(LIGHTBLUE);
				rectangle(x,y,x+47,y+47);
			}else{
				setfillstyle(SOLID_FILL, LIGHTBLUE);
				setcolor(LIGHTBLUE);
				rectangle(x,y,x+47,y+47);
			}
			x+=47;
		}
		y+=47;
		x=47;
	}
}
