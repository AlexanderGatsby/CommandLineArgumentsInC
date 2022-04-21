#include <stdio.h>

void shell(int, int []);
char comparar(int, int);
void shellCads(int, int[]);
void shellSort(int[], int);
char comparaCads(char*, char*);
void imprimir(int, int[]);

int main(){
	
	int datos[11] = {3,5,7,13,9,4,2,8,6,1,0};
	
	printf("Salto n. Datos: ");
	imprimir(11, datos);
	printf("\n");
	
	shellCads(11, datos);
	printf("\n");
	imprimir(11, datos);
	
	
	
	
	return 0;
}

void imprimir(int c, int v[]){
	for(int i = 0; i < c; i++){
		printf(" %d ", v[i]);
	}
}

char comparar(int a, int b){
	
	if (a > b)
		return 'A';
	else if (a < b)
		return 'D';
	
	return 'N';
}

char compararCads(char a, char b){
	
	if (a > b)
		return 'A';
	else if (a < b)
		return 'D';
	
	return 'N';
}


void intercambiar(int v[], int i, int j){
	int temporal;
	          	
	temporal = v[i];
	v[i] = v[j];
	v[j] = temporal;
}

void shell(int n , int v[])
{
   int i , j , k , salto ;  int aux ;  int fin ;
   char formato = 'D';

	
   salto = n ;
   
   
   while ( salto > 0 )
   {
      salto = salto / 2 ;
      do
      {
         fin = 1;
         k  = n - salto;
         for ( i = 0 ; i < k ; i++ )
         {
            j = i + salto ;
            if ( comparar(v[i],v[j]) == formato)
            {
                intercambiar(v, i, j);
				fin = 0;
             }
          }
       }
       while ( fin == 0);
    }
}

char comparaCads(char *cad1, char *cad2){
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

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
        printf("\n");
        imprimir(n, arr);
    }
}

void shellCads(int c, int v[]){	
	int salto, i, aux, flag;
	
	salto = c;
		
	while (salto > 0){
			
		i = 0;
		
		salto = salto/2;
		
		do {
			if (v[i] > v[i+salto]){
				
				aux = v[i+salto];
				v[i+salto] = v[i];
				v[i] = aux;
				flag == 1;
			}
			
			i++;
		}while ((i + salto) < c);
				
		printf("Salto %d. Lista :", salto);
		imprimir(c, v);
		printf("\n");
	}
}
