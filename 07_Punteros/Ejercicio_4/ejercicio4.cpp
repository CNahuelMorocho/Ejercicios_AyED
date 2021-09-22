/* Escriba un subprograma que ordene un array, el tamaño del array lo define el usuario y luego ingresa sus elementos. Debe hacerse todo a través del uso de punteros:
*/

#include <iostream>

using namespace std;

int* ordenarArray(int arr[], int largo){
   int* p = arr;
   int aux = 0;

   for(int i = 0; i < largo; i++){
      for(int j = 0; j < largo; j++){
         if(*(p+j) > *(p+j+1)){
            aux = *(p+j);
            *(p+j) = *(p+j+1);
            *(p+j+1) = aux; 
         }
      }
   }
   return p;
}

int main(){
   int n;

   cout<<"Ingrese el largo del array: ";
   cin>>n;

   int arr[n];
   int* p = arr;

   cout<<"Ingrese "<<n<<" enteros: "<<endl;
   for(int i = 0; i < n; i++){
      cin>>*(p+i);
   }

   int* arrOrdenado = ordenarArray(arr, n);

   cout<<"\nArray ordenado ascendentemente: "<<endl;
   for(int i = 0; i < n; i++){
      cout<<*(arrOrdenado+i)<<endl;
   }
   
}