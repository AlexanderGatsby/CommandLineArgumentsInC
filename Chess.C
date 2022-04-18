#include <stdio.h>
#include <stdlib.h>
#define BOXES 8

void startBoard(int**);
void printBoard(int**);
void printPlayGround();

int main(){
	int i;
	int **Board;
	
	Board = (int **) malloc(BOXES * sizeof(int *));
		
	for (i = 0; i < BOXES; i++)
		Board[i] = (int *) malloc(BOXES * sizeof(int));
	
	
	printPlayGround();
	
	//startBoard(Board);
	//printBoard(Board);
	
	return 0;
}

void startBoard(int **Board){
	
//Empty boxes = 0
//Pawns = 1
//Knight = 2
//Bishop = 3
//Rook = 4
//Queen = 5
//King = 6
	
	int i, j;
	
	for (i = 0; i < BOXES; i++){
		for(j = 0; j < BOXES; j++){
			
			//Pawns
			if (i == 1 or i == 6){
				Board[i][j] = 1;				
			}else if (i == 0 or i == 7){
				//Rooks
				if (j == 0 or j == 7){
					Board[i][j] = 4;	
				}
				
				//Knights
				if (j == 1 or j == 6){
					Board[i][j] = 2;	
				}
			
				//Bishops
				if (j == 2 or j == 5){
					Board[i][j] = 3;
				}
				
				//Queen
				if (j == 3){
					Board[i][j] = 5;
				}
				
				//Queen
				if (j == 4){
					Board[i][j] = 6;
				}
				
			} else {
				Board[i][j] = 0;	
			}
			
		}
	}
}

void printBoard(int **Board){
	int i, j;
	
	for (i = 0; i < BOXES; i++){
		for (j = 0; j < BOXES; j++){
			
			switch (Board[i][j]){
				case 1:
					printf("%3 P");	
				break;
				case 2:
					printf("%3 N");
				break;
				case 3:
					printf("%3 B");
				break;
				case 4:
					printf("%3 R");
				break;
				case 5:
					printf("%3 Q");
				break;
				case 6:
					printf("%3 K");
				break;
			}
			
			if (Board[i][j] == 0){
				
				if ((i + j)%2 == 0)
					printf("  ");
				else 
					printf("%c%c", 219,219);
			}
			
				
			
			
		}
		printf("\n");
	}
	
}

void printPlayGround(){
	int i, j;
	
	for (i = 0; i < 17; i++){
		for (j = 0; j < 17; j++){
			
			if (i == 0){
				if (j == 0)
					printf("%c", 201);
				else if (j == 16)
					printf("%c", 187);
				else if ((j+i)%2 == 0)
					printf("%c", 203);
				else
					printf("%c", 205);
			} else if (i == 16){
				if (j == 0)
					printf("%c", 200);
				else if (j == 16)
					printf("%c", 188);
				else if ((j+i)%2 == 0)
					printf("%c", 202);
				else
					printf("%c", 205);
					
			} else{
				if (i%2 == 0){
					if (j == 0)
						printf("%c", 204);
					else if (j == 16)
						printf("%c", 185);
					else if ((j+i)%2 == 0)
						printf("%c", 206);
					else
						printf("%c", 205);
				} else{
					if (j == 0)
						printf("%c", 186);
					else if (j == 16)
						printf("%c", 186);
					else if ((j+i)%2 == 0){
						printf(" ");
					}else
						printf("%c",186);
				}
			}
		}
		printf("\n");
	}
	
	
	printf("%c%c%c%c%c\n", 201,205,203,205,187);
	printf("%c%c%c %c\n", 186,219,186,186);
	printf("%c%c%c%c%c\n", 200,205,202,205,188);
	
	
	printf("%c%c%c\n", 201,205,187);
	printf("%c%c%c\n", 186,219,186);
	printf("%c%c%c\n", 200,205,188);
	
}


