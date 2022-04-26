#include <stdio.h>

#include "child_class.h"
#include "parent_class.h"

int main (void)
{
    child_class *cc = init_child_class(3);
    print_child(cc);
    // 상속된 정보를 활용하고자 할 때 child_class 의 base_obj 를 파악해야한다는 단점이 존재함
    control_field(cc->base_obj);
    free_child_class(cc);

    // 일관된 사용이 불가능하며
    // 다형성 구현이 불가하다는 문제가 발생함
    parent_class *pc = init_parent_class(3);
    control_field(pc);
    free_parent_class(pc);

    return 0;
}
