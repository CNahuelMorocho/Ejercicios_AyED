/* 
Un buque de carga traslada 100 contenedores a tres diferentes puertos del país. Los puertos se identifican con los números 1, 2 y 3. 
De cada contenedor que el buque traslade se registran los siguientes datos:
    -Identificación del contenedor
    -Peso del contenedor en kg
    -Puerto de arribo(un valor de 1 a 3).

Se pide calcular e informar:
    1)El peso total que el buque debe trasladar
    2)La identificación del contenedor de mayor peso
    3)La cantidad de contenedores que debe trasladar a cada puerto    
 */

#include <iostream>

using namespace std;

int main(){
    int id, idMayorPeso = 0, numPuerto, cntPuertoUno = 0, cntPuertoDos = 0, cntPuertoTres = 0;
    float peso, pesoTotal = 0, mayorPeso = 0;

    for ( int i = 0; i < 5; i++ ) {
        cout<<"Ingresar id del contenedor: ";cin>>id;
        cout<<"Ingresar el peso del contenedor de id "<<id<<": ";cin>>peso;
        cout<<"Ingresar el puerto destino: ";cin>>numPuerto;

        if ( i == 0 ) {
            mayorPeso = peso;
        }else if ( peso > mayorPeso ) { 
            mayorPeso = peso;
            idMayorPeso = id;
        }

        switch (numPuerto){
            case 1: cntPuertoUno++;
            case 2: cntPuertoDos++;
            case 3: cntPuertoTres++;
        }

        pesoTotal = pesoTotal + peso;
    }

    cout<<"============================================================="<<endl;
    cout<<"El peso total es: "<<pesoTotal<<endl;
    cout<<"El ID del contenedor de mayor peso es: "<<idMayorPeso<<endl;
    cout<<"Contenedores con destino Puerto 1: "<<cntPuertoUno<<endl;
    cout<<"Contenedores con destino Puerto 2: "<<cntPuertoDos<<endl;
    cout<<"Contenedores con destino Puerto 3: "<<cntPuertoTres<<endl;


    return 0;
}
