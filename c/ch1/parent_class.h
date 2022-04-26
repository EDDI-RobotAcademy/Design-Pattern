#ifndef C_CH1_PARENT_CLASS_H
#define C_CH1_PARENT_CLASS_H

typedef struct _parent_class parent_class;

struct _parent_class
{
    int field;
    void *derived_obj;
};

parent_class *init_parent_class (int);
void control_field (parent_class *);
void free_parent_class (parent_class *);

#endif //C_CH1_PARENT_CLASS_H
