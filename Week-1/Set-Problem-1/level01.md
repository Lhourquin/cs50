# Level 1 explanation of my code 

## Step 1

Code:
```C 
  int blocks = 0;

  do{
    blocks = get_int("Size ?");
  } while( blocks < 1);

  int blocks_to_add = blocks;

```
Explanation:

I initialize `int` variable `blocks` to zero, which will later be used to store the user input. We protect our program from invalid input by using a `do while` loop to ensure the users inputs a number greater than 0. Once the valid input received, we store this value in the variable `blocks`, this variable will be use for the iteration of the first loop. We also create and initialize a new `int` variable `blocks_to_add` to the same value of `blocks` . This variable will be used to be decrease each time a block is added during the program.

## Step 2

Code:
```C 
  for (int i = 0; i < blocks; i++) {
    for (int j = 1; j <= blocks_to_add; j++) {
      if(j != blocks_to_add){
        printf(" ");
      }else{
        int tmp = blocks_to_add - 1;
        while(tmp != blocks){
          printf("#");
          tmp++;
        }
      }
    } 
    printf("\n");
    blocks_to_add--;
  }
  }
```
Explanation:

The first loop with `int i` creates each row and allows the second loop to print characters on that row. We decrease the number of blocks to add with each iteration, and use `printf("\n")` to move to the next line for the next row.
The second loop, using `int j`, prints a blank space or a `#` depending on the conditions. 
The conditions `if(j != nb_of_block)` checks if the loop has not reached the end, and if so, it print blank space. Otherwise, if `j` is equal to the current number of blocks to add, we create a temporary variable `tmp` to store the current value of `blocks_to_add`, and we made a subtraction each time because we started at one, so to add all blocks as waiting we do that, also at the first iteration, if we don't substract them by one, we cannot enter in the loop because it will have the same value. 
