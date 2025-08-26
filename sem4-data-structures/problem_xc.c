#include <stdio.h>

#define HASH_MAX 1001

typedef int (*get_hash_t)(const char *s);

int ncollisions(char **strs, int n, get_hash_t f) {
    int counts[HASH_MAX + 1] = {};

    int collisions = 0;
    for (int i = 0; i < n; i++) {
        int h = f(strs[i]);
        if (counts[h] > 0) {
            collisions++;
        }
        counts[h]++;
    }
    return collisions;
}