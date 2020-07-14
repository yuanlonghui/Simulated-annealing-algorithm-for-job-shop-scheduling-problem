#pragma once
class Machine
{//自定义类：机器
	int processing;//正在加工调度方案中的第几个零件,-1表示还未加工零件
	int left_time;//剩余加工时间
public:
	Machine():processing(-1) , left_time(0) { }
	int leftTime(); //返回该机器当前加工零件的剩余加工时间
	int process(); //返回正在加工调度方案中的第几个零件
	void nextTime(); //进入下一时间状态，可能空闲
	void nextWP(int time); //调度方案下一个工件就为
	void reset(); //重置状态
};

