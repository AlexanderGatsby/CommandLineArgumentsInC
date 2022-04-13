#include <stdio.h>

int ordenable(int, char*[]);
int length(char*);
int comparaCads(char*, char*);
char* copiaCad(char*, char*);
void burbuja(int, char*[]);
void intercambiar(char*[], int);

int main(int argc, char* argv[]){
	
	if (ordenable(argc, argv) == 1)
		printf("\nEs ordenable\n\n");
	else
		printf("\nNo se puede ordenar esta madre no mms xd\n\n");
	
	burbuja(argc, argv);	
	
	
	
	int i;
	for (i = 1; i < argc - 3; i++)
		printf("%s\n", *(argv+i));
	
	//printf("\n%c Ponemos el acento o tilde en canel%cn\n",162, 162); //ó
	//Es decir, invocar el código de carácter que corresponde a la letra acentuada...

	//Códigos:

	//á: 160 é: 130 í: 161 ó: 162 ú: 163 Á: 181 É: 144 Í: 214 Ó: 224 Ú: 223 ñ: 164 Ñ: 165
	
	
	return 0;
}



int ordenable(int c, char* v[]){
	
	//Verificar que hay al menos dos cadenas y los tres argumentos
	if (c <= 5){
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
			printf("\nEror: Falta un argumento de tipo de elementos a ordenar A o D\n");
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

int comparaCads(char* cad1, char* cad2){
	int i = 0;
	
	while (*(cad1 + i) != '\0' && *(cad2 + i) != '\0'){
		
		if (*(cad1 + i) < *(cad2 + i))
			return -1;
		else if (*(cad1 + i) > *(cad2 + i))
			return 1;
		i++;
		
		if (*(cad1 + i) == '\0')
			return -1;
		if (*(cad2 + i) == '\0')
			return 1;
	}
	
	return 0;
}

void burbuja(int c, char* v[]){
	
	int i,j;
	
	int formato = v[c - 1][0] == 'A'? 1 : -1;

	for (i = 1; i < c; i++){
	       for (j = 1; j < (c - 4); j++){
	       	
	       	if (comparaCads(v[j], v[j + 1]) == formato)
	       		intercambiar(v, j);
		}
	}
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

void intercambiar(char* v[], int i){
	char temporal[length(v[i + 1]) + 1];
	          	
	copiaCad(temporal, v[i + 1]);
	copiaCad(v[i + 1], v[i]);
	copiaCad(v[i], temporal);
}
