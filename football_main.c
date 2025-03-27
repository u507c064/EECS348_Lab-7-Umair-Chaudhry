#include <stdio.h>
#include "football.h"

int main(int argc, char *argv[]) {
    //Integer variable called "score".
    int score;

    //While 1
    while (1) {
        //Display the message "Enter the NFL score (must be 2 or higher): "
        printf("Enter the NFL score (must be 2 or higher): ");
        //Checks to see if the score is valid by checking in the value with scanf.
        //Checks to see if thee value passed in was a valid integer.
        if (scanf("%d", &score) != 1) {
            //If it was not, then display the message "Invalid input, Please enter a valid integer."
            printf("Invalid input. Please enter a valid integer.\n");
            while (getchar() != '\n'); //Clear input buffer, so that it does not override the input.
            //Continue to ask the user for a valid input.
            continue;
        }

        //Another case where the score must be at least 2.
        //Checks to see if the score is less than 2.
        if (score < 2) {
            //If it is, then display the message "Score must be at least 2. Please enter a valid score."
            printf("Score must be at least 2. Please enter a valid score.\n");
            //Continue looping until valid input.
            continue;
        }

        //Integer variable called "total_combinations" set to the function call count_combinations with the score from the user passed in as an argument.
        int total_combinations = count_combinations(score);
        //Displays the message "Total possible combinations: " with the total_combinations.
        printf("Total possible combinations: %d\n", total_combinations);
        //Function call to print_combinations with score passed in as arguments.
        //This is to print each combination.
        print_combinations(score);
    }

    return 0;
}
