/*2.a)Generar o inicializar la lista.                                          (completo)
b)Funci�n para determinar si una lista est� vac�a.                             (completo)
c)Insertar el primer producto (nodo) de la lista.                              (completo)
d)Insertar un producto al principio de la lista.                               (completo)
e)Eliminar el primer producto de la lista.                                     (completo)
f)Insertar un producto en una determinada posici�n dentro de la lista.         (completo)
g)Eliminar un producto de una determinada posici�n de la lista.                (completo)
h)Visualizar todos los datos de los productos que est�n en la lista.           (completo)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

//Variables
typedef char string[50];
typedef struct ListaProductos{	
	int codProducto; 
	string descripcion; 
	float precioUnitario;
	
	struct ListaProductos *siguiente;
} producto;


//prototipo
producto *inicializar(producto *lista);
bool listaVacia(producto *pLista);
void mostrar(producto *lista);
producto *agregarProduc(producto *lista, int codProducto, string descripcion, float precioUnitario);
producto *insentarPrimero(producto *lista, int codProducto, string descripcion, float precioUnitario);
producto *eliminarPrimerProdu(producto *lista);
producto *insertarProduEnPosicionk(int k,producto *lista, int codProducto, string descripcion, float precioUnitario);
producto *eliminarProduEnPosicionk(int k, producto *lista);


//funcion principal
int main() {
    producto *lista1;    
    int codProducto, opcion, posicion;
    string descripcion; 
    float precioUnitario;
    char continuar;

    // Inicializar lista
    lista1 = inicializar(lista1);

    do {
        printf("\nMenu:\n");
        printf("1. Agregar un producto al final\n");
        printf("2. Insertar un producto al principio\n");
        printf("3. Eliminar el primer producto\n");
        printf("4. Insertar un producto en una posicion especifica\n");
        printf("5. Eliminar un producto en una posicion especifica\n");
        printf("6. Mostrar lista de productos\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1:
                // Agregar un producto al final
                printf("Ingrese codigo de producto: ");
                scanf("%d", &codProducto);
                fflush(stdin);
                printf("Ingrese descripcion: ");
                scanf("%s", descripcion);
                fflush(stdin);
                printf("Ingrese precio del producto: ");
                scanf("%f", &precioUnitario);
                fflush(stdin);

                lista1 = agregarProduc(lista1, codProducto, descripcion, precioUnitario);
                break;

            case 2:
                // Insertar un producto al principio
                printf("Ingrese codigo de producto: ");
                scanf("%d", &codProducto);
                fflush(stdin);
                printf("Ingrese descripcion: ");
                scanf("%s", descripcion);
                fflush(stdin);
                printf("Ingrese precio del producto: ");
                scanf("%f", &precioUnitario);
                fflush(stdin);

                lista1 = insentarPrimero(lista1, codProducto, descripcion, precioUnitario);
                break;

            case 3:
                // Eliminar el primer producto
                lista1 = eliminarPrimerProdu(lista1);
                break;

            case 4:
                // Insertar un producto en una posicion especifica
                printf("Ingrese la posicion en la que desea insertar: ");
                scanf("%d", &posicion);
                fflush(stdin);
                printf("Ingrese codigo de producto: ");
                scanf("%d", &codProducto);
                fflush(stdin);
                printf("Ingrese descripcion: ");
                scanf("%s", descripcion);
                fflush(stdin);
                printf("Ingrese precio del producto: ");
                scanf("%f", &precioUnitario);
                fflush(stdin);

                lista1 = insertarProduEnPosicionk(posicion, lista1, codProducto, descripcion, precioUnitario);
                break;

            case 5:
                // Eliminar un producto en una posicion especifica
                printf("Ingrese la posicion del producto a eliminar: ");
                scanf("%d", &posicion);
                fflush(stdin);

                lista1 = eliminarProduEnPosicionk(posicion, lista1);
                break;

            case 6:
                // Mostrar lista de productos
                mostrar(lista1);
                break;

            case 7:
                // Salir
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }

        if (opcion != 7) {
            printf("Desea continuar? (s/n): ");
            scanf(" %c", &continuar);
            fflush(stdin);
        } else {
            continuar = 'n';
        }

    } while (continuar == 's' || continuar == 'S');

    return 0;
}


//desarrolo de las funciones:

producto *inicializar(producto *lista){ //Inicializar una lista vac�a
	lista = NULL;
	return lista;
}

bool listaVacia(producto *pLista){  //Comprueba si la lista est� vac�a
	return (pLista==NULL); //retorna true en el caso que la lista apunte a NULL y false en caso contrario
}

// Funci�n para agregar un nuevo producto al final de la lista.
// Par�metros:
// - lista: Puntero al inicio de la lista de productos.
// - codProducto: C�digo del nuevo producto.
// - descripcion: Descripci�n del nuevo producto.
// - precioUnitario: Precio unitario del nuevo producto.
producto *agregarProduc(producto *lista, int codProducto, string descripcion, float precioUnitario){
	producto *nuevoProduc, *aux;  //(nuevoProduc) se crea el nodo que se va a insertar
	                              //(aux) puntero se utilizar� para recorrer la lista hasta encontrar el �ltimo nodo
	
	nuevoProduc = (producto *) malloc(sizeof(producto));  //Se asigna memoria al nodo
	
	nuevoProduc->codProducto=codProducto;
	strcpy(nuevoProduc->descripcion, descripcion);
	nuevoProduc->precioUnitario=precioUnitario;
	
	nuevoProduc->siguiente=NULL;  // se asegura de que este nuevo nodo no apunte a ning�n otro nodo
	
	if(listaVacia(lista)){            //Si lista es NULL, significa que la lista est� vac�a
		lista=nuevoProduc;        //el nuevo nodo nuevoProduc se convierte en el primernodo de la lista
	}
	else{                    //Si la lista no est� vac�a
		aux = lista;
		while(aux->siguiente != NULL){       //recorre la lista hasta ---
			aux = aux->siguiente;           //---hasta llegar al �ltimo nodo---
			
		}
		aux->siguiente = nuevoProduc;      //---se enlaza el nuevo nodo nuevoProduc a este �ltimo nodo
	}
	
	return lista;	// Retorno: Puntero al inicio de la lista actualizada:
}

// Funci�n que inserta un nuevo elemento al principio de la lista.
producto *insentarPrimero(producto *lista, int codProducto, string descripcion, float precioUnitario){
	
	producto *nuevoProdu;  //Se crea el nodo que se va a insertar 
	
	nuevoProdu = (producto *) malloc(sizeof(producto)); 
	
	//Se asigna el dato recibido al componente correspondiente al elemento:
	nuevoProdu->codProducto = codProducto;              
	strcpy(nuevoProdu->descripcion, descripcion);
	nuevoProdu->precioUnitario=precioUnitario;
	
	
	nuevoProdu->siguiente=lista;  //Asigna nuevoProdu en la primera pocision en la lista
	
	lista=nuevoProdu; //Se agrega el nodo a la lista: la lista debe apuntar a nuevoNodo
	
	return lista;
}

// Funcion que elimina el primer elemento de la lista.
producto *eliminarPrimerProdu(producto *lista){
	
	if(listaVacia(lista)){                            
		printf(" No hay elemento para eliminar.\n"); 	
	}
	else{
		producto *eliminarProdu;
		
		eliminarProdu=lista;  //Se guarda en eliminarProdu el primer nodo de la lista
		lista=lista->siguiente; //Se avanza el puntero una vez, es decir se pasa al siguiente nodo de la lista
		free(eliminarProdu); //Se libera la memoria del nodo a suprimir que conten�a el primer elemento de la lista  
		eliminarProdu=NULL;	//Se asigna NULL a la variable auxiliar que guarda el nodo a suprimir 	
	}
	
	return lista;	
}


// Funci�n que inserta un nuevo elemento en una determinada posici�n de la lista.
//vamos a usar k para saber en que posicion esta
producto *insertarProduEnPosicionk(int k,producto *lista, int codProducto, string descripcion, float precioUnitario){
	
    // Verificamos si k es menor o igual a 1 para manejar casos donde el usuario
    // haya ingresado una posicion no v�lida (como 0 o un n�mero negativo).
    // En esos casos, tratamos la insercion como si fuera en la primera posicion.
	if(k <= 1 || listaVacia(lista)) {
		//si la lista esta vacia invocamos a insentarPrimero:
		return insentarPrimero(lista, codProducto, descripcion, precioUnitario);
	}
	
	
	producto *nuevoProdu, *aux;
	int i;
	
	aux = lista;
	//El bucle avanza aux hasta el nodo K-1:
	for(i=1;i<k-1;i++){
		aux = aux->siguiente;
	}
	
	nuevoProdu = (producto *) malloc(sizeof(producto)); 
	nuevoProdu->codProducto=codProducto;
	strcpy(nuevoProdu->descripcion, descripcion);
	nuevoProdu->precioUnitario=precioUnitario;
	
	/* Se actualizan los punteros 
	   1. Se indica a qu� nodo tiene que apuntar nuevoProdu: al siguiente de aux */
	nuevoProdu->siguiente=aux->siguiente;
	
	// 2. Se indica a qu� nodo tiene que apuntar aux: a nuevoProdu.
	aux->siguiente=nuevoProdu;
	
	return lista;
}


//Funci�n que elimina un producto de una determinada posici�n de la lista.
producto *eliminarProduEnPosicionk(int k, producto *lista){
	if(listaVacia(lista) || k < 1) {
		printf("lista vacia.\n");
		return lista;
	}
	
	//si posicion es 1 entonces invocamos eliminarPrimerProd:
	if(k == 1) {
		return eliminarPrimerProdu(lista);
	}
		
	producto *eliminarprodu, *aux;
	int i;
	aux = lista;
	
	for(i=1;i<k-1;i++){
		aux = aux->siguiente;
	}
	
	eliminarprodu=aux->siguiente;    //Se resguarda el nodo que se va a suprimir en la variable eliminarprodu.
	aux->siguiente=eliminarprodu->siguiente; //Se indica a qu� nodo tiene que apuntar aux: al siguiente del que se va a eliminar.
	free(eliminarprodu); //Se libera la memoria del nodo a suprimir que contenia el elemento de la posicion K de la lista.  
	eliminarprodu=NULL;
	
	return lista;
}


//funcion imprime cada nodo de la lista junto con su direccion de memoria para el siguiente nodo
void mostrar(producto *lista){	
	producto *aux;
	aux=lista;
	
	if(!listaVacia(lista)){
		/* Se puede recorrer la lista */
		while(aux != NULL){
		printf("\n %d - %s - %.2f - %p\n", lista->codProducto, lista->descripcion, lista->precioUnitario, lista->siguiente);
		aux = aux->siguiente;
		}
		
	}
	else{
		printf( "\nLa lista esta vacia!!\n" );
	}	
}








