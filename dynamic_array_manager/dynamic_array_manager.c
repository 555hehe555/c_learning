//
// Created by Asus on 28.11.2026.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array_manager.h"
#include "../own_tools/own_tools.h"


struct InitStruct init_data() {
    struct InitStruct init;

    init.data = malloc(sizeof(struct NumbersStruct));

    if (init.data == NULL) {
        init.status = 1;
        return init;
    }

    init.data->numbers = malloc(3 * sizeof(int));

    if (init.data->numbers == NULL) {
        free(init.data);
        init.data = NULL;
        init.status = 1;
        return init;
    }

    init.data->size = 0;
    init.data->capacity = 3;
    init.status = 0;

    return init;
}


void print_numbers(const int *numbers, int size) {
    printf("{");
    for (int i=0; i<size--; i++) {
        printf("%d, ", *numbers);
        numbers++;
    }
    printf("}\n");
}

int calculate_sum(const int *numbers, int size) {
    if (size==0) {return 0;}

    int sum = *numbers;

    for (int i=1; i<size; i++) {
        numbers++;
        sum = sum + *numbers;
    }

    return sum;
}

int find_max(const int *numbers, int size) {
    if (size==0) {return 0;}
    int max = *numbers;

    for (int i=1; i<size; i++) {
        numbers++;
        if (max < *numbers) { max = *numbers; }
    }

    return max;
}

int append_number(struct NumbersStruct *data) {
    struct InputIntStruct new_num = input_int("введіть число яке хочете додати: \n");

    if (new_num.status != 0) {
        return 1;
    }

    if (data->size == data->capacity) {
        int new_capacity = data->capacity + 2;

        int *temp = realloc(
            data->numbers,
            new_capacity * sizeof(int)
        );

        if (temp == NULL) {
            return 1;
        } else {
            data->numbers = temp;
            data->capacity = new_capacity;
        }
    }

    data->numbers[data->size] = new_num.out;
    data->size++;

    return 0;
}

void out_program(struct InitStruct init) {
    free(init.data->numbers);
    free(init.data);
}




int dynamic_array_manager_ui() {
    struct InitStruct init = init_data();
    int choose;

    if (init.status == 1) {
        free(init.data);
        return 1;
    }

    struct NumbersStruct *data = init.data;

    while (1) {
        printf("\n\n=== Dynamic Array Manager ===\n");
        printf("1. print_numbers\n");
        printf("2. calculate_sum\n");
        printf("3. find_max\n");
        printf("4. append_number\n");
        printf("0. Exit\n\n");
        printf("Choose:");

        struct InputIntStruct answer = input_int(" ");
        if (answer.status == 0) {
            if (answer.out >= 0 && answer.out <= 4) {
                choose = answer.out;
            } else {
                printf("неправильний ввід\n");
                continue;
            }
        } else {
            out_program(init);
            return 1;
        }

        switch (choose) {
            case 1:
                print_numbers(data->numbers, data->size);
                break;
            case 2:
                printf("сума чисел: %d", calculate_sum(data->numbers, data->size));
                break;
            case 3:
                printf("максимальне число: %d", find_max(data->numbers, data->size));
                break;
            case 4:
                append_number(data);
                break;
            case 0:
                out_program(init);
                return 0;

            default:
                printf("щось не так, спробуйте \n");
        }
    }
}

int dynamic_array_manager() {
    return dynamic_array_manager_ui();
}
