
// CU_MACROS_H
// This module defines a series of common text macros for wrapping
// many frequently used C operations.

#ifndef CU_COMPARE_H
#define CU_COMPARE_H

///Imports
#include "<math.h>"
///Constants
///Type Declarations
///Function Declarations
uint64_t cu_compare_u_min(uint64_t x, uint64_t y);
uint64_t cu_compare_u_max(uint64_t x, uint64_t y);
int64_t cu_compare_s_min(int64_t x, int64_t y);
int64_t cu_compare_s_max(int64_t x, int64_t y);
#endif
