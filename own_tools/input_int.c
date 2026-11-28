#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

#include "./own_tools.h"


struct InputIntStruct input_int(const char *text) {
    struct InputIntStruct results = {0, 1};
    char buffer[128];

    printf("%s", text);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Некоректне введення!\n");
        return results;
    }

    // Перевіряємо, чи весь рядок помістився в буфер
    size_t len = 0;
    while (buffer[len] != '\0' && buffer[len] != '\n') {
        len++;
    }

    if (buffer[len] != '\n' && !feof(stdin)) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);

        printf("Занадто довге введення!\n");
        return results;
    }

    errno = 0;

    char *end;
    long value = strtol(buffer, &end, 10);

    // Чи було введено число
    if (end == buffer) {
        printf("Некоректне введення!\n");
        return results;
    }

    // Чи не переповнилося число
    if (errno == ERANGE || value < INT_MIN || value > INT_MAX) {
        printf("Число виходить за межі int!\n");
        return results;
    }

    // Дозволяємо пробіли після числа
    while (isspace((unsigned char)*end)) {
        end++;
    }

    // Перевіряємо залишок рядка
    if (*end != '\0') {
        printf("Некоректне введення!\n");
        return results;
    }

    results.out = (int)value;
    results.status = 0;

    return results;
}