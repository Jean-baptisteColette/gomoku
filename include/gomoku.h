#ifndef _GOMOKU_H_
#define _GOMOKU_H_

#define MAX_BOARD 100
#define NO_STONE  0
#define OWN_STONE 1
#define OPP_STONE 2
#define ALIGNED_STONE 3
#include <string.h>

const char *infotext = "name=\"Plazza\", author=\"Sophie Darrigol et Jb Colette\", version=\"5.2\", country=\"France\", www=\"http://lorem.gélesum.com\"";

int board[MAX_BOARD][MAX_BOARD];
int isFree(int x, int y);
unsigned seed;
int ia(int **grille);
int	checkForFirst(int **grille);
int my_estimator(int **grille, int x, int y, int Maxestimation);
int func_verti(int **grille, int x, int y);
int func_hori(int **grille, int x, int y);
int func_diago2(int **grille, int x, int y);
int	func_diago1(int **grille, int x, int y);

int **nvGrille;

static int finalx = 0;
static int finaly = 0;

#endif // _GOMOKU_H_
