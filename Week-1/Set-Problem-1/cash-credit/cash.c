#include <stdio.h>
#include <cs50.h>

int coin_dispensing(int owed);

int main(void){

  int owed = 0;

  do{
    owed = get_int("Change owed: ");
  }while(owed <= 0);

  int result = coin_dispensing(owed);
  printf("%d\n", result);

  return 0;
}

int coin_dispensing(int owed){

  int tmp = owed;
  int coins = 0;

  int quarters = 25;
  int dimes = 10;
  int nickels = 5;
  int pennies = 1;


  while(tmp != 0){
    if (tmp >= quarters) {
      tmp = tmp - quarters;
      coins++;
    }else if (tmp < quarters){
      if(tmp >= dimes){
        tmp = tmp - dimes;
        coins++;
      }else if (tmp < dimes) {
        if(tmp >= nickels){
          tmp = tmp - nickels;
          coins++;
        }else {
          if(tmp >= pennies){
            tmp = tmp - pennies;
            coins++;
          }
        }
      }
    }
  }

  return coins;
}
