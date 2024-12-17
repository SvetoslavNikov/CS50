#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote_is_correct(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote_is_correct(i, j, name))
            {
                printf("Invalid vote.\n");
                j--;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("Winner - %s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote_is_correct(int voter, int rank, string name)
{
    // Submit the vote
    for (int z = 0; z < candidate_count; z++)
    {
        if (strcmp(candidates[z].name, name) == 0)
        {
            preferences[voter][rank] = z;
            printf("Congrats Preference [%d] [%d] Voted for: %s\n", voter, rank, name);
            return true;
        }
    }

    // Return false to repeat vote when the input is incorrect
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    int rank_available;
    for (int i = 0; i < voter_count; i++) // Iterate throughout the array of voters
    {
        rank_available = 1;

        for (int rank = 0; rank < rank_available; rank++) // Iterate throughout the ranks
        {
            for (int z = 0; z < candidate_count; z++) // Iterate throughout the candidates
            {
                if (z == preferences[i][rank] && candidates[z].eliminated)
                {
                    rank_available++;
                    break;
                }
                else if (z == preferences[i][rank])
                {
                    candidates[z].votes++;
                }
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int majority = voter_count / 2 + 1;

    for (int z = 0; z < candidate_count; z++)
    {
        if (candidates[z].votes >= majority)
        {
            printf("The winner is %s\n", candidates[z].name);
            return true;
        }
    }
    printf("There is no winner still\n");
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = candidates[0].votes;
    for (int z = 0; z < candidate_count; z++)
    {
        if (candidates[z].votes < min && !candidates[z].eliminated)
        {
            min = candidates[z].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int z = 0; z < candidate_count; z++)
    {
        if (candidates[z].votes != min && !candidates[z].eliminated)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int z = 0; z < candidate_count; z++)
    {
        if (candidates[z].votes == min) // Corrected comparison
        {
            candidates[z].eliminated = true;
        }
    }
    return;
}
