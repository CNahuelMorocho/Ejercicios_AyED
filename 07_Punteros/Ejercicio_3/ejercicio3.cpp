/* Usando un puntero, escriba un programa que encuentre el máximo de un conjunto de enteros que ingresa el usuario. El usuario ingresa al principio el tamaño de la muestra.
*/

#include <iostream>

using namespace std;

int main(){
   int n, mayor = 0;

   cout<<"Ingrese la cantidad de enteros que desea ingresar: ";
   cin>>n;

   int arr[n];
   int *p = arr;

   cout<<"Ingrese "<<n<<" enteros: "<<endl;
   for(int i = 0; i < n; i++){
      cout<<">> ";
      cin>>*(p+i);
   }

   for(int i = 0; i < n; i++){
      if(i == 0 || *(p+i) >= mayor)
         mayor = *(p+i);
   }
   cout<<"El mayor del conjunto es: "<<mayor;

   return 0;
}