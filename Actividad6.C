#include <stdio.h>
#include <stdlib.h>

#define ARGUMENTOS 3

int ordenable(int, char*[]);
int length(char*);
char comparaCads(char*, char*);
char comparaNums(int, int);
char* copiaCad(char*, char*);
void burbuja(int, char*[]);
void intercambiar(char*[], int, int);
void insercion(int, char*[]);
void seleccion(int, char*[]);
void shell(int, char*[]);

int main(int argc, char* argv[]){
	
	if (ordenable(argc, argv) == 1){
		
		char opcion = argv[argc-2][0];
				
		switch(opcion){
			case 'B':
				burbuja(argc, argv);
			break;
			
			case 'I':
				insercion(argc, argv);
			break;
			
			case 'S':
				seleccion(argc, argv);
			break;
			
			case 'D':
				shell(argc, argv);
			break;	
		}
	
		//Imprimir lista
		for (int i = 1; i < argc - 3; i++)
			printf("%s\n", *(argv+i));
	}
	
	return 0;
}

int ordenable(int c, char* v[]){
	
	//Verificar que est� el nombre del programa, al menos dos cadenas y tres argumentos.
	if (c < 6){
		printf("\nError: No hay cadenas suficientes para ordenar\n");
		return 0;
	}
		
	if ( v[(c - 1)][0] != 'A'){		
		if (v[(c - 1)][0] != 'D'){
			printf("\nError: Falta un argumento de formato de orden A o D\n");
			return 0;
		}
	}
	
	switch (v[(c - 2)][0]){
		case 'B': case 'I':	case 'S': case 'D':
		break;
		
		default:
			printf("\nError: Falta un argumento de metodo de ordenamiento B, I, S o D\n");
			return 0;
		break;	
	}
	
	if ( v[(c - 3)][0] != 'N'){
		if (v[(c - 3)][0] != 'C'){
			printf("\nEror: Falta un argumento de tipo de elementos a ordenar N o C\n");
			return 0;
		}
	}
	
	return 1;
}

int length(char *string){
	
	int i = 0;
	while (*(string + i) != '\0')
		i++;
	
	return i;
}

//Copia la segunda cadena en la primera cadena
char* copiaCad(char* cad1, char* cad2){
	int i = 0;
	
	while (*(cad2 + i) != '\0'){
		*(cad1 + i) = *(cad2 + i);
		i++;
	}
	
	*(cad1 + i) = '\0'; //Cerrar la cadena
		
	return cad1;
}

//Intercambia dos cadenas de lugar
void intercambiar(char* v[], int i, int j){
	char temporal[length(v[j]) + 1];
	          	
	copiaCad(temporal, v[j]);
	copiaCad(v[j], v[i]);
	copiaCad(v[i], temporal);
}

char comparaCads(char* cad1, char* cad2){
	int i = 0;
	
	char a, b;
	
	while (*(cad1 + i) != '\0' && *(cad2 + i) != '\0'){
		
		//Si son letras min�sculas, tomar el valor de la misma letra en may�scula.
		a = (*(cad1 + i) > 96 && *(cad1 + i) < 123) ? *(cad1 + i) - 32 : *(cad1 + i);
		b = (*(cad2 + i) > 96 && *(cad2 + i) < 123) ? *(cad2 + i) - 32 : *(cad2 + i);
		
		//Comparar cu�l de las dos aparece antes y regresar un orden A o D respecto al primer elemento.
		if (a > b)
			return 'A';
		else if (a < b)
			return 'D';
		
		i++;
	}
	//Si son iguales lexicogr�ficamente, primero debe aparecer la cadena m�s peque�a.
	if (length(cad1) > length(cad2))
		return 'A';
	else if (length(cad1) < length(cad2))
		return 'D';
	
	return 'N';
}

char comparaNums(int a, int b){
	if (a > b)
		return 'A';
	else if (a < b)
		return 'D';
	return 'N';	
}

void burbuja(int c, char* v[]){
	
	int i,j, a, b;
	
	char formato = v[c - 1][0];
	char tipo = v[c - 3][0];

	for (i = 1; i < (c - ARGUMENTOS); i++){
	    for (j = 1; j < (c - (ARGUMENTOS + 1)); j++){
	    	
	    	if (tipo == 'C'){
	    		
	    		if (comparaCads(v[j], v[j + 1]) == formato)
		       		intercambiar(v, j, j + 1);
	    		
			}else {
				a = strtol(v[j], NULL, 10);
	       		b = strtol(v[j + 1], NULL, 10);
	       	
	       		if (comparaNums(a, b) == formato)
	       			intercambiar(v, j, j+1);
			}
		}
	}
}

void insercion(int c, char* v[]){
	int i, j, claveNumero;
	
	char formato = v[c - 1][0];
	char tipo = v[c - 3][0];
			
   //Recorrer el arreglo
	for (i = 2; i < (c - ARGUMENTOS); i++){
		
		char clave[length(v[i]) + 1];
		copiaCad(clave, v[i]);
				
		j = i-1;
		
		if (tipo == 'C'){
			//Comparar el valor selecionado con todos los valores anteriores
			while (j >= 1 && comparaCads(v[j], clave) == formato){
				//Insertar el valor donde corresponda
				copiaCad(v[j + 1], v[j]);
				--j;
			}
			copiaCad(v[j + 1], clave);
			
		}else {
			claveNumero = strtol(v[i], NULL, 10);
			//Comparar el valor selecionado con todos los valores anteriores
			while (j >= 1 && comparaNums(strtol(v[j], NULL, 10), claveNumero) ==  formato){
				//Desplazar el valor una posici�n a la derecha
				copiaCad(v[j + 1], v[j]);
				--j;
			}
				copiaCad(v[j + 1], clave);
		}
	}
}

void seleccion(int c, char* v[]){
	
	int i, j, limite, a, b;
	
	char formato = v[c - 1][0];
	char tipo = v[c - 3][0];
	
	for (i = 1; i < (c - ARGUMENTOS); i++){
		
		limite = i;
		
		for (int j = i + 1; j < (c - ARGUMENTOS); j++){
			if (tipo == 'C'){
				if (comparaCads(v[limite], v[j]) == formato){
					limite = j;
				}	
			} else{
				a = strtol(v[limite], NULL, 10);
	       		b = strtol(v[j], NULL, 10);
			
				if (comparaNums(a,b) == formato){
					limite = j;
				}
			}	
		}
		intercambiar(v, i, limite);
	}	
}

void shell(int c , char* v[]){

   int i , salto, bandera, a, b;
   char formato = v[c - 1][0];
   char tipo = v[c - 3][0];

   salto = (c - ARGUMENTOS);
   
   while (salto > 0){
   	
      salto /= 2;
      do{
	        bandera = 1;
	        
	        for ( i = 1 ; i < (c - ARGUMENTOS) - salto; i++){
	            if (tipo == 'C'){
	            	if (comparaCads(v[i], v[i + salto]) == formato){
	            		intercambiar(v, i, i + salto);
						bandera = 0;
	            	}
				}else{
					a = strtol(v[i], NULL, 10);
					b = strtol(v[i + salto], NULL, 10);
					
					if (comparaNums(a,b) == formato){
	            		intercambiar(v, i, i + salto);
						bandera = 0;
	            	}
				}
	       }
       }
       while ( bandera == 0);
    }
}

