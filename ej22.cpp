/* 
Dado  un  conjunto  de  Nombres  y  Fechas  de  nacimientos  (AAAAMMDD),  que finaliza con un Nombre= ‘FIN’, informar el nombre de la persona con mayor edad y el de la más joven.
 */

#include <iostream>
#include <string>

using namespace std;

int main(){
    string nombre, nomViejo = "", nomJoven = "";
    int fnac, mayor = 0, menor = 0, i = 0;

    cout<<"Ingresar nombre: ";cin>>nombre;
    cout<<"Ingresar fecha de nacimiento: ";cin>>fnac;
    while(nombre != "FIN"){
        if(i == 0){
            nomViejo = nombre;
            nomJoven = nombre;
            mayor = fnac;
            menor = fnac;
            i++;
            continue;
        }else{
            cout<<"Ingresar nombre: ";cin>>nombre;
            cout<<"Ingresar fecha de nacimiento: ";cin>>fnac;
            if(fnac > mayor){
                mayor =  fnac;
                nomJoven = nombre;
            }else if (fnac < menor){
                menor = fnac;
                nomViejo = nombre;
            }
            i++;
        }
        
    }

    cout<<"El mas viejo es: "<<nomViejo;
    cout<<"El mas joven es: "<<nomJoven;
      
}