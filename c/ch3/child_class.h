#ifndef C_CH3_CHILD_CLASS_H
#define C_CH3_CHILD_CLASS_H

#include "parent_class.h"

typedef struct _child_class child_class;

struct _child_class
{
    char *child_specific;
    parent_class *base_obj;

    void (* print) (struct _child_class * const);
    void (* control) (struct _child_class * const, const int, const char * const);
    void (* free) (struct _child_class * const);
};

child_class *init_child_class (const char * const, const int);

void control_child_field (struct _child_class * const, const int, const char * const);
void free_child_class (struct _child_class * const);
void print_child_class (struct _child_class * const);

#endif //C_CH3_CHILD_CLASS_H
