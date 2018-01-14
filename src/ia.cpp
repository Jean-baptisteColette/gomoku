#include "../include/pisqpipe.h"
#include "../include/gomoku.h"
#include <windows.h>

// Value of all of the estimations

#define _A 100000000 // 5 alligné pour la win
#define _B 10000000 // 5 et 6 pour défendre
#define _C 1000000 // 4 pour la win
#define _D 100000 // 4 pour defendre
#define _E 10000 // 3 pour la win
#define _F 1000 // 3 pour défendre
#define _G 100 // 2 pour la win
#define _H 10 // 2 pour défendre
#define _I 1 // 1 pour défendre

// Function that returns an estimation
int func_estimation(int countenemis, int countamis)
{
	int ret1 = 0;
	int ret2 = 0;

	switch (countamis) {
	case 5: 
		ret1 = _A;
		break;
	case 4: 
		ret1 = _C;
		break;
	case 3:
		ret1 = _E;
		break;
	case 2:
		ret1 = _G;
		break;
	default:
		break;
	}
	switch (countenemis) {
	case 6:
		ret2 = _B;
		break;
	case 5:
		ret2 = _B;
		break;
	case 4:
		ret2 = _D;
		break;
	case 3:
		ret2 = _F;
		break;
	case 2:
		ret2 = _H;
		break;
	case 1:
		ret2 = _I;
		break;
	default:
		break;
	}
	if (ret2 > ret1)
		return (ret2);
	else if (ret2 < ret1)
		return (ret1);
	return (0);
}

// Function Diagonale Nord/West qui retourne une estimation
int	func_diago1(int **grille, int x, int y)
{
	if (x >= 0 && y >= 0 && y < height && x < width && grille[x][y] == 0)
	{
		int countamis = 0;
		int countenemis = 0;
		int bonus = 0;
		int danger = 0;
		int tempx;
		int tempy;
		// count how many are aligned if 1 is put
		grille[x][y] = 1;
		tempx = x;
		tempy = y;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 1)
		{
			tempx++;
			tempy++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			bonus++;
		}
		tempx--;
		tempy--;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 1)
		{
			tempx--;
			tempy--;
			countamis++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			bonus++;
		}
		// count how many are aligned if 2 is put
		grille[x][y] = 2;
		tempx = x;
		tempy = y;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 2)
		{
			tempx++;
			tempy++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			danger++;
		}
		tempx--;
		tempy--;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 2)
		{
			tempx--;
			tempy--;
			countenemis++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			danger++;
		}
		grille[x][y] = 0;
		if (danger == 2)
		{
			return (func_estimation(countenemis + 1, countamis));
		}
		else if (bonus == 2)
		{
			return (func_estimation(countenemis, countamis));
		}
		return (func_estimation(countenemis, countamis));
	}
	else
		return (0);
}
// Function Diagonale Sud/Est qui retourne une estimation
int func_diago2(int **grille, int x, int y)
{
	if (x >= 0 && y >= 0 && y < height && x < width && grille[x][y] == 0)
	{
		int bonus = 0;
		int danger = 0;
		int countamis = 0;
		int countenemis = 0;
		int tempx;
		int tempy;
		// count how many are aligned if 1 is put
		grille[x][y] = 1;
		tempx = x;
		tempy = y;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 1)
		{
			tempx++;
			tempy--;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			bonus++;
		}
		tempx--;
		tempy++;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 1)
		{
			tempx--;
			tempy++;
			countamis++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			bonus++;
		}
		// count how many are aligned if 2 is put
		grille[x][y] = 2;
		tempx = x;
		tempy = y;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 2)
		{
			tempx++;
			tempy--;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			danger++;
		}
		tempx--;
		tempy++;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 2)
		{
			tempx--;
			tempy++;
			countenemis++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			danger++;
		}
		grille[x][y] = 0;
		if (danger == 2)
		{
			return (func_estimation(countenemis + 1, countamis));
		}
		else if (bonus == 2)
		{
			return (func_estimation(countenemis, countamis+ 1));
		}
		return (func_estimation(countenemis, countamis));
	}
	else
		return (0);
}

// Function Horizontal qui retourne une estimation
int func_hori(int **grille, int x, int y)
{
	if (x >= 0 && y >= 0 && y < height && x < width && grille[x][y] == 0)
	{
		int danger = 0;
		int bonus = 0;
		int countamis = 0;
		int countenemis = 0;
		int tempx;
		int tempy;
		// count how many are aligned if 1 is put
		grille[x][y] = 1;
		tempx = x;
		tempy = y;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 1)
		{
			tempx++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			bonus++;
		}
		tempx--;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 1)
		{
			tempx--;
			countamis++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			bonus++;
		}
		// count how many are aligned if 2 is put
		grille[x][y] = 2;
		tempx = x;
		tempy = y;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 2)
		{
			tempx++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			danger++;
		}
		tempx--;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 2)
		{
			tempx--;
			countenemis++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			danger++;
		}
		grille[x][y] = 0;
		if (danger == 2)
		{
			return (func_estimation(countenemis + 1, countamis));
		}
		else if (bonus == 2)
		{
			return (func_estimation(countenemis, countamis + 1));
		}
		return (func_estimation(countenemis, countamis));
	}
	else
		return (0);
}

// Function Verticale qui retourne une estimation
int func_verti(int **grille, int x, int y)
{
	if (x >= 0 && y >= 0 && y < height && x < width && grille[x][y] == 0)
	{
		int bonus = 0;
		int danger = 0;
		int countamis = 0;
		int countenemis = 0;
		int tempx;
		int tempy;
		// count how many are aligned if 1 is put
		grille[x][y] = 1;
		tempx = x;
		tempy = y;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 1)
		{
			tempy++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			bonus++;
		}
		tempy--;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 1)
		{
			tempy--;
			countamis++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			bonus++;
		}
		// count how many are aligned if 2 is put
		grille[x][y] = 2;
		tempx = x;
		tempy = y;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 2)
		{
			tempy++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			danger++;
		}
		tempy--;
		while (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 2)
		{
			tempy--;
			countenemis++;
		}
		if (tempx >= 0 && tempy >= 0 && tempy < height && tempx < width && grille[tempx][tempy] == 0)
		{
			danger++;
		}
		grille[x][y] = 0;
		if (danger == 2)
		{
			return (func_estimation(countenemis + 1, countamis));
		}
		else if (bonus == 2)
		{
			return (func_estimation(countenemis, countamis + 1));
		}
		return (func_estimation(countenemis, countamis));
	}
	else
		return (0);

}

// Function qui check tous les cotés et qui retourne l'estimation

int my_estimator(int **grille, int x, int y, int Maxestimation)
{
	int estimation = 0;
	int tempx;
	int tempy;

	//Diago1
	tempx = x - 1;
	tempy = y - 1;
	estimation = func_diago1(grille, tempx, tempy);
	estimation += func_diago2(grille, tempx, tempy);
	estimation += func_hori(grille, tempx, tempy);
	estimation += func_verti(grille, tempx, tempy);
	if (Maxestimation < estimation)
	{
		Maxestimation = estimation;
		finalx = tempx;
		finaly = tempy;
	}
	//Diago1
	tempx = x + 1;
	tempy = y + 1;
	estimation = func_diago1(grille, tempx, tempy);
	estimation += func_diago2(grille, tempx, tempy);
	estimation += func_hori(grille, tempx, tempy);
	estimation += func_verti(grille, tempx, tempy);
	if (Maxestimation < estimation)
	{
		Maxestimation = estimation;
		finalx = tempx;
		finaly = tempy;
	}
	//Diago2
	tempx = x - 1;
	tempy = y + 1;
	estimation = func_diago1(grille, tempx, tempy);
	estimation += func_diago2(grille, tempx, tempy);
	estimation += func_hori(grille, tempx, tempy);
	estimation += func_verti(grille, tempx, tempy);
	if (Maxestimation < estimation)
	{
		Maxestimation = estimation;
		finalx = tempx;
		finaly = tempy;
	}
	//Diago2
	tempx = x + 1;
	tempy = y - 1;
	estimation = func_diago1(grille, tempx, tempy);
	estimation += func_diago2(grille, tempx, tempy);
	estimation += func_hori(grille, tempx, tempy);
	estimation += func_verti(grille, tempx, tempy);
	if (Maxestimation < estimation)
	{
		Maxestimation = estimation;
		finalx = tempx;
		finaly = tempy;
	}
	//Horiz
	tempx = x;
	tempy = y - 1;
	estimation = func_diago1(grille, tempx, tempy);
	estimation += func_diago2(grille, tempx, tempy);
	estimation += func_hori(grille, tempx, tempy);
	estimation += func_verti(grille, tempx, tempy);
	if (Maxestimation < estimation)
	{
		Maxestimation = estimation;
		finalx = tempx;
		finaly = tempy;
	}
	//Horiz
	tempx = x;
	tempy = y + 1;
	estimation = func_diago1(grille, tempx, tempy);
	estimation += func_diago2(grille, tempx, tempy);
	estimation += func_hori(grille, tempx, tempy);
	estimation += func_verti(grille, tempx, tempy);
	if (Maxestimation < estimation)
	{
		Maxestimation = estimation;
		finalx = tempx;
		finaly = tempy;
	}
	//Verti
	tempx = x - 1;
	tempy = y;
	estimation = func_diago1(grille, tempx, tempy);
	estimation += func_diago2(grille, tempx, tempy);
	estimation += func_hori(grille, tempx, tempy);
	estimation += func_verti(grille, tempx, tempy);
	if (Maxestimation < estimation)
	{
		Maxestimation = estimation;
		finalx = tempx;
		finaly = tempy;
	}
	//Verti
	tempx = x + 1;
	tempy = y;
	estimation = func_diago1(grille, tempx, tempy);
	estimation += func_diago2(grille, tempx, tempy);
	estimation += func_hori(grille, tempx, tempy);
	estimation += func_verti(grille, tempx, tempy);
	if (Maxestimation < estimation)
	{
		Maxestimation = estimation;
		finalx = tempx;
		finaly = tempy;
	}
	return (Maxestimation);
}

// Fontion qui check si c'est le premier move
int	checkForFirst(int **grille)
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++)
		{
			if (grille[x][y] != 0)
			{
				return (1);
			}
		}
	}
	do_mymove(width / 2, height / 2);
	return (0);
}

// Function qui parcourt tous les pions et verifie les estimation pour chacune des positions libre à coté de ce meme pion
int ia(int **grille) {
	int tempx;
	int tempy;
	int Maxestimation = 0;
	int estimation = 0;

	if (checkForFirst(grille) == 0)
		return (0);
	finalx = 0;
	finaly = 0;
	for (int x = 0; x < width - 1; x++)
	{
		for (int y = 0; y < height - 1; y++)
		{
			if (grille[x][y] != 0)
			{
				estimation = my_estimator(grille, x, y, Maxestimation);
				if (estimation > Maxestimation)
					Maxestimation = estimation;
			}
		}
	}
	do_mymove(finalx, finaly);
	return (0);
}

/*
**  ________________
**
**		  IA
**  ________________
*/

void brain_my(int x,int y)
{
	if (isFree(x, y))
		{
			board[x][y] = OWN_STONE;
		}	
	else
		pipeOut("ERROR my move [%d,%d]", x, y);
}

void brain_opponents(int x,int y) 
{
	int tmp = 0;
	if (isFree(x, y))
	{
		board[x][y] = OPP_STONE;
	}
  else
    pipeOut("ERROR opponents's move [%d,%d]", x, y);
}

void brain_block(int x,int y)
{
  if (isFree(x,y))
	board[x][y] = ALIGNED_STONE;
  else
	pipeOut("ERROR winning move [%d,%d]", x, y);
}

void brain_end()
{
}


/*
**  ________________
**
**		 UTILS
**  ________________
*/


/*		 MOVE			*/
void	brain_turn()
{

	nvGrille = new int*[width];

	for (int i = 0; i < width; i++)
	{
		nvGrille[i] = new int[height];
		nvGrille[i] = board[i];
	}
	ia(nvGrille);
	return;
}

/*		CHECK IF A SQUARE IS EMPTY	*/
int		isFree(int x, int y)
{
	return (x >= 0 && y >= 0 && x < width && y < height && board[x][y] == NO_STONE);
}


/*		INITIALIZE THE GAME		*/
void	brain_init()
{
	if (width < 5 || height < 5)
	{
		pipeOut("ERROR size of the board");
		return;
	}
	if (width > MAX_BOARD || height > MAX_BOARD)
	{
		pipeOut("ERROR Maximal board size is %d", MAX_BOARD);
		return;
	}
	seed = start_time;
	pipeOut("OK");
}

/*		UNDO			*/
int		brain_takeback(int x, int y)
{
	if (x >= 0 && y >= 0 && x < width && y < height && board[x][y] != NO_STONE)
	{
		board[x][y] = NO_STONE;
		return (NO_STONE);
	}
	return (OPP_STONE);
}

/*		RESTART GAME	*/
void	brain_restart()
{
	int x, y;
	for (x = 0; x < width; x++)
	{
		for (y = 0; y < height; y++)
		{
			board[x][y] = NO_STONE;
		}
	}
	pipeOut("OK");
}


#ifdef DEBUG_EVAL
#include <windows.h>

void brain_eval(int x, int y)
{
	HDC dc;
	HWND wnd;
	RECT rc;
	char c;
	wnd = GetForegroundWindow();
	dc = GetDC(wnd);
	GetClientRect(wnd, &rc);
	c = (char)(board[x][y] + '0');
	TextOut(dc, rc.right - 15, 3, &c, 1);
	ReleaseDC(wnd, dc);
}

#endif