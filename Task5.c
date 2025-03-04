/**************************************************************************************************************************************************************************/
//CodeForWin (functions prob.)
// problem 1
#include <stdio.h>
int main (){
 int num , cube;
 printf("Enter a number: ");
    scanf("%d", &num);
    cube = num * num * num;
    printf("Cube of %d is %d", num, cube);
    return 0;
}

// problem 2
#include <stdio.h>
void circle_func(int radius);
    int main(){
        int radius ;
        scanf("%d",&radius);
        circle_func(radius);
        return 0;

    }
    void circle_func(int radius){
        int diameter , area , circumference ;
        diameter = 2 * radius ;
        area = 3.14 * radius * radius ;
        circumference = 2 * 3.14 * radius ;
        printf("Diameter of the circle is %d\n",diameter);
        printf("Area of the circle is %d\n",area);
        printf("Circumference of the circle is %d\n",circumference);
    }
// problem 3
#include <stdio.h>
void max(int num1 ,int num2);
int main(){
    int num1 , num2 ;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    max(num1, num2);
    return 0;
}
void max(int num1 , int num2)
{
   num1 > num2 ? printf("Maximum: %d \nMinimum: %d", num1, num2) : printf("Maximum: %d \nMinimum: %d", num2 , num1 );
}


// problem 6 
#include <stdio.h>
#include <math.h>
void primes(int a ,int b);
int main(){
    int a , b ;
    printf("Enter intervals: ");
    scanf("%d %d", &a, &b);
    primes(a, b);
    return 0;
}
void primes(int num1, int num2)
{
   int i , j , isprime;
   for (i = num1; i <= num2; i++){
    isprime = 1;
    for (j = 2; j <= sqrt(i); j++){
        if(i % j == 0){
            isprime = 0;
            break;
        }
    }
    if(isprime == 1){
        printf("%d ", i);
    }
   }
    
}

// problem 8
#include <stdio.h>
#include <math.h>
int armstrong_check(int num);
int main(){
    int num ;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (armstrong_check(num)){
        printf("%d is an armstrong number", num);
    }
    else{
        printf("%d is not an armstrong number", num);
    }

}
int armstrong_check(int num){
    int temp = num;
    int sum =0 ;
    while (temp > 0){
        int rem = temp % 10;
        sum += pow(rem, 3);
    }
    if (sum == num){
        return 1;
    }
    else{
        return 0;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Recursion problem (12)
#include <stdio.h>

void odd_even_func(int a , int b);
int main(){
    int a , b ;
    printf("Enter the interval:");
    scanf("%d %d", &a, &b);
    odd_even_func(a , b);
    return 0;

}
void odd_even_func(int a , int b){
    if (a > b){
        return ;
    }
    printf("%d\n", a);
    odd_even_func(a +2 , b);
}

//problem 16 
#include <stdio.h>
int is_palindrome(int number);
int main(){
    int number ;
    printf("Enter a number: ");
    scanf("%d", &number);
    if(is_palindrome(number) == 1){
        printf("%d is a palindrome number.\n", number);
    }
    else{
        printf("%d is not a palindrome number.\n", number);
    }
}
int is_palindrome(int number){
    int reverse = 0 ;
    int temp = number ;
    while (temp> 0){
        reverse = reverse*10 + temp % 10 ;
        temp = temp / 10 ;
    }
    if (number == reverse){
        return 1;
    }
    else{
        return 0;
    }
}

// problem 17 
#include <stdio.h>
#include <math.h>
int is_palindrome(int number);
int reverse (int number);

int main(){
    int number ;
    printf("Enter a number: ");
    scanf("%d", &number);
    if(is_palindrome(number) == 1){
        printf("%d is a palindrome number.\n", number);
    }
    else{
        printf("%d is not a palindrome number.\n", number);
    }
}
int is_palindrome(int number){
    if(number == reverse(number)){
        return 1;
    }
    return 0;
}
int reverse (int number){
    int digits = (int)log10(number);
    if (number == 0){
        return 0;
    }
    return (number%10 * pow(10, digits) + reverse(number/10));
}
// problem 18
#include <stdio.h>

int factorial (int n);
int main() {
    int number ;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Factorial of %d = %d", number, factorial(number));
    return 0;
}
int factorial (int n) {
    if (n == 0){
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Hacker Rankk problems 
// Recursion in C
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c) {
  //Write your code here.
 if(n == 1){
    return  a;
 } 
 if (n ==2) return b ;
 if(n == 3 ) return c;
 return (find_nth_term(n-1, b, c, a + b + c));
}


int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}

//Students marks sum
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
  //Write your code here.
  int i ;
  if( gender == 'b') 
  {
    i = 0 ;
  }
  if(gender == 'g')
  {
    i = 1;
  }
  int sum = 0;
  for (int  j = i; j < number_of_students ; j+=2 ){
    sum += marks[j];
  }
  return sum;
}



int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}
    
