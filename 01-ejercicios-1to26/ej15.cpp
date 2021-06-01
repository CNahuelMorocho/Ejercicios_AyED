/* 
Se realiza una inspección en una fábrica de pinturas, y se detectaron 20 infracciones. De cada infracción se tomó nota de los siguientes datos:
    -Tipo de Infracción (1, 2, 3, ó 4)
    -Motivo de la infracción
    -Valor de la multa 
    -Gravedad de la infracción (‘L’,‘M’, ‘G’)
Se pide informar al final del proceso: 
    -Los valores totales de la multa a pagar de acuerdo al tipo de gravedad.
    -La leyenda “Clausurar fábrica” si la cantidad de infracciones 3 y 4 con gravedad “G” sean mayor a 3
*/

#include <iostream>

using namespace std;

int main(){
    int tot_infracciones = 20, tipo_infraccion = 0, multa_tot = 0, multa_ind = 0, count = 0;
    char gravedad[] = ""; 
    char motivo_inf[15]; 

    for(int i = 0; i < tot_infracciones; i++ ){
        cout<<"Ingresar tipo de infraccion (1, 2, 3 o 4): ";cin>>tipo_infraccion;
        while(tipo_infraccion != 1 && tipo_infraccion != 2 && tipo_infraccion != 3 && tipo_infraccion != 4){
            cout<<"Tipo de infraccion invalida.\nIngrese nuevamente el tipo de infraccion: ";cin>>tipo_infraccion;
        }

        cout<<"Ingresar motiva de infracción: ";cin>>motivo_inf[0];
        cout<<"Valor de la multa: ";cin>>multa_ind;

        cout<<"Gravedad de Infraccion Leve (L), Media (M), Grave (G): ";cin>>gravedad;
        while(tolower(gravedad[0]) != 'l' && tolower(gravedad[0]) != 'm' && tolower(gravedad[0]) != 'g'){
            cout<<"Tipo de gravedad no valida. Ingrese el tipo de gravedad nuevamente: ";cin>>gravedad;
        }

        multa_tot = multa_tot + multa_ind;

        if(tipo_infraccion == 3 || tipo_infraccion == 4){
            if(tolower(gravedad[0]) == 'g'){
                count++;
                }
        }

    }
    if(count > 3){
        cout<<"Se va clausurar la fabrica!"<<endl;
        cout<<"La multa total es de: $"<<multa_tot<<endl;
    }else{
        cout<<"La multa total es de: $"<<multa_tot<<endl; 
    }

    return 0;
}

