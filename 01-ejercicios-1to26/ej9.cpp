/* 
Dados un mes y el año correspondiente informar cuantos días tiene el mes.
 */

#include <iostream>

using namespace std;

int main(){
    int month = 0, year = 0, dJanuary = 31, dFebruary, dMarch = 31, dApril = 30, dMay = 31, dJune = 30, dJuly = 31, dAugust = 31, dSept = 30, dOctober = 31, dNov = 30, dDec = 31;

    bool leapYear = false;

    cout<<"Ingresar mes: ";cin>>month;
    cout<<"Ingresar anio: ";cin>>year;

    if(year % 4 == 0){
        if(year % 400 == 0 || year % 100 != 0){
            leapYear = true;
        }
    }

    switch (month){
        case 1: cout<< dJanuary;break;
        case 2: 
        if(leapYear == true){
            dFebruary = 29;
            cout<<dFebruary;
        }else{
            dFebruary = 28;
            cout<<dFebruary;
        };break;
        case 3:cout<<dMarch;break;
        case 4:cout<<dApril;break;
        case 5:cout<<dMay;break;
        case 6:cout<<dJune;break;
        case 7:cout<<dJuly;break;
        case 8:cout<<dAugust;break;
        case 9:cout<<dSept;break;
        case 10:cout<<dOctober ;break;
        case 11:cout<<dNov;break;
        case 12:cout<<dDec;break;
        default: cout<<"No es un mes valido";
    }

    return 0;
}