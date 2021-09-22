/* Dados dos archivos de enteros, previamente ordenados ascendentemente, confeccione un programa que guarde en un tercer archivo el contenido de ambos ordenado descendentemente. */

#include <iostream>

using namespace std;

void crearArchivos(char ruta1[], char ruta2[]){
   FILE* arch1;
   FILE* arch2;

   int arr1[] = {1,2,3,4,5};
   int arr2[] = {2,3,6,7,8};

   arch1 = fopen(ruta1, "wb");
   arch2 = fopen(ruta2, "wb");
   
   fwrite(arr1, sizeof(int), 5, arch1);
   fwrite(arr2, sizeof(int), 5, arch2);

   fclose(arch1);
   fclose(arch2);

}

void mezclarArchivos(char ruta1[], char ruta2[], char ruta3[]){
   FILE* arch1;
   FILE* arch2;
   FILE* arch3;

   int a, b;
   
   arch1 = fopen(ruta1, "rb");
   arch2 = fopen(ruta2, "rb");
   arch3 = fopen(ruta3, "wb");

   while(fread(&a, sizeof(int), 1, arch1) && fread(&b, sizeof(int), 1, arch2)){
      if(a < b){
         fwrite(&a, sizeof(int), 1, arch3);
         fseek(arch2, (-1)*sizeof(int), SEEK_CUR); //El (-1)*sizeof(int) indica que retroceda una unidad.
      }else{
         fwrite(&b, sizeof(int), 1, arch3);
         fseek(arch1, (-1)*sizeof(int), SEEK_CUR);
      }
   }
   
   while(fread(&a, sizeof(int), 1, arch1)){
      fwrite(&a, sizeof(int), 1, arch3);
   }
   
   while(fread(&b, sizeof(int), 1, arch2)){
      fwrite(&b, sizeof(int), 1, arch3);
   }
   
   fclose(arch1);
   fclose(arch2);
   fclose(arch3);
}

int obtenerLargoArchivo(char ruta[]){
   FILE *arch;
   int largoArchivo = 0;

   arch = fopen(ruta, "rb");

   fseek(arch, 0, SEEK_END);
   largoArchivo = ftell(arch) / sizeof(int);
   fseek(arch, 0, SEEK_SET);

   fclose(arch);
   return largoArchivo;
}

void mostrarArchivo(char ruta[], int largo){
   FILE* arch = fopen(ruta, "rb");
   int output[largo];

   for(int i = 0; i < largo; i++){
      fread(&output[i], sizeof(int), 1, arch);
   }

   fclose(arch);

   for(int i = 0; i < largo; i++){
      cout<<output[i]<<endl;
   }
}

int main(){
   char ruta1[] = "archivo1.bak";
   char ruta2[] = "archivo2.bak";
   char ruta3[] = "archivo3.bak";

   crearArchivos(ruta1, ruta2);
   mezclarArchivos(ruta1, ruta2, ruta3);
   int largo = obtenerLargoArchivo(ruta3);
   mostrarArchivo(ruta3, largo);


   return 0;
}