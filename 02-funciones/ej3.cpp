/* 
Confeccione una función que reciba un número entero n y devuelva el factorial de dicho
número.
*/

#include <iostream>

using namespace std;

int factorial( int );

int main(){
    int n;
    
    cin>>n;
    cout<<n<<"! = "<<factorial(n);

    return 0;
}


int factorial( int x ) {
    int rs = 1;
    if ( x <= 0) {
        if (x == 0) {
            rs = 1;
            return rs;
        } else {
            throw invalid_argument("Factorial de un numero unicamente acepta valores positivos");
        }
    } else {
        for (int i = 1; i <= x; i++) {
            rs = rs * i;
        }
        return rs;
    }

}