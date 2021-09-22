/* Agregue al código anterior la funcionalidad para poder modificar un número, solicitando al usuario en qué posición está el número que quiere modificar y cuál es el nuevo valor. Los cambios deben ser guardados en el archivo. */

#include <iostream>

using namespace std;

void agregarValores(FILE *arch, int n){
   float buffer[n];
   for(int i = 0; i < n; i++){
      cout<<"Ingresar valores\n: ";
      cin>>buffer[i];
   }
   arch = fopen("archivo", "wb");
   fwrite(buffer, sizeof(float), n, arch);
   fclose(arch);
}

void mostrarValores(FILE *arch, int n){
   float lector[n];
   arch = fopen("archivo", "rb");
   fread(lector, sizeof(float), n, arch);
   cout<<"Archivos cargados..."<<endl;
   for(int i = 0; i < n; i++){
      cout<<lector[i]<<endl;
   }
   fclose(arch);
}

void modificarValor(FILE *arch, int pos, float valor){
   arch = fopen("archivo", "r+b");
   // Como cada float vale 4 bytes entonces "pos * sizeof(float)" va indicar cuantos lugares me voy a mover hacia adelante.
   fseek(arch, pos * sizeof(float), SEEK_SET);
   //No va sobreescribir todo el archivo, sino unicamente el valor sobre el que esta posicionado.
   fwrite(&valor, sizeof(float), 1, arch);
   fclose(arch);
   

}

int main(){
   int n = 0, pos = 0;
   float valor = 0;
   char opcion;
   cout<<"Cuantos valores desea ingresar?\n: ";
   cin>>n;
   FILE *archivo;
   agregarValores(archivo, n);
   mostrarValores(archivo, n);
   cout<<"Desea modificar un archivo antes de salir? (s/n) \n: ";
   cin>>opcion;
   switch(opcion){
      case 's': 
               cout<<"Indique la linea (0-"<<n-1<<")\n: ";
               cin>>pos;
               cout<<"Indique que valor desea\n: ";
               cin>>valor;
               modificarValor(archivo, pos, valor); 
               mostrarValores(archivo, n); 
               break;
      case 'n': cout<<"Guardado exitosamente."; exit(0); break;
      default: cout<<"Opcion no valida"; break;
   }

   return 0;
}