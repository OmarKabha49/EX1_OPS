#include <stdio.h>

void rec_func() {
	rec_func();
}

int main() {
    rec_func();
    return 0;
}
