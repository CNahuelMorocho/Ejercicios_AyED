/* 
Dados dos valores enteros A y B, informar la suma, la resta y el producto.
 */

#include <iostream>

using namespace std;

int main (){
    int a, b, suma = 0, resta = 0, producto = 0;
    cout<<"Ingresar un numero: ";cin>>a;
    cout<<"Ingresar otro numero: ";cin>>b;

    suma = a + b;
    resta = a - b;
    producto = a * b;

    cout<<"La suma es: "<<suma<<"\nLa resta es: "<<resta<<"\nEl producto es: "<<producto;
    
    return 0;
}