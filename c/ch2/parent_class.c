#include "parent_class.h"

#include <stdlib.h>
#include <stdio.h>

parent_class *init_parent_class (const int field)
{
    parent_class *tmp;

    if (!(tmp = (parent_class *)malloc(sizeof(parent_class))))
    {
        return NULL;
    }

    tmp->field = field;
    tmp->derived_obj = tmp;

    tmp->control = control_parent_field;
    tmp->free = free_parent_class;
    tmp->print = print_parent_class;

    return tmp;
}

void control_parent_field (parent_class * const obj, const int field)
{
    obj->field = field;
}

void free_parent_class (parent_class * const obj)
{
    free(obj);
}

void print_parent_class (parent_class * const obj)
{
    printf("parent:\n");
    printf("field = %d\n", obj->field);
}