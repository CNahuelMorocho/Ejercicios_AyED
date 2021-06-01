/* 
Se  ingresa  un  conjunto  de  valores float,  cada  uno  de  los  cuales  representan  el sueldo de un empleado, excepto el último valor que es cero e indica el fin del conjunto. Se pide desarrollar un programa que determine e informe:
a)Cuántos empleados ganan menos $1.520.
b)Cuántos ganan  $1.520 o más pero menos de $2.780.
c)Cuántos ganan $2.780 o más pero menos de $5.999.
d)Cuántos ganan $5.999 o más.
*/

#include <iostream>

using namespace std;

int main(){
    float sueldo;
    int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0;

    cout<<"Ingresar sueldo: "; cin>>sueldo;
    while(sueldo > 0){
        cout<<"Ingresar sueldo: "; cin>>sueldo;
        if(sueldo < 1520){
            cont1++;
        }else if (2780 > sueldo && sueldo >=1520){
            cont2++;
        }else if(5999 > sueldo && sueldo >= 2780){
            cont3++;
        }else if(sueldo >= 5999){
            cont4++;
        }
        
    }

    cout<<"Empleados que ganan menos de $1520:"<<cont1<<endl;
    cout<<"Empleados que ganan $1520 o mas pero menos de $2780:"<<cont2<<endl;
    cout<<"Empleados que ganan $2780 o mas pero menos que $5999:"<<cont3<<endl;
    cout<<"Empleados que ganan mas de $5999:"<<cont4<<endl;

    

    return 0;
}
