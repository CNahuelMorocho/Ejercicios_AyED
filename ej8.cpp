/* 
Dado un triángulo representado por sus lados L1, L2, L3, determinar e imprimir una leyenda según sea: equilátero, isósceles o escálenos.
 */

#include <iostream>

using namespace std;

int main(){
    int l1, l2, l3;

    cout<<"Ingresar los lados de un triangulo: "<<endl;
    cin>>l1>>l2>>l3;

    if(l1 + l2 > l3 && l1 + l3 > l2 && l3 + l2 > l1){ //Desigualdad triangular
        if(l1 == l2 && l2 == l3){
            cout<<"Es un triangulo equilatero.";
        }else if(l1 != l2 && l2 == l3 || l1 != l3 && l1 == l2|| l1 == l3 && l2 != l3){
            cout<<"Es un triangulo isosceles";
        }else{
            cout<<"Es un triangulo escaleno";
        }
    }

    return 0;
}