#include <iostream>
#include <fstream>
#include <conio.h>
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
					*(*(alfil->getTablero()+i)+j)='*';
				}
			}
   }

	void Solucion::crearArchivo(){
		archivo.open("exaustivo.txt",fstream::out);
		archivo<<"solucion"<<alfil->getN()<<"*"<<alfil->getN()<<endl<<endl;;
	}
	
	void Solucion::bloquear(int x, int y){
		int aux1,aux2;
		
		aux2=y;//diagonal
		aux1=x;
		while(aux1>0&&aux2>0){
			aux1--;
			aux2--;
		}
		aux2=y;
		aux1=x;
		while(aux1<alfil->getN() && aux2>0){
			aux1++;
			aux2--;
		}
		aux1--;
		aux2++;
		while(aux1>=0 && aux2<alfil->getN()){
			*(*(alfil->getValidar()+aux1)+aux2)=true;
			aux1--;
			aux2++;
		}
	}
	
	
	void Solucion::mostrar(){
		int contador=0;
		contador++;
		archivo<<"solucion N "<<contador <<endl;
		cout<<endl;
		for(int i=0;i<alfil->getN();i++){
			for(int j=0;j<alfil->getN();j++){
				archivo<<*(*(alfil->getTablero()+i)+j)<<" ";
				cout<<*(*(alfil->getTablero()+i)+j)<<" ";
			}
			archivo<<endl;
			cout<<endl;
		}
		archivo<<endl;
		cout<<endl;
	}
	void Solucion::quitarRelleno(int x, int y){
		*(*(alfil->getTablero() +x)+y)='*';
		for(int i=0;i<alfil->getN();i++){
			for(int j=0;j<alfil->getN();j++){
				*(*(alfil->getValidar() +i)+j)=false;
			}
		}
		for(int i=0;i<alfil->getN();i++){
			for(int j=0;j<alfil->getN();j++){
				if(*(*(alfil->getTablero() +i)+j)=='A')
				bloquear(i,j);
			}	
		}
	}

	
	void Solucion::solucionFinal(int x, int y, int n1){
		*(*(alfil->getTablero() +x)+y)='A';
		bloquear(x,y);
		if(n1==alfil->getN()){
			mostrar();
		}else{
			for(int i=0;i<alfil->getN();i++){
				if(*(*(alfil->getValidar() +i )+ y+1)==false){
					solucionFinal(i,y+1,n1+1);
				}
			}
		}
		quitarRelleno(x,y);
	}
	void Solucion::solucionReinas(){
		for(int i=0;i<alfil->getN();i++){
			solucionFinal(i,0,1);
		}
		archivo.close();	
	}
