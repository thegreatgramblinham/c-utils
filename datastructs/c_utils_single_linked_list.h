#ifndef C_UTILS_SINGLE_LINKED_LIST_H
#define C_UTILS_SINGLE_LINKED_LIST_H

///Imports
#include <stdlib.h>
#include <stdbool.h>

///Type Declarations
struct cu_sl_list_item_s
{
    struct cu_sl_list_item_s* next_item_p;
    void* value_p;
};

typedef struct cu_sl_list_item_s* sl_list_item_p_t;
typedef sl_list_item_p_t* sl_list_item_p_ref_t;

struct cu_sl_list_operation_result_s
{
    sl_list_item_p_t result_list_head_p;
    bool operation_success;
};

typedef struct cu_sl_list_operation_result_s sl_list_op_result_t;

typedef void (*value_dispose_func_t)(void* value_to_dispose);
typedef bool (*value_equals_func_t)(void* val1, void* val2);

///Function Declarations
sl_list_op_result_t sl_list_add_value(void* preallocated_value_p, sl_list_item_p_ref_t list_head_p_ref);

//TODO insert

size_t sl_list_count(sl_list_item_p_ref_t list_head_p_ref);

bool sl_list_contains(void* target_value_p, sl_list_item_p_t list_head_p,
    value_equals_func_t val_equals_func_p);

sl_list_op_result_t sl_list_remove_value(void* target_value_p, sl_list_item_p_t list_head_p,
    value_equals_func_t val_equals_func_p, value_dispose_func_t val_dispose_func_p);

void sl_list_dispose(sl_list_item_p_t list_head_p, value_dispose_func_t val_dispose_func_p);

#endif
