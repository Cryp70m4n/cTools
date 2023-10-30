#include <stdint.h>

// MurmurHash3 constants
#define MURMUR_C1 0xff51afd7ed558ccd
#define MURMUR_C2 0xc4ceb9fe1a85ec53
#define MURMUR_R1 27
#define MURMUR_R2 31
#define MURMUR_R3 33
#define MURMUR_M 5
#define MURMUR_N 0xe6546b64

uint64_t fmix64(uint64_t k) {
    k ^= (k >> 33);
    k *= 0xff51afd7ed558ccd;
    k ^= (k >> 33);
    k *= 0xc4ceb9fe1a85ec53;
    k ^= (k >> 33);
    return k;
}

uint64_t MurmurHash3(const void* key, int len, uint32_t seed) {
    const uint8_t* data = (const uint8_t*)key;
    const int nblocks = len / 8;
    const uint64_t* blocks = (const uint64_t*)(data);
    uint64_t h1 = seed;
    uint64_t h2 = seed;
    
    for (int i = 0; i < nblocks; i++) {
        uint64_t k1 = blocks[i * 2];
        uint64_t k2 = blocks[i * 2 + 1];
        
        k1 *= MURMUR_C1;
        k1 = (k1 << MURMUR_R1) | (k1 >> (64 - MURMUR_R1));
        k1 *= MURMUR_C2;
        h1 ^= k1;
        
        h1 = (h1 << MURMUR_R2) | (h1 >> (64 - MURMUR_R2));
        h1 = h1 + h2;
        h1 = h1 * MURMUR_M + MURMUR_N;
        
        k2 *= MURMUR_C2;
        k2 = (k2 << MURMUR_R3) | (k2 >> (64 - MURMUR_R3));
        k2 *= MURMUR_C1;
        h2 ^= k2;
        
        h2 = (h2 << MURMUR_R2) | (h2 >> (64 - MURMUR_R2));
        h2 = h2 + h1;
        h2 = h2 * MURMUR_M + MURMUR_N;
    }
    
    const uint8_t* tail = (const uint8_t*)(data + nblocks * 16);
    uint64_t k1 = 0;
    uint64_t k2 = 0;
    
    switch (len & 15) {
        case 15:
            k2 ^= ((uint64_t)tail[14]) << 48;
			break;
        case 14:
            k2 ^= ((uint64_t)tail[13]) << 40;
			break;
        case 13:
            k2 ^= ((uint64_t)tail[12]) << 32;
			break;
        case 12:
            k2 ^= ((uint64_t)tail[11]) << 24;
			break;
        case 11:
            k2 ^= ((uint64_t)tail[10]) << 16;
			break;
        case 10:
            k2 ^= ((uint64_t)tail[9]) << 8;
			break;
        case 9:
            k2 ^= ((uint64_t)tail[8]) << 0;
            k2 *= MURMUR_C2;
            k2 = (k2 << MURMUR_R3) | (k2 >> (64 - MURMUR_R3));
            k2 *= MURMUR_C1;
            h2 ^= k2;
			break;
        case 8:
            k1 ^= ((uint64_t)tail[7]) << 56;
			break;
        case 7:
            k1 ^= ((uint64_t)tail[6]) << 48;
			break;
        case 6:
            k1 ^= ((uint64_t)tail[5]) << 40;
			break;
        case 5:
            k1 ^= ((uint64_t)tail[4]) << 32;
			break;
        case 4:
            k1 ^= ((uint64_t)tail[3]) << 24;
			break;
        case 3:
            k1 ^= ((uint64_t)tail[2]) << 16;
			break;
        case 2:
            k1 ^= ((uint64_t)tail[1]) << 8;
			break;
        case 1:
            k1 ^= ((uint64_t)tail[0]) << 0;
            k1 *= MURMUR_C1;
            k1 = (k1 << MURMUR_R1) | (k1 >> (64 - MURMUR_R1));
            k1 *= MURMUR_C2;
            h1 ^= k1;
			break;
    }
    
    h1 ^= len;
    h2 ^= len;
    h1 += h2;
    h2 += h1;
    h1 = fmix64(h1);
    h2 = fmix64(h2);
    h1 += h2;
    h2 += h1;
    return h1;
}
