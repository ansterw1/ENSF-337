/*
 *  lab2exe_D.c
 *  ENSF 337, lab2 Exercise D
 *
 *  In this program the implementatiom of function pascal_trangle is missing.
 *  Studtent must complete this function.
 */

#include <stdio.h>
#include <stdlib.h>

void pascal_triangle(int n);
/* REQUIRES: n > 0 and n <= 20
 PROMISES: displays a pascal_triangle. the first 5 line of the function's output
 should have the following format:
 row 0:  1
 row 1:  1   1
 row 2:  1   2   1
 row 3:  1   3   3   1
 row 4:  1   4   6   4   1
 */

int main() {
    int nrow;
    // These are ALL of the variables you need!
    printf("Enter the number of rows (Max 20): ");
    scanf("%d", &nrow);
    if(nrow <= 0 || nrow > 20) {
        printf("Error: the maximum number of rows can be 20.\n");
        exit(1);
    }
    
    pascal_triangle(nrow);
    return 0;
}

void pascal_triangle(int n) {
	int previous_row[n+1];
	int current_row[n+1];
	
    for(int i = 0; i <= n; i++){
		printf("row %d:\t", i);
		for(int j = 0; j <= i; j++){
			if((j == 0) || (j == i)){
				printf("1\t");
				current_row[j] = 1;
			}
			else{
				current_row[j] = previous_row[j-1] + previous_row[j];
				printf("%d\t", current_row[j]);
			}
		}
		for(int k = 0; k <= i; k++){
			previous_row[k] = current_row[k];
		}
		printf("\n");
	
	
	}
	
}






