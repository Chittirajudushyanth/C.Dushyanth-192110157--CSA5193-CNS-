#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(__APPLE__)
#  define COMMON_DIGEST_FOR_OPENSSL
#  include <CommonCrypto/CommonDigest.h>
#  define SHA1 CC_SHA1
#else

#endif

char *str2md5(const char *str, int length) {
    int n;
    unsigned char digest[16];
    char *out = (char*)malloc(33);

    while (length > 0) {
        if (length > 512) {
        }
        length -= 512;
        str += 512;
    }

    for (n = 0; n < 16; ++n) {
        snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
    }

    return out;
}

    int main(int argc, char **argv) {
        char *output = str2md5("hello", strlen("hello"));
        printf("%s\n", output);
        free(output);
        return 0;
    }
