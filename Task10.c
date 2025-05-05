// E_count
#include <stdio.h>

int main(){
    char str[1000000];
    scanf("%s", &str);
    int i =0, sum =0;
    while(str[i] != '\0'){
        sum += str[i] -'0';
        i++;
    }
    printf("%d", sum);
}
//////////////////////////////////////////////////////////////////////
// G
#include <stdio.h>
#include <ctype.h>
int main(){
    char str[100000];
    scanf("%s", &str);
    int i =0;
    while(str[i] != '\0'){
        if(str[i] == ','){
            str[i] = ' ';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i]= tolower(str[i]);
        }
        else{
            str[i]  = toupper(str[i]);
        }
        i++;
    }
    printf("%s", str);
}
////////////////////////////////////////////////////////////////////////////
// I
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
    char str[1001];
    scanf("%s", &str);
    int i =0;
    int len =strlen(str);
    for(i = 0 ; i < len/2; i++)
    {
        if(str[i] != str[len-i-1]){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}
/////////////////////////////////////////////////////////////////////////////////
// O
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    char*str = malloc(sizeof(char)*(n+1));
    scanf("%s", str);
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j < n-i-1 ;j++)
        {
            if(str[j] > str[j+1]){
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
    printf("%s", str);
    free(str);
}
//////////////////////////////////////////////////////////////////////////////////////
//R
#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char S[N + 1];
    scanf("%s", S);

    int score = 0;
    int i = 0;

    while (i < strlen(S)) {
        if (S[i] == 'V') {
            score += 5;
            i++;
        } else if (S[i] == 'W') {
            score += 2;
            i++;
        } else if (S[i] == 'X') {
            if (i + 1 < strlen(S)) {
                for (int j = i + 1; j < strlen(S); j++) {
                    S[j] = S[j + 1];
                }
            }
            i++;
        } else if (S[i] == 'Y') {
            if (i + 1 < strlen(S)) {
                char next = S[i + 1];
                int len = strlen(S);
                for (int j = i + 1; j < len; j++) {
                    S[j] = S[j + 1];
                }
                S[len - 1] = next;
                S[len] = '\0';
            }
            i++;
        } else if (S[i] == 'Z') {
            if (i + 1 < strlen(S)) {
                if (S[i + 1] == 'V') {
                    score /= 5;
                    for (int j = i + 1; j < strlen(S); j++) {
                        S[j] = S[j + 1];
                    }
                } else if (S[i + 1] == 'W') {
                    score /= 2;
                    for (int j = i + 1; j < strlen(S); j++) {
                        S[j] = S[j + 1];
                    }
                }
            }
            i++;
        } else {
            i++;
        }
    }

    printf("%d", score);
    return 0;
}
