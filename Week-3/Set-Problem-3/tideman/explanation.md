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

Very siple, just loop to compare the given `strings name` in argument, if is in array `candidates` update the `ranks` array at the given index in argument `rank`, which is the `j` variable on the loop to the order of preference, and I assign the value `i` of the current loop, which is the index position in array candidates, by do this we know who is the candidates.
