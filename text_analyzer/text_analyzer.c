//
// Created by Asus on 23.11.2026.
//

#include "text_analyzer.h"

#include <stdio.h>
#include <stdlib.h>

#include "../own_tools/own_tools.h"


void quit(struct InputStrStruct *text) {
    free(text->out);
    text->out = NULL;
}

int count_chars(const char *text) {
    int cont = 0;

    while (*text != '\0') {
        cont++;
        text++;
    }

    printf("Characters: %d\n", cont);

    return cont;
}

void count_spaces(const char *text) {
    int spaces_cont = 0;

    while (*text != '\0') {
        if (*text == ' ') {
            spaces_cont++;
        }
        text++;
    }

    printf("Spaces: %d\n", spaces_cont);
}

void print_reverse(const char *text, const int len) {
    char out[len+1];

    for (int i=len-1; i>=0; i--) {
        out[len - 1 - i] = text[i];
    }
    out[len] = '\0';

    printf("Reversed: %s\n", out);
}

int text_analyzer_user_interface() {
    struct InputStrStruct input;

    printf("(консоль чомусь не розуміє якщо щось написати українською\nтому пишіть тут тільки англіською)\n");

    input = input_str("Введіть вашу строку: ");
    printf("DEBUG: [%s]\n", input.out);

    if (input.status != 0) {
        printf("Помилка введення!\n");

        quit(&input);
        return 1;
    }

    char *text = input.out;

    printf("\n\n");

    int len = count_chars(text);
    count_spaces(text);
    print_reverse(text, len);

    quit(&input);
    return 0;
}


int text_analyzer() {
    return text_analyzer_user_interface();
}
