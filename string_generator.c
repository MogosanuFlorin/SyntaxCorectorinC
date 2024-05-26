#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string_generator.h"

void generate_random_string(char *str, int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < length; i++) {
        int key = rand() % (sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[length] = '\0';
}

// Function to generate two random strings with lengths between 2 and 30
void generate_random_strings(char *str1, char *str2) {
    int length1 = 2 + rand() % 29; // Length between 2 and 30
    int length2 = 2 + rand() % 29; // Length between 2 and 30

    generate_random_string(str1, length1);
    generate_random_string(str2, length2);
}