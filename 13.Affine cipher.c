#include <stdio.h>

// Function to find the modular multiplicative inverse of 'a' modulo 'm'
int findModInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now; process same as Euclid's algorithm
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to encrypt the plaintext using the affine cipher
void encrypt(char plaintext[], int a, int b) {
    int m = 26;
    int i = 0;
    char encryptedText[100];

    while (plaintext[i]) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            encryptedText[i] = ((a * (plaintext[i] - 'a') + b) % m) + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            encryptedText[i] = ((a * (plaintext[i] - 'A') + b) % m) + 'A';
        } else {
            encryptedText[i] = plaintext[i];
        }
        i++;
    }
    encryptedText[i] = '\0';

    printf("Encrypted Text: %s\n", encryptedText);
}

int main() {
    char plaintext[100];
    int a, b;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key 'a' (must be coprime with 26): ");
    scanf("%d", &a);

    // Check if 'a' is coprime with 26
    if (a % 2 == 0 || a % 13 == 0) {
        printf("Invalid key 'a'. It must be coprime with 26.\n");
        return 1;
    }

    printf("Enter key 'b': ");
    scanf("%d", &b);

    encrypt(plaintext, a, b);

    return 0;
}
