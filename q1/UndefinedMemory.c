#include <stdio.h>

int main(){
	int *p = (int *)0xdeadbeef;
	*p = 43;
	printf("%d\n", *p);
	return 0;

}
