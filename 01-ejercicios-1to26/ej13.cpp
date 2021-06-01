/* 
Dados N y M números naturales, informar su producto por sumas sucesivas.
*/

#include <iostream>

using namespace std;

int main(){
    int n = 0, m = 0, rs = 0;

    cout<<"Ingresar un numero natural: ";cin>>n;
    cout<<"Ingresar otro numero natural: ";cin>>m;

    while(n <  0 || m < 0){cout<<"No ingresaste un numero natural\nIngrese los numeros nuevamente: ";cin>>n>>m;}

    for(int i = 0; i < m; i++){
        rs = rs + n;
        
    }
    cout<<rs<<endl;
    
    return 0;
}