/* 
Dados N valores informar el mayor, el menor y en que posición del conjunto fueron ingresados.
*/

#include <iostream>

using namespace std;

int main(){
    float n, mayor = 0, menor = 0, posicion_menor = 0, posicion_mayor;
    for(int i = 0; i < 4; i++){
        cout<<"Ingresar numero: ";cin>>n;
        if(i == 0){
            mayor = n;
            menor = n;
            posicion_menor = i+1;
            posicion_mayor = i+1;
            continue;
        }else if(n > mayor){
            mayor = n;
            posicion_mayor = i+1;
        }else if(n < menor){
            menor = n;
            posicion_menor = i+1;
        }

    }
    cout<<"Mayor: "<<mayor<<" Posicion: ["<<posicion_mayor<<"]"<<endl;
    cout<<"Menor: "<<menor<<" Posicion: ["<<posicion_menor<<"]"<<endl;
}