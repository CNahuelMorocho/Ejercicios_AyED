/* 
Dado tres valores determinar e imprimir una leyenda según sea: “Forman triangulo” o “No forman triangulo”.
*/

#include <iostream>

using namespace std;

int main(){
    int lado1, lado2, lado3, lmayor = 0;

    cin>>lado1;
    cin>>lado2;
    cin>>lado3;

    if(lado1 > lado2 && lado1 > lado3){
        lmayor = lado1;
    }else if(lado2 > lado1 && lado2 > lado3){
        lmayor = lado2;
    }else if(lado3 > lado2 && lado3 > lado1){
        lmayor = lado3;
    }
    
    if((lado1 > 0) && (lado2 > 0) && (lado3 > 0)){
        if(lmayor == lado1){
            if(lado2 + lado3 > lmayor){
                cout<<"Es triangulo";
            }else{
                cout<<"No es triangulo";
            }
        }else if(lmayor == lado2){
            if(lado1 + lado3 > lmayor){
                cout<<"Es triangulo";
            }else{
                cout<<"No es triangulo";
            }
        }else if(lmayor == lado3){
            if(lado1 + lado2 > lmayor){
                cout<<"Es triangulo";
            }else{
                cout<<"No es triangulo";
            }
        }
    }else{
        cout<<"Error. Un triangulo necesita tener 3 lados positivos";
    }
    
    return 0;
}
