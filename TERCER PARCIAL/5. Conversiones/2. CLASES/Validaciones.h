#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cctype>
#include <conio.h>
#include <cctype>


using namespace std;

class Validaciones
{
public:
	int validarEnteros() {
		char* dato = new char[10];
		int i = 0;
		int numero;
		char c;
		while ((c = getch()) != 13) {

			if (c >= '0' && c <= '9') {

				dato[i++] = c;
				printf("%c", c);
				numero = atoi(dato);

			}
			else if (c == 8 && i != 0) {

				dato[i - 1] = 0;
				i--;

				putchar(8);
				putchar(32);
				putchar(8);
			}
		}
		dato[i] = '\0';
		return numero;
	}

    int validarEnterosBinarios() {
		char* dato = new char[10];
		int i = 0;
		int numero;
		char c;
		while ((c = getch()) != 13) {

			if (c >= '0' && c <= '1') {

				dato[i++] = c;
				printf("%c", c);
				numero = atoi(dato);

			}
			else if (c == 8 && i != 0) {

				dato[i - 1] = 0;
				i--;

				putchar(8);
				putchar(32);
				putchar(8);
			}
		}
		dato[i] = '\0';
		return numero;
	}

	char* validarStrings() {
		char* dato = new char[0];
		char c;
		int i = 0;

		while ((c = getch()) != 13) {
			if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
				dato[i++] = toupper(c);
				printf("%c", c);
			}
			else if (c == 8 && i != 0) {

				*(dato + (i - 1)) = 0;
				i--;

				putchar(8);
				putchar(32);
				putchar(8);
			}
		}
		dato[i] = '\0';
		return dato;
		delete[]dato;
	}
};