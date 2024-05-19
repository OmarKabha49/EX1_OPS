#include <stdio.h>
#include <stdlib.h>

#define PHONEBOOK "phonebook.txt"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s \"<name>,<phone_number>\"\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(PHONEBOOK, "a");
    if (fp == NULL) {
        perror("Failed to open phonebook");
        return 1;
    }

    // Calculate the length of the input string
    int input_length = 0;
    while (argv[1][input_length] != '\0') {
        input_length++;
    }

    // Write the input to the file character by character
    for (int i = 0; i < input_length; i++) {
        fputc(argv[1][i], fp);
    }

    // Write the newline character
    fputc('\n', fp);

    fclose(fp);

    return 0;
}
