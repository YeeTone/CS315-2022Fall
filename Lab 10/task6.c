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

BIGNUM* M = BN_new();
BIGNUM* e = BN_new();
BIGNUM* n = BN_new();
BIGNUM* S = BN_new();

BN_hex2bn(&n, "00a75ac9d50c18210023d5970febaedd5c686b6b8f5060137a81cb97ee8e8a61944b2679f604a72afba4da56bbeea0a4f07b8a7f551f4793610d6e71513a2524082f8ce1f789d692cfafb3a73f30edb5df21aefef54417fdd863d92fd3815a6b5fd347b0acf2ab3b24794f1fc72eeab9153a7c184c69b3b52059095e29c363e62e465baa9490490eb9f0f54aa1092f7c344dd0bc00c506557906cea2d010f14843e8b95ab59555bd31d21b3d86bea1ec0d12db2c9924ad47c26f03e67a70b570cccd272ca58c8ec2183c92c92e736f0610569340aaa3c552fbe5c505d669685c06b9ee5189e18a0e414d9b92900a89e9166befef75be7a46b8e3478a1d1c2ea74f");
BN_hex2bn(&e, "010001");
BN_hex2bn(&S, "03eb45dde8eaf5b18654d3f5709aa85781eb25c005d700ef193a6d866361635eff8129b9a2378fca0c756ac9150c59e87725233d68b15dee0c75b35147e3ecc57d88a7ecff425ee006bcb2ed40243ff5aae7237e959bfe437529fef89a8a409adbf93cfb2a89532af95a66c96919cd937394117bc53fea08a3b6924782b30daa157e6f462a16b3a1731163d1bac1ef8dc67c0d6362fd9341feaba9ffd1dc6495390f53cbef2168f4b4433eb8ae474a029c378f1293fef2e1041e062c15b38f062218aaf4073c252c802ecc6780e81cb0b9196dcdd59b2e7cdd69c3b01f22d96cb720533ea916bec47d6dd13235fb046d1bf84dcf76a7bb8099f85d57abb033a1");


BN_mod_exp(M,S,e,n,ctx);

printBN("3.6 Task 6: Manually Verifying an X.509 Certificate, M --> ", M);

return 0;
}
