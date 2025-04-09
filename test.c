#include <stdio.h>

int sum = 1;

void num(int n) {
    if(n <= 0) {
        return;
    }
    
    num(n-1);
    sum *= n;
}

void f(int n) {
    if(n <= 0) {
        return;
    }

    f(n-1);
    num(n);
}

int main() {
    
    int n;

    scanf("%d", &n);
    f(n);

    return 0;
}
