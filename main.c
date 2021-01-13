// https://parzibyte.me/blog
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMA_LONGITUD_CADENA 100

struct nodoCadena
{
    // El verdadero dato
    char cadena[MAXIMA_LONGITUD_CADENA];
    // Las ramas
    struct nodoCadena *izquierda;
    struct nodoCadena *derecha;
};

struct nodoCadena *nuevoNodo(char cadena[MAXIMA_LONGITUD_CADENA])
{
    // Solicitar memoria
    size_t tamanioNodo = sizeof(struct nodoCadena);
    struct nodoCadena *nodo = (struct nodoCadena *)malloc(tamanioNodo);
    // Asignar el dato e iniciar hojas
    strcpy(nodo->cadena, cadena);
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

void agregar(struct nodoCadena *nodo, char *cadena)
{
    if (strcmp(cadena, nodo->cadena) > 0)
    {
        if (nodo->derecha == NULL)
        {
            nodo->derecha = nuevoNodo(cadena);
        }
        else
        {
            agregar(nodo->derecha, cadena);
        }
    }
    else
    {
        if (nodo->izquierda == NULL)
        {
            nodo->izquierda = nuevoNodo(cadena);
        }
        else
        {
            agregar(nodo->izquierda, cadena);
        }
    }
}

struct nodoCadena *buscar(struct nodoCadena *nodo, char *cadena)
{
    if (nodo == NULL)
    {
        return NULL;
    }
    if (strcmp(cadena, nodo->cadena) == 0)
    {
        return nodo;
    }
    else if (strcmp(cadena, nodo->cadena) > 0)
    {
        return buscar(nodo->derecha, cadena);
    }
    else
    {
        return buscar(nodo->izquierda, cadena);
    }
}
void preorden(struct nodoCadena *nodo)
{
    if (nodo != NULL)
    {
        printf("%s,", nodo->cadena);
        preorden(nodo->izquierda);
        preorden(nodo->derecha);
    }
}

void inorden(struct nodoCadena *nodo)
{
    if (nodo != NULL)
    {
        inorden(nodo->izquierda);
        printf("%s,", nodo->cadena);
        inorden(nodo->derecha);
    }
}

void postorden(struct nodoCadena *nodo)
{
    if (nodo != NULL)
    {
        postorden(nodo->izquierda);
        postorden(nodo->derecha);
        printf("%s,", nodo->cadena);
    }
}

int main(int argc, char const *argv[])
{
    // Declarar raíz
    struct nodoCadena *raiz = NULL;
    // También podría ser:
    // struct nodoCadena *raiz = nuevoNodo("Dato");
    // La primera vez hay que comprobar si la raíz es NULL
    if (raiz == NULL)
    {
        raiz = nuevoNodo("Luis");
    }
    // Agregar varias cadenas
    agregar(raiz, "Marijo");
    agregar(raiz, "Dennis");
    agregar(raiz, "Taylor");
    agregar(raiz, "Guido");
    agregar(raiz, "Andrew");
    agregar(raiz, "Leon");
    agregar(raiz, "Jack");
    agregar(raiz, "Aloy");
    printf("\nInorden: \n");
    inorden(raiz);
    printf("\nPostorden: \n");
    postorden(raiz);
    printf("\nPreorden: \n");
    preorden(raiz);
    printf("\n");
    // Mostrar búsqueda
    char busqueda[MAXIMA_LONGITUD_CADENA] = "Chris";
    struct nodoCadena *apuntador = buscar(raiz, busqueda);
    if (apuntador == NULL)
    {
        printf("%s no existe en el árbol\n", busqueda);
    }
    else
    {
        printf("%s sí existe en el árbol\n", busqueda);
    }
    // Otra búsqueda con alguien que sabemos que sí existe
    char otraBusqueda[MAXIMA_LONGITUD_CADENA] = "Guido";
    apuntador = buscar(raiz, otraBusqueda);
    if (apuntador != NULL)
    {
        printf("%s sí existe en el árbol\n", otraBusqueda);
    }
    else
    {
        printf("%s sí existe en el árbol\n", otraBusqueda);
    }
    return 0;
}
