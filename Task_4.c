// HackerRank (for loop in c )

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    for(int i = a; i < b+ 1; i++){
        if(i <= 9){
            if(i == 1){
                printf("one");
            }
            else if (i == 2){
                printf("two");
            }
            else if (i == 3){
                printf("three");
            }
            else if (i == 4){
                printf("four");
            }
            else if (i == 5){
                printf("five");
            }
            else if (i == 6){
                printf("six");
            }
            else if (i == 7){
                printf("seven");
            }
            else if (i == 8){
                printf("eight");
            }
            else if (i == 9){
                printf("nine");
            }
        }
        else{
            if (i%2 == 0){
                printf("even");
                
            }
            else{
                printf("odd");
            }
        }
        printf("\n");
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// HackerRank (conditional statements in c )
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    // Write Your Code Here
    if( n == 1){
        
        printf("one");
    }
    else if (n == 2){
        printf("two");
    }
    else if (n == 3){
        printf("three");
    }
    else if (n == 4){
        printf("four");
    }
    else if (n == 5){
        printf("five");
    }
    else if (n == 6){
         printf("six");
    }
    else if (n == 7){
         printf("seven");
    }
    else if (n == 8){
         printf("eight");
    }
    else if (n == 9){
         printf("nine");
    }
    else{
        printf("Greater than 9");
    }

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COde for win (if statement ) 
// Problem 4
#include <stdio.h>
 int main() {
    int num ;
    printf("Enter  number :" );
    scanf("%d", &num);
    if (num % 5 == 0 && num % 11 == 0)
        printf("Number is divisible by 5 and 11");
    else
        printf("Number is not divisible by 5 and 11");
    return 0;
 }

// problem 7 
#include <stdio.h>
 int main() {
    char ch;
    printf("Enter anything :" );
    scanf("%c", &ch);
    if ( ch >= 'A' && ch <= 'Z' )
        printf("the input is an alphabet \n");
    else if ( ch >= 'a' && ch <= 'z' )
        printf("Your input is an alphabet\n");
    else
        printf("your input is not an alphabet\n");
    return 0;
 }
// problem 8 
#include <stdio.h>
 int main() {
    char ch;
    printf("Enter an alphabet charchter:" );
    scanf("%c", &ch);
    if ( ch == 'A' || ch == 'O' || ch == 'I' || ch == 'E' || ch == 'U' || ch == 'a' || ch == 'o' || ch == 'i' || ch == 'e' || ch == 'u' )
        printf("this is a vowel \n");
    
    else
        printf("This charchter is consontant\n");
    return 0;
 }
// problem 12
#include <stdio.h>
 int main() {
    int month_number;
    printf("Enter month number:" );
    scanf("%d", &month_number);
    if (month_number == 1)
        printf("31\n");
    else if(month_number == 2){
        printf("28\n");
    }
    else if(month_number == 3){
        printf("31\n");
    }
    else if(month_number == 4){
        printf("30\n");
    }
    else if(month_number == 5){
        printf("31\n");
    }
    else if(month_number == 6){
        printf("30\n");
    }
    else if(month_number == 7){
        printf("31\n");
    }
    else if(month_number == 8){
        printf("31\n");
    }
    else if(month_number == 9){
        printf("30\n");
    }
    else if(month_number == 10){
        printf("31\n");
    }
    else if(month_number == 11){
        printf("30\n");
    }
    else if(month_number == 12){
        printf("31\n");
    }
    else{
        printf("Invalid month number\n");
    }
    
    return 0;
 }
// problem 14
#include <stdio.h>
 int main() {
    int side1 , side2 , side3;
    printf("Enter triangle dimensions:" );
    scanf("%d %d %d", &side1, &side2, &side3);
    if ((side1 + side2) >= side3 && (side1 + side3) >= side2 && (side2 + side3) >= side1) {
        printf("Triangle\n");
    } else {
        printf("Not a triangle\n");
    }
 }
// problem 16
#include <stdio.h>
 int main() {
    int side1 , side2 , side3;
    printf("Enter triangle dimensions:" );
    scanf("%d %d %d", &side1, &side2, &side3);
    if (side1 == side2 && side2 == side3) {
        printf("Equilateral triangle\n");
    } else if (side1 == side2 || side2 == side3 || side1 == side3) {
        printf("Isosceles triangle\n");
    } else {
        printf("Scalene triangle\n");
    }
    return 0;
 }
// problem 19
#include <stdio.h>
char  calculate_grade(int subject );
int calculate_percentage (int subject);
 int main() {
    int math , biology , physics , chemistry , computer;
    printf("Enter marks of math, biology, physics, chemistry and computer: ");
    scanf("%d %d %d %d %d", &math, &biology, &physics, &chemistry, &computer);
    printf("Your grade and percentage is: \n");
    printf("Math: %c %d\n", calculate_grade(math), calculate_percentage(math));
    printf("Biology: %c %d\n", calculate_grade(biology), calculate_percentage(biology));
    printf("Physics: %c %d\n", calculate_grade(physics), calculate_percentage(physics));
    printf("Chemistry: %c %d\n", calculate_grade(chemistry), calculate_percentage(chemistry));
    printf("Computer: %c %d\n", calculate_grade(computer), calculate_percentage(computer));
    return 0;

    
 }
 int calculate_percentage (int subject){
    return (subject / 100.0) * 100;
 }
 char  calculate_grade(int subject ){
    if (subject >= 90) {
        return 'A';
    } else if (subject >= 80) {
        return 'B';
    } else if (subject >= 70) {
        return 'C';
    } else if (subject >= 60) {
        return 'D';
    } else if (subject >= 40) {
        return 'E';
    } else {
        return 'F';
    }
 }
// problem 20 
#include <stdio.h>
int main (){
    int bsic_salary, gross_salary , da , hdr;
    printf("Enter basic salary: ");
    scanf("%d", &bsic_salary);
    if (bsic_salary <= 10000){
        da = bsic_salary * 0.8;
        hdr = bsic_salary * 0.2;
    }
    else if (bsic_salary <= 20000){
        da = bsic_salary * 0.9;
        hdr = bsic_salary * 0.25;
    }
    else{
        da = bsic_salary * 0.95;
        hdr = bsic_salary * 0.3;
    }
    gross_salary = bsic_salary + da + hdr;
    printf("Gross salary is: %d", gross_salary);
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// code for win (Switch case problem)
// problem 1 
#include <stdio.h>
int main() {
    int day ;
    printf("Enter a day of the week: ");
    scanf("%d", day);
    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day\n");
    }

    return 0;
}
// prblem 7 
#include <stdio.h>
int main() {
   int a , b , c;
   printf("Enter the values of teh quadratic equation\n"); 
    scanf("%d %d %d", &a, &b, &c); 
    printf("The quadratic equation is %dx^2 + %dx + %d\n", a, b, c); 
    int d = b*b - 4*a*c;
    switch (d > 0) {
        case 1:
            printf("The roots are real and distinct\n");
            break;
        case 0:
        switch (d < 0) {
                    case 1:
                        printf("The roots are imaginary\n");
                        break;
                    case 0:
                        printf("The roots are real and equal\n");
                        break;
                }
                break;
        }            
    return 0;
}

// problem 8
#include <stdio.h>
int main() {
   int num1 , num2;
   char op;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the operator: ");
    scanf(" %c", &op);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    switch(op) {
        case '+':
            printf("The sum  is %d\n", num1, num2, num1+num2);
            break;
        case '-':
            printf("The difference  is %d\n", num1, num2, num1-num2);
            break;
        case '*':
            printf("The product  is %d\n", num1, num2, num1*num2);
            break;
        case '/':
            printf("The division  is %d\n", num1, num2, num1/num2);
            break;
        default:
            printf("Invalid operator\n");
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CodeForWin (Loop problems )
// problem 2
int main() {
    int n ;
    printf ("Enter a number: ") ;
    scanf ("%d", &n) ;
    for (int i = n; i > 0; i--) {
        printf ("%d\n", i) ;
    }
    return 0;
}
// problem 5 
#include <stdio.h>
int main() {
    for (int i = 0; i < 100; i++) {
        if (i % 2 != 0) {
            printf("%d\n", i);
        }
    }
}
// problem 6 
#include <stdio.h>
int main() {
    int n , sum = 0; 
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 0; i <n ; i++) {  
        sum = n + sum ;
    }
    printf("Sum = %d", sum);
    return 0;
}
// problem 9 
#include <stdio.h>
int main() {
    int n ;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 0; i <=12 ; i++) {  
       printf("%d x %d = %d\n", n, i, n * i);
    }
    return 0;
}
// problem 15 
#include <stdio.h>
int main() {
    int n ,prod , digit;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n >0){
        digit = n % 10;
        prod = prod * digit;
        n = n / 10;
    }
    printf("Product of digits: %d", prod);
    return 0;
}
// problem 16 
#include <stdio.h>
int main() {
    int n ,reverse = 0, digit;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n >0){
        digit = n % 10;
        reverse = reverse * 10;
        reverse = reverse + digit;
        n = n / 10;
    }
    printf("reverse of the number: %d", reverse);
    return 0;
}
// problem 21 
#include <stdio.h>
int main() {
    int num , pow , res = 1;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter power: ");
    scanf("%d", &pow);

    for (int i = 0 ; i < pow ; i++){
        res = res *num; 
    }
    printf("The power %d of number %d is : %d",pow , num, res);
    return 0;
}

// problem 40 
#include <stdio.h>
#include <math.h>
int main() {
    int bin , dec = 0;
    printf("Enter binary number: ");
    scanf("%d", &bin);
    int n = 0;
   while(bin != 0){
    if (bin% 10 == 1 )
    {
        dec = dec + pow(2,n); 
        bin = bin /10;
    }
    n++;
   }
   printf("Decimal number is: %d", dec);
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
