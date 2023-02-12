#include <iostream>
#include <graphics.h>
#include "Menu.h"

using namespace std;

int main(){
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
    Menu menu;

    menu.mostrarMenuPrincipal();
    
    getch();
	closegraph();
    return 0;
}