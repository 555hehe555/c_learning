//
// Created by Asus on 24.11.2026.
//

#include "array_modifier.h"

#include <stdio.h>

void print_arr(int *nums, int len) {

    while (len>1) {
        printf("%d, ", *nums);
        nums++;
        len--;
    }

    printf("%d", *nums);

    printf("}\n\n");
}

void multiply_array(int *nums, int len) {
    printf("якщо його помножити на 3\n{");
    while (len>0) {
        *nums = *nums * 3;

        nums++;
        len--;
    }
}

int max_in_array(int *nums, int len) {
    int max = *nums;

    printf("максимальне число в масиві це ");
    while (len>1) {
        nums++;
        if (max < *nums) {
            max = *nums;
        }
        len--;
    }

    return max;
}


int array_modifier_ui() {
    int numbers[] = {4, 8, 15, 16, 23, 42};

    const int len = sizeof(numbers) / sizeof(numbers[0]);

    printf("у нас є масив\n{");
    print_arr(numbers, len);

    multiply_array(numbers, len);
    print_arr(numbers, len);

    const int max = max_in_array(numbers, len);

    printf("%d", max);

    return 0;
}


int array_modifier() {
    return array_modifier_ui();
}
