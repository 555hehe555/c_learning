//
// Created by Asus on 22.11.2026.
//

#include <stdio.h>

#include "mini_inventory.h"
#include <bemapiset.h>

#include "../own_tools/own_tools.h"


struct ItemStruct {
    int id;
    int rating;
    char *name;
};

struct InventoryStruct {
    struct ItemStruct *items;
    int size;
    int capacity;
};


void inventory_destroy(struct InventoryStruct *inventory) {
    for (int i = 0; i < inventory->size; i++) {
        free(inventory->items[i].name);
    }

    free(inventory->items);

    inventory->items = NULL;
    inventory->size = 0;
    inventory->capacity = 0;
}


int inventory_add(struct InventoryStruct *inventory) {
    struct ItemStruct temp_item;

    struct InputStrStruct item_name = input_str("введіть назву предмета: \n");
    struct InputIntStruct item_rate =  input_int("введіть рідкість предмету: \n");

    if (item_name.status == 0 && item_rate.status == 0) {
        temp_item.id = inventory->size + 1;
        temp_item.name = item_name.out;
        temp_item.rating = item_rate.out;
    } else {
        free(item_name.out);
        return 1;
    }

    if (inventory->size == inventory->capacity) {
        int new_capacity = inventory->capacity * 2;

        struct ItemStruct *temp = realloc(
            inventory->items,
            new_capacity * sizeof(struct ItemStruct)
        );

        if (temp == NULL) {
            free(item_name.out);
            return 1;
        } else {
            inventory->items = temp;
            inventory->capacity = new_capacity;
        }
    }

    inventory->items[inventory->size] = temp_item;
    inventory->size++;

    return 0;
}

int inventory_show(struct  InventoryStruct *inventory) {
    for (int i=0; i<inventory->size; i++) {
        printf("id предмета: %d\n", inventory->items[i].id);
        printf("імя предмета: %s\n", inventory->items[i].name);
        printf("рейтинг предмета: %d\n\n", inventory->items[i].rating);
    }

    return 0;
}

int inventory_search(struct  InventoryStruct *inventory) {
    struct InputIntStruct item_id =  input_int("введіть id предмета для пошуку: ");
    if (item_id.status == 0) {
        if (1 <= item_id.out && inventory->size >= item_id.out) {
            if (inventory->items[item_id.out-1].name != NULL) {
                printf("id предмета: %d\n", inventory->items[item_id.out-1].id);
                printf("імя предмета: %s\n", inventory->items[item_id.out-1].name);
                printf("рейтинг предмета: %d\n\n", inventory->items[item_id.out-1].rating);
            } else {
                printf("щось пішло не так %d нема в памяті\n", item_id.out);
                return 1;
            }
        } else {
            printf("може бути тільки від 1 до %d\n", inventory->size);
        }
    } else {
        return 1;
    }
    return 0;
}


int inventory_delete(struct  InventoryStruct *inventory) {
    struct InputIntStruct item_id =  input_int("введіть id предмета для видалення: ");
    if (item_id.status == 0) {
        if (1 <= item_id.out && inventory->size >= item_id.out) {
            if (inventory->items[item_id.out-1].name != NULL) {
                free(inventory->items[item_id.out-1].name);

                for (int i=item_id.out; i<inventory->size-1; i++) {
                    inventory->items[i] = inventory->items[i + 1];
                }

                for (int i=item_id.out; i<inventory->size-1; i++) {
                    inventory->items[i].id = inventory->items[i].id - 1;
                }

                inventory->size--;

                printf("предмет успішно видалено");
            } else {
                printf("щось пішло не так %d нема в памяті\n", item_id.out);
                return 1;
            }
        } else {
            printf("може бути тільки від 1 до %d\n", inventory->size);
        }
    } else {
        return 1;
    }
    return 0;
}


int user_interface() {
    struct InventoryStruct inventory;

    inventory.items = malloc(3 * sizeof(struct ItemStruct));
    inventory.size = 0;
    inventory.capacity = 3;

    if (inventory.items == NULL) { return 1; }

    int choose;

    while (1) {
        printf("=== MINI INVENTORY ===\n\n");
        printf("1. Add item\n");
        printf("2. Show all items\n");
        printf("3. Search item\n");
        printf("4. Delete item\n");
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
            return 1;
        }

        switch (choose) {
            case 1:
                inventory_add(&inventory);
                break;
            case 2:
                inventory_show(&inventory);
                break;
            case 3:
                inventory_search(&inventory);
                break;
            case 4:
                inventory_delete(&inventory);
                break;
            case 0:
                inventory_destroy(&inventory);
                return 0;

            default:
                printf("щось не так, спробуйте \n");
        }
    }
}


int mini_inventory() {
    return user_interface();
}

// це ПІЗДЄЦ, я 2.5 години пробую розібратись з цім піздєцом, я блять ніхуя не знаю, я тільки блять зробив 2 проєкт з трошки списами, та зразу нахуй пішов робити цю всю хуйню
// сука, мені вже гпт під кінець казав що поміняти, но всеодно в мене від цього коду зараз тільки смак гамна без палок, може це ефект пацебо но блять, йобані 2.5 години
// на минулі я потратив годину і півтори відповідно, но блять подумав полісти сюди, впоприти те що мнимий здравий смисл казав мені зупинитись
// АААААААААААААААААААА БЛЯТЬ, Я З ГЛУЗДУ СУКА СХОДЖУ