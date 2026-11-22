//
// Created by Asus on 22.11.2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./own_tools.h"


struct InputStrStruct input_str(const char *text) {
    struct InputStrStruct results;
    char buffer[256];

    printf("%s", text);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Некоректне введення!\n");

        results.out = NULL;
        results.status = 1;
        return results;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    results.out = malloc(strlen(buffer) + 1);

    if (results.out == NULL) {
        results.status = 1;
        return results;
    }

    strcpy(results.out, buffer);
    results.status = 0;

    return results;
}
