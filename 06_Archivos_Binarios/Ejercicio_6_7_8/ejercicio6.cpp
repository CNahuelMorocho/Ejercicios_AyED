/* 
Escriba un programa que guarde en un archivo tres alumnos y luego los liste. El alumno es una estructura que contiene:
   Nombre
   Apellido
   Legajo
   DNI
   Fecha de Nacimiento
*/

#include <iostream>

using namespace std;

struct Alumno{
   char nombre[20];
   char apellido[20];
   int legajo;
   int dni;
   int fdenac;
   bool borrado = false;
};

int obtenerLargoArchivo(char ruta[]){
   FILE *arch;
   int largoArchivo = 0;


   arch = fopen(ruta, "rb");
   fseek(arch, 0, SEEK_END);
   largoArchivo = ftell(arch) / sizeof(Alumno);
   fseek(arch, 0, SEEK_SET);
   fclose(arch);
   return largoArchivo;
}


void agregarAlumno(char ruta[]){
   FILE *arch;
   Alumno alumnoNuevo;

   cout<<"Ingrese los datos del alumno nuevo"<<endl;
   cout<<"Nombre: ";cin>>alumnoNuevo.nombre;
   cout<<"Apellido: ";cin>>alumnoNuevo.apellido;
   cout<<"Legajo: ";cin>>alumnoNuevo.legajo;
   cout<<"DNI: ";cin>>alumnoNuevo.dni;
   cout<<"Fecha de Nacimiento: ";cin>>alumnoNuevo.fdenac;

   arch = fopen(ruta, "ab"); //Lo abro en modo apend binary para que cada alumno ingresado se añada al final del archivo.
   fwrite(&alumnoNuevo, sizeof(Alumno), 1, arch);
   fclose(arch);
   cout<<"\nGuardado exitosamente."<<endl;
   cout<<endl;
}

void mostrarAlumno(Alumno alum){
   cout<<"================================"<<endl;
   cout<<"Nombre: "<<alum.nombre<<endl;
   cout<<"Apellido: "<<alum.apellido<<endl;
   cout<<"Legajo: "<<alum.legajo<<endl;
   cout<<"DNI: "<<alum.dni<<endl;
   cout<<"Fecha de Nacimiento: "<<alum.fdenac<<endl;
   cout<<"Borrado: "<<alum.borrado<<endl;
   cout<<"================================"<<endl;
   cout<<endl;
}

void listarAlumnos(char ruta[]){
   FILE *arch; 
   Alumno alumno;
   int largoArchivo = obtenerLargoArchivo(ruta);
   int contador = 0;
   
   arch = fopen(ruta, "rb");

   if(arch){
      do{
         fread(&alumno, sizeof(Alumno), 1, arch);
         if(alumno.borrado == false){
            mostrarAlumno(alumno);
            fread(&alumno, sizeof(Alumno), 1, arch);
            break;
         }else{
            contador++;
         }
      }while(!feof(arch));
      fclose(arch);
      if(contador > obtenerLargoArchivo(ruta))
         cout<<"Todavia no se ha agregado ningun alumno."<<endl;
   }else{
      cout<<"No se ha podido abrir el archivo."<<endl;
   }
}

void buscarAlumnoLegajo(char ruta[]){
   FILE* arch;
   Alumno alumno; 
   int legajoBuscado;
   int contador = 0;

   cout<<"Ingrese el legajo del alumno que esta buscando: ";
   cin>>legajoBuscado;
   cout<<endl;

   arch = fopen(ruta, "rb");
   if(arch){
      do{
         fread(&alumno, sizeof(Alumno), 1, arch);
         if(alumno.borrado == false && alumno.legajo == legajoBuscado){
            mostrarAlumno(alumno);
            break;
         }else{
            contador++;
         }
      }while(!feof(arch));
      if(contador > obtenerLargoArchivo(ruta))
         cout<<"No se ha encontrado ningun alumno con ese legajo."<<endl;       
      fclose(arch);
   }else{
      cout<<"No se ha podido abrir el archivo."<<endl;
   }
}

void buscarAlumnoDNI(char ruta[]){
   FILE* arch;
   Alumno alumno; 
   int dniBuscado;
   int contador = 0;

   cout<<"Ingrese el DNI del alumno que esta buscando: ";
   cin>>dniBuscado;
   cout<<endl;

   arch = fopen(ruta, "rb");
   if(arch){
      do{
         fread(&alumno, sizeof(Alumno), 1, arch);
         if(alumno.dni == dniBuscado){
            mostrarAlumno(alumno);
            break;
         }else{
            contador++;
         }
      }while(!feof(arch));
      if(contador > obtenerLargoArchivo(ruta))
         cout<<"No se ha encontrado ningun alumno con ese DNI."<<endl;       
      fclose(arch);
   }else{
      cout<<"No se ha podido abrir el archivo."<<endl;
   }
}

void metodoBurbujeo(Alumno listaAlumnos[], int largo){
   Alumno alumnoAux;
   for(int i = 0; i < largo; i++){
      for(int j = 0; j < largo; j++){
         if(listaAlumnos[j].legajo > listaAlumnos[j + 1].legajo){
            alumnoAux = listaAlumnos[j];
            listaAlumnos[j] = listaAlumnos[j + 1];
            listaAlumnos[j + 1] = alumnoAux;
         }
      }
   }
}

void ordenarPorLegajo(char ruta[], int largo){
   FILE *arch;
   Alumno nuevaLista[largo];
   
   arch = fopen(ruta, "rb");
   if(arch){
      fread(nuevaLista, sizeof(Alumno), largo, arch);
      metodoBurbujeo(nuevaLista, largo);

      fseek(arch, 0, SEEK_SET); //Pongo el puntero en el inicio del archivo
      for(int i = 0; i < largo; i++){
         mostrarAlumno(nuevaLista[i]);
      }
      fclose(arch);
   }else{
      cout<<"No se ha podido abrir el archivo."<<endl;
   }
   
}

void borrarAlumno(char ruta[]){
   FILE *arch;
   Alumno alumno;
   int legajoBuscado;
   int contador = 0;
   char opcion;

   cout<<"Ingrese el legajo del alumno que desea borrar: ";
   cin>>legajoBuscado;
   cout<<endl;

   arch = fopen(ruta, "r+b");
   if(arch){
      do{
         fread(&alumno, sizeof(Alumno), 1, arch);

         if(alumno.borrado == false && alumno.legajo == legajoBuscado){
            mostrarAlumno(alumno);
            cout<<"Desea borrar este alumno? (s/n)"<<endl;
            cout<<">> ";
            cin>>opcion;
            cout<<endl;

            switch(opcion){
               case 's': alumno.borrado = true;
                        fseek(arch, ftell(arch) - sizeof(Alumno), SEEK_SET); 
                        fwrite(&alumno, sizeof(Alumno), 1, arch);
                        cout<<"Borrado exitosamente."<<endl;
                        break;
               case 'n': break;
               default: cout<<"Valor incorrecto."<<endl; break;
            }
            break;
         }else{
            contador++;
         }
      }while(!feof(arch));

      if(contador > obtenerLargoArchivo(ruta))
         cout<<"No se ha encontrado ningun alumno con ese legajo."<<endl;       
      fclose(arch);

   }else{
      cout<<"No se ha podido abrir el archivo."<<endl;
   }

}


void menu(){
   char opcion; //Opte por ponerlo tipo char para que no se rompa si pongo algo que no sea un numero
   char ruta[] = "lista_alumnos.bak"; // Ruta del archivo


   cout<<"================================"<<endl;
   cout<<"Elija una opcion."<<endl;
   cout<<"================================"<<endl;
   cout<<endl;
   cout<<"================================"<<endl;
   cout<<"1. Agregar alumno"<<endl;
   cout<<"2. Listar todos los alumnos"<<endl;
   cout<<"3. Buscar alumno por legajo"<<endl;
   cout<<"4. Buscar alumno por DNI"<<endl;
   cout<<"5. Ordenar archivo por legajo"<<endl;
   cout<<"6. Borrar alumno"<<endl;
   cout<<"7. Salir"<<endl;
   cout<<"================================"<<endl;
   cout<<"\n>> ";cin>>opcion;
   cout<<endl;

   switch(opcion){
      case '1': agregarAlumno(ruta); menu(); break;
      case '2': listarAlumnos(ruta); menu(); break;
      case '3': buscarAlumnoLegajo(ruta); menu(); break;
      case '4': buscarAlumnoDNI(ruta); menu(); break;
      case '5': ordenarPorLegajo(ruta, obtenerLargoArchivo(ruta)); menu(); break;
      case '6': borrarAlumno(ruta); menu(); break;
      case '7': exit(0); break;
      default: cout<<"No se ha elegido una opcion valida, se volvera al menu."<<endl; menu(); break;
   }

}

int main(){
   menu();
   
   return 0;

}