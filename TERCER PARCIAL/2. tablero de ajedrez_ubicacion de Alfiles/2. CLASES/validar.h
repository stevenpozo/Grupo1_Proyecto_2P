#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
class validar{
	public:
			
	int ingresarEnteros() {
	char *dato=new char[10];
	int i=0;
	int numero;
	char c;
	while((c=getch())!=13){
		
		if(c>='0' && c<='9' || c==45){
			
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