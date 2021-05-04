//declaracion de librerias a usar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define largoDescripcion 100

//declaracion de estructuras a usar
typedef struct Tarea{
    int TareaID; 
    char *Descripcion;
    int Duracion; // entre 10-100
}Tarea;


//declaracion de funciones a usar
int cantidadTareas();
Tarea ** espaciotareas(int longitud);
Tarea* cargarTarea(int);
void cargarTodasTarea(Tarea **,int);
void mostrar(Tarea *);
void mostrarTodo(Tarea **,int);
void tareasHechas(Tarea **, Tarea **,int);
Tarea * BuscarTareafunc(Tarea**, int,int);
Tarea * BuscarTarea(Tarea**, int);
//menu principal
int main(){
    int cantidad = cantidadTareas();
    Tarea **pendientes,**realizadas;

    pendientes = espaciotareas(cantidad);
    realizadas = espaciotareas(cantidad);
    cargarTodasTarea(pendientes,cantidad); 
    Tarea *tareaSolicitada = BuscarTarea(pendientes,cantidad);
    tareasHechas(pendientes,realizadas,cantidad);
    printf("las tareas realizadas son:\n");
    mostrarTodo(realizadas,cantidad);
    printf("las tareas pendientes son:\n");
    mostrarTodo(pendientes,cantidad);
    return 0;
}

//funciones
int cantidadTareas(){
    int cantidad;
    printf("ingresa la cantidad de tareas a cargar\n");
    scanf("%d",&cantidad);
    return cantidad;
}

Tarea ** espaciotareas(longitud){
    Tarea **punteroDoble = (Tarea **) malloc(sizeof(Tarea *) * longitud);
    return punteroDoble;
}

Tarea* cargarTarea(int id){
    Tarea *nueva;
    int posicion=rand()%2;
    char descrip[largoDescripcion];

    nueva = (Tarea *) malloc(sizeof(Tarea));
    nueva->TareaID=id;
    nueva->Duracion = rand()%10 *10;
    printf("escriba la descripcion de la tarea por favor: ");
    scanf("%s",&descrip);
    nueva->Descripcion = (char *) malloc(sizeof(char) * strlen(descrip)); 
    strcpy(nueva->Descripcion,descrip); 
    
    return nueva;
}

void cargarTodasTarea(Tarea **todos,int cantid){
    for (int i = 0; i < cantid; i++)
    {
        todos[i] = cargarTarea(i+1);
    }
}

void mostrar(Tarea *tareaUnica){
    if (tareaUnica != NULL)
    {
        printf("el ID de la tarea es: %d\n",tareaUnica->TareaID);
        printf("la duracion de la tareas es: %d\n",tareaUnica->Duracion);
        printf("la descripcion es: %s\n",tareaUnica->Descripcion);   
    }
}


void mostrarTodo(Tarea **todo,int cant){
for (int i = 0; i < cant; i++)
    {
        mostrar(todo[i]);
    }
}

void tareasHechas(Tarea **pendiente, Tarea **hecha,int cantidad){
    char caracter;
    for (int i = 0; i < cantidad; i++)
    {
        printf("se realizo la tarea %d ? s/n",pendiente[i]->TareaID);
        getchar();
        scanf("%c",&caracter);
        if (caracter == 's' || caracter=='S')
        {
            hecha[i] = pendiente[i];
            pendiente[i] = NULL;
        }
    }
}

Tarea * BuscarTareafunc(Tarea** tareas, int cantidad,int numeroBuscar){
    Tarea *devolver = NULL;
    for (int i = 0; i < cantidad; i++)
    {
        if (tareas[i]->TareaID==numeroBuscar)
        {
            devolver = tareas[i];
        }
    }
    return devolver;
}
Tarea * BuscarTarea(Tarea** tareas, int cantidad){
    int numero;
    printf("ingrese el numero de id de la tarea:\n");
    scanf("%d",&numero);
    Tarea *tar = BuscarTareafunc(tareas,cantidad,numero);
    return tar;
}

