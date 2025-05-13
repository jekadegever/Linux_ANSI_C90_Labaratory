/*
  author : Ivgeny Tokarzhesky
  semester : 2024a
  course : C labaratory
  maman no : 12
  maman name : "magic square"
*/


#include <stdio.h>
#include "magicSquare.h"
#include <limits.h>

#define NUMBERS_RANGE SIZE*SIZE

int magicSquare[SIZE][SIZE];/*declarate the matrix that will contain the magicSquare*/

int main(void) {/*start of main method*/


    /*arible declaration*/
    int input_result;/*will hold the result of getMagicSquareNumber,1 if input inserted successfully and 0 f not*/
    int magicSum;/*to hold the magic sum(the number that all rows, columns and diagonals will equals to in magicSquare*/


   if(SIZE == 0){
       printf("\nthe size defined in header file \"magicSquare.h\" is 0\nimposible to have a magic square in size 0, please change the size defined inheader file!\nprogram stopped ");/*if the size of square is 0, stop the program, imposible to have magic square in size 0*/
       return 0;
     }


    /*print message to user to insert numbers to check  if those numbers represent a magic square*/
     printf("please insert your magic square numbers !\nMagic square size : %d X %d\nInsert %d numbers between %d to %d\n",SIZE,SIZE,NUMBERS_RANGE,1,NUMBERS_RANGE);
     input_result = getMagicSquareNumbers();/*call function to get the numbers, hold the result in varible, 1 input done successfully, 0 - error in input*/

    if (!input_result) {/*if there is a problem in the input, stop the program, return 0*/

        printf("\nProgram stopped");
        return 0;
    }
    printf("\ninserted numbers (square form) :\n");/*input is ok, print the inserted numbers in square form*/
    printMagicSquare();


    /*calculate the magic sum*/
    magicSum = (SIZE*((SIZE*SIZE)+1))/2;/*calculate the magic sum to check if all rows, columns and diagonals are equals to this sum, that mean its a magic square*/

    if ( checkMagicSquareNumbers() && checkRows(magicSum) && checkColumns(magicSum) && checkDiagonals(magicSum)) {/*if all rows, columns and diagonals equals tomagic sum, its a magic Square !*/
        printf("\n\nThis is a magic square !");
    }
    else {/*its not a magic square, print the reason why the numbers are not a magic square*/
        printf("\n\nThis is not a magic square.\n\n\nReasons :");
        if (!checkMagicSquareNumbers()) {
            printf("\nThe numbers out of range %d to %d or contains duplicates !",1,SIZE*SIZE);
        }
        if (!checkRows(magicSum)) {
            printf("\nThe sum of numbers in each row doesn't equals the magic sum: %d",magicSum);
        }
        if (!checkColumns(magicSum)) {
            printf("\nThe sum of numbers in each column doesn't equals the magic sum: %d",magicSum);
        }
        if (!checkDiagonals(magicSum)) {
            printf("\nThe sum of numbers in the diagonals doesn't equals the magic sum: %d",magicSum);
        }
    }
    return 1;/*program done successfully, return 1*/
    
}
