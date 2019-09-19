#include<stdio.h>
#include<stdlib.h>

   struct datastack{
   int top;
   int capacity;
   int *array;
};

//function to create stack..
struct datastack* Createstack(int cap)
{
    struct datastack *stack;
    stack=malloc(sizeof(struct datastack));
    stack->capacity=cap;
    stack->top=-1;
    stack->array=malloc(sizeof(int)*stack->capacity);
    return(stack);

}
int isfull(struct datastack *stack)
{
    if(stack->top==(stack->capacity)-1)
        return(1);
    else
        return(0);
}
int isempty(struct datastack *stack)
{
    if(stack->top==-1)
        return(1);
    else
        return(0);
}
//for push in stack...
void push(struct datastack *stack,int item)
{
   if(!isfull(stack))
   {    stack->top++;
       stack->array[stack->top]=item;

   }

}
//for pop in stack
int pop(struct datastack *stack)
{    int item;
    if(!isempty(stack))
    {
        item=stack->array[stack->top];
        stack->top--;
        return(item);
    }
}
main()
{
  struct datastack *stack;
  int n;
  int s;
  int i;
  int item;
  int t;




  printf("Enter the size of stack");
  scanf("%d",&s);
  stack=Createstack(s);
  while(1){
        printf("__________________________________________________________________________________________\n");


  printf("enter your choice\n");
  printf("1.pop\n");
  printf("2.push\n");
  printf("3.Show stack\n");
  printf("4.exit\n");
  printf("_____________________________________________________________________________________________\n");
  scanf("%d",&n);
  switch(n)
  {
    case 1:if(stack->top==-1)
            printf("stack is empty\n");
            else
          {
           item= pop(stack);
           printf("poped  %d\n",item);
          }
           break;


    case 2:if(stack->top!=stack->capacity-1)
    {
           printf("Enter the value to be pushed\n");
           scanf("%d",&item);
           push(stack,item);
           printf("%d pushed\n",item);
    }
    else
        printf("stack is full\n");
         break;

    case 3 :printf("stack so far is:\n");
            t=stack->top;
           while(stack->top!=-1)
             {
                 printf("%d\n",stack->array[stack->top--]);

             }
             stack->top=t;
             break;

    case 4:exit(0);
  }
  }
  getch();

}

