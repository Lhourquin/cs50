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
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool create_cycle(int source_main, int source);
bool is_pointed(int candidate);

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
    int tmp_balot = 0;
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
        tmp_balot++;
        record_preferences(ranks);
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
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        int j = i + 1;
        while (j < candidate_count)
        {
            preferences[ranks[i]][ranks[j]] += 1;
            j++;
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        int j = candidate_count - 1;
        while (j != 0)
        {

            pair pair;
            if (i != candidate_count - 1)
            {
                if (i != j)
                {
                    int oponent_points = 0;
                    int candidate_points = 0;
                    candidate_points = preferences[i][j];
                    oponent_points = preferences[j][i];
                    if (candidate_points > oponent_points)
                    {
                        pair.winner = i;
                        pair.loser = j;
                    }
                    else if (candidate_points < oponent_points)
                    {
                        pair.winner = j;
                        pair.loser = i;
                    }
                    else
                    {
                        break;
                    }
                    bool pair_exist;
                    for (int k = 0; k < MAX * (MAX - 1) / 2; k++)
                    {
                        if (pairs[k].winner == pair.winner && pairs[k].loser == pair.loser)
                        {
                            pair_exist = true;
                        }
                    }
                    if (!pair_exist)
                    {
                        pairs[pair_count].winner = pair.winner;
                        pairs[pair_count].loser = pair.loser;
                        pair_count++;
                    }
                }
            }
            j--;
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        // comparer tout les autres au premier????
        int prev_strength_victory = preferences[pairs[i].winner][pairs[i].loser] -
                                    preferences[pairs[i].loser][pairs[i].winner];
        for (int j = i + 1; j < pair_count; j++)
        {
            int current_strength_victory = preferences[pairs[j].winner][pairs[j].loser] -
                                           preferences[pairs[j].loser][pairs[j].winner];
            if (current_strength_victory > prev_strength_victory)
            {
                pair tmp_pairs;
                tmp_pairs.winner = pairs[j].winner;
                tmp_pairs.loser = pairs[j].loser;
                pairs[j].winner = pairs[i].winner;
                pairs[j].loser = pairs[i].loser;
                pairs[i].winner = tmp_pairs.winner;
                pairs[i].loser = tmp_pairs.loser;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int origin = pairs[i].winner;
        if (!create_cycle(origin, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (!is_pointed(i))
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }

    return;
}

bool create_cycle(int origin, int source)
{
    // source is the winner, we want to jnow if from target we can return to the winner in another
    // pairs
    if (source == origin)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[source][i])
        {
            if (create_cycle(origin, i))
            {
                return true;
            }
        }
    }
    return false;
}

bool is_pointed(int candidate)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (i != candidate)
        {
            if (locked[i][candidate])
            {
                return true;
            }
        }
    }
    return false;
}
