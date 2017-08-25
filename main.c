#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  /* first read number of rows and number of columns */
  int rows, columns;
  scanf("%d %d", &rows, &columns);

  /* then, create a matrix full of zeros */
  int matrix[rows][columns];
  memset(matrix, 0, sizeof(matrix));

  /* next, start reading rows until 0 0 0 found */
  int r_i, c_i, v_i;
  do {
    scanf("%d %d %d", &r_i, &c_i, &v_i);
    if (r_i < 0 || c_i < 0 || v_i < 0 || v_i > 20){
      printf("Invalid Input Data!!\n");
      return 1;
    }

    if (r_i > 0 && c_i > 0 && r_i <= rows && c_i <= columns) {
      matrix[r_i - 1][c_i - 1] = v_i;
    }
  } while (r_i != 0 && c_i != 0 && v_i != 0);

  /* finally, check where are stars and return simplified the map */
  int i, j;
  float e;

  for (i = 0; i < rows; i++){
    for (j = 0; j < columns; j++){
      /* evaluate the stars existance condition */
      e = matrix[i][j];
      
      if (i-1 >= 0) {
        e += matrix[i-1][j];
      }
      if (i+1 < rows) {
        e += matrix[i+1][j];
      }
      if (j-1 >= 0) {
        e += matrix[i][j-1];
      }
      if (j+1 < columns) {
        e += matrix[i][j+1];
      }

      e = e/5.0;

      if (e > 6.0) {
        printf(" * ");
      } else {
        printf("   ");
      }
    }
    printf("\n");
  }

  return 0;
}