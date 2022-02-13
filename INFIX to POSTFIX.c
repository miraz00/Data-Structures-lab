
#include<stdio.h>
#define size 50

int top=0;
char s[size];

int isempty()
{
  if(top==0)
    return 1;
  else
    return 0;
}

int isfull()
{
  if(top==size)
    return 1;
  else 
    return 0;
}
  
char pop()
{
  return(s[--top]);
}

char peek()
{
return(s[top-1]);
}

void push(char a)
{
  if(isfull())
    printf("Stack full");
  else
    s[top++]=a;  
}

void displaystack()
{
  printf("\t stack: ");
  for(int i=0;i<top;i++)
    printf("%c",s[i]);
}


void displaypf(char pf[],int j)
{
  printf("\t postfix:");
  for(int i=0;i<j;i++)
    printf("%c",pf[i]);
}

int inputprecedence(char a)
{
  switch(a)
  {
    case '+':
    case '-':return 1;
             break;
    case '*':
    case '/':return 3;
             break;
    case '^':return 6;
             break;   
  }
}

int stackprecedence(char a)
{
  switch(a)
  {
    case '+':
    case '-':return 2;
             break;
    case '*':
    case '/':return 4;
             break;
    case '^':return 5;
             break;   
    case '(':return 0;
             break;
  }
}

int main()
{
  char token,expr[50],pf[50],c;
  int j=0;
 
  printf("\nEnter an infix expression\n");
  scanf("%[^\n]",expr);
  printf("Expression:\n %s \n",expr);

  for(int i=0;expr[i]!='\0';i++)
  {
    token=expr[i];
    
    switch(token)
    {
      case '(':push(token);
               break;
      case '+':
      case '-':               
      case '*':
      case '/':            
      case '^':while(!isempty() && (stackprecedence(peek())>inputprecedence(token)))                
                 pf[j++]=pop();  
               push(token);
               break;                    
      case ')':while((c=pop())!='(')
                 pf[j++]=c;
               break;
      default:pf[j++]=token;
              break;
    }
    printf("\nToken:%c",token);
    displaystack();
    displaypf(pf,j);
  }

    
  while(!isempty())
    pf[j++]=pop();
    
  pf[j]='\0';
  
  printf("\n\nPostfix expression is %s",pf);

  return 0;
}
