/* 
Ingresar  e  informar  valores,  mientras  que  el  valor  ingresado  no  sea  negativo. Informar la cantidad de valores ingresados.
*/

#include <iostream>

using namespace std;

int main(){
    int number, count = 0;
    cout<<"Ingresar numero positivo: ";cin>>number;

    while(number >= 0){
        cout<<"Ingresar numero positivo: ";cin>>number;
        count++;
    }
    cout<<"Cantidad de numeros positivos ingresados: "<<count;
}