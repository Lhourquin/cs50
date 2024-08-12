#include <stdio.h>
#include <cs50.h>

int main(void){
  int nb_of_block = 0;

  do{
  nb_of_block = get_int("Size ?");
  } while( nb_of_block < 1);

  int tmp = nb_of_block;

  for (int i = 0; i < tmp; i++) {
    for (int j = 0; j < tmp; j++) {
      if(j == (nb_of_block -1)){
        if(tmp == nb_of_block){
          nb_of_block--;
          printf("#");
        }else{
          int new_tmp = nb_of_block;
          do{
            printf("#");
            new_tmp++;
          }while(new_tmp != tmp);
          nb_of_block--;
        }
      }else{
        printf(" ");
      }
    } 
    printf("\n");
  }
  return 0;
}

