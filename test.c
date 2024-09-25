#include <stdio.h> 
int sum(int *p,int n);
int main(){
int a[20],i,n,*p;
    printf("Enter number of elements: \n");
    scanf("%d", &n);
    p=a;
    printf("Enter element: \n");
    for(i=0;i<n;i++)
        scanf("%d", (p+i));
    sum(p,n);
}
int sum(int *p,int n){
    int s,i;
    for(i=0;i<n;i++)
        s+=*(p+i);
    printf("Sum: %d",s);
}