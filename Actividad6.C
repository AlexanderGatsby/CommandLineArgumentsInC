#include <stdio.h>

int ordenable(int c, char* v[]){
	
	//Verificar que hay al menos dos cadenas y los tres argumentos
	if (c <= 5){
		printf("\nFallo: No hay cadenas suficientes\n");
		return 0;
	}
	
	printf("\n%c\n", v[(c - 1)][0]);
	
	if ( v[(c - 1)][0] != 'A'){		
		if (v[(c - 1)][0] != 'D'){
			printf("\nFallo: No hay argumento de forma de orden\n");
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
			printf("\nFallo: No hay metodo de ordenamiento\n");
			return 0;
		break;	
	}
	
	if ( v[(c - 3)][0] != 'N'){
		if (v[(c - 3)][0] != 'C'){
			printf("\nFallo: No hay tipo de elemento a ordenar\n");
			return 0;
		}
	}
			
	
	return 1;
}

int main(int argc, char* argv[]){
	
	int i;
	for (i = 0; i < argc; i++)
		printf("%s\n", *(argv+i));
	
	
	if (ordenable(argc, argv) == 1)
		printf("\nEs ordenable\n");
	else
		printf("\nNo se puede ordenar esta madre no mms xd\n");
	
	//printf("%s", argv[argc]); //Returns (null)
	//printf("%d", argv[argc]); //Returns 0
	
	printf("\n%c Ponemos el acento o tilde en canel%cn\n",162, 162); //ó
//Es decir, invocar el código de carácter que corresponde a la letra acentuada...

//Códigos:

//á: 160 é: 130 í: 161 ó: 162 ú: 163 Á: 181 É: 144 Í: 214 Ó: 224 Ú: 223 ñ: 164 Ñ: 165
	
	
	return 0;
}
