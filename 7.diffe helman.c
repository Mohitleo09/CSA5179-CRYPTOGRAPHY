#include <stdio.h>
#include <math.h>
int mod_exp(int base, int exp, int modulus) {
    int result = 1;
    base = base % modulus;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % modulus;
        }
        exp = exp >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
int main() {
    int prime = 23; 
    int base = 5;   
    int aliceKey = 6; 
    int bobKey = 15;
    int alicePublicKey = mod_exp(base, aliceKey, prime);
    int bobPublicKey = mod_exp(base, bobKey, prime);
    printf("Alice's Public Key: %d\n", alicePublicKey);
    printf("Bob's Public Key: %d\n", bobPublicKey);
    int aliceSharedSecret = mod_exp(bobPublicKey, aliceKey, prime);
    int bobSharedSecret = mod_exp(alicePublicKey, bobKey, prime);
    printf("Alice's Shared Secret: %d\n", aliceSharedSecret);
    printf("Bob's Shared Secret: %d\n", bobSharedSecret);
    return 0;
}
