#ifndef C_CH3_CHILD_CLASS2_H
#define C_CH3_CHILD_CLASS2_H

#include "parent_class.h"

typedef struct _child_class2 child_class2;

struct _child_class2
{
    char *child_specific;
    parent_class *base_obj;

    void (* print) (struct _child_class2 * const);
    void (* control) (struct _child_class2 * const, const int, const char * const);
    void (* free) (struct _child_class2 * const);
};

child_class2 *init_child_class2 (const char * const, const int);

void control_child2_field (struct _child_class2 * const, const int, const char * const);
void free_child2_class (struct _child_class2 * const);
void print_child2_class (struct _child_class2 * const);

#endif //C_CH3_CHILD_CLASS2_H
