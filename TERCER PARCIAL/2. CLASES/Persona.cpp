/***********************************************************************
 * UFA-ESPE
 * Nombres: Steven Pozo,Quilumbaquin Jairo
 * Fecha de creacion: miércoles, 26 de octubre de 2022 19:06:30
 * Purpose: Implementation of the class Persona
 * Enunciado del problema: programar en datos abstractos para ingresar datos personales y calcular la edad
 ***********************************************************************/ 

#include <ctime>
#include <string>
#include <iostream>

#include "Persona.h"

using namespace std;


string Persona::getapellido(void)
{
   return apellido;
}


void Persona::setapellido(string newApellido)
{
   apellido = newApellido;
}


string Persona::getnombre(void)
{
   return nombre;
}


void Persona::setnombre(string newNombre)
{
   nombre = newNombre;
}


int Persona::getanioNacimiento(void)
{
   return anioNacimiento;
}

void Persona::setanioNacimiento(int newAnioNacimiento)
{
   anioNacimiento = newAnioNacimiento;
}


int Persona::getdiaNacimiento(void)
{
   return diaNacimiento;
}

void Persona::setdiaNacimiento(int newDiaNacimiento)
{
   diaNacimiento = newDiaNacimiento;
}


int Persona::getmesNacimiento(void)
{
   return mesNacimiento;
}

void Persona::setmesNacimiento(int newMesNacimiento)
{
   mesNacimiento = newMesNacimiento;
}

Persona::Persona(){
	//CONSTRUCTOR VACIO
}


void Persona::pedirDatos(void){
	
	string nombre;
	string apellido;
	int dia;
	int mes;
	int anio;
	
	cout<<"ingrese su nombre: "<<endl;
	cin>>nombre;
	cout<<"ingrese su apellido: "<<endl;
	cin>>apellido;
	cout<<"ingrese su anio de nacimiento: "<<endl;
	cin>>anio;
	cout<<"ingrese su mes de nacimiento: "<<endl;
	cin>>mes;
	cout<<"ingrese su dia de nacimiento: "<<endl;
	cin>>dia;
	
	setnombre(nombre);
	setapellido(apellido);
	setanioNacimiento(anio);
	setmesNacimiento(mes);
	setdiaNacimiento(dia);
	
}

void Persona::imprimirEdad(void){
	cout<<"La edad de "<<getnombre()+" "+getapellido()<<" es: "<<calcularEdad();
}

int Persona::calcularEdad()
{
  	time_t hoy = time(0);
	int anioActual;

   	tm *fechaActual = localtime(&hoy);
	
	//OBTENER LA FECHA ACTUAL
	int anio= 1900 + fechaActual->tm_year;
   	int mes=1 + fechaActual->tm_mon;
   	int dia=fechaActual->tm_mday;
   	
   	
   	//CALCULAR LA EDAD
   	if(getmesNacimiento()<mes){
	   anioActual = anio-getanioNacimiento();
    }
    else if(getmesNacimiento() == mes){
    	if(getdiaNacimiento()<dia+1){
    		anioActual=anio-getanioNacimiento();
		}else{
			anioActual=anio-getanioNacimiento()-1;
		}
	}else
		anioActual=anio-getanioNacimiento()-1;

   	return anioActual;         

}

