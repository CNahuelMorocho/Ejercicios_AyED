/* 
Dados 10 valores informar el mayor
*/

#include <iostream>

using namespace std;

int main(){
    float n, mayor = 0;
    for(int i = 0; i < 10; i++){
        cout<<"Ingresar numero: ";cin>>n;
        if(i == 0){
            mayor = n;
            continue;
        }else if(n > mayor){
            mayor = n;
        }

    }
    cout<<"Mayor: "<<mayor;
}