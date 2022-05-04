#include <stdio.h>

#include "child_class.h"
#include "parent_class.h"

int main (void)
{
    // 어느정도 일관성이 지켜지고 있음
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

    return 0;
}
