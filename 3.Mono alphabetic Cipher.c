#include <stdio.h>
#include <ctype.h>
char monoalphabeticSubstitution(char ch) {
    char substitutionKey[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    ch = toupper(ch);
    if (ch>='A' && ch <= 'Z') {
        int index = ch - 'A';
        return substitutionKey[index];
    }
    return ch;
}
int main() {
    char plaintext[100]; 
    char ciphertext[100];
    int i = 0;
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    while (plaintext[i] != '\0') 
	{
    ciphertext[i] = monoalphabeticSubstitution(plaintext[i]);
    i++;
    }
    ciphertext[i] = '\0';
    printf("ENCRYPTION: %s", ciphertext);
    printf("\n DECRYPTION: %s",plaintext);
}
