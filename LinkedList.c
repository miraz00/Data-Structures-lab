#include<stdio.h>
#include<malloc.h>

struct NODE
{ 
  int item;
  struct NODE *link;
}
typedef struct NODE node;

node *head=NULL;

p=node *newnode(int val)
{
  node *p;
  p=(node*)malloc(sizeof(node));
  node->item=val;
  node->link=NULL;
  return p;
}



int main()
 {
  int ch,po,it;
    
   do
   { 
     printf("\n1. insert first\n2. Insert after\n3. insert before\n4. display \n5. Delete \n6. quit");
     scanf("%d",&ch);

     switch(ch)
     { 
     case 1:printf("value to be inserted first:");
            scanf("%d",&po); 
            insertfirst(po);
            break;

     case 2:printf("enter item after which an element is inserted");
            scanf("%d",&it);
            printf("value to be inserted:");
            scanf("%d",&po);
            insertafter(it,po);
            break;

      case 3:printf("enter item before which an element is inserted");
            scanf("%d",&it);
            printf("value to be inserted:");
            scanf("%d",&po);
            insertbefore(it,po);
            break;

      case 4:displaylist(head);
             break;
         
      case 5:printf("value to be Deleted:");
             scanf("%d",&po);
             delete(po);
             break;
         
      case 6:break;

      default:printf("Invalid choice");
      }

    }while(ch!=6);

}
