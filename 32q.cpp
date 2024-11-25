#include <stdio.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <string.h>
#include <stdlib.h>
void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}
int main() {
    ERR_load_crypto_strings();
    OpenSSL_add_all_algorithms();
    DSA *dsa = DSA_new();
    if (dsa == NULL) handleErrors();
    if (DSA_generate_parameters_ex(dsa, 1024, NULL, 0, NULL, NULL, NULL) != 1) {
        handleErrors();
    }
    if (DSA_generate_key(dsa) != 1) {
        handleErrors();
    }
    printf("DSA key pair generated successfully.\n");
    const char *message = "This is a test message.";
    unsigned char hash[SHA_DIGEST_LENGTH]; 
    unsigned char *signature = NULL;
    unsigned int sig_len;
    if (!EVP_Digest(message, strlen(message), hash, NULL, EVP_sha1(), NULL)) {
        handleErrors();
    }
    signature = OPENSSL_malloc(DSA_size(dsa));
    if (!signature) handleErrors();
    if (DSA_sign(0, hash, SHA_DIGEST_LENGTH, signature, &sig_len, dsa) != 1) {
        handleErrors();
    }
    printf("Message signed successfully.\n");
    int verify = DSA_verify(0, hash, SHA_DIGEST_LENGTH, signature, sig_len, dsa);
    if (verify == 1) {
        printf("Signature verification succeeded.\n");
    } else if (verify == 0) {
        printf("Signature verification failed.\n");
    } else {
        handleErrors();
    }
    OPENSSL_free(signature);
    DSA_free(dsa);
    EVP_cleanup();
    ERR_free_strings();

    return 0;
}
