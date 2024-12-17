#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    string name;
    int votes;
} candidate;

int main(int argc, string argv[]) {
    // Initialize candidates array
    candidate candidates[argc - 1];
    for(int i = 1; i < argc; i++) {
        candidates[i - 1].name = argv[i];
        candidates[i - 1].votes = 0;
    }

    int voters = get_int("Number of voters:\n");
    string vote;

    // Voting process
    for(int i = 0; i < voters; i++) {
        vote = get_string("Vote:\n");
        bool wrong_name = true;
        for(int j = 0; j < argc - 1; j++) {
            if(strcmp(candidates[j].name, vote) == 0) {
                candidates[j].votes++;
                wrong_name = false;
                break;
            }
        }

        if(wrong_name) {
            printf("Invalid name\n");
            i--; // Allow user to re-enter vote
        }
    }

    // Finding the winner
    int idx_winner = 0;
    int winner_votes = 0;
    for(int i = 0; i < argc - 1; i++) {
        if(candidates[i].votes > winner_votes) {
            winner_votes = candidates[i].votes;
            idx_winner = i;
        }
    }

    printf("winner is %s\n", candidates[idx_winner].name);

    return 0;
}
