#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

string encrypt_plaintext(string plaintext, int key);

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s key\n", argv[0]);
    return 1;
  }else {
    //TODO check for letter in arg with arguments
    int key = atoi(argv[1]);
    if(key <= 0){
      printf("Usage: %s key\n", argv[0]);
      return 1;
    }else {
      printf("key: %d\n", key );
      string plaintext = get_string("plaintext: ");
      string ciphertext = encrypt_plaintext(plaintext, key);
      printf("ciphertext: %s\n", ciphertext);
    }
  } 

  return 0;
}

string encrypt_plaintext(string plaintext, int key){
  int lowercase_alphabet[26] = { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90 };
  int uppercase_alphabet[26] = { 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122 };

  string ciphertext = plaintext;

  int i = 0;
  while (ciphertext[i] != '\0') {
    if(ciphertext[i] >= 65 && ciphertext[i] <= 90){
      for (int j = 0; j < 26;j++) {
        if(ciphertext[i] == lowercase_alphabet[j]){
          int cipher_char_idx = (j + key) % 26;
          ciphertext[i] = lowercase_alphabet[cipher_char_idx];
          break;
        }
      }
    }else if (ciphertext[i] >= 97 && ciphertext[i] <= 122) {
      for (int j = 0; j < 26;j++) {
        if(ciphertext[i] == uppercase_alphabet[j]){
          int cipher_char_idx = (j + key) % 26;
          ciphertext[i] = uppercase_alphabet[cipher_char_idx];
          break;
        }
      }
    }
    i++;
  }
  return ciphertext;
}
