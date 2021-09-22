/* 
Escriba un programa que, utilizando aritmética de punteros, tome 5 elementos enteros en un array y luego los muestre en pantalla
*/

#include <iostream>

using namespace std;

int main(){
   int arr[5];
   int *p = arr; //p va estar apuntando a el conentido de arr

   cout<<"Ingrese 5 digitos: "<<endl;
   for(int i = 0; i < 5; i++){
      cout<<">> ";
      cin>>*(p+i); //Cada p+i va estar apuntando al contenido de un indice distinto de arr, por lo que indirectamente esta modificando el contenido de arr[0], arr[1], arr[2], arr[3], arr[4]
   }
   
   for(int i = 0; i < 5; i++){
      cout<<"<< "<<arr[i]<<endl; //Imprimo arr, pero nunca modifique arr directamente, pero si lo hice indirectamente con el puntero p.
   }

   return 0;
}