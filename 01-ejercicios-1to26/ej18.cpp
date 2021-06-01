/* 
Dado un valor M determinar y emitir un listado con los M primeros múltiplos de 3 que no lo sean de 5, dentro del conjunto de los números naturales.
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m;
    vector <int> rs;

    for(int i = 0; i < 5; i++){
        cout<<"Ingresar un numero natural: "; cin>>m;
        while(m <= 0){
            cout<<"No ingreso un numero natural. Ingrese denuevo: ";cin>>m;
        }
        if(m % 3 == 0 && m % 5 != 0){
            rs.push_back(m);
        }
    }
    cout<<"Numeros que son multiplos de 3 y no de 5: "<<endl;
    for(int j : rs){
        cout<<j<<endl;
    }

    return 0;
}