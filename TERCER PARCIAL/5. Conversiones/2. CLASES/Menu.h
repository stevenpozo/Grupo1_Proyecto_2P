
#include <iostream>
#include "Conversion.cpp"
using namespace std;

class Menu{
    public:

        void mostraMenu(){
            int opc;
            Conversion c;
            do{
                system("CLS");
                cout<<"MENU DE CONVERSIONES"<<endl;
                cout<<"1. De decimal a binario"<<endl;
                cout<<"2. De binario a decimal"<<endl;
                cout<<"3. De hexadecimal a decimal"<<endl;
                cout<<"4. De decimal a hexadecimal"<<endl;
                cout<<"5. de decimal a octal"<<endl;
                cout<<"6. salir"<<endl;
                cout<<"Elija una opcion: ";
                cin>>opc;

                switch(opc){
                    case 1:
                        system("CLS");
                        c.mostrarConversionDAB();
                        cout<<endl;
                        system("PAUSE");
                        break;
                    case 2:
                        system("CLS");
                        c.mostrarConversionBAD();
                        cout<<endl;
                        system("PAUSE");
                        break;
                    case 3:
                        system("CLS");
                        c.mostrarConversionHAD();
                        cout<<endl;
                        system("PAUSE");
                        break;
                    case 4:
                        system("CLS");
                        c.mostrarConversionDAH();
                        cout<<endl;
                        system("PAUSE");
                        break;
                    case 5:
                        system("CLS");
                        c.mostrarConversionDAO();
                        cout<<endl;
                        system("PAUSE");
                        break;
                    case 6:
                        exit(0);
                        break;
                    default:
                        system("CLS");
                        break;
                }
            }while(opc<7 || opc>0);
        }
};