#include <stdio.h>
#include <stdlib.h>

// STRUCT DECLARE
typedef struct node{
    struct node *left;
    struct node *right;
    int id;
} *node;

typedef struct stack_item{
    node p;
    struct stack_item *next;
} *stack_item;

typedef struct stack{
    stack_item top;
} *stack;

node create_node(int value){
    node nn = malloc(sizeof(struct node));
    nn->id = value;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

// STACK PROCEDURE

stack_item stack_create_item(node value){
    stack_item n = malloc(sizeof(struct stack_item));
    n->next = NULL;
    n->p = value;
    return n;
}

void stack_free_item(stack_item node){
    free(node);
}

stack stack_create(){
    stack stack = malloc(sizeof(struct stack));
    stack->top = NULL;
    return stack;
}

void stack_push(stack stack, stack_item node){
    if (stack->top == NULL){
      stack->top = node;
    }
    else{
      node->next = stack->top;
      stack->top = node;
    }
}

int stack_is_empty(stack stack){
    return stack->top == NULL;
}

node stack_pop(stack stack){
    if (stack_is_empty(stack)){
      return NULL;
    }
    stack_item tmp = stack->top;
    node result = tmp->p;
    stack->top = stack->top->next;
    stack_free_item(tmp); 
    return result;
}

void stack_free(stack stack){
    while (!stack_is_empty(stack)){
      stack_pop(stack);
    }
    free(stack);
}

node stack_peek(stack stack){
    if(stack_is_empty(stack))
      return NULL;
    return stack->top->p;
}

// INTERATIVE TRAVERSE
void inOrder_i(node root){
    node tmp = root;
    stack_item cur = stack_create_item(tmp);
    stack s = stack_create();
    int done = 0;
    while(!done){
        if(cur->p != NULL){
            stack_push(s, cur);
            tmp = tmp->left;
            cur = stack_create_item(tmp);
        }
        else{
            if(!stack_is_empty(s)){
                cur->p = stack_pop(s);
                printf("%d  ", cur->p->id);
                cur->p = cur->p->right;
                tmp = cur->p;
            }
            else{
                done = 1;
            }
        }
    } 
}

int main(){
    node root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);
    root->right->right = create_node(7);
    root->left->right->right = create_node(8);

    /* Binary tree
             1
         2       3
       4   5   6   7   
            8
    */
    inOrder_i(root);
    printf("\n");
    return 0;
}