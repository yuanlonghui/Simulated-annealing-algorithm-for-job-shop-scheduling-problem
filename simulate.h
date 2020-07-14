#pragma once
#include"Machine.h"
#include"Workpiece.h"
#define Max_number_Machine 30
#define Max_number_Workpiece 60
class simulate
{ //自定义类：模拟一次整体的加工
	int cost[Max_number_Workpiece][Max_number_Machine];  //时间花费
	int management[Max_number_Machine][Max_number_Workpiece]; //调度方案
	int Time[Max_number_Machine][Max_number_Workpiece]; //记录每个机器的调度方案中的零件开始加工时间时间
	int Wcount, Mcount; //工件，机器数量
	int switchx, switchy , switchrow; //记录交换信息，便于回退至上一状态
	Machine M[Max_number_Machine]; //机器集合
	Workpiece W[Max_number_Workpiece]; //工件集合
public:
	simulate(int n, int m, int* p);
	void randomReset(); //随机初始化整个调度方案
	void rollBack(); //回退至上一状态
	void randomExchange(); //随机交换某两个零件在某个机器上的的加工顺序
	int evaluate();//模拟一次加工，返回加工时间，并且维护Time数组
	void outdata(); //输出调度方案，时间方案
	void resetForNewRound();//重置所有状态，准备下一次模拟
	void setManagement(int* p);//设置调度方案，调试时可用
};

