#pragma once
class Machine
{//�Զ����ࣺ����
	int processing;//���ڼӹ����ȷ����еĵڼ������,-1��ʾ��δ�ӹ����
	int left_time;//ʣ��ӹ�ʱ��
public:
	Machine():processing(-1) , left_time(0) { }
	int leftTime(); //���ظû�����ǰ�ӹ������ʣ��ӹ�ʱ��
	int process(); //�������ڼӹ����ȷ����еĵڼ������
	void nextTime(); //������һʱ��״̬�����ܿ���
	void nextWP(int time); //���ȷ�����һ��������Ϊ
	void reset(); //����״̬
};

