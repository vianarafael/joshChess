#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
int board[8][8];
int move[4][2];
bool exiter = false;


void board_print(){
char piece;
printf("\n  ");
	for(int i = 0; i<8; i++){
		printf("  %d  ", i+1);
	}
	printf("\n");
	for(int i = 0; i < 8; i++){
		printf("%d ",i+1);
		for(int j = 0; j<8; j++){
			switch(board [i][j]){
				case 0: 
				piece = ' ';	break;
				case 1: 
				piece = '+';	break;
				case 2:
				piece = 'Q';	break;
				case 3:
				piece = 'B';	break;
				case 4:
				piece = 'K';	break;
				case 5:
				piece = 'R';	break;
				case 6:
				piece = 'p';	break;
				case 7: 
				piece = '+';	break;
				case 8:
				piece = 'Q';	break;
				case 9:
				piece = 'B';	break;
				case 10:
				piece = 'K';	break;
				case 11:
				piece = 'R';	break;
				case 12:
				piece = 'p';	break;
			}
			if(board[i][j] == 0){
				printf("[   ]");
			}else if(board[i][j] <= 6){
				printf("[=%c=]",piece); 
			}else {
		
			printf("[-%c-]",piece); 
			}
	
		}
		printf("\n\n");
	}
}

void setup(){
	board[0][0] = 5;
	board[0][1] = 4;
	board[0][2] = 3;
	board[0][3] = 2;
	board[0][4] = 1;
	board[0][5] = 3;
	board[0][6] = 4;

	board[7][0] = 11;
	board[7][1] = 10;
	board[7][2] = 9;
	board[7][3] = 8;
	board[7][4] = 7;
	board[7][5] = 9;
	board[7][6] = 10;
	board[7][7] = 11;
	for(int j = 0; j<8; j++){
		board[1][j] = 6;
	}
	for(int j = 0; j<8; j++){
		board[6][j] = 12;
	}
	for(int i = 2; i < 6; i++){
		for(int j =0; j<8; j++){
			board[i][j] = 0;
		}
	}
	board[0][7] = 5;

}

int update_board(int originali, int originalj,int  targeti, int targetj){
	int temp = board[originali][originalj];
	board[targeti][targetj] = temp;
	board[originali][originalj] = 0;
		return(0);

}

int accept_command(){
	bool valid = false;
	bool valid2 = false;
	char inp[20];
	scanf("%s", inp);
	if(!(strcmp(inp,"move"))){
	
		scanf("%d %d", &move[0][0], &move[1][0]);
		move[0][0]--;	
		move[1][0]--;
		if(board[move[0][0]][move[1][0]] != 0){
		valid2 = true;
		}
		scanf("%d %d", &move[2][0], &move[3][0]);
		move[2][0]--;
		move[3][0]--;
		if(((board[move[2][0]][move[3][0]]+5)/6 != (board[move[0][0]][move[1][0]]+5)/6 || board[move[2][0]][move[3][0]] == 0) ){
			if(board[move[0][0]][move[1][0]] == 6){
				}
				if(move[0][0]+ 1 == move[2][0] && move[1][0] == move[3][0] && board[move[2][0]][move[3][0]] == 0) {
					valid = true;
				}else if(board[move[0][0]+1][move[1][0]] == 0 && move[1][0] == move[3][0] && move[0][0] + 2 == move[2][0] && move[0][0] == 1 && board[move[2][0]][move[3][0]] == 0){
					valid = true;
				}else if(move[0][0] + 1 == move[2][0] && abs(move[1][0]-move[3][0]) == 1 && board[move[2][0]][move[3][0]] != 0){
					valid = true;
			}else if(board[move[0][0]][move[1][0]] == 12){
				if(move[0][0]- 1 == move[2][0] && move[1][0] == move[3][0] && board[move[2][0]][move[3][0]] == 0) {
					valid = true;
				}else if(board[move[0][0]-1][move[1][0]] == 0 && move[1][0] == move[3][0] && move[0][0] - 2 == move[2][0] && move[0][0] == 6 && board[move[2][0]][move[3][0]] == 0){
					valid = true;
				}else if(move[0][0] - 1 == move[2][0] && abs(move[1][0]-move[3][0]) == 1 && board[move[2][0]][move[3][0]] != 0){
					valid = true;
				}
			}else if(board[move[0][0]][move[1][0]] ==  1 ||board[move[0][0]][move[1][0]] == 7){
				if(abs(move[0][0]-move[2][0]) == 1){
					if(abs(move[1][0]-move[3][0]) == 1 || abs(move[1][0] - move[3][0]) == 0){
						valid = true;
						
					}
				}else if(abs(move[0][0] - move[2][0]) == 0){
					if(abs(move[1][0] - move[3][0]) == 1){
						valid = true;
				}
				}
			}else if(board[move[0][0]][move[1][0]] == 4 || board[move[0][0]][move[1][0]] == 10){
				if(abs(move[0][0]-move[2][0]) == 2 || abs(move[1][0] - move[3][0]) == 2){
					if(abs(move[0][0] - move[2][0]) == 1 || abs(move[1][0] - move[3][0]) == 1){
						valid = true;
					}
				}
			}else if(board[move[0][0]][move[1][0]] == 5 || board[move[0][0]][move[1][0]] == 11){
				
				if((move[0][0] == move[2][0]) || (move[1][0] == move[3][0])){
					if(abs(move[0][0] - move[2][0]) == 1 || abs(move[1][0] - move[3][0]) == 1){
						valid = true;
					}else{
						bool obst = false;
						if(move[0][0] < move[2][0]){
							for(int i = 1; i < (move[2][0] - move[0][0]); i++){
								if(board[move[0][0]+i][move[1][0]] != 0){
									obst = true;
								}	
							}
						}else if (move[0][0] > move[2][0]){
							for(int i = 1; i < (move[0][0] -move[2][0]); i++){
								if(board[move[2][0]+i][move[1][0]] != 0){
									obst = true;
								}
							}
						}else if (move[1][0] < move[3][0]){
							for(int i =1; i < (move[3][0] - move[1][0]); i++){
								if(board[move[0][0]][move[1][0]+i] != 0){
									obst = true;
								}
							}
						}else{
							for(int i =1; i < (move[1][0] - move[3][0]); i++){
								if(board[move[0][0]][move[3][0]+i] != 0){
									obst = true;
								}
							}
						}
						if (obst == false){
							valid = true;
						}
					}	

				}
			}else if(board[move[0][0]][move[1][0]] == 3 || board[move[0][0]][move[1][0]] ==  9){
			
				if(abs(move[0][0] - move[2][0]) == abs(move[3][0] - move[1][0])){
					if(abs(move[0][0] - move[2][0]) == 1){
						valid = true;
					}else{
						bool obst = false;
						if(move[0][0] - move[2][0] > 0 && move[3][0] - move[1][0] > 0){
							for(int i=1; i < move[0][0] - move[2][0]; i++){
								if(board[move[0][0]- 1][move[1][0]+1] != 0){
									obst = true;
								}
							}
						}else if(move[0][0] - move[2][0] > 0 && move[1][0] - move[3][0] >0){
							for(int i = 1; i < move[0][0] - move[2][0]; i++){
								if(board[move[0][0]-1][move[1][0]-1] != 0){
									obst = true;
								}	
							}
						}else if(move[2][0] - move[0][0] > 0 && move[1][0] - move[3][0] >0){
							for(int i = 1; i < move[2][0] - move[0][0]; i++){
								if(board[move[0][0]+1][move[1][0]-1] != 0){
									obst = true;
								}	
							}
						}else{
							for(int i = 1; i < move[2][0] - move[0][0]; i++){
								if(board[move[0][0]+1][move[1][0]+1] != 0){
									obst = true;
								}	
							}
						}
						if (obst == false){
							valid = true;
						}
					}
				}	
			}else if(board[move[0][0]][move[1][0]] == 2 || board[move[0][0]][move[1][0]] == 8 ){
				
				if((move[0][0] == move[2][0]) || (move[1][0] == move[3][0])){
					if(abs(move[0][0] - move[2][0]) == 1 || abs(move[1][0] - move[3][0]) == 1){
						valid = true;
					}else{
						bool obst = false;
						if(move[0][0] < move[2][0]){
							for(int i = 1; i < (move[2][0] - move[0][0]); i++){
								if(board[move[0][0]+i][move[1][0]] != 0){
									obst = true;
								}	
							}
						}else if (move[0][0] > move[2][0]){
							for(int i = 1; i < (move[0][0] -move[2][0]); i++){
								if(board[move[2][0]+i][move[1][0]] != 0){
									obst = true;
								}
							}
						}else if (move[1][0] < move[3][0]){
							for(int i =1; i < (move[3][0] - move[1][0]); i++){
								if(board[move[0][0]][move[1][0]+i] != 0){
									obst = true;
								}
							}
						}else{
							for(int i =1; i < (move[1][0] - move[3][0]); i++){
								if(board[move[0][0]][move[3][0]+i] != 0){
									obst = true;
								}
							}
						}
						if (obst == false){
							valid = true;
						}
					}	

				}
				
				
				if(abs(move[0][0] - move[2][0]) == abs(move[3][0] - move[1][0])){
					if(abs(move[0][0] - move[2][0]) == 1){
						valid = true;
					}else{
						bool obst = false;
						if(move[0][0] - move[2][0] > 0 && move[3][0] - move[1][0] > 0){
							for(int i=1; i < move[0][0] - move[2][0]; i++){
								if(board[move[0][0]- 1][move[1][0]+1] != 0){
									obst = true;
								}
							}
						}else if(move[0][0] - move[2][0] > 0 && move[1][0] - move[3][0] >0){
							for(int i = 1; i < move[0][0] - move[2][0]; i++){
								if(board[move[0][0]-1][move[1][0]-1] != 0){
									obst = true;
								}	
							}
						}else if(move[2][0] - move[0][0] > 0 && move[1][0] - move[3][0] >0){
							for(int i = 1; i < move[2][0] - move[0][0]; i++){
								if(board[move[0][0]+1][move[1][0]-1] != 0){
									obst = true;
								}	
							}
						}else{
							for(int i = 1; i < move[2][0] - move[0][0]; i++){
								if(board[move[0][0]+1][move[1][0]+1] != 0){
									obst = true;
								}	
							}
						}
						if (obst == false){
							valid = true;
						}
					}
				}	
			}
		}
		
		if(valid == true && valid2 == true){
		return(1);
		}
	}else if(!(strcmp(inp,"exit"))){
		exiter = true;
		return(2);	
	}else if(!(strcmp(inp,"reset"))){
		setup();
		printf("\nboard reset\n");
		return(2);
	}else if(!(strcmp(inp,"command"))){
		scanf("%s", inp);
		if(!(strcmp(inp,"list"))){
		printf("\n\nBelow is the list of commands:\nmove [a] [b] [c] [d] - this command moves the piece from (a,b) to (c,d). This command will not be registered if the move is invalid\nexit - this command quits the game\nreset - this command resets the board to the original state\ncommand list - displays this list\nrules - displays the rules of the game\nboard - prints the state of the current board\n");
		return(2);
		}
	}else if(!(strcmp(inp,"board"))){
		board_print();
		return(2);
	}else if(!(strcmp(inp,"rules"))){
		printf("\nHere are the rules:\n");
		return(2);
	}
		printf("\nYour command was not registered. Please try again:\n");
		return(0);
	

}

int main(void){
	printf("\n");
	setup();
	while(!(exiter)){
	int ready = 0;
	if(ready == 1){
	board_print();
	}
	while(ready == 0){
	ready = accept_command();
	}
	if(ready == 1){
	update_board(move[0][0],move[1][0], move[2][0] ,move[3][0]);
	}
}
	printf("\n");
	return(0);
}







