#include <stdio.h>

int main(){
	int limite; //Puede ser superior o inferior
	int size = 10;
	int arr[10] = {9,-4,75,32,1235,4,-88,11,-465,0};
	
	for (int i = 0; i < size; i++){
		int limite = i;
		for (int j = i + 1; j < size; j++){
			if (arr[limite] > arr[j]){
				limite = j;				
			}
		}
		
		int temp = arr[i];
		arr[i] = arr[limite];
		arr[limite] = temp;
	}
	
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	
	
	
	return 0;
}
