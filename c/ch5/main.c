#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct list_node
{
    struct list_node *next, *prev;
    int data;
};

struct test_list
{
    struct list_node list;
    int count;
};

#define container_of(ptr, type, member) ({                      \
	void *__mptr = (void *)(ptr);                               \
	((type *)(__mptr - offsetof(type, member))); })

#define list_entry(ptr, type, member)                           \
	container_of(ptr, type, member)

static inline int list_is_head(const struct list_node *list, const struct list_node *head)
{
    return list == head;
}

#define list_for_each(pos, head)                                \
    for (pos = (head)->next; !list_is_head(pos, (head)); pos = pos->next)

#define list_first_entry(ptr, type, member)                     \
	list_entry((ptr)->next, type, member)

#define list_entry_is_head(pos, head, member)                   \
	(&pos->member == (head))

#define list_next_entry(pos, member) \
	list_entry((pos)->member.next, typeof(*(pos)), member)

#define list_for_each_entry(pos, head, member)                  \
	for (pos = list_first_entry(head, typeof(*pos), member);    \
	     !list_entry_is_head(pos, head, member);                \
	     pos = list_next_entry(pos, member))

#define list_for_each_safe(pos, n, head)                        \
	for (pos = (head)->next, n = pos->next;                     \
	     !list_is_head(pos, (head));                            \
	     pos = n, n = pos->next)

#define __WRITE_ONCE(x, val)                                    \
do {                                                            \
	*(volatile typeof(x) *)&(x) = (val);                        \
} while (0)

#define WRITE_ONCE(x, val)                                      \
do {                                                            \
	__WRITE_ONCE(x, val);                                       \
} while (0)

static inline void INIT_LIST_NODE(struct list_node *list)
{
    WRITE_ONCE(list->next, list);
    WRITE_ONCE(list->prev, list);
    WRITE_ONCE(list->data, 0);
}

#define LIST_NODE_INIT(name) { &(name), &(name), NULL }

#define LIST_NODE(name) \
	struct list_node name = LIST_NODE_INIT(name)

static inline void __list_del(struct list_node * prev, struct list_node * next)
{
    next->prev = prev;
    WRITE_ONCE(prev->next, next);
}

static inline void __list_del_entry(struct list_node *entry)
{
    __list_del(entry->prev, entry->next);
}

static inline void list_del(struct list_node *entry)
{
    __list_del_entry(entry);
    entry->next = NULL;
    entry->prev = NULL;
}

struct list_node *create_stack_node(void)
{
    struct list_node *tmp;

    tmp = (struct list_node *)malloc(sizeof(struct list_node));
    tmp->next = NULL;
    tmp->prev = NULL;

    return tmp;
}

static inline void __push_list(struct list_node *new,
                              struct list_node *prev,
                              struct list_node *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    WRITE_ONCE(prev->next, new);
}

static inline void push_list(struct list_node *new, struct list_node *head)
{
    __push_list(new, head, head->next);
}

void push(struct list_node *top, int data)
{
    struct list_node *tmp = top;
    top = create_stack_node();
    top->data = data;

    push_list(top, tmp);
}

void print_stack(struct list_node *top)
{
    struct list_node *start = top;

    while (top->next)
    {
        printf("top = %d\n", top->next->data);

        if (top->next == start) { break; }

        top = top->next;
    }
}

int main(void)
{
    struct test_list test_list;
    INIT_LIST_NODE(&test_list.list);

    struct test_list *lists;
    LIST_NODE(list);

    struct list_node *pos, *q;

    push(&test_list.list, 10);
    push(&test_list.list, 20);
    push(&test_list.list, 30);

    print_stack(&test_list.list);

    printf("sizeof(list_node) = 0x%x\n", sizeof(struct list_node));

    printf("C Based Iterator\n");

    list_for_each(pos, &test_list.list)
    {
        lists = list_entry(pos, struct test_list, list);
        printf("data: %d\n", lists->list.data);
    }

    printf("C Based Iterator\n");

    list_for_each_entry(lists, &test_list.list, list)
    {
        printf("data: %d\n", lists->list.data);
    }

    printf("C Based Iterator\n");

    list_for_each_safe(pos, q, &test_list.list)
    {
        struct test_list *tmp;
        tmp = list_entry(pos, struct test_list, list);
        printf("Delete node: %d\n", tmp->list.data);
        printf("del - pos: %d\n", pos->data);
        list_del(pos);
        free(tmp);
    }

    printf("Delete Success");

    return 0;
}