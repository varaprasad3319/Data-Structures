#include <stdio.h>
int main(){
   int i, first, last, middle, n, search, array[100];
   printf("Enter number of elements :: ");
   scanf("%d",&n);
   printf("\nEnter %d integers :: \n", n);
   for ( i = 0 ; i < n ; i++ )
   {
       printf("\nEnter %d value :: ", i+1);
       scanf("%d",&array[i]);
   }

   printf("\nEnter value to search :: ");
   scanf("%d",&search);
    first = 0;
   last = n - 1;
   middle = (first+last)/2;
    while( first <= last ){
        if ( array[middle] < search )
                first = middle + 1;
        else if ( array[middle] == search ) {
                printf("\n %d found at location %d.\n", search, middle+1);
                break;
        }
        else
                last = middle - 1;
        middle = (first + last)/2;
   }
   if ( first > last )
      printf("Not found! %d is not present in the list.\n", search);
return 0;
}
