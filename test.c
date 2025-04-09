#include <stdio.h>

void star(int n) {
    if(n <= 0) {
        return;
    }
  
    star(n-1);
    printf("%d", n);
}

void f(int n) {
    if(n <= 0) {
        return;
    }

    f(n-1);
    star(n);
    printf("\n");
}

int main() {
    
    int n;

    scanf("%d", &n);
    f(n);

    return 0;
}
