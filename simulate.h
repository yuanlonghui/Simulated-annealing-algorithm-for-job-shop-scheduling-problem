#pragma once
#include"Machine.h"
#include"Workpiece.h"
#define Max_number_Machine 30
#define Max_number_Workpiece 60
class simulate
{ //�Զ����ࣺģ��һ������ļӹ�
	int cost[Max_number_Workpiece][Max_number_Machine];  //ʱ�仨��
	int management[Max_number_Machine][Max_number_Workpiece]; //���ȷ���
	int Time[Max_number_Machine][Max_number_Workpiece]; //��¼ÿ�������ĵ��ȷ����е������ʼ�ӹ�ʱ��ʱ��
	int Wcount, Mcount; //��������������
	int switchx, switchy , switchrow; //��¼������Ϣ�����ڻ�������һ״̬
	Machine M[Max_number_Machine]; //��������
	Workpiece W[Max_number_Workpiece]; //��������
public:
	simulate(int n, int m, int* p);
	void randomReset(); //�����ʼ���������ȷ���
	void rollBack(); //��������һ״̬
	void randomExchange(); //�������ĳ���������ĳ�������ϵĵļӹ�˳��
	int evaluate();//ģ��һ�μӹ������ؼӹ�ʱ�䣬����ά��Time����
	void outdata(); //������ȷ�����ʱ�䷽��
	void resetForNewRound();//��������״̬��׼����һ��ģ��
	void setManagement(int* p);//���õ��ȷ���������ʱ����
};

