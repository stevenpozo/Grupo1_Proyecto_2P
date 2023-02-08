/*
	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	INTEGRANTES:
		- STEVEN POZO
		- JAIRO QUILUMBAQUIN
		- SEBASTIAN PAUCAR
	NRC: 7999
	FECHA DE ENTREGA: 27/01/2023
	TEMA: CREAR UN TABLERO DE AJEDREZ DE 1 Y 0 QUE SEA LEIDO DESDE UN ARCHIVO DE TEXTO
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <cstring>
#include <string>
#include <graphics.h>
#define FILA 8
#define COLUMNA 8

using namespace std;
using std::string;

class Matriz{
	
	public:
		
//GENERAR TABLA DE AJEDREZ EN TIEMPO DE EJECUCION
		int** crearMatriz(){
			int **matriz;
			matriz=new int*[FILA];
			
			for(int i=0;i<FILA;i++){
				matriz[i]=new int[COLUMNA];
			}
			return matriz;	
		}
		
		void rellenarTablero(int **matriz){	
			for(int i=0;i<FILA;i++){
				for(int j=0;j<COLUMNA;j++){
						*(*(matriz+i)+j)= (i+j)%2;
			
				}
			}
			cout<<"\n";
		}
		
		
		void mostrarTablero(int **matriz){
    		int i;
	
			for(int i=0;i<FILA;i++){
				for(int j=0;j<COLUMNA;j++){
					if(*(*(matriz+i)+j)==1){
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0| BACKGROUND_INTENSITY);
					}else{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10|0);
					}
					cout<<*(*(matriz+i)+j)<<" ";
				}
				cout<<"\n";
			}
		}
		
		bool crearArchivo(int **matriz){
			int i;
			int j;
			ofstream tablero;
   			tablero.open("Ajedrez.txt",ios::trunc);
   			
			if(tablero.is_open()){
				for(i=0; i<FILA; i++){
					for (j=0; j<COLUMNA; j++) {
            			tablero << *(*(matriz+i)+j);
        			}
        		cout << endl;
        		tablero <<endl;
    			}
			}
			
			return true;
		}
		
		
//GENERAR TABLA DE AJEDREZ DESDE UN ARCHIVO DE TEXTO

		char** crearMatrizArchivo(){
			char **matriz;
			matriz=new char*[FILA];
			
			for(int i=0;i<FILA;i++){
				matriz[i]=new char[COLUMNA];
			}
			return matriz;	
		}
		
		char** LeerArchivo(){
		
		    ifstream tablero;
		    string line;
		    int filas;
		    int cont=0;
		    char** TableroMatriz=NULL;
		
		    TableroMatriz=crearMatrizArchivo(); 
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
		
		void generarTablero(){
		    char** prueba=NULL;
		    char codigo;
		
		    prueba=LeerArchivo();
		
		    for (int i = 0; i < FILA; i++)
		    {
		        for (int j = 0; j <COLUMNA; j++)
		        {
		            codigo=*(*(prueba+i)+j);
		            ColorearTabla(codigo);
		            cout<<*(*(prueba+i)+j)<<" ";
		        }
		        cout<<endl;
		    } 
		}
		
		void ColorearTabla(char codigo){
		    if(codigo=='1'){
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0|BACKGROUND_INTENSITY );
			}else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10| 0);
			}
		}
		
		//GRAFICO
		
	void graficarTableroAjedrez(){
		
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"");
		char** prueba=NULL;
   		prueba=LeerArchivo();
		   	
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
	                	setcolor(BLACK);
	                	outtextxy(x+25,y+25,"0");	
					}else if(*(*(prueba + i) + j)=='1'){
						setcolor(WHITE);	
	                	outtextxy(x+25,y+25,"1");
					}
	                
	            }
	            else
	            {
	            	setfillstyle(SOLID_FILL,BLACK);
	            	setbkcolor(BLACK);
	                bar(x,y,x+50,y+50);
	                 if(*(*(prueba + i) + j)=='0'){
	                 	setcolor(BLACK);
	                	outtextxy(x+25,y+25,"0");	
					}else if(*(*(prueba + i) + j)=='1'){
						setcolor(WHITE);
						outtextxy(x+25,y+25,"1");	
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
		
};
