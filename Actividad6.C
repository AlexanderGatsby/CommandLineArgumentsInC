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
void insercionNumeros(int, char*[]);
void seleccion(int, char*[]);
void seleccionNumeros(int, char*[]);

int main(int argc, char* argv[]){
	
	if (ordenable(argc, argv) == 1)
		printf("\nEs ordenable\n\n");
	else
		printf("\nNo se puede ordenar\n\n");
	
	//burbuja(argc, argv);
	
	//insercionNumeros(argc, argv);
	//insercionNumeros(argc, argv);
	//seleccion(argc, argv);
	//seleccionNumeros(argc, argv);
	
	int i;
	//for (i = 1; i < argc - 3; i++)
	for (i = 0; i < argc; i++)
		printf("%s\n", *(argv+i));
	
	
	//printf("\n%c Ponemos el acento o tilde en canel%cn\n",162, 162); //ó
	//Es decir, invocar el código de carácter que corresponde a la letra acentuada...

	//Códigos:

	//á: 160 é: 130 í: 161 ó: 162 ú: 163 Á: 181 É: 144 Í: 214 Ó: 224 Ú: 223 ñ: 164 Ñ: 165
	
	
	return 0;
}



int ordenable(int c, char* v[]){
	
	//Verificar que hay al menos dos cadenas y los tres argumentos
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
		case 'B':
		case 'I':
		case 'S':
		case 'D':
		
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

char* copiaCad(char* cad1, char* cad2){
	int i = 0;
	
	while (*(cad2 + i) != '\0'){
		*(cad1 + i) = *(cad2 + i);
		i++;
	}
	
	*(cad1 + i) = '\0'; //Cerrar la cadena
		
	return cad1;
}

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
		
		//Si son letras minúsculas, tomar el valor de la misma letra en mayúscula.
		a = (*(cad1 + i) > 96 && *(cad1 + i) < 123) ? *(cad1 + i) - 32 : *(cad1 + i);
		b = (*(cad2 + i) > 96 && *(cad2 + i) < 123) ? *(cad2 + i) - 32 : *(cad2 + i);
		
		//Comparar letra a letras, siempre van a ser sus valores de mayúsculas
		if (a > b)
			return 'A';
		else if (a < b)
			return 'D';
		
		i++;
		
		//Si se acaba una palabra antes que la otra, retornar la menor.
		if (*(cad1 + i) == '\0')
			return 'D';
		if (*(cad2 + i) == '\0')
			return 'A';
	}
	
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

	for (i = 1; i < c; i++){
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
	int i, j;
	
	char formato = v[c - 1][0];
			
   //Recorrer el arreglo
	for (i = 2; i < (c - ARGUMENTOS); i++){
		
		char clave[length(v[i]) + 1];
		copiaCad(clave, v[i]);
				
		j = i-1;
		
		//Comparar el valor selecionado con todos los valores anteriores
		while (j >= 1 && comparaCads(v[j], clave) == formato){
			//Insertar el valor donde corresponda
			copiaCad(v[j + 1], v[j]);
			--j;
		}
		copiaCad(v[j + 1], clave);	
	}
}

void insercionNumeros(int c, char* v[]){
	
	int i,j,claveNumero;
	char formato = v[c - 1][0];
   	//Recorrer el arreglo
   	
	for (i = 2; i < (c - 3); i++){
		char clave[length(v[i]) + 1];
		copiaCad(clave, v[i]);
		
		claveNumero = strtol(v[i], NULL, 10);
		j = i-1;
		//Comparar el valor selecionado con todos los valores anteriores
		while (j >= 1 && comparaNums(strtol(v[j], NULL, 10), claveNumero) ==  formato){
			//Desplazar el valor una posición a la derecha
			copiaCad(v[j + 1], v[j]);
			--j;
		}
		copiaCad(v[j + 1], clave);
	}
}

void seleccion(int c, char* v[]){
	
	int i, j, limite;
	
	char formato = v[c - 1][0];
	
	for (i = 1; i < (c - ARGUMENTOS); i++){
		
		limite = i;
		
		for (int j = i + 1; j < (c - ARGUMENTOS); j++){
			if (comparaCads(v[limite], v[j]) == formato){
				limite = j;
			}
		}
		
		intercambiar(v, i, limite);
	}	
}

void seleccionNumeros(int c, char* v[]){
	
	int i, j, limite, a, b;
	
	char formato = v[c - 1][0];
	
	
	for (i = 1; i < (c - ARGUMENTOS); i++){
		
		limite = i;
		
		for (int j = i + 1; j < (c - ARGUMENTOS); j++){
			
			a = strtol(v[limite], NULL, 10);
	       	b = strtol(v[j], NULL, 10);
			
			if (comparaNums(a,b) == formato){
				limite = j;
			}
		}
		
		intercambiar(v, i, limite);
	}
}

void Shell(int n , int v[])
{
   int i , j , k , salto, aux, fin;
	
   salto = n;
   
   while ( salto > 0 )
   {
      salto = salto / 2;
      do
      {
         fin = 1;
         k  = n - salto;
         for ( i = 0 ; i < k ; i++ )
         {
            j = i + salto ;
            if ( v[i] < v[j] )
            {
                aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				fin = 0;
             }
          }
       }
       while ( fin == 0);
    }
}

