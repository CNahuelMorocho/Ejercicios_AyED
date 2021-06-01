/* 
Realice una función que reciba los coeficientes de un polinomio de grado 2 y devuelva las
raíces del mismo siempre y cuando sean raíces reales.
*/

#include <iostream>
#include <cmath>

using namespace std;

void raices (float, float, float, float&, float&);


int main () {
    float a, b, c, raiz1 = 0, raiz2 = 0;
    cout<<"Ingresar coeficientes de un polinomio de segundo grado: "<<endl;
    cout<<"a: ";cin>>a;
    cout<<"b: ";cin>>b;
    cout<<"c: ";cin>>c;

    raices(a,b,c,raiz1,raiz2);

    return 0;
}

void raices (float a, float b, float c, float& rs1, float& rs2) {
    float discriminante = pow(b, 2) - 4*c*a;

    if(discriminante == 0){
        rs1 = (-b)/(2*a);
        cout<<rs1;
    }else if (discriminante > 0){
        rs1 = ((-b) + (sqrt(discriminante)))/(2*a);
        rs2 = ((-b) - (sqrt(discriminante)))/(2*a);

        cout<<"x1: "<<rs1<<endl;
        cout<<"x2: "<<rs2<<endl;
        
    }else{
        cout<<"La discriminante es menor a 0. Por lo tanto no tiene solución real";
    }
} 