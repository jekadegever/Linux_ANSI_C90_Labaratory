#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

#include "magicSquare.h"

/*method printMagicSquare print the magicSquare numbers in square form
input: void
return: void
*/
void printMagicSquare(void) {/*start of printMagicSquare method*/ 
/*Declarate varibels*/
    int i;
    int j;

    for (i=0; i < SIZE; i++) {/*start of for loop*/
        printf("\n");/*new line*/
        for (j=0; j < SIZE; j++) {/*start of for loop*/
            printf("%-6d",magicSquare[i][j]);/*print the number, if needed fill with space till 6charcters size*/
        }/*end of for loop*/
    }/*end of for loop*/
}/*end of printMagicSquare method*/


/*function isValidInt get pointer to string, and check if this string represent a valin integer number, checking that the number is not biggre or smaller than an integer
@input: pointer to the string
@returns: (int) 1 isValid 0 invalid*/
int isValidInt(const char *str) {
    char *endptr;/*end pointer str*/
    long val;

    errno = 0; /*reset errno*/
    val = strtol(str, &endptr, 10);

    if (*endptr != '\0') {
        return 0; /* not fully numeric */
    }

    if ((errno == ERANGE) || val > INT_MAX || val < INT_MIN) {
        return 0; /* overflow or out of int range, return 0 */
    }

    return 1; /* valid */
}


/*method getMagicSquareNumbers getting the input from user until get EOF, checking the input, if the input contains any non-white character, more or less numbers than required
in the C_Labaratory_ANSI_C90 square - (known by defined SIZE macro), if a non integer number inserted the program will return 0(false) -(bad input), otherwise it will return 1 - (input is ok)
@input: void
@returns: int (1 or 0)
 */

int getMagicSquareNumbers(void){/*start of method getMagicSquareNumbers*/
/*varibles declaration*/
    int c;/*input character*/
    int buff_pointer = 0;/*buff pointer*/
    int counter =0;/*count of inserted numbers*/
    char buff[9999];/*buffer for numbers- because using getchar,buffer is required to be able getting few digit numbers and negative numbers*/
    enum previous_insert {NUM,MINUS,SPACE};/*types of inputs*/
    enum previous_insert previous = SPACE;/* enum varible to hold the previous inserted type*/
    int invalid_char_error=0;/*error flag*/
    int invalid_num_error=0;/*error flag*/

    while ((c = getchar()) != EOF) {/*start of while loop*/

        if ( invalid_char_error || invalid_num_error || counter > SIZE*SIZE) {/*if any error flag appear, stop getting input, wait for EOF*/
            continue;
        }

        if (isdigit(c)) {/*if a digit inserted*/
            buff[buff_pointer++] = c;/*insert to buffer and increment the pointer*/
            buff[buff_pointer] = '\0';/*mark the current end of string*/
            previous = NUM;/*update the the input type*/
        }

        else if (c == '-') {/*if its a minus (for negative numbers)*/
            if (previous != SPACE) {/*check if the minus inserted after white char (for avlid negative numbers, the minus must be inserted after white char*/
                invalid_char_error = 1;/*update the error flag*/
            } else {
                buff[buff_pointer++] = '-';/*insert into buffer and increment the pinter*/
                buff[buff_pointer] = '\0';/*mark the current end of string*/
                previous = MINUS;/*update the input type */
            }
        }

        else if (isspace(c)) {/*if its a white char -> empty the buffer*/

            if (previous == MINUS) {/*if there is only a minus in the buffer, its an invalid input*/
                invalid_char_error = 1;/*update the error flag*/
            }

            else if (previous == NUM) {/*so there is a number in the buffer*/
                if (isValidInt(buff)) {/*check if the inserted number is in INTEGER range*/
                    int num = (int)strtol(buff, NULL, 10);/*convert the string to int*/
                    insertIntoMagicSquare(num);/*if its ok, call method to insert the number into the matrix*/
                    counter++;/*increment the count of numbers*/ 
                } else {/*else, the number is not an integer*/
                    invalid_num_error = 1;/*update the flag*/
                }
            }

            buff_pointer=0;/*reset the pointer*/
            buff[buff_pointer] = '\0';/*mark the string as empty*/
            previous = SPACE;/*update the last input type enum*/
        }

        else {/*if the input is not a digit and not a white char -> invalid input*/
            invalid_char_error =1;/*update the error flag*/
        }

    }/*end of while loop*/


    /*if EOF inserted without white char before, the buffer may not be empty so we must
     *to check and empty the buffer first.
     **/
    if ( buff_pointer > 0 && counter < SIZE*SIZE) {/*check if the buffer is not empty*/
        if (previous == NUM) {/*the buffer full with a number, get the number from it*/
            if (isValidInt(buff)) {/*check if the number in buffer is an integer*/
                int num = (int)strtol(buff, NULL, 10);/*convert the string to number*/
                insertIntoMagicSquare(num);/*insert the number into magicSquare matrix*/
                counter++;/**increment the numbers count*/
            } else {
                invalid_num_error = 1;/*if the number is not an integer, update the error flag*/
            }
        }
        /*if the buffer filled only with '-' this is an invalid input, turn error flag on*/
        else if (previous == MINUS) {
            invalid_char_error = 1;
        }
    }

/*if no errors, return 1*/
    if (!(invalid_char_error) && !(invalid_num_error) && counter == SIZE*SIZE) {/*check if there is error and check if theere is not too much or not enough numbers*/
        return 1;
    }

    else {/*error found, print the found errors*/
        if (invalid_char_error) {
            printf("\nError: invalid character inserted, please insert numbers only (integers)");
        }
        if (invalid_num_error) {
            printf("\nError: number that is not integer inserted, integer number is between %d and %d",INT_MIN,INT_MAX);
        }
        if (counter < SIZE*SIZE) {
            printf("\nError: not enough numbers inserted");
        }
        if (counter > SIZE*SIZE) {
            printf("\nError: too much numbers inserted");
        }
        return 0;/*return 0*/
    }/*end of else*/
}/*end of getMagicSquareNumbers methoda*/



/*method insertMagicSquare insserting an integer to the magicSquare matrix, it will stop inserting when there is not anymore space
@input: Integer (the num to insert into the matrix)
@returns: Void
*/

void insertIntoMagicSquare(int num) {/*start of insertIntoMagicSquare method*/
   /*static varibles to save the value of row/col after calling the method*/
    static int row =0;/*index of row*/
    static int col =0;/*index of column*/

    if ((row < SIZE && col < SIZE)) {/*check if the matrix has an availble space*/

        if (col == SIZE-1 && row < SIZE-1) {/*check if the mat pointer is in the last index in the row*/
            magicSquare[row][col] = num;/*insert the number*/
            row++;/*increment the row index*/
            col = 0;/*reset the column index*/
        }
        else {/*mat pointer is not in the last index on the row*/
            magicSquare[row][col] = num;/*insert the number to matrix*/
            col++;/*increment the column pointer*/
        }
    }
}/*end of insertIntoMagicSquare method*/

