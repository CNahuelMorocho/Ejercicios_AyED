/* 
Dados  50  números  enteros,  informar  el  promedio  de  los  mayores  que  100  y  la suma de los menores que –10
 */

#include <iostream>

using namespace std;

int main(){
    int num, sum = 0, cont = 0, tot = 50;
    float prom = 0;

    for(int i = 0; i < tot; i++){
        cout<<"Ingresar numero: ";cin>>num;
        if(num > 100){
            cont++;
        }else if(num < -10){
            sum = sum + num;
        }
    }

    prom = (float(cont)/float(tot))*100;

    cout<<"Promedio de los mayores que 100: "<<prom<<"%"<<endl;

    cout<<"Suma de los menores que -10: "<<sum;

    return 0;
}