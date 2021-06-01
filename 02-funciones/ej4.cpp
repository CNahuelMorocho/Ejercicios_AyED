/* Elabore un procedimiento que reciba tres parámetros, n1, n2 y mayor. A través del
parámetro “mayor” devuelva el mayor número entre n1 y n2.
*/

#include <iostream>

using namespace std;


void getMayor( int num1, int num2, int mayor );

int main() {
    int num1, num2, mayor = 0;

    cin>>num1;
    cin>>num2;

    getMayor( num1,num2, mayor );

    return 0;
}

void getMayor( int num1, int num2, int mayor ) {
    if ( num1 >= num2) {
        mayor = num1;
        cout<<mayor;
    } else {
        mayor = num2;
        cout<<mayor;
    }
}