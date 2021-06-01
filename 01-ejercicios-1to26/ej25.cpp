/* 
Dada una serie de M pares {color, número} que corresponden a los tiros de una ruleta. Se pide informar:
    a) Cuántas veces salió el número cero y el número anterior a cada cero
    b) Cuántas  veces seguidas llegó a repetirse el color negro
    c) Cuántas  veces seguidas llegó a repetirse el mismo número y cuál fue
    d) El mayor número de veces seguidas que salieron alternados el rojo y el negro
    e) El mayor número de veces seguidas que se negó la segunda docenas
*/


#include <iostream>
#include <ctype.h>

using namespace std;

int main() {
    int m, number, cntRepBlack = 0, cntBfZero = 0, cntZeros = 0, saveNum = 0, cntRepNum = 0, cntAltCol = 0;
    char color, saveColor;
    
    cout<<"Ingresar cantidad de pares: ";cin>>m;

    for(int i = 0; i < m; i++){
        cout<<"Ingresar numero: ";cin>>number;
        cout<<"Ingresar color [(n)egro o (r)ojo]: ";cin>>color;
        
        // <------------ Comparaciones --------------->
        if (tolower(color) == 'n' && tolower(saveColor) == 'n' && i > 0){ 
            /* Si ambos colores son iguales y no es la primera entrada,  aumento el contador de cantidad de negros repetidos */
            cntRepBlack++;
            
            
        } else if (towlower(color) != towlower(saveColor) && i > 0){
            cout<<"FLAG"<<endl;
            cntAltCol++;
            if(cntRepBlack > 0){
                cout<<"La cantidad de veces que se repitio el color negro: "<<cntRepBlack<<endl;
                cntRepBlack = 0;
            }
        } else if (towlower(color) == towlower(saveColor) && cntAltCol > 0){
                /* Si el contador de alternos es mayor a 0 muestro la cantida de veces que se repitieron y reinicio el contador. */
                cout<<"La cantidad de veces que salieron alternados los colores fueron: "<<cntAltCol<<endl;
                cntAltCol = 0;
        }


        if(number == saveNum && i > 0){
            cntRepNum++;
        }else if (cntRepNum > 0 && number != saveNum){
            cout<<"Se repitio el "<<saveNum<<": "<<cntRepNum<<" veces"<<endl;
        }

        if (number == 0) {
            cntZeros++;
            if(saveNum != 0){
                cntBfZero++;
            }
        }else{
            saveNum = number;
            saveColor = color;
        }
        
    }
    /* Si termina antes de que se repitan  */
    if(cntAltCol > 0){
        cout<<"La cantidad de veces que salieron alternados los colores fueron: "<<cntAltCol<<endl;
                
    }
    if(cntRepBlack > 0){
        cout<<"La cantidad de veces que se repitio el color negro: "<<cntRepBlack<<endl;
    }

    cout<<"La cantidad de ceros: "<<cntZeros<<endl;
    cout<<"La cantidad de numeros antes del cero: "<<cntBfZero<<endl;

    return 0;
}