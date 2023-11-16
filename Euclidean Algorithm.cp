#include <stdio.h>
#include <stdint.h>
uint64_t euclidean_algorithm(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void key_generation(uint64_t *public_key, uint64_t *private_key, uint64_t p, uint64_t q) {
    *public_key = p * q;
    *private_key = euclidean_algorithm(p - 1, q - 1);
}
uint64_t sign(uint64_t message, uint64_t private_key, uint64_t public_key) {
    return message % public_key;
}
int verify(uint64_t message, uint64_t signature, uint64_t public_key) {
    return (message % public_key == signature) ? 1 : 0;
}

int main() {
    uint64_t p = 61;
    uint64_t q = 53;
    uint64_t public_key, private_key;

    key_generation(&public_key, &private_key, p, q);

    uint64_t message = 42;
    uint64_t signature = sign(message, private_key, public_key);

    printf("Message: %lu\n", message);
    printf("Signature: %lu\n", signature);

    int is_valid = verify(message, signature, public_key);
    printf("Verification Result: %s\n", is_valid ? "Valid" : "Invalid");

    return 0;
}

