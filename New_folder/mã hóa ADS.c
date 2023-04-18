#include<stdio.h> 
#include <openssl/.h>

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &aes_key, iv, AES_ENCRYPT);
}
int main(){	
unsigned char key[] = "01234567890123456789012345678901";
unsigned char iv[] = "0123456789012345";
unsigned char plaintext[] = "This is a secret message.";

unsigned char ciphertext[128];
encrypt(plaintext, strlen(plaintext), key, iv, ciphertext);
printf("%s",ciphertext);
return 0; 
} 
