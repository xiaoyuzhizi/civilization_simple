
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
	bool flagv;//true代表赢了
	int round;  //当前第几回合
	Cell** map = NULL;
	float food;
	float perfood;//每局加的food
	int centrepop;//市中心的人口数
	float allpop;//总人口
	float alltech;//总科技值
	float allcul;//总文化值
	float previouscul;//上一次扩张土地时的文化值
	float score;//分数
	float pertech;//每个人能提供的科技值
	float percul;//同
	float perprod;//同
	bool flagp;//这回合用过生产力了就true：活动/建筑用的
	bool flagd;//true表示此回合已经投入过一次生产力
	float prod;//当前生产力**************************************************************************************************************************
	char current_distribution;//当前生产力分配给的项目
	int currenti = 0;    //上一回合正在建造的建筑编号
	int bo[20][20];//记录一个单元格上有没有建筑（正在建的建筑也是建筑）
	buone zao[101];//每一条建造记录，一条记录中包含：1、在哪里建什么 2、这次建造还需几点生产力，即oktime
	int idx;  //下一次建造建筑在zao数组中的下标
	const float meeting = 50.0, show = 50.0, logistics = 50.0;  //各个活动的生产力基础值
	int lastmeeting[100] = { 0 }, lastshow[100] = { 0 }, lastlogistics[100] = { 0 };//lasttime为活动加成持续时间，
	float endmeeting, endshow, endlogistics;//endtime为当前活动所需生产力
	double x;//x的值增到1，则人口加一。x的值减到-1，则人口减一。
	double foodbonus=0;//食物加成
	double prodbonus;//生产力加成

	int length=0;
	int width=0;
	int m_centre; int n_centre;// 记录市中心的位置
	int mark_remove = 0;//记录人口是否减少，依次判断是否调用removepop

	Controller()
	{
		flagv = false;
		x = 0;
		food = 0;
		perfood = 0.5;
		centrepop = 2;//市中心的人口数
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
	//选择举办活动
	void activity();
	void updatepop();
	// 统计是否有开始或结束的活动
	void tongji2();

	// 检查能否参加活动
	bool check(char name, int endtime);

	/*用于main函数的总while结束后，进行每回合统计,
	接收一个当前活动或建筑的变量，如果本回合不传入，默认为上回合的参数，否则改为本回合的，
	并且计算时用相应的工期减去当前真实生产力消耗*/
	void default_statistics(char current_distribution);

	void setpopBonus();//统计土地加成

	//统计科技、文化、生产力
	void tongji3();

	//扩张土地
	void expansion();

	void victory();
	void removepop();//用于在总人口减少时选择某块地儿将人减少
	bool removepop_judge(int& m, int& n);
	bool removepop_input(int& m, int& n);


};
bool select_poptrsf(Controller& controller);//实现输入土地坐标后结果成功与否的判断
bool judge_coord_1(Controller& controller, int& m, int& n);//判断1.中各种情况
bool judge_coord_2(Controller& controller, int& m1, int& n1);
bool coord_1(Controller& controllerint ,int&m,int &n);
bool coord_2(Controller& controllerint,int &m1,int &n1);
void poptrsf_inner(Controller& controller, int m1, int n1, int m, int n);
#endif 

