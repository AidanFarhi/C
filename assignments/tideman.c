#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
bool has_cycle(int original, int current);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // First search if name is a valid candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0) // Name matches one of the candidate names.
        {
            // Now update ranks array, i == candidate
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        int c1 = ranks[i];
        for (int j = i + 1; j < candidate_count; j++)
        {
            int c2 = ranks[j];
            preferences[c1][c2]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            int c1_tally = preferences[i][j];
            int c2_tally = preferences[j][i];
            if (c1_tally > c2_tally)
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            if (c1_tally < c2_tally)
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Bubblesort in descending order.
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = i; j < pair_count - 1; j++)
        {
            // Get margin of victory
            int winner1 = pairs[j].winner;
            int loser1 = pairs[j].loser;
            int winner2 = pairs[j + 1].winner;
            int loser2 = pairs[j + 1].loser;
            int strength1 = preferences[winner1][loser1];
            int strength2 = preferences[winner2][loser2];
            if (strength1 < strength2)
            {
                int temp_winner = pairs[j].winner;
                int temp_loser = pairs[j].loser;
                pairs[j].winner = pairs[j + 1].winner;
                pairs[j].loser = pairs[j + 1].loser;
                pairs[j + 1].winner = temp_winner;
                pairs[j + 1].loser = temp_loser;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        locked[winner][loser] = true;
        if (has_cycle(winner, loser))
        {
            locked[winner][loser] = false;
        }
    }
    return;
}

bool has_cycle(int original, int current)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[current][i] == true && i == original)
        {
            return true;
        }
        if (locked[current][i])
        {
            return has_cycle(original, i);
        }
    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    // Create a losers array that keeps track of every candidate that has lost
    int losers[pair_count];
    for (int i = 0; i < pair_count; i++)
    {
        losers[i] = 0; // 0 = no losses, 1 = has a loss
    }

    // Now iterate through locked matrix, recording every loser
    for (int j = 0; j < pair_count; j++)
    {
        for (int k = 0; k < pair_count; k++)
        {
            if (locked[j][k])
            {
                losers[k] = 1;
            }
        }
    }

    for (int n = 0; n < pair_count; n++)
    {
        if (losers[n] == 0)
        {
            printf("%s\n", candidates[n]);
            return;
        }
    }

}