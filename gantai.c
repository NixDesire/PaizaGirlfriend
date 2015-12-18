// 眼帯

#include <stdio.h>

int main(){
    int allNum = 0; //巻の総数
    int myBookNum = 0; //所持巻数
    int myBookList[1000] = {0}; //所持巻数リスト
    int usedBookNum = 0; //中古巻数
    int usedBookList[1000] = {0}; //中古巻数リスト
    int myBookBooleanList[1000] = {0}; //所持巻フラグテーブル
    int usedBookBooleanList[1000] = {0}; //中古巻フラグテーブル
    int checkFlag = 0; //買うべき巻があるのかどうかのフラグ
    int firstFlag = 0; //初回表示処理用
    int i = 0; //ループカウンタ

    // 入力--------------------------------
    scanf("%d", &allNum);
    scanf("%d", &myBookNum);
    for(i = 0; i < myBookNum; i++){
        scanf("%d", &myBookList[i]);
    }
    scanf("%d", &usedBookNum);
    for(i = 0; i < usedBookNum; i++){
        scanf("%d", &usedBookList[i]);
    }

    // 1~N巻まで所持しているのかどうかをフラグテーブルで管理
    for(i = 0; i < myBookNum; i++){
        myBookBooleanList[myBookList[i] - 1] = 1;
    }

    for(i = 0; i < usedBookNum; i++){
        usedBookBooleanList[usedBookList[i] - 1] = 1;
    }

    // フラグテーブルを比較して中古のみ1のものを表示する
    for(i = 0; i < allNum; i++){
        if(myBookBooleanList[i] == 0 && usedBookBooleanList[i] == 1){
            if(firstFlag == 1){
                printf(" %d", i + 1);
            }else{
                firstFlag = 1;
                printf("%d", i + 1);
            }
            checkFlag = 1;
        }
    }
    // 買うべきものが無ければ
    if(checkFlag == 0){
        printf("None\n");
    }
    // 表示整理用
    else{
        printf("\n");
    }

    return 0;
}