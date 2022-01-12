#include <stdio.h>

int check (char c) {        
    int i;
    char a[6] = "+-*/:";
    for (i=0; a[i]; i++)
        if (a[i] == c) return i+1;
    return 0;
}
 
int main (void) {
    char c;
    float a, b, result;
    int d;
 
    while(1) {
        printf("> ");   
        scanf("%f %c %f", &a, &c, &b);
        fflush(stdin);
        if ((d = check(c)) > 0) break;
    }
 
    if (d == 1) result = a+b;
    if (d == 2) result = a-b;
    if (d == 3) result = a*b;
    if (d > 3) {
        if (!b) return -1;     
        result = a/b;
    }
 
    printf("%f %c %f = %f\n", a, c, b, result);
    return 0;
}
