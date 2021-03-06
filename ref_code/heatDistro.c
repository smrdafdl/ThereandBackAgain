#include <stdio.h>
#include <math.h>
#define NROWS 6
#define NCOLS 8



void heatDistro(double top_t, double bot_t, double right_t, double left_t, double tol) // heat distribution function (fair)
{
double plate2[NROWS][NCOLS] = {{0}}, plate1[NROWS][NCOLS] = {{0}}; // return value
double dtmax =0.0; // return value
int i, j;

	for (j = 0; j<NCOLS;j++) {
		plate1[0][j] = plate2[0][j] = top_t;
		plate1[NROWS-1][j] = plate2[NROWS-1][j] = bot_t;
	}
	for (i =0;i < NROWS-1; i++) {
		plate1[i][0] =plate2[i][0] = left_t;
		plate1[i][NCOLS-1] = plate2[i][NCOLS-1] = right_t;
	}
do 
{
	dtmax = 0.0;
	for(i = 1; i < NROWS-1; i++)
	for(j = 1; j < NCOLS-1;j++)
	{
		plate2[i][j] = (plate1[i-1][j] + plate1[i][j-1] + plate1[i+1][j] + plate1[i][j+1])/4; //physics
		if (fabs(plate2[i][j] - plate1[i][j]) > dtmax)
		dtmax =fabs(plate2[i][j] - plate1[i][j]);
	}
	printf("dtmax:%.2f\n",dtmax);
	for(i = 1;i<NROWS-1;i++)
	for(j=1;j<NCOLS-1;j++)
	plate1[i][j] = plate2[i][j];
	}while(dtmax > tol);
	for(i=0;i<NROWS;i++){
		for(j=0;j<NCOLS;j++)
		printf("%5.0f", plate1[i][j]);
		printf("\n");
	}

	}

	



int main(int argc, char** argv) {
	double top_t, bot_t, right_t, left_t, tol;

	printf("enter the temperatures of the left, right, top and bottom sides of the plate \n");
	scanf("%lf" "%lf" "%lf" "%lf", &left_t, &right_t, &top_t , &bot_t);
	printf("enter tolerance value: ");
	scanf("%lf", &tol);

	heatDistro(top_t, bot_t, right_t, left_t, tol);

	return 0;

}