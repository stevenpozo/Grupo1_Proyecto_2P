
#include <iostream>
#include "Solucion.cpp"
#include "validar.h"
using namespace std;


int main(){
	
	int n;
	validar val;
	cout<<"\tIngrese el numero de Reinas"<<endl;
	n=val.ingresarEnteros(); 
	cout << endl;
	Solucion *sol=new Solucion(n) ;
	sol->solucionReinas();
	cout<<"Se creo el archivo txt"<<endl;
	
	return 0;
}