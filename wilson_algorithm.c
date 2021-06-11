
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void screenUpdate(int matrix[][50], int type, int processTime);
int randomWalk(int matrix[][50], int processTime);

void characterMovement(int matrix[][50]);
int main()
{
	srand(time(NULL));
	int matrix[50][50];
	int i, j;
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 50; j++)
		{
			if (j == 0 || j == 49)
			{
				matrix[i][j] = 1;
			}
			else if (i == 0 || i == 49)
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = 0;
			}
		}
	}
	matrix[48][49] = 0;
	i = 0;
	while (randomWalk(matrix, i) == 1)
	{
		i++;
	}
	matrix[0][1] = 0;
	characterMovement(matrix);
	return 0;
}

void characterMovement(int matrix[][50])
{
	int characterRow = 0;
	int characterColumn = 1;
	matrix[characterRow][characterColumn] = 5;
	screenUpdate(matrix, 5, 0);
	char move;
	int movement = 0;
	while (characterRow != 48 || characterColumn != 49)
	{
		move = getch();
		if ((move == 'w' || move == 'W') && (matrix[characterRow - 1][characterColumn] != 1) && characterRow > 0)
		{
			matrix[characterRow][characterColumn] = 0;
			characterRow -= 1;
			movement += 1;
		}
		else if ((move == 'a' || move == 'A') && (matrix[characterRow][characterColumn - 1] != 1))
		{
			matrix[characterRow][characterColumn] = 0;
			characterColumn -= 1;
			movement += 1;
		}
		else if ((move == 's' || move == 'S') && (matrix[characterRow + 1][characterColumn] != 1))
		{
			matrix[characterRow][characterColumn] = 0;
			characterRow += 1;
			movement += 1;
		}
		else if ((move == 'd' || move == 'D') && (matrix[characterRow][characterColumn + 1] != 1))
		{
			matrix[characterRow][characterColumn] = 0;
			characterColumn += 1;
			movement += 1;
		}
		matrix[characterRow][characterColumn] = 5;
		screenUpdate(matrix, 5, movement);
	}
	return;
}

void screenUpdate(int matrix[][50], int type, int processTime)
{
	int i;
	int j;
	system("@cls||clear");
	printf("\033[48;2;90;180;0m"
		   "| M A Z E  G E N E R A T O R |\n");
	printf("\033[48;2;180;90;0m"
		   "");

	if (type == 1)
	{
		printf("STAGE=%d\tSTATE = SEARCHING TILE\n", processTime);
		printf("\033[48;2;0;0;0m"
			   "");
	}
	else if (type == 2)
	{
		printf("STAGE=%d\tSTATE = REACHING TO TILE...\n", processTime);
		printf("\033[48;2;0;0;0m"
			   "");
	}
	else if (type == 3)
	{
		printf("STAGE=%d\tSTATE = CLEANING PATH...\n", processTime);
		printf("\033[48;2;0;0;0m"
			   "");
	}
	else if (type == 4)
	{
		printf("STAGE=%d\tSTATE= LABYRINTH COMPLETED\n", processTime);
		printf("\033[48;2;0;0;0m"
			   "");
	}
	else if (type == 5)
	{
		printf("\033[48;2;180;90;0m"
			   "");
		printf("GAME STARTED\tStep Counter = %d\n", processTime);
		printf("\033[48;2;0;0;0m"
			   "");
		printf("To win, reach to the end\nUp=W\tDown=S\tLeft=A\tRight=D\n");
	}
	if (type != 5)
	{
		printf("Builds a labyrinth with Wilson's Algorithm\nBecomes playable once the map is completed\n");
	}

	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 50; j++)
		{
			if (matrix[i][j] == 0)
			{
				printf("\033[48;2;0;0;0m"
					   "  \033[48;2;0;0;0m");
			}
			else if (matrix[i][j] == 1)
			{
				printf("\033[48;2;90;180;0m"
					   "  \033[48;2;0;0;0m");
			}
			else if (matrix[i][j] == 4)
			{
				printf("\033[48;2;150;150;0m"
					   "  \033[48;2;0;0;0m");
			}
			else if (matrix[i][j] == 5)
			{
				printf("\033[48;2;0;150;150m"
					   "  \033[48;2;0;0;0m");
			}
			else if (matrix[i][j] == 6)
			{
				printf("\033[48;2;150;0;150m"
					   "  \033[48;2;0;0;0m");
			}
			else if (matrix[i][j] == 7)
			{
				printf("\033[48;2;150;150;150m"
					   "  \033[48;2;0;0;0m");
			}
			else
			{
				printf("\033[48;2;90;90;0m"
					   "  \033[48;2;0;0;0m");
			}
		}
		printf("\n");
	}
	return;
}

int randomWalk(int matrix[][50], int processTime)
{

	int i = 0;
	int j = 0;
	int row = 0;
	int col = 0;
	int direction = 0;
	int endPass = 0;
	int startPass = 0;
	int i_tmp = 0;
	int j_tmp = 0;
	while ((matrix[row][col] != 0 || matrix[row + 1][col] != 0 || matrix[row - 1][col] != 0 || matrix[row][col + 1] != 0 || matrix[row][col - 1] != 0 || matrix[row - 1][col - 1] != 0 || matrix[row + 1][col - 1] != 0 || matrix[row - 1][col + 1] != 0 || matrix[row + 1][col + 1] != 0) && endPass < 250)
	{
		row = rand() % 49 + 1;
		col = rand() % 49 + 1;
		endPass++;
	}
	while ((matrix[i][j] != 0 || matrix[i + 1][j] != 0 || matrix[i - 1][j] != 0 || matrix[i][j + 1] != 0 || matrix[i][j - 1] != 0 || matrix[i - 1][j - 1] != 0 || matrix[i + 1][j + 1] != 0 || matrix[i + 1][j - 1] != 0 || matrix[i - 1][j + 1] != 0) && startPass < 250)
	{
		i = rand() % 49 + 1;
		j = rand() % 49 + 1;
		startPass++;
	}
	if (startPass >= 250 || endPass >= 250)
	{
		return 0;
	}
	matrix[row][col] = 1;
	matrix[i][j] = 4;
	i_tmp = i;
	j_tmp = j;
	direction = rand() % 4;
	if (direction == 0)
	{
		i_tmp++;
		matrix[i][j] = 6;
	}
	else if (direction == 1)
	{
		j_tmp++;
		matrix[i][j] = 7;
	}
	else if (direction == 2)
	{
		i_tmp--;
		matrix[i][j] = 4;
	}
	else if (direction == 3)
	{
		j_tmp--;
		matrix[i][j] = 5;
	}
	startPass = 0;
	while (matrix[i_tmp + 1][j_tmp] != 1 && matrix[i_tmp - 1][j_tmp] != 1 && matrix[i_tmp][j_tmp + 1] != 1 && matrix[i_tmp][j_tmp - 1] != 1 && matrix[i_tmp - 1][j_tmp - 1] != 1 && matrix[i_tmp + 1][j_tmp - 1] != 1 && matrix[i_tmp - 1][j_tmp + 1] != 1 && matrix[i_tmp + 1][j_tmp + 1] != 1 && i_tmp + 1 < 49 && i_tmp - 1 > 0 && j_tmp + 1 < 49 && j_tmp - 1 > 0 && startPass < 300)
	{
		startPass++;
		direction = rand() % 4;
		if (direction == 0 && matrix[i + 2][j - 1] != 1 && matrix[i + 2][j + 1] != 1)
		{
			matrix[i_tmp][j_tmp] = 6;
			i_tmp++;
		}
		else if (direction == 1 && matrix[i - 1][j + 2] != 1 && matrix[i + 1][j + 2] != 1)
		{
			matrix[i_tmp][j_tmp] = 7;
			j_tmp++;
		}
		else if (direction == 2 && matrix[i - 2][j - 1] != 1 && matrix[i - 2][j + 1] != 1)
		{
			matrix[i_tmp][j_tmp] = 4;
			i_tmp--;
		}
		else if (direction == 3 && matrix[i - 1][j - 2] != 1 && matrix[i + 1][j - 2] != 1)
		{
			matrix[i_tmp][j_tmp] = 5;
			j_tmp--;
		}
		if (startPass % 20 == 19)
		{
			screenUpdate(matrix, 1, processTime);
		}
	}

	if (startPass > 300)
	{
		return 0;
	}
	while (matrix[i][j] != 1)
	{
		if (matrix[i][j] == 4)
		{
			matrix[i][j] = 1;
			i--;
		}
		else if (matrix[i][j] == 5)
		{
			matrix[i][j] = 1;
			j--;
		}
		else if (matrix[i][j] == 6)
		{
			matrix[i][j] = 1;
			i++;
		}
		else if (matrix[i][j] == 7)
		{
			matrix[i][j] = 1;
			j++;
		}
		else
		{
			matrix[i][j] = 1;
		}
	}
	screenUpdate(matrix, 2, processTime);
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 50; j++)
		{
			if (matrix[i][j] > 1)
			{
				matrix[i][j] = 0;
			}
		}
	}
	screenUpdate(matrix, 3, processTime);
	return 1;
}
