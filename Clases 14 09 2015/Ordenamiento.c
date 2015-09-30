#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 2
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct producto {
	int codigo;
	int cantidad;
	char descripcion[51];
	float importe;
};

// Funciones
int menu();
float promedio(float *prome);
int main(int argc, char *argv[]) {
	
	struct producto miProducto[MAX];

	int auxcant,codaux,i,j,opcion,search,encontrado=0,h;
	float  impaux,maximp=0,prome;
	char descaux[51];
	
	// inicialización
	for(i=0;i<MAX;i++){
		miProducto[i].codigo=0;
	}
	do{
	// Menu
	opcion = menu();
	// Opcion seleccionada
	encontrado = 0;
	
	switch(opcion){
		// Alta
		case 1:
			for(i=0;i<MAX;i++){
				if(miProducto[i].codigo==0){
				
				printf("\nIngrese el codigo del producto %d: ",i+1);
				//scanf("%d",&miProducto.codigo[i]);
				scanf("%d",&miProducto[i].codigo);
				printf("\nIngrese la descripcion (51 max caracteres) del producto %d: ",i+1);
				//scanf("%s",&desc[i]);
				scanf("%s",miProducto[i].descripcion);
				printf("\nIngrese el importe del producto %d: ",i+1);
				//scanf("%f",&importe[i]);
				scanf("%f",&miProducto[i].importe);
				printf("\nIngrese la cantidad del producto %d: ",i+1);
				//scanf("%d",&cantidad[i]);
				scanf("%d",&miProducto[i].cantidad);
				
				}else{
					printf("\nNo hay datos a cargar...\n");
				}
			}
		break;
		// Modificar
		case 2:
			system("cls");
			printf("\nIngrese el codigo del producto a modificar: ");
			scanf("%d",&search);
			
			for(i=0;i<MAX;i++){
				//if(codigo[i]==search){
				if(miProducto[i].codigo==search){
					//printf("\nSe ha encontrado el producto: \n\nCodigo produco: %d\nDescripcion: %s\nImporte: %f\nCantidad: %d\n",codigo[i],desc[i],importe[i],cantidad[i]);
					printf("\nSe ha encontrado el producto: \n\nCodigo producto: %d\nDescripcion: %s\nImporte: %f\nCantidad: %d\n",miProducto[i].codigo,miProducto[i].descripcion,miProducto[i].importe,miProducto[i].cantidad);
					system("pause");
					encontrado=1;
					break;
				}
			}
			
			if(encontrado==0){
				printf("\nNo se ha encontrado el producto.\n");
				system("pause");
			}else{
				// Se realiza la modificación
				printf("\nModificar la descripcion del codigo %d: ",miProducto[i].codigo);
				scanf("%s",miProducto[i].descripcion);
				
				printf("\nModificar el importe del codigo %d: ",miProducto[i].codigo);
				scanf("%f",&miProducto[i].importe);
				
				printf("\nModificar la cantidad del codigo %d: ",miProducto[i].codigo);
				scanf("%d",&miProducto[i].cantidad);
				
				//Mostramos la grabacion:
				printf("\nSe ha modificado el producto: \n\nCodigo producto: %d\nDescripcion: %s\nImporte: %f\nCantidad: %d\n",miProducto[i].codigo,miProducto[i].descripcion,miProducto[i].importe,miProducto[i].cantidad);
				system("pause");
			}
			
		break;
		// Baja
		case 3:
			system("cls");
			printf("\nIngrese el codigo del producto a dar de baja: ");
			scanf("%d",&search);
			
			for(i=0;i<MAX;i++){
				//if(codigo[i]==search){
				if(miProducto[i].codigo==search){
					//printf("\nSe ha encontrado el producto: \n\nCodigo produco: %d\nDescripcion: %s\nImporte: %f\nCantidad: %d\n",codigo[i],desc[i],importe[i],cantidad[i]);
					printf("\nSe ha encontrado el producto: \n\nCodigo producto: %d\nDescripcion: %s\nImporte: %f\nCantidad: %d\n",miProducto[i].codigo,miProducto[i].descripcion,miProducto[i].importe,miProducto[i].cantidad);
					system("pause");
					encontrado=1;
					break;
				}
			}
			
			if(encontrado==0){
				printf("\nNo se ha encontrado el producto.\n");
				system("pause");
			}else{
				// se da de baja
				miProducto[i].codigo = 0;
				miProducto[i].cantidad = 0;
				//miProducto[i].descripcion = '';
				miProducto[i].importe = 0;
				printf("\nProducto dado de baja\n");
				system("pause");
			}
		break;
		// Informar
		case 4:
			system("cls");
			for(i=0;i<MAX-1;i++){
				for(j=i+1;j<MAX;j++){
					// Ordenar de mayor importe
					if(miProducto[i].importe<miProducto[j].importe){
						// Importe
						impaux = miProducto[i].importe;
						miProducto[i].importe = miProducto[j].importe;
						miProducto[j].importe = impaux;
						// Codigo
					    codaux = miProducto[i].codigo;
						miProducto[i].codigo= miProducto[j].codigo;
						miProducto[j].codigo = codaux;
						// Cantidad
						auxcant = miProducto[i].cantidad;
						miProducto[i].cantidad = miProducto[j].cantidad;
						miProducto[j].cantidad = auxcant;
						// Descripcion
						strcpy(descaux,miProducto[i].descripcion);
						strcpy(miProducto[i].descripcion,miProducto[j].descripcion);
						strcpy(miProducto[j].descripcion,descaux);
					
					}
				}
			}
			//prome = promedio(miProducto.importe);
			for(i=0;i<MAX;i++){
				
				printf("\nCodigo del Producto: %d",miProducto[i].codigo);
				printf("\nDescripcion: %s",miProducto[i].descripcion);
				printf("\nImporte: %f",miProducto[i].importe);
				printf("\nCantidad: %d",miProducto[i].cantidad);
				
			}
			system("pause");
		break;
		
	/*
	for(i=0;i<MAX-1;i++){
		for(j=i+1;j<MAX;j++){
			if(cantidad[i]<cantidad[j]){
				
				auxcant = cantidad[i];
				cantidad[i] = cantidad[j];
				cantidad[j] = auxcant;
				
				codaux = codigo[i];
				codigo[i] = codigo[j];
				codigo[j] = codaux;
				
				impaux = importe[i];
				importe[i] = importe[j];
				importe[j] = impaux;
				// Ordenamiento de palabras
				strcpy(descaux,desc[i]);
				strcpy(desc[i],desc[j]);
				strcpy(desc[j],descaux);
				
			}
			
			if(cantidad[i]==cantidad[j]){
				if(strcmp(desc[i],desc[j])>0){
					
					codaux = codigo[i];
					codigo[i] = codigo[j];
					codigo[j] = codaux;	
				
					impaux = importe[i];
					importe[i] = importe[j];
					importe[j] = impaux;					

					strcpy(descaux,desc[i]);
					strcpy(desc[i],desc[j]);
					strcpy(desc[j],descaux);					
					
				}
			}
		}*/
	}
	}while(opcion<6);
	return 0;
}

int menu(){
	int opcion;
	system("cls");
	printf("\nPrograma: \n--------\n\n1. Altas\n2. Modificar\n3. Baja \n4. Informar\n5. Listar\n6. Salir\nElija una opcion: ");
	scanf("%d",&opcion);
	while(opcion<1||opcion>6){
		printf("\nOpcion incorrecta, elija nuevamente: ");
		scanf("%d",&opcion);
	}
	return opcion;
}

float promedio(float *prome){
	
	int suma=0,i;
	
	float resultado;
	
	for(i=0;i<MAX;i++){
		
		suma = suma + prome[i];
		
	}
	
	resultado = suma / 2;
	
	return resultado;
	
	
}
