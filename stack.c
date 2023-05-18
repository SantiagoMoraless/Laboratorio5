#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};



stack stack_empty(){
    stack s = malloc(sizeof(struct _s_stack));
    s->capacity = 1u;
    s->elems = calloc(s->capacity,sizeof(stack_elem));
    s->size = 0u;
    return s;
}


stack stack_push(stack s, stack_elem e){
    s->size = s->size + 1;

    if (s->size > s->capacity) {
        s->elems = realloc(s->elems,sizeof(stack_elem)*s->capacity*2);
        s->capacity *= 2;
    }
    s->elems[s->size-1] = e;
    return s;
}


stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    s->size = s->size-1;
    return s;
}


unsigned int stack_size(stack s){
    return s->size;
}


stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->elems[s->size-1];
}


bool stack_is_empty(stack s){
    return s->elems == 0;
}


stack_elem *stack_to_array(stack s){
    stack_elem *arreglo = calloc(s->size, sizeof(stack_elem));
    for(unsigned int i = 0; i < stack_size(s); ++i){
        arreglo[i] = s->elems[i];
    }

    return arreglo;
}


stack stack_destroy(stack s){
    free(s->elems);
    free(s);
    s = NULL;
    return s;
}


