#include <stdio.h>

// Function to find and print all combinations of scoring plays that sum to the given score
void findCombinations(int score) {
    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

    // Loop through all possible counts of each scoring type
    // TD + 2pt conversion = 8 points
    for (int td2 = 0; td2 * 8 <= score; td2++) {
        // TD + 1pt field goal = 7 points
        for (int td1 = 0; td1 * 7 + td2 * 8 <= score; td1++) {
            // Regular TD = 6 points
            for (int td = 0; td * 6 + td1 * 7 + td2 * 8 <= score; td++) {
                // Field goal = 3 points
                for (int fg = 0; fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; fg++) {
                    // Safety = 2 points
                    for (int safety = 0; safety * 2 + fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; safety++) {
                        // Calculate total score from current combination
                        int total = td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2;

                        // If total matches the target score, print the combination
                        if (total == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td2, td1, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    // Loop to repeatedly prompt user for score input
    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);

        // Exit condition: score of 1 ends the program
        if (score <= 1) break;

        // Call function to find combinations for the given score
        findCombinations(score);
    }

    return 0;
}

