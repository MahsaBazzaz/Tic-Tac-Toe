#include<stdio.h>
#include <stdbool.h>
#define SIZE 5

/*functions prototypes */
void enQueue(int); //Enqueue an item into the queue.
void deQueue(int*);//Dequeue an item from the Queue.
void display(); //displays elements of Queue.
bool isEmpty();//Return true if the queue is empty
bool isFull();//Return true if the queue is full.
int peek();
void clearQueue(); //Initialize queue to empty.
/*----------------------------- */
int queue[SIZE], head = -1, tail = -1;

int main()
{

    int element;
    char operand;
    int item;
    printf("HELP::\ne=enqueue\nd=dequeue\nD=display\nc=clear queue\nq=quit\n");
    do{
    printf("------------\n");
    scanf(" %c",&operand);
    if(operand=='e'){
        printf("What do you want to insert to the queue?\n");
        scanf("%d",&item);
        enQueue(item);
    }
    else if(operand=='d'){
        deQueue(&element);
    }
    else if(operand=='D'){
        display();
    }
    else if(operand=='c'){
        clearQueue();
    }
    else printf("ERROR:: bad operator!!\n");
    }while(operand!='q');
    return 0;

}
/*functions defining*/
void enQueue(int value){
    if(isFull())
        printf("Queue is Full!!\n");
    else {
        if(head == -1)
            head = 0;
        tail++;
        queue[tail] = value;
        printf("Inserted -> %d\n", value);
    }
}

void deQueue(int *element){
    if(isEmpty())
        printf("Queue is Empty!!\n");
    else{
        *element=peek();
        printf("Deleted : %d\n",peek());
        head++;
        if(head > tail)
            head = tail = -1;
    }
}

void display(){
    if(tail == -1)
        printf("Queue is Empty!!!\n");
    else{
        int i;
        printf("Queue elements are:\n");
        for(i=head; i<=tail; i++)
            printf("%d\t",queue[i]);
        printf("\n");
    }
}
bool isEmpty(){
    return (head == tail);
}
bool isFull(){
    return (tail == SIZE-1);
}
int peek(){
    return queue[head];
}
void clearQueue(){
	head = tail = -1;
	printf("Queue became empty\n");
}

