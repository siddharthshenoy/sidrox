#include <stdio.h>
#include <stdlib.h>

void transitive_closure_warshalls(int **g, int n){
	int i,j,k;
	for (k=0;k<n;k++){
		for (i=0;i<n;i++){
			for (j=0;j<n;j++){
				g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
			}
	    }
	}
}

int min(int a, int b){
	if(a<b){
		return a;
	}
	return b;
}

void all_pairs_shortest_path_distances_floyds(int **g, int n){
	int i,j,k;
	for (k=0;k<n;k++){
		for (i=0;i<n;i++){
			for (j=0;j<n;j++){
				g[i][j] = min(g[i][j],(g[i][k] + g[k][j]));
			}
	    }
	}
}