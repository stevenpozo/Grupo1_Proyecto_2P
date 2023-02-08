/***********************************************************************
 * Module:  Solucion.cpp
 * Author:  steve
 * Modified: viernes, 3 de febrero de 2023 20:41:08
 * Purpose: Implementation of the class Solucion
 ***********************************************************************/
#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include<conio.h>
#include <cstdlib>
#include <ctime>
#include "SolucionAlfil.h"
#include "Alfil.cpp"
#define TAM 8
Alfil *alfil;
Alfil alfil2;

using namespace std;

SolucionAlfil::SolucionAlfil()
{
   Alfil alfil1 (new char *[TAM]);
   alfil2 = alfil1;
   alfil = &alfil2;
   encerarTablero();
   generarPosicionesAleatorias();
   crearArchivo();
}

SolucionAlfil::~SolucionAlfil()
{
   delete[] alfil;
}

//FUNCIONES USADAS EN TIEMPO DE EJECUCION

void SolucionAlfil::encerarTablero(void)
{
   for(int i=0;i<TAM;i++){
      alfil->getTablero()[i]=new char[TAM];
      for(int j=0;j<TAM;j++){
         *(*(alfil->getTablero()+i)+j)='0';
      }
   }
}


bool SolucionAlfil::crearArchivo(void)
{
   int i;
   int j;
   ofstream tablero;
      tablero.open("Ajedrez.txt",ios::trunc);
      
   if(tablero.is_open()){
      for(i=0; i<TAM; i++){
         for (j=0; j<TAM; j++) {
               tablero << *(*(alfil->getTablero()+i)+j);
         }
      cout << endl;
      tablero <<endl;
      }
   }
   return true;
}


void SolucionAlfil::generarPosicionesAleatorias(){
   srand(time(0));
   int fila, columna;
   fila = rand()%8+1;
   columna = rand()%8+1;
   alfil->setX(columna);
   alfil->setY(fila);
   generarTrayectoria(alfil->getY(),alfil->getX());
}


void SolucionAlfil::generarTrayectoria(int x,int y){
   
   for (int f= 0; f <TAM; f++)
   {
      for (int  c = 0; c <TAM; c++){
         
         if ((f+c)==((x-1)+(y-1))||(f-c)==((x - 1) - (y - 1)))
         {
            *(*(alfil->getTablero()+f)+c) = 'A';
         }
      }
   }
}


void SolucionAlfil::mostrarTableroConsola(void)
{
   for(int i=0;i<TAM;i++){
      for(int j=0;j<TAM;j++){
         if(*(*(alfil->getTablero()+i)+j)=='A'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5| BACKGROUND_INTENSITY);
         }else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10|0);
         }
         cout<<*(*(alfil->getTablero()+i)+j)<<" ";
      }
      cout<<"\n";
   }
}

//FUNCIONES USADAS PARA GENERAR TABLA DESDE ARCHIVO

char** SolucionAlfil::creartableroArchivo()
{
   char **matriz;
			matriz=new char*[TAM];
			
			for(int i=0;i<TAM;i++){
				matriz[i]=new char[TAM];
			}
			return matriz;
}


char** SolucionAlfil::leerArchivo(void)
{
   ifstream tablero;
   string line;
   int cont=0;
   char** TableroMatriz=NULL;

   TableroMatriz=creartableroArchivo(); 
   tablero.open("Ajedrez.txt");

   if(tablero.is_open()){
      
      while (getline(tablero,line))
      {
         *(TableroMatriz+cont)=strdup(line.c_str());
         cont++;
      }
      
   }else{
      cout<<"El archivo no existe :c"<<endl;
   }
   tablero.close();
   return TableroMatriz;
}

void SolucionAlfil::mostrarTableroArchivo(void)
{
   char** prueba=NULL;

   prueba=leerArchivo();

   for (int i = 0; i < TAM; i++)
   {
      for (int j = 0; j <TAM; j++)
      {
         if(*(*(prueba+i)+j)=='A'){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0| BACKGROUND_INTENSITY);
         }else if(*(*(prueba+i)+j)=='0'){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10|0);
         }
         cout<<*(*(prueba+i)+j)<<" ";
      }
      cout<<endl;
   } 
}


//FUNCION QUE DIBUJA EL TABLERO EN TIEMPO DE EJECUCION


void SolucionAlfil::dibujarTablero(){

	    int x=50,y=50;
	    setfillstyle(SOLID_FILL,RED);
	    bar(20,20,480,480);
	    setfillstyle(SOLID_FILL,GREEN);
	    bar(30,30,470,470);
	    setfillstyle(SOLID_FILL,YELLOW);
	    bar(100,0,390,40);
	    settextstyle(0,HORIZ_DIR,2);
	    outtextxy(120,20,"TABLITA DE AJEDREZ");
	    for(int i=0;i<8;i++)
	    {
	        for(int j=0;j<8;j++)
	        {
	            if((i+j)%2==0)
	            {
	            	setfillstyle(SOLID_FILL,WHITE);
	            	setbkcolor(WHITE);
	                bar(x,y,x+50,y+50);
	                if(*(*(alfil->getTablero() + i) + j)=='A'){
	                	readimagefile("alfil.jpg", x,y,x-50,y-50);	
					}
	                
	            }
	            else
	            {
	            	setfillstyle(SOLID_FILL,BLACK);
	            	setbkcolor(BLACK);
	                bar(x,y,x+50,y+50);
	                if(*(*(alfil->getTablero() + i) + j)=='A'){
						readimagefile("alfil.jpg",x,y,x-50,y-50);	
	            	}
	                
	            }
	            x+=50;
	        }
	        y+=50;
	        x=50;
	    }
	    delete [] alfil;
}

// DIBUJA TABLERO GENERADO DESDE ARCHIVO
void SolucionAlfil::dibujarTableroArchivo(){
		char** prueba=NULL;
   		prueba=leerArchivo();
   		
	    int x=50,y=50;
	    setfillstyle(SOLID_FILL,RED);
	    bar(20,20,480,480);
	    setfillstyle(SOLID_FILL,GREEN);
	    bar(30,30,470,470);
	    setfillstyle(SOLID_FILL,YELLOW);
	    bar(100,0,390,40);
	    settextstyle(0,HORIZ_DIR,2);
	    outtextxy(120,20,"TABLITA DE AJEDREZ");
	    for(int i=0;i<8;i++)
	    {
	        for(int j=0;j<8;j++)
	        {
	            if((i+j)%2==0)
	            {
	            	setfillstyle(SOLID_FILL,WHITE);
	            	setbkcolor(WHITE);
	                bar(x,y,x+50,y+50);
	                if(*(*(prueba + i) + j)=='0'){
	                	outtextxy(x+25,y+25," ");	
					}else if(*(*(prueba + i) + j)=='A'){	
	                	readimagefile("alfil.jpg", x,y,x-50,y-50);
					}
	                
	            }
	            else
	            {
	            	setfillstyle(SOLID_FILL,BLACK);
	            	setbkcolor(BLACK);
	                bar(x,y,x+50,y+50);
	                 if(*(*(prueba + i) + j)=='0'){
	                	outtextxy(x+25,y+25," ");	
					}else if(*(*(prueba + i) + j)=='A'){
						readimagefile("alfil.jpg",x,y,x-50,y-50);	
	            	}
	                
	            }
	            x+=50;
	        }
	        y+=50;
	        x=50;
	    }
}

void SolucionAlfil::mostrarCoordenadas(){
	cout<<"El alfil se posiciona en las coordenadas: "<<endl;
	cout<<"FILA -> "<< alfil->getY()<<endl;
	cout<<"COLUMNA-> "<< alfil->getX()<<endl;
}
