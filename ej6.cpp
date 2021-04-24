/* 
Dadas  dos  fechas  informar  cual  es  la  más  reciente.  Determine  cuales  serían  los datos de entrada  y las leyendas a informar de acuerdo al proceso solicitado.
 */

#include <iostream>

using namespace std;

int main(){
    int day1, day2, dayt, month1, month2, montht, year1, year2, yeart;

    cout<<"Ingresa la fecha actual...\nAño: ";cin>>yeart;
    cout<<"Mes: ";cin>>montht;
    cout<<"Dia: ";cin>>dayt;

    cout<<"Ingresa la primera fecha...\nAño: ";cin>>year1;
    cout<<"Mes: ";cin>>month1;
    cout<<"Dia: ";cin>>day1;

    cout<<"Ingresa la segunda fecha...\nAño: ";cin>>year2;
    cout<<"Mes: ";cin>>month2;
    cout<<"Dia: ";cin>>day2;

    int date1 = 0, date2 = 0, datet = 0;
    date1 = (year1*10000) + (month1*100) + day1;
    date2 = (year2*10000) + (month2*100) + day2;
    datet = (yeart*10000) + (montht*100) + dayt;

    if((datet > date1) && (datet > date2)){
        if(date1 != date2){
            if (date1 > date2){
            cout<<date1<<" es la fecha mas reciente";
            }else{
            cout<<date2<<" es la fecha mas reciente";
            }
        }else{
            cout<<"Ambas fechas son iguales.";
        }
        
    }else{
        cout<<"Ninguna de las fechas ingresadas pasaron antes que la actual.";
    }
      
    return 0;
}