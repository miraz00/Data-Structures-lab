#include<stdio.h>
#define size 50

int f=-1,r=-1,q[size];

int isfull()
{
    if((r==size-1 && f==0) || f==r+1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(f==-1)
        return 1;
    else
        return 0;
}

void insert(int item)
{
    if(f==-1)
    { 
      f=r=0;
      q[r]=item;
    }
   
    else
    {
      r=(r+1)%size;
      q[r]=item;
    }
    
    printf("item inserted");
}

int delete()
{
    if(f==r)
    {
      int item=q[f];
      f=r=-1;
      return item;
    }
    else
    {
      int item=q[f];
      f=(f+1)%size;
      return item; 
    }               
}

int display()
{
  if(f==r || r>f)
    for(int i=f;i<=r;i++)
      printf("%d\n",q[i]);
  else
  {
    for(int i=f;i<size;i++)      
      printf("%d\n",q[i]);
    for(int i=0;i<=r;i++)
      printf("%d\n",q[i]);     
  }
}


int main()
{
    int a,item;
    
    do
    {
    
        printf("\nEnter the operation to be performed \n1.Insert \n2.Delete \n3.Display \n4.Exit\n");
        scanf("%d",&a);
    
        switch(a)
        {
        case 1:
            if(isfull())
              printf("Queue is full");
            else
            {               
              printf("Enter the item to be inserted\n");
              scanf("%d",&item);
              insert(item); 
            }
            break;
            

        case 2:
            if(isempty())           
              printf("Queue is empty");                           
            else
            {
              item=delete();
              printf("%d is removed",item);                
            }
            break;
                         
        case 3:
            if(isempty())
              printf("Queue is empty");
            else    
            {                     
              printf("Items in the queue are\n");
              display();
            }
            break;
            
           
        case 4:break;
        
        default:printf("Please enter a valid option");
        
        }
    }while(a!=4);

return 0;
}
