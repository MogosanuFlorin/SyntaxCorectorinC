#include <stdio.h>
#include <string.h>
#include "levenshtein_alg.h"
#include "string_generator.h"

int main() {
    char source_string[256];
    char target_string[256];
    int choice;
    FILE *file;
    file = fopen("../input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Enter 1 run the program with 10 pregenerated tests\nEnter 2 to run the program 5 times with 2 random generated strings.\nInput: ");
    scanf("%d", &choice);
    getchar();
    if(choice == 1){

        char buffer[256];
        int line_count = 0;

        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            // Remove newline character
            buffer[strcspn(buffer, "\n")] = '\0';

            // Alternate between source_string and target_string
            if (line_count % 2 == 0) {
                strncpy(source_string, buffer, sizeof(source_string) - 1);
                source_string[sizeof(source_string) - 1] = '\0'; // Ensure null-termination
            } else {
                strncpy(target_string, buffer, sizeof(target_string) - 1);
                target_string[sizeof(target_string) - 1] = '\0'; // Ensure null-termination
                // Calculate the Levenshtein distance
                int distance = calculate_levenshtein_distance(source_string, target_string);
                // Output the result
                printf("The minimum number of operations to transform '%s' into '%s' is %d\n", source_string, target_string, distance);
            }

            line_count++;
        }


    }
    else if(choice==2){
        for(int i=0; i<=5; i++){
            // Generate 2 random strings
            generate_random_strings(source_string, target_string);
            // Calculate the Levenshtein distance
            int distance = calculate_levenshtein_distance(source_string, target_string);
            // Output the result
            printf("The minimum number of operations to transform '%s' into '%s' is %d\n", source_string, target_string, distance);
        }
    }
    return 0;
}
