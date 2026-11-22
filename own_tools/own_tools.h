//
// Created by Asus on 22.11.2026.
//

#ifndef C_LEARNING_OWN_TOOLS_H
#define C_LEARNING_OWN_TOOLS_H

struct InputIntStruct {
    int out;
    int status;
};

struct InputIntStruct input_int(const char *text);


struct InputStrStruct {
    char *out;
    int status;
};

struct InputStrStruct input_str(const char *text);

#endif //C_LEARNING_OWN_TOOLS_H
