#include <stdio.h>

int main(){
    int colorLength = 0; //各色長
    int allLength = 0; //表示長
    int colorFlag = 0; //色フラグ
    int redCounter = 0;
    int whiteCounter = 0;
    int i = 0; //ループカウンタ
    scanf("%d", &colorLength);
    scanf("%d", &allLength);

    for(i = 0; i < allLength; i++){
        if(colorFlag == 0){
            printf("R");
            redCounter++;
        }else{
            printf("W");
            whiteCounter++;
        }

        // 各色長に達したらフラグを反転
        if(redCounter == colorLength || whiteCounter == colorLength){
            redCounter = 0;
            whiteCounter = 0;
            colorFlag = !colorFlag; //フラグを反転
        }
    }
    printf("\n");
}
