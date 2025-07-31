#include<stdio.h>
void ibegin(int a[50],int *n);
void iend(int a[50],int *n);
void ipos(int a[50],int *n);
void dbegin(int a[50],int *n);
void dend(int a[50],int *n);
void dpos(int a[50],int *n);
void del(int a[50],int *n);
void display(int a[50],int n);
//basic program to grasp the concept of arrays
void main()
{ int a[50],x,n,i;
   printf("Enter the no of elements = ");
   scanf("%d",&n);
   printf("Enter the elements = ");
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   for (i=1;i>0;i++)   
  { printf("\n1.INSERT AT START\n2.INSERT AT END\n3.INSERT AT A POSITION\n4.DELETE FROM START\n5.DELETE FROM END\n6.DELETE AT POSITION\n7.DELETE AN ELEMENT\n8.DISPLAY ARRAY\n9.EXIT\nEnter you choice = ");
scanf("%d",&x);
if (x==9)
  break;
switch(x)
  {  case 1 : ibegin(a,&n);
              break;
     case 2 : iend(a,&n);
              break; 
     case 3 : ipos(a,&n);
              break; 
     case 4 : dbegin(a,&n);
              break; 
     case 5 : dend(a,&n);
              break; 
     case 6 : dpos(a,&n);
              break;
     case 7 : del(a,&n);
              break; 
     case 8 : display(a,n);
              break;
     default : printf("You have entered invalid number");
               break;                                                                           
  }
 }    
}
//func to insert at beginning
void ibegin(int a[50],int *n){ 
   for(int i=*n;i!=0;i--)
      a[i]=a[i-1];
   printf("Enter the element = ");
   scanf("%d",&a[0]);
   printf("New Array = ");
   *n = *n+1;
   for(int i=0;i<*n;i++)
      printf("%d ",a[i]);
   printf("\n");
}     
void iend(int a[50],int *n){ 
  printf("Enter the element = ");
  scanf("%d",&a[*n]);
  printf("New Array = ");
   *n = *n+1;
   for(int i=0;i<*n;i++)
      printf("%d ",a[i]);
   printf("\n");  
}  
void ipos(int a[50],int *n){ 
  int i,x;
  printf("What position do you want to enter the element = ");
  scanf("%d",&x);
  for(i=*n;i!=x-1;i--)
    a[i]=a[i-1];
  printf("Enter the element = ");
   scanf("%d",&a[x-1]);
  printf("New Array = ");
   *n = *n+1;
   for(i=0;i<*n;i++)
      printf("%d ",a[i]);
   printf("\n"); 
   
 }      
 void dbegin(int a[50],int *n){
   int i;
    for(i=0;i<*n;i++)
       a[i]=a[i+1];
    *n = *n-1;
    printf("New Array = ");
   for(i=0;i<*n;i++)
      printf("%d ",a[i]);
   printf("\n");
 }        
void dend(int a[50],int *n){
   int i;
   *n=*n-1;
   printf("New Array = ");
   for(i=0;i<*n;i++)
      printf("%d ",a[i]);
   printf("\n");
}   
void dpos(int a[50],int *n){
   int i,x;
  printf("Which position of element do you want to delete = ");
  scanf("%d",&x);
  for(i=x-1;i<*n;i++)
     a[i]=a[i+1];
  *n = *n-1;
  printf("New Array = ");
   for(i=0;i<*n;i++)
      printf("%d ",a[i]);
   printf("\n");
 }         
void del(int a[50],int *n){
   int i,x,y,flag=0;
   printf("Enter the element you want to delete = ");
   scanf("%d",&x);
   for(i=0;i<*n;i++)
      if (a[i]==x)
           { y = i+1;
             flag = 1;
             break;
            }
   if (flag==0)           
       printf("Element is not present\n");
   else{
      for(i=y-1;i<*n;i++)
         a[i]=a[i+1];
      *n = *n-1;
      printf("New Array = ");
      for(i=0;i<*n;i++)
         printf("%d ",a[i]);
      printf("\n"); 
     }
}            
void display(int a[50],int n){
   int i;
   printf("Array = ");
   for(i=0;i<n;i++)
      printf("%d ",a[i]);
   printf("\n");
}     
