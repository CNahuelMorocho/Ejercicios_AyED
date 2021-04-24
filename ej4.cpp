/* 
A partir de un valor entero ingresado por teclado, se pide informar:
a) La quinta parte de dicho valor
b) El resto de la división por 5
c) La séptima parte del resultado del punto a)
 */

#include <iostream>

using namespace std;

int main(){
    int x; 
    float cociente = 0, resto, cocienteDiv7 = 0;

    cout<<"Ingresar un valor: ";cin>>x;

    cociente = float(x)/5;
    resto = x - (cociente * 5);
    cocienteDiv7 = cociente / 7;

    cout<<"Quinta parte del valor: "<<cociente<<"\nResto de la quinta parte del valor: "<<resto<<"\nSeptima parte de la quinta parte: "<<cocienteDiv7;

    return 0;
}