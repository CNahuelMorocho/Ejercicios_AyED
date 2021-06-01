/* 
Dado un conjunto de valores, que finaliza con un valor nulo, determinar e imprimir (si hubo valores):
    a) El valor máximo negativo
    b) El valor mínimo positivo
    c) El valor mínimo dentro del rango -17.3 y 26.9
    d) El promedio de todos los valores
*/

#include <iostream>

using namespace std;

int main() {
    float value, maxN = 0, minP = 0, minR = 0, prom = 0, tot = 0, count = 0;
    bool firstEntryN = true, firstEntryP = true, firstEntryR;
    
    do { 
        cout<<"Ingresar valor: ";cin>>value;
        if (value < 0 && firstEntryN) {
            firstEntryN = false;
            maxN = value;
        } else if (value < 0 && value > maxN) {
            maxN = value;
        } 
        
        if (value > 0 && firstEntryP) {
            firstEntryP = false;
            minP = value;
        } else if (value > 0 && value < minP) {
            minP = value;
        }

        if (value > -17.3 && value <26.9 && firstEntryR) {
            firstEntryR = false;
            minR = value;
        }else if (value > -17.3 && value <26.9 && value < minR) {
            minR = value;
        }

        count++;
        tot = tot + value;
    
    } while (value != 0);

    prom = tot / count;

    cout<<"Valor maximo negativo: "<<maxN<<endl;
    cout<<"Valor minimo positivo: "<<minP<<endl;
    cout<<"Valor minimo dentro de (-17.9 ; 26.9): "<<minR<<endl;
    cout<<"Promedio: "<<prom<<endl;
    

    return 0;
}