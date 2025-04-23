#include <stdio.h>


#define size 5

int rear=-1,value,front=-1,queue[size];


void enqueue();
void dequeue();
void display();


int main(){


    int ch;

    printf("\n\n    WELCOME TO CIRCULAR QUEUE  ");

    while(1){

        printf("\n\nEnter the operation to perform in the queue\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit the program\n          :   ");

        scanf("%d",&ch);

        switch(ch){


            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting the program..........");
                return 0;
            default :
                printf("\nInvalid choice , plese enter only number from 1 to 4.");

        }
    }



    return 0;

}




void enqueue(){

    if(front==rear+1 || (front==0 && rear == size -1)){
        printf("\nThe queue is full...");
        return ;
    }


    printf("\nEnter the value to add in the queue  :   ");
    scanf("%d",&value);

    rear = (rear+1)%size;
    queue[rear] = value;

    if(front==-1){
        front=0;
    }
}




void dequeue(){

    if(front==-1 || rear==-1){
        printf("\nThe queue is empty....");
        return ;
    }


    printf("\nThe removed value is %d...",queue[front]);
    front = (front+1)%size;

    if(front==rear+1 || (front == 0 && rear == size-1)){
        front = -1;
        rear = -1;
    }

}



void display(){

    if(front==-1 || rear==-1){
        printf("\nThe queue is empty....");
        return ;
    }



    printf("\nThe queue is ..\n  |");

    for(int i=front ; i!=rear ; i=(i+1)%size){

        printf(" %d |",queue[i]);
    }
    printf(" %d |",queue[rear]);


}


/*
Output :



    WELCOME TO CIRCULAR QUEUE

Enter the operation to perform in the queue
1.Enqueue
2.Dequeue
3.Display
4.Exit the program
          :   1

Enter the value to add in the queue  :   45


Enter the operation to perform in the queue
1.Enqueue
2.Dequeue
3.Display
4.Exit the program
          :   1

Enter the value to add in the queue  :   87


Enter the operation to perform in the queue
1.Enqueue
2.Dequeue
3.Display
4.Exit the program
          :   3

The queue is ..
  | 45 | 87 |

Enter the operation to perform in the queue
1.Enqueue
2.Dequeue
3.Display
4.Exit the program
          :   2

The removed value is 45...

Enter the operation to perform in the queue
1.Enqueue
2.Dequeue
3.Display
4.Exit the program
          :   3

The queue is ..
  | 87 |

Enter the operation to perform in the queue
1.Enqueue
2.Dequeue
3.Display
4.Exit the program
          :   4

 Exiting the program..........

*/
