#include <stdio.h>

int main(){
    int n = 0;
    int i = 0;
    int sum = 1;
    scanf("%d", &n);

    for(i = n; i > 1; i--){
        sum *= i;
    }
    printf("%d\n", sum);
    return 0;
}
