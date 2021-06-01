/* 
Dada una terna de números naturales que representan al día, al mes y al año de una
determinada fecha informarla como un solo número natural de 8 dígitos con la forma
(AAAAMMDD).
*/
#include <iostream>
#include <string.h>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_CTYPE,"Spanish");
    int anio, dia, mes;
    string fecha = "";

    cout<<"Ingresar año: ";cin>>anio;
    cout<<"Ingresar mes: ";cin>>mes;
    cout<<"Ingresar dia: ";cin>>dia;

    string stAnio = to_string(anio);

    string stMes = "";
    if(mes < 10){
        stMes = to_string(mes);
        stMes = "0" + stMes;
    }else{
        stMes = to_string(mes);
    }

    string stDia = "";
    if(dia < 10){
        stDia = to_string(dia);
        stDia = "0" + stDia;
    }else{
        stDia = to_string(dia);
    }

    
    fecha = stAnio+stMes+stDia;

    int iFecha = stoi(fecha);
    
    cout<<iFecha;

    return 0;
}






/* #include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

int main(){
    int dia, mes, anio;
    string fecha = "";
    char stAnio[4] = "";
    char stMes[2] = "";
    char stDia[2] = "";

    cout<<"Ingresar año: ";cin>>anio;
    cout<<"Ingresar mes: ";cin>>mes;
    cout<<"Ingresar dia: ";cin>>dia;
    
    stAnio[4] = (to_string(anio));
    while(strlen(stAnio) < 4){
        cout<<"Ingrese el año completo por favor.\nIngresar año nuevamente: ";cin>>anio;
        stAnio[4] = (to_string(anio));
    }
    char stMes[2] = (to_string(mes));
    while(strlen(stMes) < 2){
        cout<<"Ingrese el año completo por favor.\nIngresar año nuevamente: ";cin>>anio;
        stAnio[2] = (to_string(anio));
    }

    char stDia[2] = (to_string(dia));
    while(strlen(stDia) < 2){
        cout<<"Ingrese el año completo por favor.\nIngresar año nuevamente: ";cin>>anio;
        stAnio[2] = (to_string(dia));
    }
    
    fecha[] = stAnio+stMes+stDia;
    int fechaInt = atoi(fecha);

    cout<<"La fecha es: "<<fecha;

    return 0;
} */

