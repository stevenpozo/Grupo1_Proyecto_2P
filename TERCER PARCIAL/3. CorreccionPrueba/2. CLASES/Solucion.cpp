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

#include <iostream>
#include <fstream>
#include <conio.h>
#include<graphics.h>
#include<conio.h>
#include <cstdlib>
#include <ctime>
#include "Solucion.h"
#include "alfil.cpp"


using namespace std;
Alfil re;
Alfil *alfil;
fstream archivo;

   Solucion::Solucion(int n){

	   Alfil rep(n, new bool* [n], new char* [n], 0);
	   re = rep;
	   alfil = &re;
		encerarTablero();
		crearArchivo();
	}
	
   void Solucion::encerarTablero(){
   		for(int i=0;i<alfil->getN();i++){
				alfil->getValidar()[i]=new bool [alfil->getN()];
				alfil->getTablero()[i]=new char[alfil->getN()];
				for(int j=0;j<alfil->getN();j++){
					*(*(alfil->getValidar()+i)+j)=false;
					*(*(alfil->getTablero()+i)+j)='0';
				}
			}
   }

	void Solucion::crearArchivo(){
		archivo.open("exaustivo.txt",fstream::out);
		archivo<<"solucion"<<alfil->getN()<<"*"<<alfil->getN()<<endl<<endl;;
	}
	
	
	void Solucion::mostrar(){
		int contador=0;
		contador++;
		archivo<<"solucion N "<<contador <<endl;
		cout<<endl;
		for(int i=0;i<alfil->getN();i++){
			for(int j=0;j<alfil->getN();j++){
				if(*(*(alfil->getTablero()+i)+j)=='A'){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0| BACKGROUND_INTENSITY);
				}else if(*(*(alfil->getTablero()+i)+j)=='0'){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10|0);
				}
				archivo<<*(*(alfil->getTablero()+i)+j)<<" ";
				cout<<*(*(alfil->getTablero()+i)+j)<<" ";
			}
			archivo<<endl;
			cout<<endl;
		}
		archivo<<endl;
		cout<<endl;
	}
	

	void Solucion::solucionFinal(int x, int y, int n1){
		int  f, c;
		for ( f = 0; f < alfil->getN(); f++)
		{
			for ( c = 0; c < alfil->getN(); c++){
				
				if ((f+c)==((x-1)+(y-1))||(f-c)==((x - 1) - (y - 1)))
				{
					*(*(alfil->getTablero()+f)+c) = 'A';
				}
			}
		}

	}
	

	void Solucion::dibujarTabla(){
		
		int gd=DETECT,gm;
	    initgraph(&gd,&gm,"");
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
	                if(*(*(alfil->getTablero() + i) + j)=='*'){
	                	outtextxy(x+25,y+25," ");	
					}else if(*(*(alfil->getTablero() + i) + j)=='A'){
						setbkcolor(RED);
	                	outtextxy(x+25,y+25,"A");	
					}
	                
	            }
	            else
	            {
	            	setfillstyle(SOLID_FILL,BLACK);
	            	setbkcolor(BLACK);
	                bar(x,y,x+50,y+50);
	                 if(*(*(alfil->getTablero() + i) + j)=='*'){
	                	outtextxy(x+25,y+25," ");	
					}else if(*(*(alfil->getTablero() + i) + j)=='A'){
						setbkcolor(RED);
	                	outtextxy(x+25,y+25,"A");	
	            	}
	                
	            }
	            x+=50;
	        }
	        y+=50;
	        x=50;
	    }
	    getch();
	    closegraph();
	}
	
	
	void Solucion::solucionReinas(){
		srand(time(0));
		int fila, columna;
		fila = rand()%8+1;
		columna = rand()%8+1;
		
		cout<<"Fila:"<< fila<<endl;
		cout<<"Columna:"<< columna<<endl;
		cout<<endl;
		solucionFinal(fila,columna,0);
		mostrar();
		archivo.close();	
	}
