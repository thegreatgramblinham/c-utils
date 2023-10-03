
// S_ENQ.h
// This module defines a *S*ingle directional, *ENQ*ueue-able structure
// (and related types) that can be declared as the first member of another
// structure to hold arbitrary data in a singly linked list format.

#ifndef S_ENQ_H
#define S_ENQ_H

///Imports
#include <bool.h>

///Constants
///Type Declarations
struct s_enq_item_s
{
    struct s_enq_item_s *next_item;
    const char *identifier_string_ptr;
};
typedef struct *s_enq_item_s s_enq_item_ptr_t;
typedef struct *s_enq_item_s s_enq_list_ref_ptr_t;

///Function Declarations

// Creates a new list with the given identifier string and returns its address.
s_enq_list_ref_ptr_t s_enq_create_list(const char *list_identifier_string);
// Creates a new item with the given identifier string and returns its address.
s_enq_item_ptr_t s_enq_create_item(const char *item_identifier_string);

bool s_enq_is_item_enqueued(s_enq_item_ptr_t item);
bool s_eng_is_list_empty(s_enq_list_ref_ptr_t list_ref);

// Attempts to add item. Returns true if added.
bool s_enq_add_head(s_enq_list_ref_ptr_t list_ref, s_enq_item_ptr_t item);
bool s_enq_add_tail(s_enq_list_ref_ptr_t list_ref, s_enq_item_ptr_t item);

// Removes the item and returns its address.
s_enq_item_ptr_t s_enq_dequeue_item(s_enq_list_ref_ptr_t list_ref, s_enq_item_ptr_t item); //TODO comparision function ptr?
s_enq_item_ptr_t s_enq_dequeue_head(s_enq_list_ref_ptr_t list_ref, s_enq_item_ptr_t item);
s_enq_item_ptr_t s_enq_dequeue_tail(s_enq_list_ref_ptr_t list_ref, s_enq_item_ptr_t item);

// Get an item at the start or end of the list.
s_enq_item_ptr_t s_enq_get_head(s_enq_list_ref_ptr_t list_ref);
s_enq_item_ptr_t s_enq_get_tail(s_enq_list_ref_ptr_t list_ref);

//TODO destroy/free an item and list

#endif
