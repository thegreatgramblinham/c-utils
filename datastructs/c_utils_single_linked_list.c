
///Imports
#include "c_utils_single_linked_list.h"
#include <stdio.h>

///Local Declarations
///Static Constants
///Static Global Variables

///Static Functions
static sl_list_item_p_t alloc_new_item(void* preallocated_value_p)
{
    sl_list_item_p_t new_item = calloc(1, sizeof(struct cu_sl_list_item_s));
    if (new_item == NULL)
    {
        perror(">[ERROR] Unable to allocate new item memory.");
        exit(1);
    }
    new_item->value_p = preallocated_value_p;
    return new_item;
}

static void dispose_list_item(sl_list_item_p_t item_to_dispose_p, value_dispose_func_t val_dispose_func_p)
{
    if (val_dispose_func_p == NULL)
    {
        perror(">[ERROR] Missing value dispose function.");
        exit(1);
    }

    if (item_to_dispose_p == NULL)
    {
        perror(">[ERROR] Cannot dispose null item pointer.");
        exit(1);
    }

    (*val_dispose_func_p)(item_to_dispose_p->value_p);
    free(item_to_dispose_p);
}

///Extern Functions
sl_list_op_result_t sl_list_add_value(void* preallocated_value_p, sl_list_item_p_ref_t list_head_p_ref)
{
    sl_list_item_p_t item_to_add = alloc_new_item(preallocated_value_p);
    struct cu_sl_list_operation_result_s result_container =
    {
        .result_list_head_p = item_to_add,
        .operation_success = true,
    };

    if (list_head_p_ref == NULL)
    {
        perror(">[ERROR] Cannot create new list contents at 0x00");
        exit(1);
    }

    if ((*list_head_p_ref) == NULL)
    {
        (*list_head_p_ref) = item_to_add;
        return result_container;
    }

    sl_list_item_p_t curr_item_p = (*list_head_p_ref);
    while (curr_item_p->next_item_p != NULL)
        curr_item_p = curr_item_p->next_item_p;
    curr_item_p->next_item_p = item_to_add;

    result_container.result_list_head_p = (*list_head_p_ref);
    return result_container;
}

size_t sl_list_count(sl_list_item_p_ref_t list_head_p_ref)
{
    if (list_head_p_ref == NULL || (*list_head_p_ref) == NULL)
        return 0;

    size_t count = 1;
    sl_list_item_p_t curr_item_p = (*list_head_p_ref);
    while (curr_item_p->next_item_p != NULL)
    {
        curr_item_p = curr_item_p->next_item_p;
        count++;
    }
    return count;
}

sl_list_op_result_t sl_list_remove_value(void* target_value_p, sl_list_item_p_t list_head_p,
    value_equals_func_t val_equals_func_p, value_dispose_func_t val_dispose_func_p)
{
    struct cu_sl_list_operation_result_s result_container =
    {
        .result_list_head_p = NULL,
        .operation_success = false,
    };

    if (list_head_p == NULL)
        return result_container;

    sl_list_item_p_t prev_item_p = NULL;
    sl_list_item_p_t curr_item_p = list_head_p;
    while (curr_item_p != NULL)
    {
        if ((*val_equals_func_p)(target_value_p, curr_item_p->value_p))
        {
            if (prev_item_p == NULL)
            {
                result_container.result_list_head_p = curr_item_p->next_item_p;
                dispose_list_item(curr_item_p, val_dispose_func_p);
            }
            else
            {
                result_container.result_list_head_p = list_head_p;
                prev_item_p->next_item_p = curr_item_p->next_item_p;
                dispose_list_item(curr_item_p, val_dispose_func_p);
            }

            result_container.operation_success = true;
            break;
        }
        prev_item_p = curr_item_p;
        curr_item_p = curr_item_p->next_item_p;
    }
}

bool sl_list_contains(void* target_value_p, sl_list_item_p_t list_head_p,
    value_equals_func_t val_equals_func_p)
{
    if (list_head_p == NULL)
        return false;
    sl_list_item_p_t curr_item_p = list_head_p;
    while (curr_item_p != NULL)
    {
        if ((*val_equals_func_p)(target_value_p, curr_item_p->value_p))
            return true;
        curr_item_p = curr_item_p->next_item_p;
    }
    return false;
}

void sl_list_dispose(sl_list_item_p_t list_head_p, value_dispose_func_t val_dispose_func_p)
{
    if (list_head_p == NULL)
        return;
    if (list_head_p->next_item_p == NULL)
        dispose_list_item(list_head_p, val_dispose_func_p);
    else
        sl_list_dispose(list_head_p->next_item_p, val_dispose_func_p);
}

