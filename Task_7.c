//CodeForWin problems 
// problem 5 
#include <stdio.h>
#define Max_size 100
int main(){
    int original[Max_size] ,  copy[Max_size] ;
    int *original_ptr ,  *copy_ptr;
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &original[i]);
    }
    original_ptr = original;
    copy_ptr = copy;
    for(int i = 0; i < size; i++){
        *copy_ptr = *original_ptr;
        copy_ptr++;
        original_ptr++;
    }
    printf("The elements of the original array are: ");
    for(int i = 0; i < size; i++){
        printf("%d ", original[i]);
    }
    printf("\n");
    printf("The elements of the copied array are: ");
    for(int i = 0; i < size; i++){
        printf("%d ", copy[i]);
    }
}
// problem 6
#include <stdio.h>
#define Max_size 100
void swap_array(int *ptr1, int *ptr2, int size1, int size2){
    int  temp;
    int n = size1 > size2 ? size1 : size2;
    for (int i =0 ; i < n; i++){
        temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        ptr1++;
        ptr2++;
    }


}
int main(){
    int array1[Max_size], array2[Max_size];
    int size1 , size2;
    int *ptr1 = array1, *ptr2 = array2;
    
    printf("Enter the size of the frist array:");
    scanf("%d", &size1);
    printf("Enter the elements of the array:");
    for(int i = 0; i < size1; i++){
        scanf("%d", &array1[i]);
    }
    printf("Enter the size of the seconed array:");
    scanf("%d", &size2);
    printf("Enter the elements of the array:");
    for(int i = 0; i < size2; i++){
        scanf("%d", &array2[i]);
    }
    swap_array(ptr1, ptr2, size1, size2);
    printf("The first array after swapping is:");
    for(int i = 0; i < size2; i++){
        printf("%d ", array1[i]);
    }
    printf("\nThe second array after swapping is:");
    for(int i = 0; i < size1; i++){
        printf("%d ", array2[i]);
    }

}

// problem 7
#include <stdio.h>
#define Max_size 100
void reverse(int *ptr , int size)
{
    int temp_array[size];
    int count = size -1;
    for (int i = 0; i < size; i++)
    {
        temp_array[i] = ptr[count];
        count --;
    }
    for (int i = 0; i < size; i++)
    {
        ptr[i] = temp_array[i];

}}
int main(){
    int array[Max_size];
    int size;
    int *ptr = array;
    printf("Enter the size of the  array:");
    scanf("%d", &size);
    printf("Enter the elements of the array:");
    for(int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    reverse(ptr, size);
    printf("The reversed array is:");
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }

}

// problem 8
#include <stdio.h>
#define Max_size 100
void search_element(int *ptr , int size , int search){
    int found = 0;
    for (int i = 0; i < size; i++){
        if(*ptr == search){
            printf("Element found at index %d", i);
            found = 1 ;
            break;

        }
        else{
            ptr++;
        }
    }
    if(!found){
        printf("Element not found");
    }
}
int main(){
    int array[Max_size];
    int size , search;
    int *ptr = array;
    printf("Enter the size of the  array:");
    scanf("%d", &size);
    printf("Enter the elements of the array:");
    for(int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    printf("Enter the element to search:");
    scanf("%d", &search);
    search_element(ptr, size, search);
    return 0;


}

// problem 11
#include <stdio.h>
#define Max_size 100
void matrix_multi(int mat1[][Max_size], int mat2[][Max_size], int row1, int col1, int row2, int col2) {
    int res[Max_size][Max_size];
    if(col1 != row2){
        printf("Matrix multiplication is not possible");
        
    }
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col2; j++){
            res[i][j] = 0;
            for(int k = 0; k < col1; k++){
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("The resultant matrix is:\n");
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col2; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int mat1[Max_size][Max_size], mat2[Max_size][Max_size], row1, col1, row2, col2;
    printf("Enter the dimensions of the matrix (row , column):");
    scanf("%d %d", &row1 , &col1);
    printf("Enter the elements of the matrix:");
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col1; j++)
            scanf("%d", &mat1[i][j]);
    }
    printf("Enter the dimensions of the matrix (row , column):");
    scanf("%d %d", &row2 , &col2);
    printf("Enter the elements of the matrix:");
    for(int i = 0; i < row2; i++){
        for(int j = 0; j < col2; j++)
            scanf("%d", &mat2[i][j]);
    }
     matrix_multi(mat1, mat2, row1, col1, row2, col2);
    return 0;


}

// problem 12
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main (){
    char *str;
    str = (char *)malloc(MAX);
    printf("Enter a string: ");
    int i ;
    for( i =0 ; i < MAX ;i++){
        scanf("%c", &str[i]);
        if(str[i] == '\n'){
            str[i] = '\0';
            break;
        }
    }
    printf("You entered: %s\n with length : %d", str, i);
    free(str);

}


// problem 14
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main (){
   int str1 [MAX], str2 [MAX];
   int *p1 = str1, *p2 = str2;
   printf("enter the first string: ");
   gets(str1);
    printf("enter the second string: ");
    gets(str2);
    while(*p1 != '\0'){
        p1 ++;
    }
    while(*p2 != '\0' )
    {
        *p1 = *p2;
        p1++;
        p2++;
    }
    printf("combined string: %s\n", str1);
    return 0;
}


// problem 16
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void reversed(char *p1 , char *p2){
   int count = 0;
   while (*p1 != '\0'){
    p1++;
    count ++;
   }
   p1--; 
   for(int i = 0; i < count; i++){
    *p2 = *p1;
    p1--;
    p2++;
   }
   *p2 = '\0';

}
int main (){
   char str1 [MAX], reverse [MAX] ;
   char *p1 = str1, *p2 = reverse;
   printf("enter the string: ");
   gets(str1);
    reversed(p1, p2);
    for (int i = 0; reverse[i] != '\0'; i++){
        printf("%c", reverse[i]);
    }

    return 0;

}

// Hacker Rank 
#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    int sum = *a + *b;
    int sub = *a - *b;
    int absolute = abs(sub);
    *a = sum ;
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


