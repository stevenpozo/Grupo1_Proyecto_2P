#include "Conversion.h"
#include "Decimal.cpp"
#include "Binario.cpp"
#include "Hexadecimal.cpp"
#include "Octal.cpp"
#include "Validaciones.h"

#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

Decimal decimal;
Binario binario;
Hexadecimal hexa;
Octal octal;
Validaciones validar;


//DE DECIMAL A BINARIO
void Conversion::covertirDecimalABinario(int valor){
    int lenght = log2(valor)+1;
    binario.setLenght(lenght);
    binario.setBinario(new int[lenght]);
    cout<<"El numero decimal: "<<valor<<endl;
    cout<<"Numero binario: ";
    int i = 0;
    while(valor>0){
        *(binario.getBinario()+i) = valor%2;
        cout<<*(binario.getBinario()+i)<<"";
        valor/=2;
    }
    delete binario.getBinario();
}

void Conversion::mostrarConversionDAB(){
    int numero;
    cout<<"ingrese un numero decimal: ";
    numero = validar.validarEnteros();
    cout<<endl;
    decimal.setDecimal(numero);
    covertirDecimalABinario(decimal.getDecimal());
}


//DE BINARIO A DECIMAL
void Conversion::convertirBinarioADecimal(){
    int numDecimal = 0;
    int base = 1;

    for (int i = binario.getLenght()- 1; i >= 0; i--) {
        numDecimal += *(binario.getBinario()+i) * base;
        base *= 2;
    }
    decimal.setDecimal(numDecimal);
    cout<<"Numero decimal: "<< decimal.getDecimal()<<endl;
    delete binario.getBinario();
}

void Conversion::mostrarConversionBAD(){
    int numero;
    int contador=1;
    cout<<"ingrese el tamnio : "<<endl;
    numero=validar.validarEnteros();
    cout<<endl;
    binario.setLenght(numero);
    binario.setBinario(new int[numero]);
    cout<<"ingrese el numero binario: "<<endl;
    for(int i=0; i<numero; i++){
        cout<<"Binario ["<< contador<<"] =";
        *(binario.getBinario()+i) = validar.validarEnterosBinarios();
        cout<<endl;
        contador = contador+1;
    }
    convertirBinarioADecimal();
}

// DE HEXADECIMAL A DECIMAL

void Conversion::convertirHexadecimalADecimal(){

    int dec = 0;
    int base = 1; 

    for (int i = hexa.getLenght() - 1; i >= 0; i--) {
        if (*(hexa.getCadena()+i) >= '0' && *(hexa.getCadena()+i) <= '9') {
            dec += (*(hexa.getCadena()+i)  - '0') * base;
        }
        else if (*(hexa.getCadena()+i) >= 'A' && *(hexa.getCadena()+i)  <= 'F') {
            dec += (*(hexa.getCadena()+i)  - 'A' + 10) * base;
        }
        base *= 16;
    }

    cout << "Numero decimal: " << dec << endl;
    delete hexa.getCadena();
}

void Conversion::mostrarConversionHAD(){
    int numero;
    int contador=1;
    cout<<"ingrese el tamnio : "<<endl;
    numero=validar.validarEnteros();
    cout<<endl;
    hexa.setLenght(numero);
    hexa.setCadena(new char[numero]);
    cout<<"ingrese el numero Hexadecimal: "<<endl;
    for(int i=0; i<numero; i++){
        cout<<"Binario ["<< contador<<"] =";
        cin>>*(hexa.getCadena()+i);
        contador = contador+1;
    }
    convertirHexadecimalADecimal();
}


//DE DECIMAL A HEXADECIMAL

void Conversion::convertirDecimalAHexadecimal(char* cadena, int numeroDecimal){

    int i = 0;
    while(numeroDecimal != 0) {
        int residuo = numeroDecimal % 16;
        if (residuo < 10) {
            cadena[i++] = char(residuo + 48);
        } else {
            cadena[i++] = char(residuo + 55);
        }
        numeroDecimal /= 16;
    }
    std::reverse(cadena, cadena + i);
    cadena[i] = '\0'; 
    cout<<"Numero Hexadecimal: "<<cadena;
    delete[] cadena;
}

void Conversion::mostrarConversionDAH(){
    int numero;
    int lenght;
    cout<<"ingrese un numero entero: "<<endl;
    numero=validar.validarEnteros();
    cout<<endl;
    lenght = log2(numero)+3;
    hexa.setCadena(new char[lenght]);
    decimal.setDecimal(numero);
    convertirDecimalAHexadecimal(hexa.getCadena(),decimal.getDecimal());
}

//DE DECIMAL A OCTAL

void Conversion::convertirDecimalAOctal(int numeroDecimal){
    int numeroOctal = 0, i = 1;
    while (numeroDecimal != 0) {
        numeroOctal += (numeroDecimal % 8) * i;
        numeroDecimal /= 8;
        i *= 10;
    }
    cout<<"Numero octal: "<< numeroOctal;
}

void Conversion::mostrarConversionDAO(){
    int numero;
    cout<<"ingrese un numero entero: "<<endl;
    numero=validar.validarEnteros();
    cout<<endl;
    decimal.setDecimal(numero);
    convertirDecimalAOctal(decimal.getDecimal());
}