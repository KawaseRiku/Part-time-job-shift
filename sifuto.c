//
//  sifuto.c
//  
//
//  Created by 川瀬陸 on 2021/03/14.
//

#include "sifuto.h"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define RAND_MAX 0x7fffffff

#define NUMBER 5//バイトの人数


int main(void)
{
    //ループカウンタ
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    printf("RAND_MAX: %d\n", RAND_MAX);
    printf("希望が\n1:10~15時\n2:17~22時\n3:22~25時とする\n一旦バイトは5人とする\n");
    
    printf("希望はとりあえず\nAは123\nBは2\nCは1\nDは3\nEは12とする\n\n");
    
    char name[NUMBER][100];//5人ずつ100文字まで
    char saisyuu[NUMBER][100];//最終出勤する人の名前の格納場所
    int sifuto[NUMBER][3];//5人4枠(名前1、シフト3)
    
    //いけるかどうかの表
    //1はいける0はいけない
    //ファイル処理(シフト表を読み込む)
    FILE *fp;
    if((fp = fopen("sifuto.dat", "r")) == NULL)
    {
        printf("\a入力ファイルをオープン出来ません\n");
    }
    else
    {
        printf("ファイル読み込みは成功しました\n\n");
        for(i = 0; i < NUMBER; i++)//5人分
        {
            fscanf(fp, "%s%d%d%d", name[i], &sifuto[i][0], &sifuto[i][1], &sifuto[i][2]);
        }
    }
    fclose(fp);
    
    //ファイル書き込み
    FILE *fp2;
    if((fp2 = fopen("sifuto2.dat", "w")) == NULL)
    {
        printf("\a書き込みファイルをオープン出来ません\n");
    }
    
    char *jikan[3];
    jikan[0] = "10~15";
    jikan[1] = "17~22";
    jikan[2] = "22~25";
    
    char hito[NUMBER][100];//いける人の名前を格納する場所
    int count = 0;//カウンタ
    
        for(i = 0; i < 3; i++)//シフトいける時間はどこかを探すための繰り返し（1~3）
        {
            //いける人の確認といける人を前から（hito[0]）から順に格納していく
            printf("%s時が行けるのは", jikan[i]);
            for(k = 0; k < NUMBER; k++)
            {
                if(sifuto[k][i] == 1)
                {
                    for(j = 0; j < 100; j++)
                    {
                        hito[count][j] = name[k][j];
                    }
                    
                    count++;//カウンタアップ
                    printf("(%s)さん", name[k]);
                }

            }
            
            printf("です．\n");
            
            
            printf("%s時は\n", jikan[i]);
            fprintf(fp2, "\n%s　", jikan[i]);//ファイル処理
            for(l = 0; l < 2; l++)//ここで2回繰り返す
            {
                //いける人の中からランダム選ぶ
                srand((unsigned int)time(NULL));//現在時刻の情報で初期化
                
                switch(rand() % count)//countで割った余りによって人を決める
                {
                        //ここはループ使えない気がするバイトが5人やったらcase4まで
                    case 0: printf("(%s)", hito[0]);
                        fprintf(fp2, "%s　", hito[0]);//ファイル処理
                        for(m = 0; m < NUMBER; m++)
                        {
                            for(j = 0; j < 100; j++)
                            {
                                hito[m][j] = hito[m + 1][j];//hito[]を一つずつずらす
                            }
                        }
                        count--;//カウンタを減らす
                        break;
                    case 1: printf("(%s)", hito[1]);
                        fprintf(fp2, "%s　", hito[1]);//ファイル処理
                        for(m = 1; m < NUMBER; m++)
                        {
                            for(j = 0; j < 100; j++)
                            {
                                hito[m][j] = hito[m + 1][j];//hito[]を一つずつずらす
                            }
                        }
                        count--;//カウンタを減らす
                        break;
                    case 2: printf("(%s)", hito[2]);
                        fprintf(fp2, "%s　", hito[2]);//ファイル処理
                        for(m = 2; m < NUMBER; m++)
                        {
                            for(j = 0; j < 100; j++)
                            {
                                hito[m][j] = hito[m + 1][j];//hito[]を一つずつずらす
                            }
                        }
                        count--;//カウンタを減らす
                        break;
                    case 3: printf("(%s)", hito[3]);
                        fprintf(fp2, "%s　", hito[3]);//ファイル処理
                        for(m = 3; m < NUMBER; m++)
                        {
                            for(j = 0; j < 100; j++)
                            {
                                hito[m][j] = hito[m + 1][j];//hito[]を一つずつずらす
                            }
                        }
                        count--;//カウンタを減らす
                        break;
                    case 4: printf("(%s)", hito[4]);
                        fprintf(fp2, "%s　", hito[4]);//ファイル処理
                        for(m = 4; m < NUMBER; m++)
                        {
                            for(j = 0; j < 100; j++)
                            {
                                hito[m][j] = hito[m + 1][j];//hito[]を一つずつずらす
                            }
                        }
                        count--;//カウンタを減らす
                        break;
                    /*case 5: printf("(%s)", hito[5]);
                        fprintf(fp2, "%s　", hito[5]);//ファイル処理
                        for(m = 5; m < NUMBER; m++)
                        {
                            for(j = 0; j < 100; j++)
                            {
                                hito[m][j] = hito[m + 1][j];//hito[]を一つずつずらす
                            }
                        }
                        count--;//カウンタを減らす
                        break;
                    case 6: printf("(%s)", hito[6]);
                        fprintf(fp2, "%s　", hito[6]);//ファイル処理
                        for(m = 6; m < NUMBER; m++)
                        {
                            for(j = 0; j < 100; j++)
                            {
                                hito[m][j] = hito[m + 1][j];//hito[]を一つずつずらす
                            }
                        }
                        count--;//カウンタを減らす
                        break;
                    case 7: printf("(%s)", hito[7]);
                        fprintf(fp2, "%s　", hito[7]);//ファイル処理
                        for(m = 7; m < NUMBER; m++)
                        {
                            for(j = 0; j < 100; j++)
                            {
                                hito[m][j] = hito[m + 1][j];//hito[]を一つずつずらす
                            }
                        }
                        count--;//カウンタを減らす
                        break;
                    case 8: printf("(%s)", hito[8]);
                        fprintf(fp2, "%s　", hito[8]);//ファイル処理
                        for(m = 8; m < NUMBER; m++)
                        {
                            for(j = 0; j < 100; j++)
                            {
                                hito[m][j] = hito[m + 1][j];//hito[]を一つずつずらす
                            }
                        }
                        count--;//カウンタを減らす
                        break;
                    case 9: printf("(%s)", hito[9]);
                        fprintf(fp2, "%s　", hito[9]);//ファイル処理
                        for(m = 9; m < NUMBER; m++)
                        {
                            for(j = 0; j < 100; j++)
                            {
                                hito[m][j] = hito[m + 1][j];//hito[]を一つずつずらす
                            }
                        }
                        count--;//カウンタを減らす
                        break;
                     */

                }
                printf("さんが行くことになりました\n");
                sleep(1);//1秒待機
                
            }
                
                //hito[]の初期化をする
                for(k = 0; k < NUMBER; k++)
                {
                    for(j = 0; j < 100; j++)
                    {
                        hito[k][j] = '\0';
                    }
                }
                
                count = 0;//カウンタを0にする
                
                printf("\n");
                
        }
    
    fclose(fp2);

    return 0;
}
