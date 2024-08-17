#include <stdio.h>
#include <cs50.h>

int split_tens_number(long number);

int check_sum(long number, int length);

int get_length(long number);

int main(void)
{
  long card_number = 0;

  do {
    card_number = get_long("Number: ");
  } while (card_number == 0);

  int length = get_length(card_number);
  int two_first_number = split_tens_number(card_number);
  printf("card_number: %d\n", card_number);
  printf("two_first_number: %d\n", two_first_number);
  check_sum(card_number, length);
  return 0;
}

int check_sum(long number, int length){

  int sum = 0;
  int tmp = number;

  for (int i = 0; i < length; i += 2) {
    while (tmp != 0 ) {
      tmp = tmp / 10; 
      //printf("%d -> ", tmp);
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

int split_tens_number(long number){
  int tens = number / 100;
  return tens;
}

