#include <stdio.h>
#include "football.h"

//Function called "count_combinations" with points as the parameter passed in.
//Takes in the number of points and counts all the possible point combinations possible.
//This ranges from TD + 2pt conversion, TD + FG, TD, Field Goal, and Safety.
int count_combinations(int points) {
    //Variable called "count" is set to 0.
    int count = 0;

    //Iterate over possible counts for each scoring type.
    for (int td2 = 0; td2 * 8 <= points; td2++) {         // TD + 2pt conversion (8 pts)
        for (int td1 = 0; td1 * 7 <= points; td1++) {     // TD + FG (7 pts)
            for (int td = 0; td * 6 <= points; td++) {    // TD (6 pts)
                for (int fg = 0; fg * 3 <= points; fg++) { // Field Goal (3 pts)
                    for (int safety = 0; safety * 2 <= points; safety++) { // Safety (2 pts)
                        //Makes a comparison between each point value and matches it with the points passed in.
                        if ((td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2) == points) {
                            //If the comparison matches, update the count.
                            count++; //updates the count.
                        }
                    }
                }
            }
        }
    }

    //Returns the counted combinationes after the nested for loop completes.
    return count;
}

void print_combinations(int points) {
    //Displays the message "Possible combinations of scoring plays if a team's score is: " with points passed in.
    printf("Possible combinations of scoring plays if a team’s score is %d:\n", points);

    //Iterate over possible counts for each scoring type.
    for (int td2 = 0; td2 * 8 <= points; td2++) {        // TD + 2pt conversion (8 pts)  
        for (int td1 = 0; td1 * 7 <= points; td1++) {    // TD + FG (7 pts)
            for (int td = 0; td * 6 <= points; td++) {   // TD (6 pts)
                for (int fg = 0; fg * 3 <= points; fg++) { // Field Goal (3 pts)
                    for (int safety = 0; safety * 2 <= points; safety++) {  // Safety (2 pts)
                        //Makes a comparison between each point value and matches it with the points passed in.
                        if ((td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2) == points) {
                            //If the comparison matches, display the message td2, "TD + 2pt, " td1 "TD + FG, " td "TD, " fg " 3pt FG, " safety "Safety"
                            //The variables are the possible conversions in their respective order. 
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td2, td1, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}
