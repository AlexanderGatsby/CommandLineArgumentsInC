#include <stdio.h>

void Shell(int, int []);

int main(){
	
	int datos[10] = {3,5,7,9,4,2,8,6,1,0};
		
	Shell(10, datos);
	
	printf("");
	
	for(int i = 0; i < 10; i++){
		printf("%d\n", datos[i]);
	}
	
	
	return 0;
}


void Shell(int n , int v[])
{
   int i , j , k , salto ;  int aux ;  int fin ;
	
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
