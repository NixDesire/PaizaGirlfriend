#include <stdio.h>
int main(){
    int allN = 0, patternN = 0, //マスの大きさ
    i = 0, j = 0, //loop
    searchNum = 0,
    ansN = 0, ansM = 0, //回答座標格納用
    checki = 0, checkj = 0,
    trueCheck[11][11] = {{0}},
    trueChecki = 0, trueCheckj = 0,
    trueCount = 0,
    reseti = 0, resetj = 0,
    allPixel[100][100] = {{0}}, patternPixel[10][10] = {{0}};

    scanf("%d", &allN);
    for(i = 0; i < allN; i++)
        for(j = 0; j < allN; j++)
            scanf("%d", &allPixel[i][j]);
    scanf("%d", &patternN);
    for(i = 0; i < patternN; i++)
        for(j = 0; j < patternN; j++)
            scanf("%d", &patternPixel[i][j]);
    searchNum = allN - patternN + 1; //パターン捜索回数の決定

    for(checki = 0; checki < searchNum; checki++){
        for(checkj = 0; checkj < searchNum; checkj++){
            for(i = 0; i < patternN; i++)
                for(j = 0; j < patternN; j++)
                    if(allPixel[i+checki][j+checkj] == patternPixel[i][j])
                        trueCheck[i][j] = 1;
            for(trueChecki  = 0; trueChecki < patternN; trueChecki++)
                for(trueCheckj = 0; trueCheckj < patternN; trueCheckj++)
                    if(trueCheck[trueChecki][trueCheckj] == 1)
                        trueCount++;
            if(trueCount == patternN*patternN){
                ansN = checki;
                ansM = checkj;
            }
            trueCount = 0;
            for(reseti = 0; reseti < patternN; reseti++)
                for(resetj = 0; resetj < patternN; resetj++)
                    trueCheck[reseti][resetj] = 0;
        }
    }
    printf("%d %d\n", ansN, ansM);
    return 0;
}