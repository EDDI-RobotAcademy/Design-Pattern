#include "common.h"
#include "child_class.h"
#include "parent_class.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

child_class *init_child_class (const char * const specific, const int field)
{
    int specific_length;
    child_class *child_tmp;
    parent_class *parent_tmp;

    parent_tmp = init_parent_class(field);

    if (!(child_tmp = (child_class *)malloc(sizeof(struct _child_class))))
    {
        parent_tmp->free(parent_tmp);
        return NULL;
    }

    parent_tmp->derived_obj = child_tmp;
    child_tmp->base_obj = parent_tmp;

    specific_length = strlen(specific);

    if (!(child_tmp->child_specific = (char *)malloc(strlen(specific) + NULL_SAFE_BYTE)))
    {
        return NULL;
    }
    strncpy(child_tmp->child_specific, specific, specific_length);

    child_tmp->control = control_child_field;
    child_tmp->free = free_child_class;
    child_tmp->print = print_child_class;

    return child_tmp;
}

void control_child_field (child_class * const obj, const int field, const char * const specific)
{
    int input_length = strlen(specific);
    int origin_length = strlen(obj->child_specific);

    obj->base_obj->field = field;

    if (origin_length < input_length)
    {
        obj->child_specific = (char *) realloc(obj->child_specific, input_length + NULL_SAFE_BYTE);
        strncpy(obj->child_specific, specific, input_length);
    }
    else
        strncpy(obj->child_specific, specific, input_length);
}

void free_child_class (child_class * const obj)
{
    obj->base_obj->free(obj->base_obj);
    free(obj);
}

void print_child_class (child_class * const obj)
{
    obj->base_obj->print(obj->base_obj);

    printf("child:\n");
    printf("child_specific: %s\n", obj->child_specific);
}