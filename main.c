#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "t_queue.h"

int main(int argc, char const *argv[])
{
    t_queue *general_queue = create_queue();
    t_queue *priority_queue = create_queue();
    t_queue *final_queue = create_queue();
    
    char name[20], i;
    int times = 0;
    
    do{
        scanf(" %c", &i);
        if('g' == i){
            gets(name);
            push_back_queue(general_queue, name);
        }else if('p' == i){
            gets(name);
            push_back_queue(priority_queue, name);
        }else if('s' == i){
            if(is_full_queue(priority_queue) && times < 3){
                times++;
                pop_front_queue(priority_queue, name);
                push_back_queue(final_queue, name);
            }else{
                times = 0;
                pop_front_queue(general_queue, name);
                push_back_queue(final_queue, name);
            }
        }
        
    } while (i!='f');
    
    while(is_full_queue(final_queue)){
        pop_front_queue(final_queue, name);
        puts(name);
    }


    destroy_queue(general_queue);
    destroy_queue(priority_queue);
    destroy_queue(general_queue);

    return 0;
}
