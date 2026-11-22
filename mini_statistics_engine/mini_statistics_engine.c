//
// Created by Asus on 22.11.2026.
//

#include <stdio.h>

#include "../own_tools/own_tools.h"

struct ArrAnalysisStruct {
    int sum;
    float avg;
    int min;
    int max;
    int status;
};

int sum(int arr[], int len) {
    int out = 0;
    for (int i=0; i<len; i++) {
        out = out + arr[i];
    }
    return out;
}
float avg(int arr[], int len, int sum) {
    return (float)sum / len;
}
int min(int arr[], int len) {
    int out = arr[0];
    for (int i=1; i<len; i++) {
        if (arr[i] < out) { out = arr[i]; }
    }
    return out;
}
int max(int arr[], int len) {
    int out = arr[0];
    for (int i=1; i<len; i++) {
        if (arr[i] > out) { out = arr[i]; }
    }
    return out;
}

struct ArrAnalysisStruct arr_analysis(int arr[], int len) {
    struct ArrAnalysisStruct result;

    result.sum = sum(arr, len);
    result.avg = avg(arr, len, result.sum);
    result.min = min(arr, len);
    result.max = max(arr, len);
    result.status = 0;

    return result;
}



int get_input() {
    struct InputIntStruct out_input;
    struct ArrAnalysisStruct result;

    out_input = input_int("Введіть довжину списку: ");
    if (out_input.status == 1) {return 1;}
    if (out_input.out <= 0) {
        printf("Довжина списку має бути більшою за 0!\n");
        return 1;
    }
    int len = out_input.out;


    int arr[len];

    for (int i=0; i<len; i++) {
        printf("Введіть %d число списку: ", i + 1);
        arr[i] = input_int(" ").out;
    }

    result = arr_analysis(arr, len);

    printf("sum %d\n", result.sum);
    printf("avg %f\n", result.avg);
    printf("min %d\n", result.min);
    printf("max %d\n", result.max);

    return result.status;
}

int mini_statistics_engine() {
    return get_input();
}
