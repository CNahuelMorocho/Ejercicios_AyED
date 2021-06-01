/* 
Dados dos valores enteros y distintos, emitir una leyenda apropiada que informe cuál es el
mayor entre ellos.
 */

#include <iostream>

using namespace std;

int main(){
    int a, b;
    cout<<"Ingrese un valor: ";cin>>a;
    cout<<"Ingrese otro valor: ";cin>>b;

    if(a>b){
        cout<<"Mayor: "<<a;
    }else{
        cout<<"Mayor: "<<b;
    }
}