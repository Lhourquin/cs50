#include <stdio.h>
#include <cs50.h>

int main(void){
  int nb_of_block = 0;

  do{
  nb_of_block = get_int("Size ?");
  } while( nb_of_block < 1);

  int length = nb_of_block;

  for (int i = 0; i < length; i++) {
    for (int j = 1; j <= nb_of_block; j++) {
      if(j == nb_of_block){
        int tmp = nb_of_block;
        while(tmp != length){
          printf("#");
          tmp++;
        }
        nb_of_block--;
      }else{
        printf(" ");
      }
    } 
    printf("#\n");
  }
  return 0;
}

