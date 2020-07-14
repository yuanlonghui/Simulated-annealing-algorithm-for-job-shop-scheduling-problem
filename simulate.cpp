#include<ctime>
#include<cstdlib>
#include<fstream>
#include<iostream>
#include "simulate.h"

#define _DEBUG_

simulate::simulate(int n, int m, int* p) : Wcount(n) , Mcount(m) ,switchx(0) , switchy(0) ,switchrow(0)
{
	for (int i = 0; i < Wcount; i++)
		for (int j = 0; j < Mcount; j++)
			cost[i][j] = p[i * Mcount + j];
	for (int i = 0; i < Mcount; i++)
		for (int j = 0; j < Wcount; j++)
			management[i][j] = j;
	for (int i = 0; i < Mcount; i++)
		for (int j = 0; j < Wcount; j++)
			Time[i][j] = 0;
}

void simulate::randomReset()
{
	srand((unsigned)std :: time(NULL));
	for(int i = 0 ; i < Mcount ; i++)
		for (int j = 0; j < Wcount; j++) {
			int x = std :: rand() % (Wcount - j) + j;
			int temp = management[i][j];
			management[i][j] = management[i][x];
			management[i][x] = temp;
		}
}

void simulate::rollBack()
{
	int temp = management[switchrow][switchx];
	management[switchrow][switchx] = management[switchrow][switchy];
	management[switchrow][switchy] = temp;
}

void simulate::randomExchange()
{
	switchrow = std :: rand() % Mcount ;
	switchx = std :: rand() % Wcount;
	switchy = std :: rand() % Wcount;
	int temp = management[switchrow][switchx];
	management[switchrow][switchx] = management[switchrow][switchy];
	management[switchrow][switchy] = temp;
}

int simulate::evaluate()
{
	int rtime = 0; //ģ��ʱ�����
	for (rtime = 0; ; rtime++) {
#ifndef _DEBUG_
		std::cout << "time : " << rtime << std::endl;
#endif 
		for (int i = 0; i < Mcount; i++) {
			int processing = M[i].process();
			if (processing != Wcount - 1) { //�������һ������
				int x = management[i][processing + 1];
				if (M[i].leftTime() == 0 && W[x].leftTime() == 0 && W[x].beingPro() == i - 1) {
					//��һ���������У������Ѽӹ�����ǰ����
					M[i].nextWP(cost[x][i]);//��һ��������λ
					W[x].nextMachine(cost[x][i]);//����������һ����
					Time[i][processing + 1] = rtime ; // ��¼��ʼʱ��
				}
			}
		}
		//�����Լ�������������һʱ��״̬
		for (int i = 0; i < Mcount; i++)
			M[i].nextTime();
		for (int i = 0; i < Wcount; i++)
			W[i].nextTime();
		//�����Ƿ�ӽ����ӹ�
		int flag = 0;
		for (int i = 0; i < Wcount; i++) {
			if (W[i].leftTime() == 0 && W[i].beingPro() == Mcount - 1)
				continue;
			else {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			rtime++;
			break;//����
		}
	}
	return rtime;
}

void simulate::outdata()
{
	std::ofstream outfile("management.txt");
	for (int i = 0; i < Mcount; i++) {
		for (int j = 0; j < Wcount; j++) {
			outfile << management[i][j] << "\t";
		}
		outfile << std::endl;
	}
	outfile.close();
	outfile.open("time.txt");
	for (int i = 0; i < Mcount; i++) {
		for (int j = 0; j < Wcount; j++) {
			outfile << Time[i][j] << "\t" << Time[i][j] + cost[management[i][j]][i] << '\t';
		}
		outfile << std::endl;
	}
}

void simulate::resetForNewRound()
{
	for (int i = 0; i < Wcount; i++) 
		W[i].reset();
	for (int i = 0 ; i < Mcount; i++)
		M[i].reset();
}

void simulate::setManagement(int* p)
{
	for (int i = 0; i < Mcount; i++) {
		for (int j = 0; j < Wcount; j++) {
			management[i][j] = p[i * Wcount + j];
		}
	}
}
