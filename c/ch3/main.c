#include <stdio.h>

#include "child_class.h"
#include "child_class2.h"
#include "parent_class.h"

int main (void)
{
    // 역시 C에서도 parent 를 수정하면
    // 연관된 의존성에 의해 child 와 child2 에 파급이 몰려옴을 볼 수 있다.
    child_class *cc = init_child_class("test", 3);
    cc->print(cc);
    cc->control(cc, 7, "gogosing");
    cc->print(cc);
    cc->free(cc);

    parent_class *pc = init_parent_class(3);
    pc->print(pc);
    pc->control(pc, 7);
    pc->print(pc);
    pc->free(pc);

    child_class2 *cc2 = init_child_class2("dependency test", 10);
    cc2->print(cc2);
    cc2->control(cc2, 7, "gogosing");
    cc2->print(cc2);
    cc2->free(cc2);

    return 0;
}
