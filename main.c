#include <stdio.h>

#define SIZE 10
#define T char
#define ST_SIZE 100
#define MAX_LEN 64

T stack[ST_SIZE];
int stack_ptr = -1;

void push(T data)
{
        if (stack_ptr < ST_SIZE)
                stack[++stack_ptr] = data;
        else
                fprintf(stderr, "Stack overflow!\n");
}

T pop()
{
        if (stack_ptr) {
                return stack[stack_ptr--];
        } else {
                return -1;
                fprintf(stderr, "Stack is empty!\n");
        }
}

void conversion_to_Bin(unsigned int numb, char *numb_buf)
{
        do {
                push((numb % 2) ? '1' : '0');
        } while (numb /= 2);

        int i;
        for (i = 0; stack_ptr >= 0 && i < (MAX_LEN - 1); i++)
                numb_buf[i] = pop();
        numb_buf[++i] = '\0';
}

typedef struct {
int pr;
int dat;
} Node;

Node* arr[SIZE];
int head;
int tail;
int items;

void init(){
    for (int i = 0; i < SIZE;++i){
    arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void insert(int pr, int dat) {
    Node *node = (Node*) malloc (sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flags;

    if (items == 0) {
        arr[tail++] = node;
        items++;
    } else if (items = SIZE) {
        printf("%s \n", "Queue is full");
        return;
    } else {
        int i = 0;
        int idx = 0;
        Node *tmp;
        for (i = head; i < tail; ++i) {
             idx = i % SIZE;
             if (arr[idx]->pr > pr)
                break;
             else
                idx++;
      }
      flags = idx % SIZE;
      i++;
      while (i <= tail) {
          idx = i % SIZE;
          tmp = arr[idx];
          arr[idx] = arr[flags];
          arr[flags] = tmp;
          i++;
      }
      arr[flags] = node;
      items++;
      tail++;
    }
}

Node* rm(){
    if(items ==0){
        return NULL;
    } else {
         int idx = head++ % SIZE;
         Node *tmp = arr[idx];
         arr[idx] = NULL;
         items--;
         return tmp;
    }
}

void printed_Queue() {
    printf("[ ");
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

int main(const int argc, const char **argv)
{
    init();
    insert(1, 11);
    insert(3, 22);
    insert(4, 33);
    insert(2, 44);
    insert(3, 55);
    insert(4, 66);
    insert(5, 77);
    insert(1, 88);
    insert(2, 99);
    insert(6, 100);
    printed_Queue();

    for (int i = 0; i < 7; ++i) {
        Node* n = rm();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
    }
    printed_Queue();

    insert(1, 110);
    insert(3, 120);
    insert(6, 130);
    printed_Queue();


    char numb_buf[MAX_LEN];
    unsigned int x = 250;
    unsigned int y = 652;

       numb_buf[0] = '\0';
        conversion_to_Bin(x, numb_buf);
        printf("%u in binary is %s\n", x, numb_buf);

        numb_buf[0] = '\0';
        conversion_to_Bin(y, numb_buf);
        printf("%u in binary is %s\n", y, numb_buf);

	return 0;
}

