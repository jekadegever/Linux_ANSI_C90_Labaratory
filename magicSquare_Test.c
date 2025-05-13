
#include "magicSquare.h"


/*method checkMagicSquareNumbers checks the numbers in the magicSquare matrix
it check if the matrix contains number duplicates or if its missing number that must to be in the magicSquare (from 1 to n^2)
if there is missing numbers or duplicates or numbers out of range, it will return 0, otherwise the numbers are ok and it will return 1

@input: void
@return: (int) 1 or 0*/

int checkMagicSquareNumbers(void) {/*start of checkMagicSquareNumbers method*/
    int arr[SIZE*SIZE];/*arr to hold all magicSquare numbers*/
    int i=0;/*for loop index*/
    int j=0;/*for loop index*/
    /*convert the matrix into a flat array and insert any number in the index of the number value*/
    for (i=0; i < SIZE; i++) {/*start of for loop 1*/
        for (j=0; j < SIZE; j++) {/*start of for loop 2*/
            if (magicSquare[i][j] > SIZE*SIZE || magicSquare[i][j] < 1) {/*if there is a number out of 1 to SIZE^2 range, return 0*/
                return 0;
            }/*end of if*/
            arr[magicSquare[i][j]-1] = magicSquare[i][j];/*insert the number from the matrix into the flat arr in index of the num value*/

        }/*end of for loop 2*/
    }/*end of for loop 1*/

   /*if there is not missing numbers in the matrix, 0 shouldn't be found
     search for zero in the array that contains all matrix numbers*/
    for (i=0; i < SIZE*SIZE; i++) {
        if (arr[i] == 0) {/*if zero found, a number is missing or duplicatted*/
            return 0;/*return 0*/
        }
    }

    return 1;/*return 1, numbers are ok*/
}/* end of checkMagicSquareNumbers method*/





/*method checkRows check if the sum of numbers in each row equals the input magicSum
if it equals, return 1, otherwise, return 0
input: (int) magicSum
returns: (int) 1 or 0*/
int checkRows(int magicSum) {/*start of checkRows method*/
    /*declaration of varibles*/
    int i;/*for for loop index*/
    int j;/*for for loop index*/
    int temp;/*will contain the sum of numbers in each row*/


    /*run through the rows*/
    for (i=0; i < SIZE; i++) {/*start of for loop 1*/
        temp = 0;/*reset the sum count*/
        /*runs on the numbers insidee each row*/     
        for (j=0; j < SIZE; j++) {/*start of for loop 2*/
            temp+= magicSquare[i][j];/*add to the sum*/
        }/*end of for loop 2*/
        if (temp != magicSum) {/*if the sum of numbers in one of the rows doesnt equals the magicSum, stop and return 0*/
            return 0;
        }
    }/*end of for loop 1*/
    return 1;/*if the program acheived here, all rows are equals to the input number, return 1*/
}/*end of checkRows method*/




/*method checkColumns check if the sum of numbers in each column equals the magicSum
if it equals, return 1, otherwise, return 0
@input: (int) magicSum
@returns: (int) 1 or 0*/
int checkColumns(int magicSum) {/*start of checkColumns method*/
    int i;/*for for loop index*/
    int j;/*for for loop index*/
    int temp;/*to hold the temp sum of numbers in each column*/

  /*run through the columns*/
  for (j=0; j < SIZE; j++) {/*start of for loop 1*/
        temp = 0;/*reset the temp*/
        /*runs on numbers in the column*/
        for (i=0; i < SIZE; i++) {/*start of for loop 2*/
            temp+= magicSquare[i][j];/*add to temp sum*/
        }/*end of for loop 2*/
        if (temp != magicSum) {/*if the sum of numbers in one of the columns doesnt equals the magicSum, stop and return 0*/
            return 0;
        }
    }/*end of for loop 1*/
    return 1;/*if the program acheived here, all rows are equals to the input number, return 1*/
}/*end of checkColumns method*/



/*method checkDiagonals check if the sum of numbers in each diagonal equals the magicSum
if it equals, return 1, otherwise, return 0
@input: (int) magicSum
@returns: (int) 1 or 0*/
int checkDiagonals(int magicSum) {/*start of method checkDiagonals*/
    int i;/*for for loop index*/
    int j;/*for for loop index*/
    int temp=0;/*to hold the sum in each diagonal*/

    /*check main diagonal*/
    for (i=0; i < SIZE; i++) {/*start of for loop*/
        temp+= magicSquare[i][i];
    }/*end of for loop*/
    if (temp != magicSum) {/*if the sum of numbers in the diagonal doesnt equals the magicSum, return 0*/
        return 0;
    }
    temp=0;

    /*check second diagonal*/
    for (i=0,j=SIZE-1; (i < SIZE && j>-1); i++, j--) {/*start of for loop*/
        temp+= magicSquare[i][j];
    }/*end of for loop*/
    if (temp != magicSum) {/*if the sum of numbers in the diagonal doesnt equals the magicSum, return 0*/
        return 0;
    }

    return 1;/*if the program acheived here, all rows are equals to the input number, return 1*/

}/* end of method checkDiagonals*/
