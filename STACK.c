#include<stdio.h>

#define size 50

int top=0,item1[size];

int isfull()

{

    if(top==size)

        return 1;

    else

        return 0;

}

int isempty()

{

    if(top==0)

        return 1;

    else

        return 0;

}

void push(int item)

{

    item1[top]=item;

    top=top+1;

    printf("item inserted");

}

int pop()

{

    top=top-1;

    int item=item1[top];

    return item;

}

int peek()

{

    top=top-1;

    int item=item1[top];

    top=top+1;

    return item;

}

int display()

{

    for(int i=0; i<top; i++)

        printf("%d\n",item1[i]);

}

int main()

{

    int a,item;

    

    do

    {

    

        printf("\nEnter the operation to be performed \n1.Push \n2.Pop \n3.Peek \n4.Display \n5.Exit\n");

        scanf("%d",&a);

    

        switch(a)

        {

        case 1:

            if(isfull())

              printf("Stack is full");

            else

            {               

              printf("Enter the item to be inserted\n");

              scanf("%d",&item);

              push(item); 

            }

            break;

            

        case 2:

            if(isempty())           

              printf("Stack is empty");                           

            else

            {

              item=pop();

              printf("%d is removed",item);                

            }

            break;

            

        case 3:

            if(isempty())            

              printf("Stack is empty");               

            else

            {

              item=peek();

              printf("%d is the top item",item);                

            }

            break;

            

        case 4:

            if(isempty())

              printf("Stack is empty");

            else    

            {                     

              printf("Items in the stack are\n");

              display();

            }

            break;

            

           

        case 5:break;

        

        default:printf("Please enter a valid option");

        

        }

    }while(a!=5);

return 0;

}
