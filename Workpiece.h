#pragma once
class Workpiece 
{//�Զ����ࣺ����
	int being_processed;//���ڱ��ڼ��������ӹ�,-1��ʾδ���ӹ�
	int left_time;//ʣ��ӹ�ʱ��
public:
	Workpiece():being_processed(-1) , left_time(0) { }
	int beingPro(); //�������ڱ��ӹ��Ļ�����
	int leftTime(); //����Ŀǰ�����ϵ�ʣ��ӹ�ʱ��
	void nextTime(); //������һʱ��״̬�����ܴ��ڿ���
	void nextMachine(int time); //������һ����״̬
	void reset(); //����
};

