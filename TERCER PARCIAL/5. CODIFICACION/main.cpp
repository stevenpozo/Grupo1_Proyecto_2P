/***********************************************************************
 * UFA-ESPE
 * Nombres: Steven Pozo,Quilumbaquin Jairo
 * Fecha de creacion: miércoles, 26 de octubre de 2022 19:06:30
 * Purpose: Implementation of the class Persona
 * Enunciado del problema: programar en datos abstractos para ingresar datos personales y calcular la edad
 ***********************************************************************/ 

#include <iostream>
#include "Persona.cpp"
using namespace std;

int main(){
	Persona persona1= Persona();
	persona1.pedirDatos();
 	persona1.calcularEdad();
 	persona1.imprimirEdad();
}