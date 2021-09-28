#include <stdio.h>
#include <stdlib.h>

//declaracion de funciones
void show(int, float**);

int main() {
	
	//declaracion de variables locales
	int FE=0, k, c=0;
	float aux=0;
	int n, i, j;
	float **mat;
		
	//captura y validacion de datos
	printf("\nIngrese el numero de variables: ");
	scanf("%d",&n);
	while( n < 2) {
		printf("\nValor minimo aceptado es de dos: ");
		scanf("%d", &n);
	}
	
	//apartado de memoria (matriz)
	mat = malloc(n);
	for( i= 0; i < n; i++)
		mat[i] = malloc(n+1);
	 
	//captura de datos de matriz
	for( i= 0; i < n; i++)
		for( j= 0; j < n+1; j++) {
			printf("\nIngrese el valor del lugar (%d,%d): ", i+1, j+1);
			scanf("%f", &mat[i][j]);
		}
	show(n, mat);
	
	//proceso
	for( i= 0; i < n; i++) {
		//diagonal mayor igual a uno
		if(mat[i][i] == 0)
			{FE++; break;}
		else if(mat[i][i] != 1) {
			aux = mat[i][i];
			for( j= 0; j < n+1; j++)
				mat[i][j]/=aux;
		}
		show(n, mat);
		//hacer ceros los valores arriba y bajo la diagonal
		for(k= 0; k < n; k++)
		  if(k != i) {
			aux=mat[k][i];
			for(j= 0; j < n+1; j++) 
				mat[k][j]-=aux*mat[i][j];
		  }
		c++;
		show(n, mat);
	}
	
	//Pantalla de resultados:
	printf("\nEl resultado es: ");
	if(mat[n-1][n-1] == 0 && mat[n-1][n] == 0)
		printf("Posee infinitas soluciones.\n");
	else if(mat[n-1][n-1] == 0 && mat[n-1][n] != 0 && c == n-1)
		printf("No tiene solucion!!!\n");
	else if(FE) 
		printf("FATAL ERROR, RESULTADO INCONCLUSO\n");	
	else
		printf(" el mostrado en la matriz.\n");
	
	show(n, mat);

free(mat);		
printf("\n\n");
return 0;
}

void show(int n, float **mat) {
	
	int i, j;

	printf("\n");
	for( i= 0; i < n; i++) {
		printf("|");
		for( j= 0; j < n+1; j++) 
			printf("\t%.2f", *(*(mat+i) + j) );
		printf("\t|\n");
	}
	printf("\n");
}
