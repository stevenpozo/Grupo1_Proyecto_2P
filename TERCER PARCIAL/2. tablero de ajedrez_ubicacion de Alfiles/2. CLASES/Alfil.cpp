
#include "Alfil.h"

Alfil::Alfil(){
}
//crea un constructor clase Reina
Alfil::Alfil(int n, bool** validar, char** tablero, int contador)
{
	this->n = n;
	this->validar = validar;
	this->tablero = tablero;
	this->contador = contador;
}
 
  


Alfil::~Alfil()
{
   // TODO : implement
}


bool** Alfil::getValidar(void)
{
   return validar;
}


void Alfil::setValidar(bool** newValidar)
{
   validar = newValidar;
}


char** Alfil::getTablero(void)
{
   return tablero;
}


void Alfil::setTablero(char** newTablero)
{
   tablero = newTablero;
}


int Alfil::getContador(void)
{
   return contador;
}


void Alfil::setContador(int newContador)
{
   contador = newContador;
}


int Alfil::getN(void)
{
   return n;
}

void Alfil::setN(int newN)
{
    n = newN;
}