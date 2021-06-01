/* Confeccione una función que, dado un valor por parámetro, devuelva el módulo de dicho
valor a través de su invocación. Que devuelva un valor a través de su invocación quiere decir
que tiene que tiene que devolver dicho valor a través del return. */

#include <iostream>

using namespace std;

float modulo(float);

int main() {
    float n;
    cout<<"Ingresar un valor: "; cin>>n;
    cout<<"El valor absoluto de "<<n<<" es: "<<modulo(n);

    return 0;   
}

float modulo (float x) {
    if ( x >= 0 ) {
        return x;
    }else {
        return -x;
    }
}