#include <stdio.h>
#include <cs50.h>

int main(void){

  int blocks = 0;
  // ask for the number of block user want
  do{
    blocks = get_int("Size ?");
  } while( blocks< 1);

  //variable to get the lenght of block using in first loop iteration
  int blocks_to_add = blocks;

  //first loop to create the column
  for (int i = 0; i < blocks; i++) {
    //second loop to create the row with space and # symbols
    for (int j = 1; j <= blocks_to_add; j++) {//second loop with nb_of_block because we decrease the number at each iteration
      if(j != blocks_to_add){
        printf(" ");
      }else{
        int tmp = blocks_to_add - 1;// tempory variable to store the actual number of block
        while(tmp != blocks){//length doesn't change, it is always at the same length until the end.
          printf("#");
          tmp++;
        }
      }
    } 
    printf("\n");
    blocks_to_add--;
  }
  return 0;
}
