
#define SIZE 3/*the size of the magic square the magic square will be size X size*/

extern int magicSquare[SIZE][SIZE];/*extern matrix declarated in other file*/


/*functions prototypes*/
int getMagicSquareNumbers(void);
void insertIntoMagicSquare(int);
void printMagicSquare(void);
int checkMagicSquareNumbers(void);
int checkRows(int);
int checkColumns(int);
int checkDiagonals(int);


