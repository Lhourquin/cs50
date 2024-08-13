#include <stdio.h>
#include <cs50.h>

int main(void){
  int height = 0;

  do{
    height = get_int("Choose the height of pyramides between 1 and 8: ");
  }while(height < 1 || height > 8);

  int remaining_blocks = height;

  for (int i = 0; i < height; i++) {
    for (int j =1; j <= remaining_blocks; j++) {
      if(j != remaining_blocks){
        printf(" ");
      }else {
        int tmp = remaining_blocks - 1;
        while(tmp != height){
          printf("#");
          tmp++;
        }
        printf("  ");

        tmp = remaining_blocks - 1;

        while(tmp != height){
          printf("#");
          tmp++;
        }
      }
    }
    printf("\n");
    remaining_blocks--;
  }

  return 0;
}
