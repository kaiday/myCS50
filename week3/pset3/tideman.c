#include <cs50.h>
#include <stdio.h>
#include <strings.h>
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
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool cyclic(int start_vertex, int end_vertex);
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
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcasecmp(name,candidates[i]) == 0)
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
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = i+1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
            // To see who is preferrd over who, access the rank
            // person in rank 0 is preferred over rank 1, rank 2, .. -> add to preferences table
            // the same is true for rank 1 over rank 2, rank 3 ...
            //, so on and so on
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = i+1; j < candidate_count; j++)
        {
            if(preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count+=1;
            }

            else if(preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count+=1;
            }

        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    pair tmp;
    for(int i = 0; i < pair_count; i++)
    {
        for(int j = i+1; j < pair_count; j++)
        {
            if(preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[j].winner][pairs[j].loser])
            {
                tmp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = tmp;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for(int i = 0; i < pair_count; i++)
    {
        if(!cyclic(pairs[i].winner,pairs[i].loser)) // there is no cycle when adding two edges
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

//Check if it is a cycle
bool cyclic(int start_vertex, int end_vertex)
{
    bool edge_found;

    // if there an edge from start_vertex to any available vertex,
    // go to that vertex, trace back, and do it until there is no vertex left
    // if end_vertex can be reach from start_vertex in existed graph
    // then, adding an edge from start_vertex to end_vertex would result in a loop

    do
    {
        edge_found = false;

        for(int i = 0; i < candidate_count; i++)
        {
            if(locked[i][start_vertex])
            {
                edge_found = true; // if there is an edge
                start_vertex = i; // go to that vertex
            }
        }
    }
    while(edge_found && start_vertex != end_vertex);

    return edge_found;

}
// Print the winner of the election
void print_winner(void)
{
    // TODO
    int counter;

    for(int i = 0; i < candidate_count; i++)
    {
        counter = 0;

        for(int j = 0; j < candidate_count; j++)
        {
            if(locked[j][i] == false) counter++;
        }

        if(counter == candidate_count)
        {
            printf("%s\n",candidates[i]);
        }
    }
    return;
}