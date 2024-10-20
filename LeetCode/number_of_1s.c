#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    uint32_t n = 00000000000000000000000000001011;
    uint32_t powar = 1;
    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n = n / 10;
        powar *= 10;

        printf("%u %u %d\n", n, powar, sum);
    }

    return 0;
}
