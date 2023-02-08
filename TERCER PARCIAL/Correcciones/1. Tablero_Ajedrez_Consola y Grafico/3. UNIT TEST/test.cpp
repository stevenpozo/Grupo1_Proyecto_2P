#include "pch.h"
#include "../src/AtzLib/ArchivoTablero.cpp"
#include "../src/AtzLib/GraficaTablero.cpp"
/**
 *@brief Tests para leer el archivo
 *@return true
*/
TEST(leerarchivo, leerarchivo) {
	EXPECT_EQ(CrearArchivo(), true);
}
/**
*@brief Tests para tener el tamaño de la matriz
 *@return int
*/
TEST(Matriz, tamaño) {
	EXPECT_EQ(Tamaniomatriz(), 32);
}
//Test para la funcion crear matriz
TEST(crearMatriz, crearMatriz) {
	char** vect;
	vect = new char* [7];
	for (int i = 0; i < 7; i++) {
		vect[i] = new char[7];
	}
	EXPECT_EQ(CrearMatriz(7,7), vect);
}