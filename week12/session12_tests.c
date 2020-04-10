#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "session12_WarshallsFloyds.h"

//Finds time elapsed from start to end in seconds
double time_elapsed(struct timespec start, struct timespec end);

int **make_matrice(int n);
void print_matrix(int **mat, int n);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);

	int **R = make_matrice(n);
	
	scanf("%d",&n);

	int **D = make_matrice(n);
	
	struct timespec start, end;

	int result;

	// transitive_closure_warshalls() test
	clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
	transitive_closure_warshalls(R, n);
	clock_gettime(CLOCK_REALTIME, &end); //Start timestamp

	print_matrix(R,n);
	
	printf("%lf sec spent on transitive_closure_warshalls()\n", time_elapsed(start, end));

	// all_pairs_shortest_path_distances_floyds() test
	clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
	all_pairs_shortest_path_distances_floyds(D, n);
	clock_gettime(CLOCK_REALTIME, &end); //Start timestamp

	print_matrix(D,n);
	
	printf("%lf sec spent on transitive_closure_warshalls()\n", time_elapsed(start, end));

}

//Time elapsed from 'start' to 'end' in seconds
double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);				  //diff of tv_sec
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
	return t;
}

int **make_matrice(int n){
	int **R;
	int i, j;

	// allocate memory
	R = malloc(n*sizeof(int*));

	for (i=0; i<n; i++){
		R[i] = malloc(n*sizeof(int));
	}

	//get the input
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			scanf("%d", &R[i][j]);
		}
	}

	return R;
}

void print_matrix(int **mat, int n){
	int i,j;
	printf("\n");
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}