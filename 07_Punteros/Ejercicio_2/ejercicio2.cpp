/* Modifique la solución anterior para mostrar los números en orden inverso */

#include <iostream>

using namespace std;

int main(){
   int arr[5];
   int *p_arr = arr;


   cout<<"Ingrese 5 enteros: "<<endl;
   for(int i = 0; i < 5; i++){
      cout<<">> ";
      cin>>*(p_arr+i);
   }

   //Se va a mostrar el array inverso.
   for(int i = 4; i >= 0; i--){
      cout<<"<< "<<arr[i]<<endl;
   }

   return 0;
}