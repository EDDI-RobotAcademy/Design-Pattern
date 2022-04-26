#include "child_class.h"
#include "parent_class.h"

#include <stdlib.h>
#include <stdio.h>

child_class *init_child_class (int field)
{
    child_class *tmp = (child_class *)malloc(sizeof(child_class));
    tmp->base_obj = init_parent_class(field);
    tmp->base_obj->derived_obj = tmp;

    return tmp;
}

void print_child (child_class *obj)
{
    printf("I'm child - field = %d\n", obj->base_obj->field);
}

void free_child_class (child_class *obj)
{
    free(obj->base_obj);
    free(obj);
}
