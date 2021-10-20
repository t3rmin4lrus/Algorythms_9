#include <stdio.h>

#define LINE_SIZE 101
#define SIZE_STACK 101
#define MAX_NUMBER_LEN 72
#define T char

typedef struct {
 int prior;
 T data;
} Node;

Node *line[LINE_SIZE];
int line_ptr = -1;
T stack[SIZE_STACK];
int stack_ptr = -1;

void my_queue(T data, int prior)
{
        if (line_ptr < LINE_SIZE) {
                Node *node = (Node *)malloc(sizeof(Node));
                node->data = data;
                node->prior = prior;
                line[++line_ptr] = node;
        } else {
                printf("Queue overflow!\n");
        }
}

Node *my_enqueue(void)
{
        if (line_ptr < 0) {
                return NULL;
                printf("Queue is empty\n");
        }
        int max_prior_node_idx = 0;
        for (int i = 0; i <= line_ptr; i++) {
                if (line[i]->prior > line[max_prior_node_idx]->prior) {
                        max_prior_node_idx = i;
                }
        }
        Node *max_prior_node = line[max_prior_node_idx];
        line_ptr--;
        for (int i = max_prior_node_idx; i <= line_ptr; i++)
                line[i] = line[i + 1];
        return max_prior_node;
}

void print_line(void)
{
        for (int i = 0; i <= line_ptr; i++)
                printf("(%c, %d) ", line[i]->data, line[i]->prior);
        printf("\n");
}

void push(T data)
{
        if (stack_ptr < SIZE_STACK)
                stack[++stack_ptr] = data;
        else
                fprintf(stderr,"Stack overflow!\n");
}

T pop()
{
        if (stack_ptr >= 0) {
                return stack[stack_ptr--];
        } else {
                return -1;
                printf( "Stack is empty!\n");
        }
}

void toBin(unsigned int number, char *buffer)
{
        do {
                push((number % 2) ? '1' : '0');
        } while (number /= 2);

        int i;
        for (i = 0; stack_ptr >= 0 && i < (MAX_NUMBER_LEN - 1); i++)
                buffer[i] = pop();
        buffer[++i] = '\0';
}

int main()
{
        printf("Queue with priority exception:\n");

        for (int i = 0; i < LINE_SIZE; i++)
                line[i] = NULL;

        my_queue('O',1);
        my_queue('D',0);
        my_queue('L',2);
        my_queue('B',3);
        my_queue('O',1);
        print_line();

        for (int i = 0; line[i] != NULL; i++) {
                printf("%c", my_enqueue()->data);
        }
        printf("\n");

        printf("Binary representation of a numbers:\n");
        char buffer[MAX_NUMBER_LEN];
        unsigned int x = 235;
        unsigned int y = 368;

        buffer[0] = '\0';
        toBin(x, buffer);
        printf("%u Numbers in binary representation: %s\n", x, buffer);

        buffer[0] = '\0';
        toBin(y, buffer);
        printf("%u Numbers in binary representation: %s\n", y, buffer);
}
