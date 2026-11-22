//
// Created by Asus on 22.11.2026.
//

#include <stdio.h>

#include "./own_tools.h"


struct NormalizedInputIntStruct input_int(const char *text) {
    struct NormalizedInputIntStruct results;
    int x;

    printf("%s", text);

    if (scanf("%d", &x) != 1) {
        printf("Некоректне введення!\n");

        results.out = 0;
        results.status = 1;
    } else {
        results.out = x;
        results.status = 0;
    }

    return results;
}
