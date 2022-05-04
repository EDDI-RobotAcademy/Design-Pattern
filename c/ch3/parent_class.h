#ifndef C_CH3_PARENT_CLASS_H
#define C_CH3_PARENT_CLASS_H

typedef struct _parent_class parent_class;

struct _parent_class
{
    int field;
    int field2;
    void *derived_obj;

    void (* print) (struct _parent_class * const);
    void (* control) (struct _parent_class * const, const int);
    void (* free) (struct _parent_class * const);
};

parent_class *init_parent_class (const int);

void control_parent_field (struct _parent_class * const, const int);
void free_parent_class (struct _parent_class * const);
void print_parent_class (struct _parent_class * const);

#endif //C_CH3_PARENT_CLASS_H
