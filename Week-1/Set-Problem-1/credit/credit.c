#include <stdio.h>
#include <cs50.h>

long get_two_first_number(long number, int length);

long check_sum(long number, int length);

int get_length(long number);

int main(void)
{
  long card_number = 0;

  do {
    card_number = get_long("Number: ");
  } while (card_number == 0);

  int length = get_length(card_number);
  printf("card_number: %ld\n", card_number);
  long two_first_number = get_two_first_number(card_number, length);
  printf("two_first_number: %ld\n", two_first_number);
  check_sum(card_number, length);
  return 0;
}


int get_length(long number){

  int length = 0;
  
  while (number != 0 ) {
    number = number / 10; 
    length++;
  } 
  return length;
}

long get_two_first_number(long number, int length){
  long dividor = 1;
  for (int i = 2; i < length; i++) {
    dividor = dividor * 10;
  }
  long two_first_nb = number / dividor; 
  return two_first_nb;
}

long check_sum(long number, int length){
  /*
   get only one number at each time  
   maybe I need to recalculate the actual length of the number to have the only one 
   and make operation of multpilcation with it.
   
   step 1: make a do while loop to decrease each time the length
   step 2: store temporary the number popped to multpliate it by 2
   step 3: store the result of multiplication to make addition later
   * */
  long dividor = 1;
  long number_splitted = 0;
  for (int i = 0; i < length; i++) {
    dividor = dividor * 10;
    number_splitted = number / dividor; 
    printf("%ld -> ", number_splitted);
  }
  return number_splitted;
}
