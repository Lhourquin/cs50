#include <stdio.h>
#include <cs50.h>

long split_tens_number(long number);

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
  long two_first_number = split_tens_number(card_number);
  printf("two_first_number: %ld\n", two_first_number);
  check_sum(card_number, length);
  return 0;
}

long check_sum(long number, int length){

  long sum = 0;
  long tmp = number;

  for (int i = 0; i < length; i += 2) {
    while (tmp != 0 ) {
      tmp = tmp / 10; 
    } 
    printf("\n");
  }
  return sum;
}

int get_length(long number){

  int length = 0;
  
  while (number != 0 ) {
    number = number / 10; 
    length++;
  } 
  return length;
}

long split_tens_number(long number){
  long tens = number / 100; 
  return tens;
}

