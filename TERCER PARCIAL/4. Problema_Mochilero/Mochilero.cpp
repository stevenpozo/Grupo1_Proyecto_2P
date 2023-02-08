#include <iostream>
using namespace std;

int main(){

    int capacidad = 5, peso =0, valor=0, vgp=0 ;
    int peso_objetos[] = {1,2,2,2};
    int valor_objetos[] = {5,2,2,20};

    //ganancia valor tecnico
    int objetos_valor_peso[4] = {0,0,0,0};
    int lenght = sizeof(objetos_valor_peso)/sizeof(objetos_valor_peso[0]);

    for(int i = 0; i < lenght; i++){
        objetos_valor_peso[i] = valor_objetos[i]/peso_objetos[i];
        cout<<objetos_valor_peso[i]<< " ";
    }

    //algoritmo burbuja
    for(int i=lenght-1; i>=0; i--){
        for(int j = 0; j < i; j++){
            if(objetos_valor_peso[j]> objetos_valor_peso[j+1]){
                int aux = objetos_valor_peso[j];
                objetos_valor_peso[j] = objetos_valor_peso[j+1];
                objetos_valor_peso[j+1]=aux;

                int aux2 = peso_objetos[j];
                peso_objetos[j] = peso_objetos[j+1];
                peso_objetos[j+1]=aux2;

                int aux3 = valor_objetos[j+1];
                valor_objetos[j]=valor_objetos[j+1];
                valor_objetos[j+1]=aux3;
            }
        } 
        cout << endl;
        cout << "[";
        cout<< objetos_valor_peso[i]<<", ";
        cout<< peso_objetos[i]<< ", ";
        cout<< valor_objetos[i]<< ", ";
        cout<<"]"<<endl;

        //funcion mochila

        if(peso_objetos[i] <= capacidad){
            peso+=peso_objetos[i];
            valor+= valor_objetos[i];
            vgp += objetos_valor_peso[i];
            capacidad-+ peso_objetos[i];
        }else{
            break;
        }
        cout<<"peso: "<< peso << endl;
        cout<<"Valor: "<< valor << endl;
        cout<<"Ganancia valor-peso: "<< vgp << endl;

    }
    return 0;
}
