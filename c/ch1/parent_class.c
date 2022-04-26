#include "parent_class.h"

#include <stdlib.h>
#include <stdio.h>

parent_class *init_parent_class (int field)
{
    parent_class *tmp = (parent_class *)malloc(sizeof(parent_class));
    tmp->derived_obj = NULL;
    tmp->field = field;

    return tmp;
}

void control_field (parent_class *obj)
{
    printf("I'm parent - field = %d\n", obj->field);
}

void free_parent_class (parent_class *obj)
{
    free(obj);
}
