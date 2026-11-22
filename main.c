
//
// Created by Asus on 22.11.2026.
//

#include <stdio.h>
#include <windows.h>

#include "./first_calc/first_calc.h"
#include "./mini_statistics_engine/mini_statistics_engine.h"
#include "./mini_inventory/mini_inventory.h"

void setup_console() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

void wait_for_exit() {
    printf("\nНатисніть Enter, щоб завершити програму...");

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    getchar();
}

int main() {
    setup_console();

    int choice;
    int status = 0;

    printf("=== MY PROGRAMS ===\n");
    printf("1. Калькулятор\n");
    printf("2. Міністатистика\n");
    printf("3. міні інвентар\n");
    printf("Ваш вибір: ");

    if (scanf("%d", &choice) != 1) {
        printf("\nНекоректне введення!\n");
    } else {
        switch (choice) {
            case 1:
                status = first_calc();
                break;

            case 2:
                status = mini_statistics_engine();
                break;

            case 3:
                status = mini_inventory();
                break;

            default:
                printf("Невідомий пункт меню!\n");
        }
    }

    if (status == 0) {
        printf("\n\nВсе добре!");
    } else {
        printf("\n\nНе все добре...");
    }

    wait_for_exit();

    printf("\nПрограму завершено.\n");

    return 0;
}
