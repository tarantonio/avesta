

#ifndef ___MD5_H___
#define ___MD5_H___

#include "definitions.h"

/* Typedef a 32 bit type */
#ifndef UINT4
typedef uint32_t UINT4;
#endif

/* Data structure for MD5 (Message Digest) computation */
typedef struct {
	UINT4 i[2];                   /* Number of _bits_ handled mod 2^64 */
	UINT4 buf[4];                                    /* Scratch buffer */
	unsigned char in[64];                              /* Input buffer */
	unsigned char digest[16];     /* Actual digest after MD5Final call */
} MD5_CTX;

void MD5_Transform (UINT4 *buf, UINT4 *in);

void MD5Init(MD5_CTX *mdContext, unsigned long pseudoRandomNumber = 0);
void MD5Update(MD5_CTX *mdContext, const unsigned char *inBuf, unsigned int inLen);
void MD5Final(MD5_CTX *mdContext);

#endif /* ___MD5_H___ included */
