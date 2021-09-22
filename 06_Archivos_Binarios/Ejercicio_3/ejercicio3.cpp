/* Dados dos archivos de enteros confeccione un programa que guarde en un tercer archivo el contenido de ambos  intercalado de  a un número. */

#include <iostream>

using namespace std;

void crearArchivo(FILE *arch, char path[], int n){
   int buffer[n];
   for(int i = 0; i < n; i++){
      buffer[i] = rand() % 100;
   }
   arch = fopen(path, "wb");
   fwrite(buffer, sizeof(int), n, arch);
   fclose(arch);
}

void mostrarArchivo(FILE *arch, char path[], int n){
   int lector[n];
   arch = fopen(path, "rb");
   fread(lector, sizeof(int), n, arch);
   
   for(int i = 0; i < n; i++){
      cout<<lector[i]<<endl;
   }
}

void intercalarArchivos(FILE *arch1, FILE *arch2, FILE *arch3, char path1[], char path2[], char path3[], int n){
   int lector_arch1[n], lector_arch2[n], buffer_arch3[2*n];
   arch1 = fopen(path1, "rb");
   fread(lector_arch1, sizeof(int), n, arch1);
   fclose(arch1);
   arch2 = fopen(path2, "rb");
   fread(lector_arch2, sizeof(int), n, arch2);
   fclose(arch2);

   int switcher = 0;
   int k = 0, j = 0;
   for(int i = 0; i < n*2; i++){
      if(switcher == 0){
         buffer_arch3[i] = lector_arch1[j];
         j++;
         switcher = 1;
      }else {
         buffer_arch3[i] = lector_arch2[k];
         k++;
         switcher = 0;
      }
   }
   arch3 = fopen(path3, "wb");
   fwrite(buffer_arch3, sizeof(int), n*2, arch3);
   fclose(arch3);
}

int main(){
   FILE *archivo1;
   FILE *archivo2;
   FILE *archivo3;

   cout<<"Archivo 1:"<<endl;
   crearArchivo(archivo1, "archivo1.data", 3);
   mostrarArchivo(archivo1, "archivo1.data", 3);

   cout<<"Archivo 2:"<<endl;
   crearArchivo(archivo2, "archivo2.data", 3);
   mostrarArchivo(archivo2, "archivo2.data", 3);

   cout<<"Archivo 3:"<<endl;
   intercalarArchivos(archivo1, archivo2, archivo3, "archivo1.data", "archivo2.data", "archivo3.data", 3);
   mostrarArchivo(archivo3, "archivo3.data", 6);

   return 0;
}