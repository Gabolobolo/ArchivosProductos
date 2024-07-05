#include <stdio.h>
#include <string.h>
#include "funciones.h"

void listarProductos(char productos[][3][40],double precio[],int indice[]){
    printf("Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i=0; i<10; i++)
    {
    printf("%d\t\t%s\t\t%s\t\t%s\t\t%.2lf\n", indice[i], productos[i][0],productos[i][1], productos[i][2], precio[i]);
    }
}

//Comparar (buscar)//
void buscarXMarca(char productos[][3][40],double precio[]){
    char marca[40];
    int noexiste = 0;
    printf("Ingrese la marca: ");
    scanf("%s",marca);
    printf("Nombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i<10; i++)
    {
        if(strcmp(productos[i][2],marca)==0)
        {
            printf("%s\t\t%s\t\t%s\t\t%.2lf\n", productos[i][0],productos[i][1], productos[i][2], precio[i]);
            noexiste=1;
        }
    }
    if (noexiste==0){
        printf("No existe ningun producto con esa marca\n");
    }
}

void buscarXCategoria(char productos[][3][40],double precio[]){

    char categoria[40];
    int noexiste = 0;
    printf("Ingrese la categoria: ");
    scanf("%s",categoria);
    printf("Nombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i<10; i++)
    {
        if(strcmp(productos[i][1],categoria)==0)
        {
            printf("%s\t\t%s\t\t%s\t\t%.2lf\n", productos[i][0],productos[i][1],productos[i][2], precio[i]);
            noexiste=1;
        }
    }
    if (noexiste==0){
        printf("No existe ningun producto con esa categoria\n");
    }

}

void buscarXPrecioMenor(char productos[][3][40],double precio[]){
    double preciomaximo;
    int noexiste = 0;
    printf("Ingrese el precio maximo: ");
    scanf("%lf",&preciomaximo);
    printf("Nombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i<10; i++)
    {
        if(precio[i]<=preciomaximo)
        {
            printf("%s\t\t%s\t\t%s\t\t%.2lf\n", productos[i][0],productos[i][1],productos[i][2], precio[i]);
            noexiste=1;
        }
    }
    if (noexiste==0){
        printf("No existe ningun producto con esa categoria\n");
    }
}
void editarProducto(char productos[][3][40],double precio[], int indice[]){
    int num;
    char nombre[40], cat[40], marca[40];
    double nuevoprecio;
    listarProductos(productos,precio,indice);
    printf("Ingrese el producto que desee editar: ");
    scanf("%d", &num);
    num--;
    printf("Ingrese el nuevo nombre: ");
    scanf("%s", nombre);
    printf("Ingrese la nueva categoria: ");
    scanf("%s", cat);
    printf("Ingrese la nueva marca: ");
    scanf("%s", marca);
    printf("Ingrese el nuevo precio: ");
    scanf("%lf", &nuevoprecio);
    strcpy(productos[num][0], nombre);
    strcpy(productos[num][1], cat);
    strcpy(productos[num][2], marca);
    precio[num]=nuevoprecio;
    listarProductos(productos,precio,indice);
}
void leerProductos(char productos[][3][40], double precio[], int indice[]) {
    FILE *fp = fopen("productos.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir el archivo 'productos.txt'\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        fscanf(fp, "%d %s %s %s %lf\n", &indice[i], productos[i][0], productos[i][1], productos[i][2], &precio[i]);
    }
    fclose(fp);
}

void guardarProductos(char productos[][3][40], double precio[], int indice[]) {
    FILE *fp = fopen("productos.txt", "w");
    if (fp == NULL) {
        printf("Error al abrir el archivo 'productos.txt'\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        fprintf(fp, "%d %s %s %s %.2lf\n", indice[i], productos[i][0], productos[i][1], productos[i][2], precio[i]);
    }
    fclose(fp);
}