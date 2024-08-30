#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

string encrypt_plaintext(string plaintext, int key);

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
      //array of ascii decimal value
      //make operation with modulo to get cipher char
      printf("key: %d\n", key );
      string plaintext = get_string("plaintext: ");
      string encrypted_text = encrypt_plaintext(plaintext, key);
      printf("ciphertext: %s\n", encrypted_text);
    }
  } 
  

    
  return 0;
}

string encrypt_plaintext(string plaintext, int key){
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  int length = strlen(alphabet);

  string encrypted_text[length];

  int i = 0;
  while (plaintext[i] != '\0') {
    printf("plaintext[i]: %c\n", plaintext[i]);
    for (int j = 0; j < length;j++) {
      if(toupper(plaintext[i]) == alphabet[j]){
        int cipher_char = (j + key) % 26;
        plaintext[i] = tolower(alphabet[cipher_char]);
        break;
      }
    }
    i++;
  }
  return plaintext;
}
