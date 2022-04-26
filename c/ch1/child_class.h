#ifndef C_CH1_CHILD_CLASS_H
#define C_CH1_CHILD_CLASS_H

#include "parent_class.h"

typedef struct _child_class child_class;

struct _child_class
{
    parent_class *base_obj;
};

child_class *init_child_class (int);
void print_child (child_class *);
void free_child_class (child_class *);

#endif //C_CH1_CHILD_CLASS_H
