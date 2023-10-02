
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
	bool flagv;//true¥˙±Ì”Æ¡À
	int round;
	Cell** map = NULL;
	float food;
	float perfood;//√øæ÷º”µƒfood
	int centrepop;// –÷––ƒµƒ»Àø⁄ ˝
	float allpop;//◊‹»Àø⁄
	float alltech;//◊‹ø∆ºº÷µ
	float allcul;//◊‹ŒƒªØ÷µ
	float previouscul;//…œ“ª¥Œ¿©’≈Õ¡µÿ ±µƒŒƒªØ÷µ
	float score;//∑÷ ˝
	float pertech;//√ø∏ˆ»Àƒ‹Ã·π©µƒø∆ºº÷µ
	float percul;//Õ¨
	float perprod;//Õ¨
	bool flagp;//’‚ªÿ∫œ”√π˝…˙≤˙¡¶¡ÀæÕtrue£∫ªÓ∂Ø/Ω®÷˛”√µƒ
	bool flagd;//true±Ì æµ±«∞ªÿ∫œ∑÷≈‰π˝…˙≤˙¡¶
	float prod;//µ±«∞…˙≤˙¡¶**************************************************************************************************************************
	char current_distribution;//µ±«∞…˙≤˙¡¶∑÷≈‰∏¯µƒœÓƒø
	int currenti = 0;
	int bo[20][20];//º«¬º“ª∏ˆµ•‘™∏Ò…œ”–√ª”–Ω®÷˛£®’˝‘⁄Ω®µƒΩ®÷˛“≤ «Ω®÷˛£©
	buone zao[101];//√ø“ªÃıΩ®‘Ïº«¬º£¨“ªÃıº«¬º÷–∞¸∫¨£∫1°¢‘⁄ƒƒ¿ÔΩ® ≤√¥ 2°¢’‚¥ŒΩ®‘Ïªπ–Ëº∏µ„…˙≤˙¡¶£¨º¥oktime
	int idx;
	const float meeting = 50.0, show = 50.0, logistics = 50.0;
	int lastmeeting[100] = { 0 }, lastshow[100] = { 0 }, lastlogistics[100] = { 0 };//lasttimeŒ™ªÓ∂Øº”≥…≥÷–¯ ±º‰
	float endmeeting, endshow, endlogistics;//endtimeŒ™µ±«∞ªÓ∂ØÀ˘–Ë…˙≤˙¡¶
	double x;//xµƒ÷µ‘ˆµΩ1£¨‘Ú»Àø⁄º”“ª°£xµƒ÷µºıµΩ-1£¨‘Ú»Àø⁄ºı“ª°£
	double foodbonus=0;// ≥ŒÔº”≥…
	double prodbonus;//…˙≤˙¡¶º”≥…

	int length=0;
	int width=0;
	int m_centre; int n_centre;// º«¬º –÷––ƒµƒŒª÷√
	int mark_remove = 0;//º«¬º»Àø⁄ «∑Òºı…Ÿ£¨“¿¥Œ≈–∂œ «∑Òµ˜”√removepop

	Controller()
	{
		flagv = false;
		x = 0;
		food = 0;
		perfood = 0.5;
		centrepop = 2;// –÷––ƒµƒ»Àø⁄ ˝
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
	//—°‘ÒæŸ∞ÏªÓ∂Ø
	void activity();
	void updatepop();
	// Õ≥º∆ «∑Ò”–ø™ ºªÚΩ· ¯µƒªÓ∂Ø
	void tongji2();

	// ºÏ≤Èƒ‹∑Ò≤Œº”ªÓ∂Ø
	bool check(char name, int endtime);

	/*”√”⁄main∫Ø ˝µƒ◊‹whileΩ· ¯∫Û£¨Ω¯––√øªÿ∫œÕ≥º∆,
	Ω” ’“ª∏ˆµ±«∞ªÓ∂ØªÚΩ®÷˛µƒ±‰¡ø£¨»Áπ˚±æªÿ∫œ≤ª¥´»Î£¨ƒ¨»œŒ™…œªÿ∫œµƒ≤Œ ˝£¨∑Ò‘Ú∏ƒŒ™±æªÿ∫œµƒ£¨
	≤¢«“º∆À„ ±”√œ‡”¶µƒπ§∆⁄ºı»•µ±«∞’Ê µ…˙≤˙¡¶œ˚∫ƒ*/
	void default_statistics(char current_distribution);

	void setpopBonus();//Õ≥º∆Õ¡µÿº”≥…

	//Õ≥º∆ø∆ºº°¢ŒƒªØ°¢…˙≤˙¡¶
	void tongji3();

	//¿©’≈Õ¡µÿ
	void expansion();

	void victory();
	void removepop();//”√”⁄‘⁄◊‹»Àø⁄ºı…Ÿ ±—°‘Òƒ≥øÈµÿ∂˘Ω´»Àºı…Ÿ
	bool removepop_judge(int& m, int& n);
	bool removepop_input(int& m, int& n);


};
bool select_poptrsf(Controller& controller);// µœ÷ ‰»ÎÕ¡µÿ◊¯±Í∫ÛΩ·π˚≥…π¶”Î∑Òµƒ≈–∂œ
bool judge_coord_1(Controller& controller, int& m, int& n);//≈–∂œ1.÷–∏˜÷÷«Èøˆ
bool judge_coord_2(Controller& controller, int& m1, int& n1);
bool coord_1(Controller& controllerint ,int&m,int &n);
bool coord_2(Controller& controllerint,int &m1,int &n1);
void poptrsf_inner(Controller& controller, int m1, int n1, int m, int n);
#endif 

