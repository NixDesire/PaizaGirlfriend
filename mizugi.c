/*
階乗とは数学の演算の一つで、N の階乗をN! と書きます。N が自然数であるとき、階乗は次のように計算できます。

N! = N * (N - 1) * ... * 2 * 1

N が与えられたとき、N! のすべての桁の代わりに、N! の最下位桁から続く0 をすべて除いた値の下位9桁を求めるプログラムを作成してください。
9桁ではあるが先頭が0であるような場合は先頭の0を取り除いた値を出力してください。先頭に0のついた値を出力すると誤答となります。
 */

#include <stdio.h>
#include <stdlib.h>
#define N 100000
int main(){
    int sum[N] = {0}; //100桁の数字を扱う
    int n = 0;
    int j = 0;
    int i = 0;
    int carry = 0;
    int destroyFlag = 0;
    int max = 0;
    int min = 0;
    int strI = 0;
    int box[9] = {0};
    int strZero = 0;
    int count1 = 0, count2 = 0;

    sum[0] = 1;

    scanf("%d", &n);

    // 階乗計算
    for(i = 1; i <= n; i++){
        count1++;
        carry = 0;
        //printf("\nI=%d\t\n", i);
        // 全ての桁に対して計算する
        for(j = 0; j < N; j++){
            sum[j] *= i; //現在の桁をi倍
            //printf("sum[j] *= i : %d\t", sum[j]);
            sum[j] += carry; //キャリーの加算
            //printf("sum[j] += carry : %d\t", sum[j]);
            carry = sum[j] / 10; //キャリーの取得
            //printf("carry : %d\t", carry);
            sum[j] %= 10;
            //printf("ans : %d\t", sum[j]);
        }
        printf("\nEND\n");
    }
    printf("startdestroy0\n");
    // 不要な先頭の0を破壊
    while(destroyFlag == 0){
        for(i = N-1; i >=0; i--){
            if(sum[i] != 0){
                destroyFlag = 1;
                max = i;
                printf("END\n");
                break;
            }
            if(i == 0){
                printf("all0!!!!!\n");
                destroyFlag = 1;
                break;
            }
            printf("startdestroyloopI=%d\n", i);
        }
        printf("startdestroywhile\n");
    }
    printf("enddestroy0\n");
    destroyFlag = 0;
    // 不要な末尾の0を破壊
    while(destroyFlag == 0){
        for(i = 0; i < N; i++){
            if(sum[i] != 0){
                destroyFlag = 1;
                min = i;
                printf("END\n");
                break;
            }
            if(i+1 == N){
                printf("all0!!!!!\n");
                destroyFlag = 1;
                break;
            }
            printf("enddestroyloopI=%d\n", i);
        }
        printf("enddestroywhile\n");
    }
    printf("\n");

    for(i = max; i >= min; i--){
        printf("%d", sum[i]);

    }
    printf("\n");

    for(i = min+8, strI = 8; i >= min; i--, strI--){
    //    printf("%d", sum[i]);
        box[strI] = sum[i];
    }
    //printf("\n");

    for(i = 8; i >= 0; i--){

        printf("%d", box[i]);
    }
    printf("\n");

    destroyFlag = 0;
    while(destroyFlag == 0){
        for(i = 8; i >= 0; i--){
            if(box[i] != 0){
                destroyFlag = 1;
                strZero = i;
                break;
            }
        }
    }

    for(i = strZero; i >= 0; i--){
        printf("%d", box[i]);
    }
    printf("\n%d\n", n);
    return 0;
}
