# Explanation of my solution

function `bool vote(int rank, string name, int ranks[])`:

```C
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

```

Very simple, just loop to compare the given `strings name` in argument, if is in array `candidates` update the `ranks` array at the given index in argument `rank`, which is the `j` variable on the loop to the order of preference, and I assign the value `i` of the current loop, which is the index position in array candidates, by do this we know who is the candidates.

function `void record_preferences(int ranks[])`:

```C
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++){
      if(i == ranks[0]){
        for (int j = 0; j < candidate_count; j++) {
          if(j != ranks[0]){
            preferences[i][j] += 1;
          }
        }
      }else {
        for (int j = 0; j < candidate_count; j++) {
          if(i == ranks[j] && ranks[j] != ranks[candidate_count-1]){
            preferences[i][ranks[j+1]] += 1;
          }
        }
      }
    }  
    return;
}
```

Update the two dimensional array `preferences[i][j]`, first loop is to enter in a row, if `i` is equal to the preferred candidates, which index is at `ranks[0]`, that means we enter in the row of them to update they score. Then, start a nested loop to through the column and update each of them point against other candidates.

For other candidates, even if they are not the first preferred on the ballot, they can have advatages over the next candidates, so we through the column of them to, and we check if `i` is equal to the value in `ranks[j]` and also if `ranks[j]` is not equal to the last candidates of the ranks, because if is the last, he cannot win against another candidates for this ballot.
