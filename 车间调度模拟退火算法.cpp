// 车间调度模拟退火算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<fstream>
#include"simulate.h"
#include<cmath>
#include<cstdlib>


#define T0 10000 
#define theta 0.99999

int main()
{
    //数据输入
    int n, m; 
    int p[Max_number_Machine * Max_number_Workpiece];
    std::ifstream infile("input.txt");
    infile >> n >> m;
    int other;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            infile >> other >> p[i * m + j];
    infile.close();
    simulate S(n, m, p);
    S.randomReset();//随机初始化

    //模拟退火算法
    int t = 0x3f3f3f3f;
    int flag = 0;
    double T = T0;
    for (int i = 0; ; i++) {
        std::cout  << i << '\t' << t << std :: endl;
        T = T * theta; //当前温度
        S.randomExchange(); //产生新解
        S.resetForNewRound();//重置工件机器状态
        int new_t = S.evaluate();//评估新解
        if (new_t < t) {
            t = new_t;
            flag = 0;
            continue;
        }//接受新解
        else {
            double p = std::exp((t - new_t) / T);
            if (((std::rand() % 10000) / 10000.0) <= p) {
                t = new_t;
                flag = 0;      
                continue;
            }//以概率接受新解
            else {
                S.rollBack();//回退至上一状态
                flag++;
                if (flag > 50) //如果长时间未接受新解，结束搜索
                    break;
            }//拒绝新解    
        }
    }
    std::cout << t << std :: endl;
    S.resetForNewRound();
    S.evaluate();
    S.outdata();

    /*调试部分
    infile.open("management.txt");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            infile >> p[i * m + j];
    infile.close();
    S.setManagement(p);
    S.evaluate();
    S.outdata();*/
}

