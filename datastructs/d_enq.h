
// D_ENQ.h
// This module defines a *D*ouble directional, *ENQ*ueue-able structure
// (and related types) that can be declared as the first member of another
// structure to hold arbitrary data in a doubly linked list format.

#ifndef D_ENQ_H
#define D_ENQ_H

///Imports
///Constants
///Type Declarations
struct d_enq_item_s
{
    struct d_enq_item_s *next_item;
    struct d_enq_item_s *prev_item;
    char *identifier_string_ptr;
};
typedef struct *d_enq_item_s d_enq_item_ptr_t;
typedef struct *d_enq_item_s d_enq_list_ref_ptr_t;
///Function Declarations

#endif
