#include <stdio.h>
#include <string.h>

int comparacad(char *cad, char cad2*){
	
	
	
}

int main (){
	
	int resultado = 0;
	
	char c1[30] = "caso";
	char c2[30] = "cosa";
	
	resultado = strcmp(c1,c2);
	
	printf("strcmp(%s,%s) = %d", c1, c2, resultado);
	
	
	strcpy(c1, "CAsA");
	strcpy(c2, "auTomovil");
	
	resultado = strcmp(c1,c2);
	
	printf("\nstrcmp(%s,%s) = %d", c1, c2, resultado);
	
	strcpy(c1, "ZaPAtO");
	strcpy(c2, "ZApATo");
	
	resultado = strcmp(c1,c2);
	
	printf("\nstrcmp(%s,%s) = %d", c1, c2, resultado);	
	return 0;
}
