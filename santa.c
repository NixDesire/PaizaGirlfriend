/******************************************************************************
 * @file santa.c
 * @brief
  幅 X cm、奥行き Y cm、高さ Z cm の直方体の形をしたケーキがあります。
 このケーキに「側面と平行な方向」および「前面と平行な方向」に何回か包丁を入れて
 小さなケーキに切り分けることを考えます。
 上面と平行な方向（水平方向）には包丁を入れません。
 包丁を入れる場所が与えられたとき、切り分けられたケーキの中で最も体積が小さいものを求めてください。
 * @author YudaiHondo
 * @date 2015/12/18
 *****************************************************************************************/

#include <stdio.h>

#define LONGITUDINAL 0 // @def 縦
#define BESIDE 1 // @def 横

/************************************************
 * @fn 最短距離解析関数
 * @param (int size) 最大幅(立体における)
 * @param (int *booleanFlag) 切り込み位置が1のint型の配列
 * @return 最短距離
 * @detail 詳細な説明
 *************************************************/
int shortestAnalysis(int size, int *booleanFlag){
    int distanceCount = 0; //距離計測
    int mostSmall = size; //最小長
    int i = 0; //ループカウンタ

    for(i = 0; i < size; i++){
        if(booleanFlag[i] == 0) //区間距離を計測
            distanceCount++;
        else if(booleanFlag[i] == 1){ //区間距離の計測終了
            if(mostSmall > distanceCount)
                mostSmall = distanceCount + 1;
            distanceCount = 0; //計測距離リセット
        }
        // 最後まで読み込んだ時の距離が最も短かったら
        if(i + 1 == size && mostSmall > distanceCount)
            mostSmall = distanceCount;
    }
    return mostSmall;
}

int main(){
    // 幅, 高さ, 奥行き
    int width = 0, height = 0, depth = 0;
    int slashNum = 0; //切り込みを入れる回数
    int d_i[100] = {0}, //切り込みを入れる角度 縦か横か
            a_i[100] = {0}; //角度から切り込みを入れる距離
    int i = 0; //ループカウンタ
    int booleanBeside[100] = {0}; //横切り込み距離
    int booleanLongtudinal[100] = {0}; //縦切り込み距離
    int mostWidthSmall = 0; //幅計測：最短幅
    int mostDepthSmall = 0; //奥行き計測：最短奥行き

    // 入力--------------------------------------------
    scanf("%d %d %d %d", &width, &depth, &height, &slashNum);

    // 立体の高さ幅奥行きと切り込みを入れる回数を入力
    for(i = 0; i < slashNum; i++)
        scanf("%d %d", &d_i[i], &a_i[i]);

    // 切り込み距離数のフラグを立てる
    for(i = 0; i < slashNum; i++){
        if(d_i[i] == LONGITUDINAL)
            booleanLongtudinal[ a_i [ i ] - 1 ] = 1;
        else if(d_i[i] == BESIDE)
            booleanBeside[ a_i [ i ] - 1 ] = 1;
    }

    // 縦と横の最小切り込み長を解析
    mostWidthSmall = shortestAnalysis(width, booleanLongtudinal);
    mostDepthSmall = shortestAnalysis(depth, booleanBeside);

    // 結果表示
    printf("%d\n", mostDepthSmall * mostWidthSmall * height);

    return 0;
}
