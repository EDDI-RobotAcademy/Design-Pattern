#ifndef C_CH2_PARENT_CLASS_H
#define C_CH2_PARENT_CLASS_H

typedef struct _parent_class parent_class;

// 여러 개체가 생성되는 것이 아니라면 구조체 내부에 뭉쳐놓는 것이 더 좋다.
struct _parent_class
{
    int field;
    void *derived_obj;

    void (* print) (struct _parent_class * const);
    void (* control) (struct _parent_class * const, const int);
    void (* free) (struct _parent_class * const);
};

parent_class *init_parent_class (const int);

void control_parent_field (struct _parent_class * const, const int);
void free_parent_class (struct _parent_class * const);
void print_parent_class (struct _parent_class * const);

#endif //C_CH2_PARENT_CLASS_H
