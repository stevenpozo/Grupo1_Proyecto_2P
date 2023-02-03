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

#include <iostream>
#include <conio.h>


using namespace std;

class Validaciones{

    public:
        int ingresarEnteros() {
            char *dato=new char[10];
            int i=0;
            int numero;
            char c;
            while((c=getch())!=13){
                
                if(c>='0' && c<='9'){
                    
                    dato[i++]=c;
                    printf("%c",c);
                    numero = atoi(dato);
                        
                }else if(c==8){
                
                    dato[i]=0;
                    i--;
                        
                    putchar(8);
                    putchar(32);
                    putchar(8);			
                }
            }
            dato[i]='\0';
            return numero;
        }

        int pedirValorInicial(){
            int numero;
            cout<<"Ingrese el valor inicial: ";
            numero = ingresarEnteros();
            cout<<endl;
            return numero;
        }

        int pedirProgresionAritmetica(){
            int numero;
            cout<<"Ingrese el valor de la progresion aritmetica: ";
            numero = ingresarEnteros();
            cout<<endl;
            return numero;
        }

        int pedirDimension(){
            int numero;
            cout<<"Ingrese el valor de la dimension impar del 3 al 9:";
            numero = ingresarEnteros();
            cout<<endl;

            do{
                if(numero%2==0){
                    cout<<"Ingrese una dimension impar: "<<endl;
                    system("PAUSE");
                    system("CLS");
                    return pedirDimension();
                }else{
                    if(numero>=10 || numero<3){
                        cout<<"Ingrese una dimension dentro del rango de 3 y 9: "<<endl;
                        system("PAUSE");
                        system("CLS");
                        return pedirDimension();

                    }else{
                        return numero;
                    }
                }
            }while(numero%2==0);
        }

};