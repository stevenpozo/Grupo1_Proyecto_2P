#include <iostream>
#include "SolucionAlfil.cpp"
#include "SolucionReina.cpp"
#include "Validaciones.h"

using namespace std;

class Menu{
    public:
    	
    Validaciones validar;
    
    
		void mostrarMenuAlfil(){
            int opcAlfil;
            do{
            	SolucionAlfil *alfil = new SolucionAlfil();
            	system("CLS");
                cout<<"==========GRAFICO DE TABLA DE AJEDREZ========="<<endl;
	            cout<<"1. Grafica Alfil"<<endl;
	            cout<<"2. Regresar"<<endl;
	            cout<<"opcion: "<<endl;
                opcAlfil=validar.ingresarEnteros();
				cout<<endl;
				switch(opcAlfil){
					case 1:
						system("CLS");
						alfil->mostrarCoordenadas();
						
					/*
					//muestra  y dibujar tablero en tiempo de ejecucion
						alfil->mostrarTableroConsola();
						alfil->dibujarTablero();*/
					
						
					//muestra tablero y dibuja desde un archivo de texto
						alfil->mostrarTableroArchivo();
						alfil->dibujarTableroArchivo();
						system("PAUSE");
						break; 
					case 2:
						mostrarMenuPrincipal();
						system("PAUSE");
                		system("CLS");
						break;
				}
        	}while(opcAlfil>1 ||opcAlfil<3);
		}


		void mostrarMenuReina(){
            int opcReina;
            do{

				SolucionReina *reina = new SolucionReina();
            	system("CLS");
                cout<<"==========GRAFICO DE TABLA DE AJEDREZ========="<<endl;
	            cout<<"1. Grafica Reina"<<endl;
	            cout<<"2. Regresar"<<endl;
	            cout<<"opcion: "<<endl;
                opcReina=validar.ingresarEnteros();
				cout<<endl;
				switch(opcReina){
					case 1:
						system("CLS");
						reina->mostrarCoordenadas_Reina();
						
					/*
					//muestra  y dibujar tablero en tiempo de ejecucion
						reina->mostrarTableroConsola_Reina();
						reina->dibujarTablero_Reina();*/
						
						
					//muestra y dibuja tablero desde un archivo de texto
						reina->mostrarTableroArchivo_Reina();
						reina->dibujarTableroArchivo_Reina();
						system("PAUSE");
						break; 
					case 2:
						mostrarMenuPrincipal();
						system("PAUSE");
                		system("CLS");
						break;
				}
        	}while(opcReina>1 ||opcReina<3);
		}


		void mostrarMenuPrincipal(){
			int opc;
			system("CLS");
            do{
            	system("CLS");
                cout<<"==========GRAFICO DE TABLA DE AJEDREZ========="<<endl;
	            cout<<"1. Alfil"<<endl;
	            cout<<"2. Reina"<<endl;
	            cout<<"3. Salir"<<endl;
	            cout<<"opcion: "<<endl;
                opc=validar.ingresarEnteros();
				cout<<endl;
                switch(opc) {
                    case 1:
                    	system("CLS");
                    	mostrarMenuAlfil();
                    	system("PAUSE");
                        break;
                    case 2:
						system("CLS");
						mostrarMenuReina();
                        system("PAUSE");
                        break;
                    case 3:
                        exit(0);
                        break;
                }
            }while(opc>1 ||opc<4);
		}

};