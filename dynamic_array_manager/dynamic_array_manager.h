//
// Created by Asus on 28.11.2026.
//

#ifndef C_LEARNING_DYNAMIC_ARRAY_MANAGER_H
#define C_LEARNING_DYNAMIC_ARRAY_MANAGER_H

struct InitStruct {
    struct NumbersStruct *data;
    int status;
};

struct NumbersStruct {
    int *numbers;
    int size;
    int capacity;
};

int dynamic_array_manager();

#endif //C_LEARNING_DYNAMIC_ARRAY_MANAGER_H
