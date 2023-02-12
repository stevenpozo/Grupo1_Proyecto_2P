#include <string>


class Hexadecimal{
    private:
        char *cadena;
        int lenght;

    public:
        void setCadena(char* newCadena);
        char* getCadena();
        void setLenght(int newLenght);
        int getLenght();

};