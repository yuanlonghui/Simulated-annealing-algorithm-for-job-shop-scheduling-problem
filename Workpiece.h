#pragma once
class Workpiece 
{//自定义类：工件
	int being_processed;//正在被第几个机器加工,-1表示未被加工
	int left_time;//剩余加工时间
public:
	Workpiece():being_processed(-1) , left_time(0) { }
	int beingPro(); //返回正在被加工的机器号
	int leftTime(); //返回目前机器上的剩余加工时间
	void nextTime(); //进入下一时间状态，可能处于空闲
	void nextMachine(int time); //进入下一机器状态
	void reset(); //重置
};

