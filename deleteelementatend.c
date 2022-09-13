#include <stdio.h>
void main()
{
    int position, i, n, value,ch;
    printf("C Program to delete element at end of Array\n");
    printf("First enter number of elements you want in Array\n");
    scanf("%d", &n);
    int arr[n];
   for(i = 0; i < n; i++)
    {
        printf("Please give value for index %d : ",i);
        scanf("%d",&arr[i]);
    }
    value=arr[n-1]; //assigning last value in value variable
    printf("Element %d is deleting at %d index \n",value,n-1);
    n=n-1;//here decreasing value to reduce size of array
    printf("New Array after deleting element at end \n ");
    for(i = 0; i < n; i++)
    {
       printf("%d \t",arr[i]);
    }
}
