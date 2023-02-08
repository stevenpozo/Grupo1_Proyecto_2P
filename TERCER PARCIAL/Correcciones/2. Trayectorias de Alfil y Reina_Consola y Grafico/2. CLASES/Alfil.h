/***********************************************************************
 * Module:  Alfil.h
 * Author:  steve
 * Modified: viernes, 3 de febrero de 2023 20:35:08
 * Purpose: Declaration of the class Alfil
 ***********************************************************************/

#if !defined(__GraficoAlfil_Alfil_h)
#define __GraficoAlfil_Alfil_h

class Alfil
{
public:
   char** getTablero(void);
   void setTablero(char** newTablero);
   int getX(void);
   void setX(int newX);
   int getY(void);
   void setY(int newY);
   Alfil(char** _tablero);
   Alfil();
   ~Alfil();

protected:
private:
   char** tablero;
   int x;
   int y;


};

#endif