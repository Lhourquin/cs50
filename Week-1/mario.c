#include <stdio.h>
#include <cs50.h>
/*

int main(void){
  int nb_of_block = 1;
  for(int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++) {
      printf(" ");
    }
    for (int b = 0; b < nb_of_block; b++) {
      printf("#");
    }
    nb_of_block++;
    printf("#");
    printf("\n");
  }
  return 0;
}
  */
int main(void)
{
  int n;
  do {
    n = get_int("Size: ");
  }while(n < 1);

  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j < n; j++)
      {
          printf("#");
      }
      printf("\n");
  }
}
