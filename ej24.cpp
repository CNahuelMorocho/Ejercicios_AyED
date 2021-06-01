/* 
Se dispone de un lote de valores enteros positivos que finaliza con un número negativo.
El lote está dividido en sublotes por medio de valores cero. Desarrollar un programa que determine e informe:

    a) por cada sublote el promedio de valores
    b) el total de sublotes procesados
    c) el valor máximo del conjunto, indicando en que sublote se encontró y la posición relativa del mismo dentro del sublote
    d) valor mínimo de cada sublote

Nota: El lote puede estar vacío (primer valor negativo), o puede haber uno, varios o todos los sublotes vacíos (ceros consecutivos)
*/

#include <iostream>

using namespace std;

int main () {

    float value, subL = 0, prom = 0, tot = 0, count = 0, minSub = 0,  maxL = 0, posMaxL = 0, subLMax = 0;
    bool firstEntry = true;

    do {
        cout<<"Ingresar valor: ";cin>>value;
        if (firstEntry && value > 0){
            firstEntry = false;
            minSub = value;
            maxL = value;
            count++;
            tot = tot + value; 
        } else { 
            if (value < minSub && value > 0){
                minSub = value;
            } else if (value > maxL && value > 0){
                maxL = value;
                posMaxL = count;
                subLMax = subL;
            }

            count++;
            tot = tot + value; 
        }
        
        if (value == 0) {
            subL++;

            prom = tot / count;
            
            cout<<"Promedio: "<<prom<<endl;
            cout<<"Valor minimo del sublote ["<<subL<<"]: "<<minSub<<endl;

            //reinicio las variables
            minSub = 0;
            firstEntry = true;
            count = 0;
            tot = 0;
            continue;
        }


    } while(value >= 0);

    cout<<"Total de sublotes procesados: "<<subL<<endl;
    cout<<"Valor maximo del lote: "<<maxL<<"\nSublote del valor maximo del lote: "<<subLMax<<"\nPosicion dentro del sublote del valor maximo del lote: "<<posMaxL<<endl;

    return 0;
}