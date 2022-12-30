#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256
void printBN(char *msg, BIGNUM * a)
{
/* Use BN_bn2hex(a) for hex string
* Use BN_bn2dec(a) for decimal string */
char * number_str = BN_bn2hex(a);
printf("%s %s\n", msg, number_str);
OPENSSL_free(number_str);
}
int main ()
{
BN_CTX* ctx = BN_CTX_new();
BIGNUM* p = BN_new();
BIGNUM* p_1 = BN_new();
BIGNUM* q = BN_new();
BIGNUM* q_1 = BN_new();
BIGNUM* e = BN_new();
BIGNUM* n = BN_new();
BIGNUM* phi_n = BN_new();

BIGNUM* d = BN_new();

BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
BN_hex2bn(&p_1, "F7E75FDC469067FFDC4E847C51F452DE");
BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
BN_hex2bn(&q_1, "E85CED54AF57E53E092113E62F436F4E");
BN_hex2bn(&e, "0D88C3");

BN_rand(n, NBITS, 0, 0);
BN_rand(phi_n, NBITS, 0, 0);
BN_mul(phi_n, p_1,q_1,ctx);
BN_mod_inverse(d, e, phi_n, ctx);

printBN("private key: ", d);

return 0;
}
