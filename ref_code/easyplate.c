#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void plate_simulation(double tol, int NROWS, int NCOLS) {
	int i, j;
	double dtmax;
	double (*plate_old)[NCOLS] = malloc(sizeof(double[NROWS][NCOLS]));
	double (*plate_new)[NCOLS] = malloc(sizeof(double[NROWS][NCOLS]));
	double temp;
	int source;
	printf("enter the temp: ");
	scanf("%lf", &temp);
	printf("enter the location of the heat source (type 1, 2, 3 or 4 for north, south, east or west, respectively: ");
	scanf("%d", &source);
	if (source == 1 || source == 2) {
		for (j = 0; j<NCOLS;j++) {
			if (source == 1) {
				plate_old[0][j] = plate_new[0][j] = temp;
			}
			else if (source == 2) {
				plate_old[NROWS-1][j] = plate_new[NROWS-1][j] = temp;
			}

		}
	}
	else if (source == 3 || source == 4) {
		for (i = 0; i<NROWS;i++) {
			if (source == 4) {
				plate_old[i][0] = plate_new[i][0] = temp;
			}
			else if (source == 3) {
				plate_old[i][NCOLS-1] = plate_new[i][NCOLS-1] = temp;
			}

		}
	}

do {
	dtmax = 0;
	for(i = 1; i < NROWS-1; i++) {
		for(j = 1; j < NCOLS-1;j++)
		{
			plate_new[i][j] = (plate_old[i-1][j] + plate_old[i][j-1] + plate_old[i+1][j] + plate_old[i][j+1])/4; //physics
			if (fabs(plate_new[i][j] - plate_old[i][j]) > dtmax) {
			dtmax =fabs(plate_new[i][j] - plate_old[i][j]);
			}
		}
	}


	printf("dtmax:%.2f\n",dtmax);
	for(i = 1;i<NROWS-1;i++) {
		for(j=1;j<NCOLS-1;j++) {
			plate_old[i][j] = plate_new[i][j];
		}
	}
	} while(dtmax > tol);
	for(i=0;i<NROWS;i++) {
		for(j=0;j<NCOLS;j++) 
		printf("%5.0f", plate_old[i][j]);
		printf("\n");
		
	}
}

int main() {
	int NROWS, NCOLS;
	int temp;
	double tol;
	printf("please enter values for rows, cols: ");
	scanf("%d %d", &NROWS, &NCOLS);
	printf("enter the tolerance...");
	scanf("%lf", &tol);
	plate_simulation(tol, NROWS, NCOLS);
	

	return 0;
}

/* This is the good stuff ;)
void plate_simulation(double plate_old, double plate_new, int NROWS, int NCOLS, double tol) {
	do {
		double dtmax = 0.0;
		for(int i = 1; i < NROWS-1; i++) {
			for(int j = 1; j < NCOLS-1;j++)
			{
				plate_new[i][j] = (plate_old[i-1][j] + plate_old[i][j-1] + plate_old[i+1][j] + plate_old[i][j+1])/4; //physics
				if (fabs(plate_new[i][j] - plate_old[i][j]) > dtmax) {
				dtmax =fabs(plate_new[i][j] - plate_old[i][j]);
				}
			}
		}
	}while(dtmax > tol);
	return plate_new;
}


double random_plate(int NROWS, int NCOLS) {

	double (*rand_plate)[NCOLS] = malloc(sizeof(double[NROWS][NCOLS]));

	for (int i =0; i<NROWS;i++) {
		for(int j=0; j<NCOLS; j++) {
			random_plate[i][j] = rand();
		}
	}
	return random_plate;
}

void plate_print(double plate_new, double plate_old) {
	printf("dtmax:%.2f\n",dtmax);
	for(i = 1;i<NROWS-1;i++) {
		for(j=1;j<NCOLS-1;j++) {
			plate_old[i][j] = plate_new[i][j];
		}
	}
	} while(dtmax > tol);
	for(i=0;i<NROWS;i++) {
		for(j=0;j<NCOLS;j++) 
		printf("%5.0f", plate_old[i][j]);
		printf("\n");
		
	}
*/
