// codeforwin array 1
#include <stdio.h>


int main() {
    int size; 
    printf("Enter input size:");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements:");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}
////////////////////////////////////////////////////////////////////
// CodeForWin array(2)
#include <stdio.h>


int main() {
    int size; 
    printf("Enter input size:");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements:");
    int sum =0;
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        sum +=arr[i];
    }
    printf("The sum = %d", sum);

    
    
    
}
////////////////////////////////////////////////////////////////
//CodeForWin array (5)
#include <stdio.h>


int main() {
    int size; 
    printf("Enter input size:");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements:");

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    } 
    int max=0 ,second_max = -1;
   for(int i =0; i < size; i++)
   {
    if(arr[i] > max)
    {
        second_max = max ;
        max = arr[i];
    }
    else if(arr[i] < max && arr[i] > second_max)
    {
        second_max = arr[i];
    }
   }
   printf("Second largest : %d", second_max);
  
    
}
// array (8)
#include <stdio.h>


int main() {
    int size; 
    printf("Enter input size:");
    scanf("%d", &size);
    int arr1[size], arr2[size];
    printf("Enter elements:");

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    } 
    printf("First array:");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\nDuplicate array:");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr2[i]);
    }
}
// array(9)
#include <stdio.h>
int main() {
    int size; 
    printf("Enter input size:");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements:");

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    } 
    printf("enter the element and position(element , position)");
    int elem, pos;
    scanf("%d %d", &elem , &pos);
    arr[pos-1] = elem;
    printf("Updated array:");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
//array(13)
#include <stdio.h>
int main() {
    int size; 
    printf("Enter input size:");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements:");

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    } 
    int count =0;
    for(int i = 0; i < size; i++)
    {
       for(int j = i +1; j< size; j++)
       {
        if(arr[i] == arr[j])
        {
            count++;
        }
       }
    }
}
//array(15)
#include <stdio.h>
int main() {
    int s1, s2; 
    printf("Enter first array size:");
    scanf("%d", &s1);
    printf("Enter second array size:");
    scanf("%d", &s2);
    int s3 = s1 + s2;
    int arr1[s1], arr2[s2], arr3[s3];
    printf("Enter first array elements:");
    for(int i = 0; i < s1; i++)
    {
        scanf("%d", &arr1[i]);
    } 
    printf("Enter second array elements:");
    for(int i = 0; i < s2; i++)
    {
        scanf("%d", &arr2[i]);
    } 
    int index1 =0 , index2=0, mIndex;
    for(mIndex = 0; mIndex < s3; mIndex++)
    {
        if(index1 >= s1 || index2 >= s2)
        {
            break;
        }
        if(arr1[index1] > arr2[index2])
        {
            arr3[mIndex] = arr2[index2];
            index2++;
        }
        else
        {
            arr3[mIndex] = arr1[index1];
            index1++;
        }


    }
    while(index1 < s1)
    {
        arr3[mIndex] = arr1[index1];
        mIndex++;
        index1++;
    }
    while(index2 < s2)
    {
        arr3[mIndex] = arr2[index2];
        mIndex++;
        index2++;
    }
    printf("THE MERGED ARRAY: ");
    for(int i = 0; i < s3; i++)
    {
        printf("%d", arr3[i]);
    }
     
}
//array(16)
#include <stdio.h>
int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size] , rev_arr[size];
    printf("Enter elements: ");
    for(int i =0; i < size; i++)
    {
        scanf("%d", arr[i]);
    }
    int index= 0;
    for(int i = size-1; i >= 0; i--)
    {

        rev_arr[index] = arr[i];
        index++;
    }
    printf("The reverse array: ");
    for(int i =0; i < size; i++)
    {
        printf("%d", rev_arr[i]);
    }

}
// array(19)
#include <stdio.h>
int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size] ;
    printf("Enter elements: ");
    for(int i =0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i =0 ; i< size; i++)
    {
        for(int j = i +1; j < size; j++)
        {
            int temp;
            if(arr[i] > arr[j])
            {
                temp     = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\n sorted array: ");

    for(int i =0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

}
////////////////////////////////////////////////////////////////////
// matrix (24)
#include <stdio.h>
int main() {
    int size= 3 ;
    int mat1[size][size] , mat2[size][size], diff[size][size];
    printf("Enter elements(1-9): ");
    for(int i =0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter elements for the second matrix(1-9): ");
    for(int i =0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    for(int i =0 ; i< size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            diff[i][j]= mat1[i][j] - mat2[i][j];
        }
    }
    printf("\n Difference matrix:\n ");
    for(int i =0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }
    
}
// matrix (27)
#include <stdio.h>
int main() {
    int size= 3 ;
    int mat1[size][size] , mat2[size][size];
    printf("Enter elements(1-9): ");
    for(int i =0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter elements for the second matrix(1-9): ");
    for(int i =0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    int match = 1;
    for(int i =0 ; i< size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(mat1[i][j] != mat2[i][j])
            {
                match = -1;
                break;
            }
        }
    }
    if(match == 1)
    {
        printf("Matrices match !! ");


    }
    else{
        printf("Matrices do not match !! ");
    }
    
    
}
// matrix (30)
#include <stdio.h>
int main() {
    int size= 3 ;
    int mat[size][size];
    printf("Enter elements(1-9): ");
    for(int i =0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    int sum ;
    for(int i =0; i < size; i++)
    {
        sum = 0;
        for(int j = 0; j < size; j++)
        {
            sum += mat[i][j]
        }
        printf("Sum of elements in the row %d = %d" , i , sum);
        
    }
    for(int i =0; i < size; i++)
    {
        sum = 0;
        for(int j = 0; j < size; j++)
        {
            sum += mat[j][i]
        }
        printf("Sum of elements in the column %d = %d" , i , sum);
        
    }
    
}
// matrix (37)
#include <stdio.h>
int main() {
    int size= 3 ;
    int mat[size][size];
    printf("Enter elements(1-9): ");
    for(int i =0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    int det = (mat[0][0]*(mat[1][1]*mat[2][2] - mat[1][2]*mat[2][1]))-
                (mat[0][1]*(mat[1][0]*mat[2][2] - mat[1][2]*mat[2][0]) - (mat[0][2]*(mat[1][0]*mat[2][1]- mat[1][1]*mat[2][0])));
    printf("The determinant of the matrix = %d", det);
}
///////////////////////////////////////////////////////////////////////////
// hackerRank 1D array
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
      int n;
      scanf("%i" , &n);
      int *arr = (int*)malloc(n*sizeof(int));
      int sum = 0;
      for(int i = 0; i < n ; i++)
      {
        scanf("%i", &arr[i]);
        sum = sum +arr[i];
      }
      printf("%i", sum);
      free(arr);
    return 0;
}



