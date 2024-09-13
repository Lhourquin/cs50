#include <cs50.h>
#include <string.h>
#include <stdio.h>

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
        printf("Ballot number: %d\n", tmp_balot+1);
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
    // TODO
    for (int i = 0; i < candidate_count; i++) {
      if (strcmp(candidates[i], name) == 0) {
        ranks[rank] = i;
        return true;
      }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++) {
        int j = i+1;
        while (j < candidate_count) {
            preferences[ranks[i]][ranks[j]] += 1;
            j++;
        }
    }
    printf("\n");
    
    printf("\n");
    printf("display all content of array");
    printf("\n");
    //see what is on preferences after update
    printf("alice         bob       charlie        david\n");
    for (int i = 0; i < candidate_count; i++) {
      for (int j = 0; j < candidate_count; j++) {
        printf(" %d           ",preferences[i][j]);
      }
      printf("\n");
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0; 
    for (int i = 0; i < candidate_count; i++) {
        int j = candidate_count-1;
        while (j != 0) {

            pair pair;
            if(i != candidate_count-1){
                if(i != j){
                    int oponent_points = 0;
                    int candidate_points = 0;
                    printf("%s vs %s\n",candidates[i], candidates[j]);
                    candidate_points = preferences[i][j];
                    oponent_points = preferences[j][i];
                    if(candidate_points > oponent_points){
                        pair.winner = i;
                        pair.loser = j;
                    }else if (candidate_points < oponent_points) {
                        pair.winner = j;
                        pair.loser = i;
                    }else {
                        break;
                    }
                    bool pair_exist;
                    for (int k = 0; k < MAX * (MAX - 1) / 2; k++) {
                        if (pairs[k].winner == pair.winner && pairs[k].loser == pair.loser) {
                            pair_exist = true;
                        }
                    }
                    if (!pair_exist) {
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
    printf("\n");
    printf("before sort pairs\n");
    for(int i =0; i < pair_count; i++){
        printf("%s win over %s\n",candidates[pairs[i].winner] , candidates[pairs[i].loser] );
        printf("points of winner: %d, points of loser: %d\n",preferences[pairs[i].winner][pairs[i].loser], preferences[pairs[i].loser][pairs[i].winner]);
        printf("strength of victory: %d\n", (preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner]));
        printf("\n");
    }
    for (int i = 0; i< pair_count; i++) {
        //comparer tout les autres au premier????
        int prev_strength_victory = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
        for (int j = i+1; j < pair_count; j++) {
            int current_strength_victory = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            if(current_strength_victory > prev_strength_victory){
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
    printf("\n");
    printf("after sort pairs\n");
    for(int i =0; i < pair_count; i++){
        printf("%s win over %s\n",candidates[pairs[i].winner] , candidates[pairs[i].loser] );
        printf("points of winner: %d, points of loser: %d\n",preferences[pairs[i].winner][pairs[i].loser], preferences[pairs[i].loser][pairs[i].winner]);
        printf("strength of victory: %d\n", (preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner]));
        printf("\n");
    }

    // from the higher to the lower
    //
    printf("alice         bob       charlie        david\n");
    for (int i = 0; i < pair_count; i++) {
        //int j = i;
        //untill we have not cycles, locked
        //the source is the candidates where is not pointed by another
        int target = locked[pairs[i].winner][pairs[i].loser];
        int source = 0;
        for (int j = 1; j < pair_count; j++) {
           //check if the candidate I want locked on they oponent, not have they oponent beat another candidate who beat m current candidate to avoid cycle. 
        }
    }

    for (int i = 0; i < pair_count; i++) {
        int j = i+1;
        //untill we have not cycles, locked
        //the source is the candidates where is not pointed by another
        // locked[pairs[i].winner][pairs[i].loser] = true;
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            printf(" %d           ",locked[i][j]);
        }
        printf("\n");
    }
    return;
}
