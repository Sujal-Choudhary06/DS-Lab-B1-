#include <stdio.h>

int front = -1;
int rear = -1;

#define n 100
int queue[n];

void enque(int data){

    if(rear > n - 1) return;

    if(front == -1 && rear == -1){
        front++;
        rear++;
        queue[rear] = data;
    }
    else{
        queue[++rear] = data;
    }
}

int deque(){

    int x;

    if(front == -1 && rear == -1) return -1;

    if(front == rear){
       x = queue[rear];
       front = rear = -1;
       return x;      
    }
    else{
        x = queue[front];
        front++;
    }
    return x;
}

void reverse_queue(){
   
    int data = deque();
    if(data == -1) return;

    reverse_queue();
     enque(data);
}

void Display(){

    if(front == -1 && rear == -1) return;

    for(int i = front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}

int main(){

    int t;
    printf("Enter number of elements: ");
    scanf("%d",&t);

    int data;
    for(int i=0;i<t;i++){
        scanf("%d",&data);
        enque(data);
    }
    
    printf("Before Reversing: ");
    Display();
    printf("\n");
    printf("After Reversing: ");
    reverse_queue();
    Display();

    return 0;
}