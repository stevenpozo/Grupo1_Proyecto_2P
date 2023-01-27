#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "ArchivoTablero.h"

using namespace std;

bool CrearArchivo(){
    
    ofstream tablero;
    tablero.open("Tablero.txt",ios::out);

    for(int i=0; i<8;i++) {
        if(i%2==0){
            FilaTipo2();    
        }else{
            FilaTipo1();
        }
        
    }
    

   return true;

}

void FilaTipo1(){
    ofstream tablero;
    tablero.open("Tablero.txt",ios::app);

    if(tablero.is_open()){
        for(int i=0; i<4;i++) {
            for(int k=0;k<4;k++) {
                for(int j=0; j<16;j++) {

                    if(j>7){
                        tablero<<"1";
                    }else{
                        tablero <<"0";
                    }
        
                }

            }
        
        tablero <<endl;
        }

    }
    
    

}

void FilaTipo2(){
    
    ofstream tablero;
    tablero.open("Tablero.txt",ios::app);

    if(tablero.is_open()){
        for(int i=0; i<4;i++) {
            for(int k=0;k<4;k++) {
                for(int j=0; j<16;j++) {

                    if(j>7){
                        tablero<<"0";
                    }else{
                        tablero <<"1";
                    }
        
                }

            }
        
        tablero <<endl;
        }

    }
    
}