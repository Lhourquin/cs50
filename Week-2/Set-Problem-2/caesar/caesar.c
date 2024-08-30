#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
  //get argument of the command line to get the key to encrypt
  //check if the user as been enter a key (number back-to-back and no other)
  //if is it good input, ask for the plaintext to encrypt 
  //encrypt the plaintexxt and output the ciphertext

  //check for good argument
  if (argc != 2) {
    printf("Usage: %s key\n", argv[0]);
    return 1;
  }else {
    int key = atoi(argv[1]);
    if(key == 0){
      printf("Usage: %s key\n", argv[0]);
      return 1;
    }else {
      printf("key: %d\n", key );
    }
  } 
  

    
  return 0;
}
