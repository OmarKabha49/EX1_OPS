#include <stdio.h>
#include "poisson.h"

int main() {

   	 long double lambdas[] = {2.0, 2.0, 2.0, 3.0, 100.0};
   	 int k[] = {1, 10, 2, 3, 3};
   	 int n = 5;

   	 for (int i = 0; i < n; i++) {

       		 long double result = poisson_dist(lambdas[i], k[i]);
       		 printf("P(%d, %Lf) = %.15Lf\n", k[i], lambdas[i], result);
   	 }

    	return 0;
}

