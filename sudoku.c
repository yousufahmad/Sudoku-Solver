#include "sudoku.h"




/*
This MP takes a given soduku board with several filled in cells, and outputs a
complete board that follows all rules. The code uses 5 main functions that we
implemented. One checked rows for a possible value, one checked columns, and one
checked 3x3 squares. Another function checked to see if all those functions were
false meaning the possible value was OK to be placed there. The last function
utilized recursive backtracking to figure out which value should be placed in
a given cell. If the value did not work by rules of Sudoku, it would backtrack
and try another value.

partners: lofendo2, at18
*/

// You are free to declare any private functions if needed.

// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

  assert(i>=0 && i<9);

  // BEG TODO
  for(int c=0;c<9;c++){     //iterates through columns in one row
    if(val == sudoku[i][c])   //check if value already in that row
      return 1;
  }

  return 0;
  // END TODO
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9);/* condition */

  // BEG TODO
  for(int r=0;r<9;r++){       //iterates down rows in one column
    if(val == sudoku[r][j])   //checks if valuue already in column
      return 1;
  }

  return 0;
  // END TODO
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9);

  // BEG TODO
  int north;
  int west;         // the north and west corner of the cell

  north = j - j%3;    //finds the upper bound
  west = i - i%3;     //finds the west bound

  for(int r=west;r<west+3;r++){     //iterates across 3x3 matrices
    for(int c=north;c<north+3;c++){
      if(val == sudoku[r][c])     //if value exists for given cell
      return 1;
    }
  }
  return 0;
  // END TODO
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);

  // BEG TODO
  if((is_val_in_row(val, i, sudoku)==0) && (is_val_in_col(val, j, sudoku)==0) && (is_val_in_3x3_zone(val, i, j, sudoku)==0))
  return 1;   // the above line checks if the three previous functions return 0, meaning the value is valid to place

  return 0;
  // END TODO
}
// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) {
  // BEG TODO
int a, b, i, j;   // control variables
int flag=1;        // flag to help notify that input sudoku board is already full
for(int a=0;a<9 && flag;a++){   //loop through sudoku board
  for(int b=0;b<9 ;b++){
    if(sudoku[a][b]==0 && flag){   //if we find an empty cell
      flag=0;                     // set flag to 0
      i=a;                        // saves the row location of empty cell
      j=b;                        // saves the col location
    if (flag==0)                  // condition for breaking out of column for loop
      break;
      }
    }
  }
  if(flag==1)                      // if we never found an empty cell
      return 1;
            for(int number=1;number<10;number++){     // tries to insert numbers 1 through 9
              if(is_val_valid(number, i, j, sudoku)){   //checks if number is valid to place
                sudoku[i][j] = number;        // if valid then place at current cell
                  if(solve_sudoku(sudoku))      // recursive call
                    return 1;
                  sudoku[i][j] = 0;            // backtracks and replace with 0 if incorrect (not returning 1)
              }
            }
  return 0;
  // END TODO.
}

// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}
