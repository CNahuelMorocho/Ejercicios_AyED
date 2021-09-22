/* Escriba un programa que permita a un usuario ingresar n valores float y se guarden en un archivo, el número n lo informa al comienzo del programa. Al finalizar el programa debe listar todos los números guardados en el archivo */

#include <iostream>

using namespace std;

int main(){
   int n = 0;
   cout<<"Cuantos valores desea ingresar?"<<endl;
   cin>>n;
   
   FILE *archivo;
   float buffer[n], lector[n];
   archivo = fopen("datos", "wb");

   for(int i = 0; i < n; i++){
      cout<<"Ingresar numero: "<<endl;
      cin>>buffer[i];
   }
   fwrite(buffer, sizeof(float), n, archivo);
   fclose(archivo);
   
   archivo = fopen("datos", "rb");

   cout<<"Datos ingresados: "<<endl;
   fread(lector, sizeof(float), n, archivo);
   
   for(int i = 0; i < n; i++){
      cout<<lector[i]<<endl;
   }
   fclose(archivo);
}