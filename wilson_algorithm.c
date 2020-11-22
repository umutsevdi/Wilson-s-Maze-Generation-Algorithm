
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void screen_update(int matrix[][50],int type,int process_time);
int randomwalk(int matrix[][50],int process_time);

void character_movement(int matrix[][50]);
int main(){
	srand(time(NULL));
	int matrix[50][50];
	int i,j;
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			if(j==0 || j==49){
				matrix[i][j]=1;
			}else if(i==0 || i==49){
				matrix[i][j]=1;
			}else{
				matrix[i][j]=0;
			}	
		}
	}
	matrix[48][49]=0;
	i=0;
	while(randomwalk(matrix,i)==1){
		i++;
	}
	matrix[0][1]=0;
	character_movement(matrix);
	return 0;
}

void character_movement(int matrix[][50]){
	int char_row=0;
	int char_col=1;	
	matrix[char_row][char_col]=5;
	screen_update(matrix,5,0);
	char move;
	int movement=0;
	while(char_row!=48 || char_col!=49){
		move=getch();
		if((move=='w'||move=='W')&&(matrix[char_row-1][char_col]!=1)&&char_row>0){
			matrix[char_row][char_col]=0;
			char_row-=1;
			movement+=1;
		}else if((move=='a'||move=='A')&&(matrix[char_row][char_col-1]!=1)){
			matrix[char_row][char_col]=0;	
			char_col-=1;
			movement+=1;
		}else if((move=='s'||move=='S')&&(matrix[char_row+1][char_col]!=1)){
			matrix[char_row][char_col]=0;	
			char_row+=1;
			movement+=1;
		}else if((move=='d'||move=='D')&&(matrix[char_row][char_col+1]!=1)){
			matrix[char_row][char_col]=0;	
			char_col+=1;
			movement+=1;
		}
		matrix[char_row][char_col]=5;
		screen_update(matrix,5,movement);
	}
	return;
}

void screen_update(int matrix[][50],int type,int process_time){
	int i;int j;
	system("@cls||clear");		
	printf("\033[48;2;90;180;0m" "| L A B I R E N T  O L U S T U R U C U |\n");
	printf("\033[48;2;180;90;0m" "");
	
	if(type==1){
		printf("ASAMA=%d\tDURUM= BLOK ARANIYOR\n",process_time);
		printf("\033[48;2;0;0;0m" "");
	}else if(type==2){
		printf("ASAMA=%d\tDURUM= BLOGA ULASILIYOR...\n",process_time);
		printf("\033[48;2;0;0;0m" "");
	}else if(type==3){
		printf("ASAMA=%d\tDURUM= TEMIZLENIYOR...\n",process_time);
		printf("\033[48;2;0;0;0m" "");
	}else if(type==4){
		printf("ASAMA=%d\tDURUM= LABIRENT TAMAMLANDI\n",process_time);
		printf("\033[48;2;0;0;0m" "");
	}else if(type==5){
		printf("\033[48;2;180;90;0m" "");
		printf("OYUN BASLADI\tAdim Sayisi=%d\n",process_time);
		printf("\033[48;2;0;0;0m" "");
		printf("Kazanmak icin cikisa ulas\nYukari=W\tAsagi=S\tSol=A\tSag=D\n");
	}
	if(type!=5){
		printf("Wilson's Algoritmasini kullanarak bir labirent olusturur\nLabirent tamamlandiktan sonra oynanabilir hale gelir\n");
	}
	
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
 			if(matrix[i][j]==0){
				printf("\033[48;2;0;0;0m" "  \033[48;2;0;0;0m");
			}else if(matrix[i][j]==1){
				printf("\033[48;2;90;180;0m" "  \033[48;2;0;0;0m");
				
			}else if(matrix[i][j]==4){
				printf("\033[48;2;150;150;0m" "  \033[48;2;0;0;0m");
				
			}else if(matrix[i][j]==5){
				printf("\033[48;2;0;150;150m" "  \033[48;2;0;0;0m");
				
			}else if(matrix[i][j]==6){
				printf("\033[48;2;150;0;150m" "  \033[48;2;0;0;0m");
				
			}else if(matrix[i][j]==7){
				printf("\033[48;2;150;150;150m" "  \033[48;2;0;0;0m");
				
			}else{
				printf("\033[48;2;90;90;0m" "  \033[48;2;0;0;0m");
			}
		}
		printf("\n");	
	}
	return;
}

int randomwalk(int matrix[][50],int process_time){

	int i=0;int j=0;
	int row=0;
	int col=0;
	int chance=0;
	int end_bug=0;
	int start_bug=0;
	int i_tmp=0;int j_tmp=0;
	while((matrix[row][col]!=0||matrix[row+1][col]!=0||matrix[row-1][col]!=0||matrix[row][col+1]!=0||matrix[row][col-1]!=0||matrix[row-1][col-1]!=0||matrix[row+1][col-1]!=0||matrix[row-1][col+1]!=0||matrix[row+1][col+1]!=0)&&end_bug<250){
		row=rand()%49+1;
		col=rand()%49+1;
		end_bug++;		
	}
	while((matrix[i][j]!=0||matrix[i+1][j]!=0||matrix[i-1][j]!=0||matrix[i][j+1]!=0||matrix[i][j-1]!=0||matrix[i-1][j-1]!=0||matrix[i+1][j+1]!=0||matrix[i+1][j-1]!=0||matrix[i-1][j+1]!=0)&&start_bug<250){
		i=rand()%49+1;
		j=rand()%49+1;
		start_bug++;	
	}
	if(start_bug>=250 || end_bug>=250){
		return 0;
	}
	matrix[row][col]=1;
	matrix[i][j]=4;	
	i_tmp=i;
	j_tmp=j;
	chance=rand()%4;
	if(chance==0){
		i_tmp++;
		matrix[i][j]=6;
	}else if(chance==1){
		j_tmp++;
		matrix[i][j]=7;
	}else if(chance==2){
		i_tmp--;
		matrix[i][j]=4;
	}else if(chance==3){
		j_tmp--;
		matrix[i][j]=5;
	}
	start_bug=0;
	while(matrix[i_tmp+1][j_tmp]!=1&&matrix[i_tmp-1][j_tmp]!=1&&matrix[i_tmp][j_tmp+1]!=1&&matrix[i_tmp][j_tmp-1]!=1&&matrix[i_tmp-1][j_tmp-1]!=1&&matrix[i_tmp+1][j_tmp-1]!=1&&matrix[i_tmp-1][j_tmp+1]!=1&&matrix[i_tmp+1][j_tmp+1]!=1&&i_tmp+1<49&&i_tmp-1>0&&j_tmp+1<49&&j_tmp-1>0&&start_bug<300){
		start_bug++;
		chance=rand()%4;
		if(chance==0 && matrix[i+2][j-1]!=1&& matrix[i+2][j+1]!=1){
			matrix[i_tmp][j_tmp]=6;
			i_tmp++;
			
		}else if(chance==1&& matrix[i-1][j+2]!=1&& matrix[i+1][j+2]!=1){
			matrix[i_tmp][j_tmp]=7;
			j_tmp++;
			
		}else if(chance==2&& matrix[i-2][j-1]!=1&& matrix[i-2][j+1]!=1){
			matrix[i_tmp][j_tmp]=4;
			i_tmp--;
			
		}else if(chance==3&& matrix[i-1][j-2]!=1&& matrix[i+1][j-2]!=1){
			matrix[i_tmp][j_tmp]=5;
			j_tmp--;	
		}
		if(start_bug%20==19){
			screen_update(matrix,1,process_time);
		}
	}

	if(start_bug>300){
		return 0;
	}
	while(matrix[i][j]!=1){
		if(matrix[i][j]==4){
			matrix[i][j]=1;
			i--;
		}else if(matrix[i][j]==5){
			matrix[i][j]=1;
			j--;
		}else if(matrix[i][j]==6){
			matrix[i][j]=1;
			i++;

		}else if(matrix[i][j]==7){
			matrix[i][j]=1;
			j++;

		}else{
			matrix[i][j]=1;
		}
	}
	screen_update(matrix,2,process_time);
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			if(matrix[i][j]>1){
				matrix[i][j]=0;	
			}
		}
	}
	screen_update(matrix,3,process_time);
	return 1;	
}


