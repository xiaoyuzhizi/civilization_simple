
#ifndef DISPLAY_H
#define DISPLAY_H

#include "loading.h"
#include <iostream>
using namespace std;
struct buone
{
	int type = 0;
	int xx = 0;
	int yy = 0;
	float oktime = 0;
};


class Controller
{
public:
	bool flagv;//true����Ӯ��
	int round;  //��ǰ�ڼ��غ�
	Cell** map = NULL;
	float food;
	float perfood;//ÿ�ּӵ�food
	int centrepop;//�����ĵ��˿���
	float allpop;//���˿�
	float alltech;//�ܿƼ�ֵ
	float allcul;//���Ļ�ֵ
	float previouscul;//��һ����������ʱ���Ļ�ֵ
	float score;//����
	float pertech;//ÿ�������ṩ�ĿƼ�ֵ
	float percul;//ͬ
	float perprod;//ͬ
	bool flagp;//��غ��ù��������˾�true���/�����õ�
	bool flagd;//true��ʾ�˻غ��Ѿ�Ͷ���һ��������
	float prod;//��ǰ������**************************************************************************************************************************
	char current_distribution;//��ǰ���������������Ŀ
	int currenti = 0;    //��һ�غ����ڽ���Ľ������
	int bo[20][20];//��¼һ����Ԫ������û�н��������ڽ��Ľ���Ҳ�ǽ�����
	buone zao[101];//ÿһ�������¼��һ����¼�а�����1�������ｨʲô 2����ν��컹�輸������������oktime
	int idx;  //��һ�ν��콨����zao�����е��±�
	const float meeting = 50.0, show = 50.0, logistics = 50.0;  //�����������������ֵ
	int lastmeeting[100] = { 0 }, lastshow[100] = { 0 }, lastlogistics[100] = { 0 };//lasttimeΪ��ӳɳ���ʱ�䣬
	float endmeeting, endshow, endlogistics;//endtimeΪ��ǰ�����������
	double x;//x��ֵ����1�����˿ڼ�һ��x��ֵ����-1�����˿ڼ�һ��
	double foodbonus=0;//ʳ��ӳ�
	double prodbonus;//�������ӳ�

	int length=0;
	int width=0;
	int m_centre; int n_centre;// ��¼�����ĵ�λ��
	int mark_remove = 0;//��¼�˿��Ƿ���٣������ж��Ƿ����removepop

	Controller()
	{
		flagv = false;
		x = 0;
		food = 0;
		perfood = 0.5;
		centrepop = 2;//�����ĵ��˿���
		round = 0;
		allpop = 2;
		alltech = 0;
		allcul = 0;
		previouscul = 0.6;
		prod = 0;
		score = 0;
		pertech = 0.7;
		percul = 0.3;
		perprod = 0.5;
		current_distribution = 0;
		flagp = false;
		flagd = false;
		endmeeting = 0;
		endshow = 0;
		endlogistics = 0;
		remainmeeting = 0;
		remainshow = 0;
		remainlogistics = 0;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				bo[i][j] = 0;
			}

		}

		idx = 0;
		foodbonus = 0;
		prodbonus = 0;

	}


	/*void morendistribute();*/
	void showall();
	void build();
	void tongji();
	void selectcenter();
	void distribute();
	//ѡ��ٰ�
	void activity();
	void updatepop();
	// ͳ���Ƿ��п�ʼ������Ļ
	void tongji2();

	// ����ܷ�μӻ
	bool check(char name, int endtime);

	/*����main��������while�����󣬽���ÿ�غ�ͳ��,
	����һ����ǰ������ı�����������غϲ����룬Ĭ��Ϊ�ϻغϵĲ����������Ϊ���غϵģ�
	���Ҽ���ʱ����Ӧ�Ĺ��ڼ�ȥ��ǰ��ʵ����������*/
	void default_statistics(char current_distribution);

	void setpopBonus();//ͳ�����ؼӳ�

	//ͳ�ƿƼ����Ļ���������
	void tongji3();

	//��������
	void expansion();

	void victory();
	void removepop();//���������˿ڼ���ʱѡ��ĳ��ض����˼���
	bool removepop_judge(int& m, int& n);
	bool removepop_input(int& m, int& n);


};
bool select_poptrsf(Controller& controller);//ʵ������������������ɹ������ж�
bool judge_coord_1(Controller& controller, int& m, int& n);//�ж�1.�и������
bool judge_coord_2(Controller& controller, int& m1, int& n1);
bool coord_1(Controller& controllerint ,int&m,int &n);
bool coord_2(Controller& controllerint,int &m1,int &n1);
void poptrsf_inner(Controller& controller, int m1, int n1, int m, int n);
#endif 

