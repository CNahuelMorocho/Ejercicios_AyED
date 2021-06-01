/* 
Informar los primeros 100 números naturales y su sumatoria
 */

#include <iostream>

using namespace std;

int main(){
    int suma = 0;

    for (int i = 0; i <= 100; i++){
        cout<<i<<endl;
        suma += i;
    }
    cout<<"La suma total es: "<<suma;
    
    return 0;
}