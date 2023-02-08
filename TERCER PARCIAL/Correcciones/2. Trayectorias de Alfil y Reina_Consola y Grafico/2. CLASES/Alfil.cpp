/***********************************************************************
 * Module:  Alfil.cpp
 * Author:  steve
 * Modified: viernes, 3 de febrero de 2023 20:35:08
 * Purpose: Implementation of the class Alfil
 ***********************************************************************/

#include "Alfil.h"


char** Alfil::getTablero(void)
{
   return tablero;
}


void Alfil::setTablero(char** newTablero)
{
   tablero = newTablero;
}


int Alfil::getX(void)
{
   return x;
}


void Alfil::setX(int newX)
{
   x = newX;
}


int Alfil::getY(void)
{
   return y;
}


void Alfil::setY(int newY)
{
   y = newY;
}


Alfil::Alfil(char** _tablero)
{
   this->tablero = _tablero;
}

Alfil::Alfil(){
   
}

Alfil::~Alfil()
{
}