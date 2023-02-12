
class Conversion{

    public:
        //DE DECIMAL A BINARIO
        void covertirDecimalABinario(int val);
        void mostrarConversionDAB();

        //DE BINARIO A DECIMAL
        void convertirBinarioADecimal();
        void mostrarConversionBAD();
        
        //DE HEXADECIMAL A DECIMAL
        void convertirHexadecimalADecimal();
        void mostrarConversionHAD();

        //DE DECIMAL A HEXADECIMAL
        void convertirDecimalAHexadecimal(char* cadena,int numero);
        void mostrarConversionDAH();

        //DE DECIMAL A OCTAL
        void convertirDecimalAOctal(int numDecimal);
        void mostrarConversionDAO();
        
};