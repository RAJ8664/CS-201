#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define row 9
#define col 9
#define NUM_MINES 20

char board[row][col];
char hints[row][col];

void initializeBoard() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = ' ';
            hints[i][j] = '0';
        }
    }
}

void placeMines() {
    srand(time(NULL));
    int minesPlaced = 0;
    while (minesPlaced < NUM_MINES) {
        int x = rand() % row;
        int y = rand() % col;
        if (board[x][y] != '*') {
            board[x][y] = '*';
            minesPlaced++;
        }
    }
    
    for(int i = 0; i < row; i++){
    	for(int j = 0; j < col; j++){
    		int count = 0;
    		if(board[i][j] != '*'){
    			count = 0;
    			if(i - 1 >= 0){
					if(board[i - 1][j] == '*'){
						count++;
					}				
    			}
    			if(i - 1 >= 0 && j + 1 < col){
						if(board[i - 1][j + 1] == '*'){
							count++;
						}
				}
				
				if(i - 1 >=0 && j - 1 >= 0){
					if(board[i - 1][j - 1] == '*'){
						count++;
					}
				}
				
				if(j - 1 >=0){
					if(board[i][j - 1] == '*'){
						count++;
					}
				}
				if(j + 1 < col){
					if(board[i][j + 1] == '*'){
						count++;
					}
				}
				
				if(i + 1 < row && j - 1 >= 0){
					if(board[i + 1][j - 1] == '*'){
						count++;
					}
				}
				if(i + 1 < row){
					if(board[i + 1][j]== '*'){
						count++;
					}
				}
				if(i + 1 < row && j + 1 < col){
					if(board[i + 1][j + 1] == '*'){
						count++;
					} 
				}
				board[i][j] = count + '0';
    		}
    	}
   }
}


void printBoard() {
    printf("  ");
    for (int i = 0; i < row; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int x = 0; x < row; x++) {
        printf("%d ", x);
        for (int y = 0; y < col; y++) {
        	
            printf("%c ", board[x][y]);
        }
        printf("\n");
    }
}

int main() {
    initializeBoard();
    placeMines();
    //calculateHints();
    printBoard();
    return 0;
}
