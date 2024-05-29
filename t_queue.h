#ifndef T_QUEUE_H
#define T_QUEUE_H

#define value char

typedef struct _node{
    struct _node *prev;
    value item[20];
    struct _node *next;
}t_node;

typedef struct {
    t_node *head;
    t_node *tail;
    int length;
}t_queue;

t_queue* create_queue();
int push_back_queue(t_queue *queue, value *item);
int pop_front_queue(t_queue *queue, value *item);
int print_queue(t_queue *queue);
int length_queue(t_queue *queue);
int is_full_queue(t_queue *queue);
int is_empty_queue(t_queue *queue);
int clean_queue(t_queue *queue);
int destroy_queue(t_queue *queue);

#endif