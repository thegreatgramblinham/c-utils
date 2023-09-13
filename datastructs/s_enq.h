
// S_ENQ.h
// This module defines a *S*ingle directional, *ENQ*ueue-able structure
// (and related types) that can be declared as the first member of another
// structure to hold arbitrary data in a singly linked list format.

#ifndef S_ENQ_H
#define S_ENQ_H

///Imports
///Constants
///Type Declarations
struct s_enq_item_s
{
    struct s_enq_item_s *next_item;
    char *identifier_string_ptr;
};
typedef struct *s_enq_item_s s_enq_item_ptr_t;
typedef struct *s_enq_item_s s_enq_list_ref_ptr_t;
///Function Declarations
#endif
