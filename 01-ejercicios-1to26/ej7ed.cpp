/* 
Dado tres valores determinar e imprimir una leyenda según sea: “Forman triangulo” o “No forman triangulo”.
*/


#include <iostream>

using namespace std;

int main(){
    float l1, l2, l3;

    cin>>l1>>l2>>l3;

    if(l1 >= 0 && l2 >= 0 && l3 >= 0){
        if(l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1){ //Condición de desigualdad triangular
            cout<<"Forman un triangulo";
        }else{
            cout<<"No forman un triangulo";
        }
    }else{
        cout<<"El lado de un triangulo debe ser mayor a 0";
    }
    
    return 0;
}
