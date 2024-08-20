#include <stdio.h>
#include <cs50.h>

long get_two_first_number(long number, int length);

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

long get_two_first_number(long number, int length){//actually, I have the two last number, not the two first. I think I need to make loop.
  long dividor = 1;
  for (int i = 2; i < length; i++) {
    dividor = dividor * 10;
  }
  long two_first_nb = number / dividor; 
  return two_first_nb;
}

