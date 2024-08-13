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
  return 0;
}
