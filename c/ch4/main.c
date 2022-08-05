#include <stdio.h>
#include <stdlib.h>

// 아래와 같은 C 기반 매크로를 작성할 때는
// 실제 구조체 내부의 멤버 변수 위치가 중요하다.
// 만약 data가 최상위였다면 list_entry에서 찾는 member는 data로 작성되어야 올바른 처리가 되었을 것이다.
struct list_node
{
    struct list_node *next, *prev;
    int data;
};

struct list_node *ptr;
struct list_node *node;

#define stack_list_for_each(pos, head) \
    for (pos = (head); pos != NULL; pos = pos->next)

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

#define list_entry2(ptr, type, member) \
    container_of(ptr, type, member)

struct list_node *create_stack_node(void)
{
    struct list_node *tmp;

    tmp = (struct list_node *)malloc(sizeof(struct list_node));
    tmp->next = NULL;
    tmp->prev = NULL;

    return tmp;
}

void push(struct list_node **top, int data)
{
    struct list_node *tmp = *top;

    *top = create_stack_node();
    (*top)->data = data;
    (*top)->next = tmp;

    if (tmp)
    {
        tmp->prev = *top;
    }
}

void print_stack(struct list_node *top)
{
    while (top)
    {
        printf("top = %d\n", top->data);

        if (top->prev)
        {
            printf("top->prev = %d\n", top->prev->data);
        }

        top = top->next;
    }
}

int main(void)
{
    struct list_node *top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    print_stack(top);

    printf("sizeof(list_node) = 0x%x\n", sizeof(struct list_node));

    printf("C Based Iterator\n");
    stack_list_for_each(ptr, top)
    {
        printf("stack_list_for_each() ptr data: %d\n", ptr->data);
        node = list_entry(ptr, struct list_node, data);
        printf("list_entry() node data: %d\n", node->data);
        printf("node address: 0x%x\n", node);
        printf("node data address: 0x%x\n", &node->data);
        printf("*node: %d\n", *((int *)node));
    }

    stack_list_for_each(ptr, top)
    {
        printf("data: %d\n", *((int *) list_entry(ptr, struct list_node, data)));
    }

    stack_list_for_each(ptr, top)
    {
        node = list_entry(ptr, struct list_node, next);
        printf("node address: 0x%x\n", node);
        printf("node data: %d\n", node->data);
    }

    return 0;
}