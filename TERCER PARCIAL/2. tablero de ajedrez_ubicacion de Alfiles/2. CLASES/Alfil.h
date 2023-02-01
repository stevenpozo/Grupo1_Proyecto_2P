

class Alfil
{
public:
   Alfil();
   Alfil(int, bool**, char**, int);
   ~Alfil();
   bool ** getValidar(void);
   void setValidar(bool ** newValidar);
   char** getTablero(void);
   void setTablero(char** newTablero);
   int getContador(void);
   void setContador(int newContador);
   int getN(void);
   void setN(int newN);
   void crearTablero(int i, int n);
   void validarPosicion(int i,int n);

protected:
private:
   bool** validar;
   char** tablero;
   int contador=0;
   int n=0;
};