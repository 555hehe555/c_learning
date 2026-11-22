//
// Created by Asus on 21.11.2026.
//


#include <stdio.h>
#include <windows.h>

int input_correctness_test(float a, float b, char c) {
    switch (c) {
        case '+': return 0;
        case '-': return 0;
        case '*': return 0;
        case '/':
            if (b != 0) {
                return 0;
            }
            printf("на нуль ділити не можна");
            return 1;

        default:
            printf("ви ввели непонятно що замість знаку");
            return 1;
    }
}

float get_anw(float a, float b, char c) {
    switch (c) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;

        default:
            printf("невідома помилка");
            return 0;
    }
}



int calc(void) {
    float a, b;
    char c;


    printf("\nвведіть перше число: ");
    if (scanf("%f", &a) != 1) {
        printf("Некоректне введення!\n");
        return 1;
    }

    printf("\nвведіть друге число: ");
    if (scanf("%f", &b) != 1) {
        printf("Некоректне введення!\n");
        return 1;
    }

    printf("\nвведіть операцію (+, -, *, /): ");
    if (scanf(" %c", &c) != 1) {
        printf("Помилка введення оператора!\n");
        return 1;
    }

    if (input_correctness_test(a, b, c) == 1) {
        return 1;
    }

    float result = get_anw(a, b, c);
    printf("\nвідповідь: %f", result);

    return 0;
}

int first_calc() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    if (calc() == 0) {
        printf("\n\nвсе добре!");
    } else {
        printf("\n\nне все добре...");
    }

    scanf("нажміть enter щоб вийти");
}
