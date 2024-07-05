#include <stdio.h>
#include <string.h>
#include "funciones.h"

void listarProductos(char productos[][3][40],double precio[],int indice[]){
    printf("Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < 12; i++) {
        if (indice[i] != 0) { 
            printf("%d\t\t%s\t\t%s\t\t%s\t\t%.2lf\n", indice[i], productos[i][0],productos[i][1], productos[i][2], precio[i]);
        }
    }
}

void buscarXMarca(char productos[][3][40],double precio[]){
    char marca[40];
    int noexiste = 0;
    printf("Ingrese la marca: ");
    scanf("%s",marca);
    printf("Nombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i<20; i++)
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
    for (int i = 0; i<20; i++)
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
    for (int i = 0; i < 20; i++) {
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
    for (int i = 0; i < 20; i++) {
        fprintf(fp, "%d %s %s %s %.2lf\n", indice[i], productos[i][0], productos[i][1], productos[i][2], precio[i]);
    }
    fclose(fp);
}

void anadirproducto(char productos[][3][40], double precio[], int indice[]) {
    char nombre[40], categoria[40], marca[40];
        double nuevoPrecio;
        int nuevafila = 10; 
        while (nuevafila >= 0 && indice[nuevafila] != 0) {
            nuevafila--;
        }
        if (nuevafila < 0) {
            printf("No hay espacio disponible para agregar un nuevo producto.\n");
            return;
        }
        printf("Ingrese el nombre del producto: ");
        scanf("%s", nombre);
        printf("Ingrese la categoria del producto: ");
        scanf("%s", categoria);
        printf("Ingrese la marca del producto: ");
        scanf("%s", marca);
        printf("Ingrese el precio del producto: ");
        scanf("%lf", &nuevoPrecio);
        for (int i = 9; i > nuevafila; i--) { 
            strcpy(productos[i][0], productos[i - 1][0]);
            strcpy(productos[i][1], productos[i - 1][1]);
            strcpy(productos[i][2], productos[i - 1][2]);
            precio[i] = precio[i - 1];
            indice[i] = indice[i - 1]; 
        }
        strcpy(productos[nuevafila][0], nombre);
        strcpy(productos[nuevafila][1], categoria);
        strcpy(productos[nuevafila][2], marca);
        precio[nuevafila] = nuevoPrecio;
        indice[nuevafila] = nuevafila + 1; 
        printf("Producto agregado exitosamente!\n");
        listarProductos(productos, precio, indice); 
    }

void eliminarproducto(char productos[][3][40], double precio[], int indice[]) {
    int idToRemove, i, j;
    printf("Ingrese el ID del producto que desea eliminar: ");
    scanf("%d", &idToRemove);
    for (i = 0; i < 10; i++) {
        if (indice[i] == idToRemove) {
            for (j = i; j < 9; j++) { 
                strcpy(productos[j][0], productos[j + 1][0]);
                strcpy(productos[j][1], productos[j + 1][1]);
                strcpy(productos[j][2], productos[j + 1][2]);
                precio[j] = precio[j + 1];
                indice[j] = indice[j + 1] - 1; 
            }
            strcpy(productos[9][0], "");
            strcpy(productos[9][1], "");
            strcpy(productos[9][2], "");
            precio[9] = 0.0;
            indice[9] = 0; 
            printf("Producto eliminado exitosamente!\n");
            listarProductos(productos, precio, indice); 
            return; 
        }
    }
    printf("No se encontro un producto con el ID %d\n", idToRemove);
}
