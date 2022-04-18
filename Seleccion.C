#include <stdio.h>

int main(){
	
	for (int i = 0; i < size; i++){
		int minimo = i;
		for (int j = i +1; j < size; j++){
			if (arr[minimo] > arr[j]){
				minimo = j;				
			}
		}
		
		int temp = arr[i];
		arr[i] = arr[minimo];
		arr[minimo] = temp;
				
	}
	
	
	
	return 0;
}
