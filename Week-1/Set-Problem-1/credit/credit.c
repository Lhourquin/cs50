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

   step 1: print one number at each iteration ✅
      make a modulo of number
      divide the number by ten to pop the last number
      check ifthe number is od or not
        if the number is od, make operation
        otherwise, not.

   error 1: make a loop and increment by two is useless. We don't throught the number like an array with index (here, the number don't have index.)

   * */

  long mod = 0;
  long tmp_number = number;
  for (int i = 0; i < length; i++) {
    mod = tmp_number % 10;
    tmp_number = tmp_number / 10;
    if ((i % 2) == 1) {
      printf("%ld -> ", mod);
    } 
  }

  return mod;
}
