#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "t_queue.h"

t_node* create_node(value *item){
    t_node *node = (t_node*) malloc (sizeof(node));
    if(NULL==node){
        printf("Error in creating node.");
        exit(0);
    }
    strcpy(node->item, item);
    node->next = NULL;
    node->prev = NULL;
    return node;
}

t_queue* create_queue(){
    t_queue *queue = (t_queue*) malloc (sizeof(t_queue));
    if(NULL==queue){
        printf("Error in creating queue.");
        exit(0);
    }
    queue->head = NULL;
    queue->tail = NULL;
    queue->length = 0;
    return queue;
}


int push_back_queue(t_queue *queue, value *item){
    t_node *node = create_node(item);
    if(0==queue->length){
        queue->tail = node;
        queue->head = node;
    }else{
        queue->tail->next = node;
        node->prev = queue->tail;
        queue->tail = node;
    }
    queue->length++;
    return 1;
}

int pop_front_queue(t_queue *queue, value *item){
    if(0==queue->length){
        return 0;
    }
    strcpy(item, queue->head->item);
    if(1==queue->length){
        free(queue->head);
        queue->head = NULL;
        queue->tail = NULL;
    }else{
        queue->head = queue->head->next;
        free(queue->head->prev);
        queue->head->prev = NULL;
    }
    queue->length--;
    return 1;
}

int print_queue(t_queue *queue){
    t_node *node = queue->head;
    while(NULL!=node){
        printf("%d ", node->item);
        node = node->next;
    }
    printf("\n");
    return 1;
}

int length_queue(t_queue *queue){
    return queue->length;
}

int is_full_queue(t_queue *queue){
    if(0!=queue->length){
        return 1;
    }
    return 0;
}

int is_empty_queue(t_queue *queue){
    if(0==queue->length){
        return 1;
    }
    return 0;
}

int clean_queue(t_queue *queue){
    if(0==queue->length){
        return 1;
    }
    t_node *aux1 = queue->head;
    t_node *aux2 = aux1->next;
    while(NULL!=aux2){
        free(aux1);
        aux1 = aux2;
        aux2 = aux2->next;
    }
    free(aux1);
    queue->head = NULL;
    queue->tail = NULL;
    queue->length=0;
    return 1;
}

int destroy_queue(t_queue *queue){
    clean_queue(queue);
    free(queue);
    return 1;
}
