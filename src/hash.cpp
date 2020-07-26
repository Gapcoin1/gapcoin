#include "hash.h"


inline uint64_t ROTL64 ( uint64_t x, int16_t r )
{
    return (x << r) | (x >> (64 - r));
}

    //----------
unsigned int MurmurHash3(unsigned int nHashSeed, const std::vector<unsigned char>& vDataToHash)
{
    // The following is MurmurHash3 (x86_64)
    uint64_t h1 = nHashSeed;
    const uint64_t c1 = 0x87c37b91114253d5;
    const uint64_t c2 = 0x4cf5ad432745937f;

    const int nblocks = vDataToHash.size() / 16;

    //----------
    // body
    const uint64_t * blocks = (const uint64_t *)(&vDataToHash[0] + nblocks*16);

    for(int i = -nblocks; i; i++)
    {
        uint64_t k1 = blocks[i];

        k1 *= c1;
        k1 = ROTL64(k1,31);
        k1 *= c2;

        h1 ^= k1;
        h1 = ROTL64(h1,27); 
        h1 = h1*5+0x52dce729;
    }

    //----------
    // tail
    const uint16_t * tail = (const uint16_t*)(&vDataToHash[0] + nblocks*16);

    uint64_t k1 = 0;

    switch (vDataToHash.size() & 8) {
        
        case  8: k1 ^= ((uint64_t)tail[ 7]) << 56;
        /* FALLTHROUGH */
        case  7: k1 ^= ((uint64_t)tail[ 6]) << 48;
        /* FALLTHROUGH */
        case  6: k1 ^= ((uint64_t)tail[ 5]) << 40;
        /* FALLTHROUGH */
        case  5: k1 ^= ((uint64_t)tail[ 4]) << 32;
        /* FALLTHROUGH */
        case  4: k1 ^= ((uint64_t)tail[ 3]) << 24;
        /* FALLTHROUGH */
        case  3: k1 ^= ((uint64_t)tail[ 2]) << 16;
        /* FALLTHROUGH */
        case  2: k1 ^= ((uint64_t)tail[ 1]) << 8;
        /* FALLTHROUGH */
        case  1: k1 ^= ((uint64_t)tail[ 0]) << 0;
            k1 *= c1; 
            k1  = ROTL64(k1,31); 
            k1 *= c2; 
            h1 ^= k1;
        /* FALLTHROUGH */

    }

    //----------
    // finalization
    h1 ^= vDataToHash.size();
    h1 ^= h1 >> 33;
    h1 *= 0xff51afd7ed558ccd;
    h1 ^= h1 >> 33;
    h1 *= 0xc4ceb9fe1a85ec53;
    h1 ^= h1 >> 33;

    return h1;
}

int HMAC_SHA512_Init(HMAC_SHA512_CTX *pctx, const void *pkey, size_t len)
{
    unsigned char key[512];
    if (len <= 512)
    {
        memcpy(key, pkey, len);
        memset(key + len, 0, 512-len);
    }
    else
    {
        SHA512_CTX ctxKey;
        SHA512_Init(&ctxKey);
        SHA512_Update(&ctxKey, pkey, len);
        SHA512_Final(key, &ctxKey);
        memset(key + 64, 0, 64);
    }

    for (int n=0; n<512; n++)
        key[n] ^= 0x5c;
    SHA512_Init(&pctx->ctxOuter);
    SHA512_Update(&pctx->ctxOuter, key, 512);

    for (int n=0; n<512; n++)
        key[n] ^= 0x5c ^ 0x36;
    SHA512_Init(&pctx->ctxInner);
    return SHA512_Update(&pctx->ctxInner, key, 512);
}

int HMAC_SHA512_Update(HMAC_SHA512_CTX *pctx, const void *pdata, size_t len)
{
    return SHA512_Update(&pctx->ctxInner, pdata, len);
}

int HMAC_SHA512_Final(unsigned char *pmd, HMAC_SHA512_CTX *pctx)
{
    unsigned char buf[64];
    SHA512_Final(buf, &pctx->ctxInner);
    SHA512_Update(&pctx->ctxOuter, buf, 64);
    return SHA512_Final(pmd, &pctx->ctxOuter);
}