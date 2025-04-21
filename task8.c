//Hacker Rank 
// Pointers in C 
include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    int sum = *a + *b;
    int sub = *a - *b;
    int absolute = abs(sub);
    *a = sum;
    *b = absolute;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// codeForWin problem 17
#include <stdio.h>
void sort(int *arr , int size){
     int *cur = arr ;
     int *next_element = arr + 1 ;
     int *arr_end = arr +size -1 ; 
     while (cur < arr_end){
        next_element = cur +1 ;
        while (next_element <=arr_end){
            if (*next_element < *cur)
            {
                int temp = *next_element;
                *next_element = *cur ;
                *cur = temp; 
            }
            next_element++;
        }
        cur++;
     }

}
int main (){
    int arr_len;
    printf("Enter the length of the array: ");
    scanf("%d", &arr_len);
    int arr[arr_len];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < arr_len; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr,arr_len);
    for(int i = 0; i < arr_len; i++){
        printf("%d ", arr[i]);
    }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// problem 18
#include <stdio.h>
#include <stdlib.h>
int *get_divisable(int *arr , int size , int divise ,int *result_size);
int main(){
    int size;
    printf("Enter the size of the array:");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int divise ;
    printf("enter the number you want your array to be divisable :");
    scanf("%d", &divise);
    int result_size ;
    int *result= get_divisable(arr, size , divise , &result_size);
    for(int i = 0; i < result_size; i++)
    {
        printf("%d ", *(result + i));
    }
    free(result);
    return 0;

}
int *get_divisable(int *arr , int size , int divise ,int *result_size){
    int *result = (int *)malloc(size * sizeof(int));
    int j = 0 ;
    for(int i= 0; i < size; i++)
    {
        if(arr[i] %divise == 0)
        {
            result[j] = arr[i];
            j++;

        }
    }
    *result_size = j;
    return result;
}
