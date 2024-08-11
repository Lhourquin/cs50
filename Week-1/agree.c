
#include <stdio.h>
#include <cs50.h>

int main(void){
  //Prompt user to agree
  char c = get_char("Dou you agree ?");

  //Check wether agreed
  if(c == 'Y' || c == 'y'){
    printf("You agreed\n");
  }else if (c == 'N' || c == 'n') {
    printf("You not agreed\n");
  }
  return 0;
}
