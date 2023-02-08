#include <iostream>
#include <conio.h>

class Validaciones{

    public:
    int ingresarEnteros() {
            char *dato=new char[10];
            int i=0;
            int numero;
            char c;
            while((c=getch())!=13){
                
                if(c>='1' && c<='3'){
                    
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

};