#include <math.h>

long double poisson_dist(long double lambda, int k) {
   	 return (expl(-lambda) * powl(lambda, k)) / tgammal(k + 1);
}
