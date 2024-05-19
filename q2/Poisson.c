#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double poisson_dist(long double lambda, int k) {
    	return (expl(-lambda) * powl(lambda, k)) / tgammal(k + 1);
}


int main(int argc, char *argv[]) {
	 if (argc != 3) {
       		 printf("Error\n");
       		 return 1;
	 }

   	 long double lambda = strtold(argv[1], NULL);
   	 int k = atoi(argv[2]);

   	 long double result = poisson_dist(lambda, k);
   	 printf("P(%d) = %.15Lf\n", k, result);

   	 return 0;
}
