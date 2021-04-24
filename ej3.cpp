/* 
Dada un numero entero de la forma (AAAAMMDD), que representa una fecha
valida mostrar el dia, mes y año que representa. 
*/


#include <iostream>
#include <locale.h>

using namespace std;

int main(){
    setlocale(LC_CTYPE,"Spanish");
    int fecha, dia=0, mes=0, anio=0;

    cout<<"Ingresar una fecha: ";cin>>fecha;
    dia = (fecha % 100);
    cout<<"Dia: "<<dia<<endl; 
    mes = ((fecha % 1000)/100);
    cout<<"Mes: "<<mes<<endl;
    anio = ((fecha - mes - dia)/10000);
    cout<<"Año: "<<anio<<endl;


    return 0;
}