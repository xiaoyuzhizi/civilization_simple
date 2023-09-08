#include"Display.h"


void Controller::selectcenter()
{
	int m, n;
	cout << "请选择市中心的坐标：(两数字间以空格分隔)" << endl;

	cin >> m;

	cin >> n;
	while (this->map[m][n].landform == OCEAN || this->map[m][n].landform == SEA || this->map[m][n].landform == MOUNTAIN)
	{
		cout << "市中心不可建在山脉，近海，深海，请重新选择：" << endl;
		cout << "请输入横坐标：" << endl;
		cin >> m;
		cout << "请输入纵坐标：" << endl;
		cin >> n;
	}
	
	map[m][n].ifpop = OWNED;
	map[m][n].type = 6;
	
	map[m + 1][n].ifpop = OWNED;
	map[m - 1][n].ifpop = OWNED;
	map[m][n + 1].ifpop = OWNED;
	map[m][n - 1].ifpop = OWNED;
	this->m_centre = m; this->n_centre = n;
	cout << "市中心选择完成：" << endl;
	system("pause");
	system("cls");
}

void Controller::build()
{
	int n, x, y;

	//if (zao[2].type == 0) cout << "没到这";
	
	cout << "请输入对应数字以选择你想建造的建筑种类" << endl << "1:学院" << endl << "2:剧院广场" << endl << "3:奇观" << endl << "4:工业区" << endl << "5:查看帮助" << endl;
	cout << "6:返回上一级菜单" << endl;

	do {
		cin >> n;




		switch (n)
		{
		case 1:
			//	cout << "需要" << 100 / prod << "个回合完工"<<endl;
			zao[idx].oktime = round;
			zao[idx].type = n;
			



			break;
		case 2:
			//	cout << "需要" << 100 / prod << "个回合完工" << endl;

			zao[idx].oktime = round;
			zao[idx].type = n;
			
			break;
		case 3:
			//cout << "需要" << 250 / prod << "个回合完工" << endl;
			zao[idx].oktime = 2.5 * round;
			zao[idx].type = n;
			
			break;
		case 4:
			//cout << "需要" << 100 / prod << "个回合完工" << endl;
			zao[idx].oktime = round;
			zao[idx].type = n;
			
			break;
		case 5:
			cout << "学院：当有人口在此单元格时，+1科技值，每个人口提供的科技值+0.2，每相邻一个区域+1科技值，每相邻一个山脉地貌+1科技值。真实生产力消耗为：" <<round<< endl;
			cout << "剧院广场：当有人口在此单元格时， + 1文化值，每个人口提供的文化值 + 0.2，每相邻一个区域 + 1文化值，每相邻一个奇观 + 1文化值（即奇观建筑 + 2文化值）。真实生产力消耗为："<<round << endl;
			cout << "奇观： + 20文化值。每相邻一个奇观 + 5文化值。真实生产力消耗为：" <<2.5*round<< endl;
			cout << "工业区：当有人口在此单元格时， + 2生产力，每个人口提供的生产力 + 2，每相邻一个区域 + 1生产力。真实生产力消耗为：" <<round<< endl;
			cout << "备注：真实生产力消耗（即所需要投入的生产力）=生产力基础值*当前回合数/回合总数。" << endl;
			cout << "建筑只能建在城市领地内，不能建在近海、深海或山脉上" << endl;
			break;

		case 6:
			return;

		



		}

	} while (n == 5);

	cout << "请输入您想建造城市的单元格坐标（两数字间用空格分隔）" << endl;
	cin >> x >> y;
	while (bo[x][y] != 0||map[x][y].ifpop==WILD|| map[x][y].landform==OCEAN|| map[x][y].landform == SEA || map[x][y].landform == MOUNTAIN  )
	{
		cout << "抱歉，您当前无法选择此单元格，请选择其他单元格" << endl;
		cin >> x >> y;
		
	}
	zao[idx].xx = x;
	zao[idx].yy = y;
	map[x][y].type = -1;
	idx++;
	flagp = true;
	bo[x][y] = 1;

}

void Controller::tongji()
{
	int j = 0, i;




	/*while()
	cout << ;*/
	while (zao[j].type != 0)
	{
		if (zao[j].oktime <= 0)
		{
			map[zao[j].xx][zao[j].yy].type = zao[j].type;
		}





		j++;
	}



	for (i = 0;i < 20;i++)
	{
		for (j = 0;j < 20;j++)
		{
			if (map[i][j].type != 0)
			{
				switch (map[i][j].type)
				{
				case 1:
					if (map[i][j].ifpop == COLONIZED) alltech++;
					pertech += 0.2;
					if (i - 1 >= 0 && map[i - 1][j].ifpop != WILD)
						alltech++;
					if (i + 1 <= 19 && map[i + 1][j].ifpop != WILD)  alltech++;
					if (j - 1 >= 0 && map[i][j - 1].ifpop != WILD)  alltech++;
					if (j + 1 <= 19 && map[i][j + 1].ifpop != WILD)  alltech++;
					if (i - 1 >= 0 && map[i - 1][j].landform == HILLY)  alltech++;
					if (i + 1 <= 19 && map[i + 1][j].landform == HILLY)  alltech++;
					if (j - 1 >= 0 && map[i][j - 1].landform == HILLY)  alltech++;
					if (j + 1 <= 19 && map[i][j + 1].landform == HILLY)  alltech++;
					break;

				case 2:
					if (map[i][j].ifpop == COLONIZED) allcul++;
					percul += 0.2;
					if (i + 1 <= 19 && map[i + 1][j].ifpop != WILD)  allcul++;
					if (j - 1 >= 0 && map[i][j - 1].ifpop != WILD)  allcul++;
					if (j + 1 <= 19 && map[i][j + 1].ifpop != WILD)  allcul++;
					if (i - 1 >= 0 && map[i - 1][j].ifpop != WILD)  allcul++;

				case 3:
					allcul += 20;
					if (i + 1 <= 19 && map[i + 1][j].type == 3)  allcul += 5;
					if (j - 1 >= 0 && map[i][j - 1].type == 3)  allcul += 5;
					if (j + 1 <= 19 && map[i][j + 1].type == 3)  allcul += 5;
					if (i - 1 >= 0 && map[i - 1][j].type == 3)  allcul += 5;

				case 4:
					if (map[i][j].ifpop == COLONIZED) prod += 2;
					perprod += 2;
					if (i + 1 <= 19 && map[i + 1][j].ifpop != WILD)  prod++;
					if (j - 1 >= 0 && map[i][j - 1].ifpop != WILD)  prod++;
					if (j + 1 <= 19 && map[i][j + 1].ifpop != WILD)  prod++;
					if (i - 1 >= 0 && map[i - 1][j].ifpop != WILD)  prod++;

				}

			}
		}
	}

}

void Controller::activity() {
	char name;
	cout << "请选择要进行的操作" << endl;
	cout << "1：代表学术会议" << endl;
	cout << "2：代表漫展" << endl;
	cout << "3：代表工业物流" << endl;
	cout << "4：查看帮助" << endl;
	cout << "5：返回上一级菜单" << endl;
	cin >> name;
	there1:
	if (name == '1') {
		if (!check('1', endmeeting)) {
			cout << "无法进行学术会议" << endl << "请选择接下来尝试的步骤:" << endl;
			cout << "0 代表退出举行会议\n1 代表重新选择\n";
			cin >> name;
			if (name == '0') return;
			else activity();
		}
		else {
			endmeeting = meeting*round/100;
			flagp = true;
		}
	}

	if (name == '2') {
		if (!check('2', endshow)) {
			cout << "无法进行漫展" << endl << "请选择接下来尝试的步骤:" << endl;
			cout << "0 代表退出举行会议\n1 代表重新选择\n";
			cin >> name;
			if (name == '0') return;
			else activity();
		}
		else {
			endshow = show * round / 100;
			flagp = true;
		}
	}

	if (name == '3') {
		if (!check('3', endlogistics)) {
			cout << "无法进行工业物流" << endl << "请选择接下来尝试的步骤:" << endl;
			cout << "0 代表退出举行会议\n1 代表重新选择\n";
			cin >> name;
			if (name == '0') return;
			else activity();
		}
		else {
			endlogistics = logistics * round / 100;
			flagp = true;
		}
	}

	if (name == '4') { //查看帮助
		cout << "学术会议：本回合需要消耗真实生产力为" << 50.0 * prod / 100 << " 完成时提供5回合的30pop点科技值"<<endl;
		cout << "漫展：本回合需要消耗真实生产力为" << 50.0 * prod / 100 << " 完成时提供5回合的30pop点文化值" << endl;
		cout << "工业物流：本回合需要消耗真实生产力为" << 50.0 * prod / 100 << " 完成时提供5回合的30pop点生产力" << endl;
		cout << "请输入接下来的操作：" << endl;
		cout << "1：代表学术会议\n2：代表漫展\n3：代表工业物流\n4：返回上一级菜单\n";
		cin >> name;
		if (name == '4') name = '5';
		goto there1;

	}

	if (name == '5') {	//返回上一级
		return;
	}
}

void Controller::tongji2() {
	for (int i = 0; i < 100; i++) {
		if (lastmeeting[i] > 0) {
			alltech += 30.0;
			lastmeeting[i]--;
		}
		if (lastshow[i] > 0) {
			allcul += 30.0;
			lastshow[i]--;
		}
		if (lastlogistics[i] > 0) {
			prod += 30.0;
			lastlogistics[i]--;
		}
	}
}

void Controller::tongji3() {
	alltech += pertech * allpop;


	allcul += percul * allpop;


	prod += perprod * allpop;
	
	prod += prodbonus;
	food += 0.5 * allpop;
	food += foodbonus;
	
	score = 0.5 * alltech + 0.5 * allcul + 10 * allpop + prod;
}


void Controller::victory()
{
	int i,num=0;
	for (i = 0;i < idx;i++)
	{
		if (zao[i].type == 3 && zao[i].oktime <= 0)
		{
			num++;
		}
	}
	if (alltech >= 500 || (num >= 5 && allcul >= 350) || score > 500)
	{
		cout << "恭喜你！胜利啦！";
		flagv = true;
	}
}


bool Controller::check(char name, int endtime) {

	
	    if (name == '1') {
	        if (endmeeting>0) {
	            cout << "当前活动正在进行，请重新选择活动" << endl;
	            return false;
	        }
	    }
	    if (name == '2') {
	        if (endshow > 0) {
	            cout << "当前活动正在进行，请重新选择活动" << endl;
	            return false;
	        }
	    }
	    if (name == '3') {
	        if (endlogistics > 0) {
	            cout << "当前活动正在进行，请重新选择活动" << endl;
	            return false;
	        }
	    }
		switch (name)
		{
		case '1': 
			for (int row = 0; row <= 19; row++) {
				for (int col = 0; col <= 19; col++) {
					if (map[row][col].type == 1) return true;
				}
			}
			cout << "未检测到有学院" << endl;
			return false; 
			break;
		case '2': 
			for (int row = 0; row <= 19; row++) {
				for (int col = 0; col <= 19; col++) {
					if (map[row][col].type == 2) return true;
				}
			}
			cout << "未检测到有剧院广场" << endl;
			return false; 
			break;
		case '3':
			for (int row = 0; row <= 19; row++) {
				for (int col = 0; col <= 19; col++) {
					if (map[row][col].type == 3) return true;
				}
			}
			cout << "未检测到有工业区" << endl;
			return false;
			break;

	    }
		return false;
}

void Controller::default_statistics(char current_distribution) {
	if (current_distribution == '1') {  // 学术会议
		endmeeting -= prod ;
	}
	if (current_distribution == '2') {  // 漫展
		endshow -= prod ;
	}
	if (current_distribution == '3') {  // 工业物流
		endlogistics -= prod ;
	}
	if (current_distribution == '0') {  // 工业物流
		if(zao[currenti].oktime>0)
			zao[currenti].oktime -= prod;
	}
}

//
//void morendistribute()
//{
//	if(currenti>=0)
//		if (zao[currenti].oktime > 0)
//			zao[currenti].oktime -= prod;
//}
void Controller::distribute(){
	int m, ii, h;
	bool flag = false;
	cout << "输入1表示用于建造建筑"<<endl<<"输入2表示用于举办活动"<<endl<<"输入3表示返回上一级菜单"<<endl;
	
	cin >> m;
	if (m == 3) return;
	if (m == 1)
	{
		for (ii = 0;ii < idx;ii++)
		{
			if (zao[ii].oktime > 0)
			{
				flag = true;
				if(zao[ii].type==1)
					cout << ii << ":在" << zao[ii].xx << "," << zao[ii].yy << "学院建造中，还需生产力" << zao[ii].oktime << "点" << endl;
				if (zao[ii].type == 2)
					cout << ii << ":在" << zao[ii].xx << "," << zao[ii].yy << "剧院广场建造中，还需生产力" << zao[ii].oktime << "点" << endl;
				if (zao[ii].type == 3)
					cout << ii << ":在" << zao[ii].xx << "," << zao[ii].yy << "奇观建造中，还需生产力" << zao[ii].oktime << "点" << endl;
				if (zao[ii].type == 4)
					cout << ii << ":在" << zao[ii].xx << "," << zao[ii].yy << "工业区建造中，还需生产力" << zao[ii].oktime << "点" << endl;
			}
				
		}
		if (flag == true)
		{
			cout << "请输入选项前的编号来选择将生产力投入哪项活动中" << endl;
			cin >> h;
			zao[h].oktime -= prod;
			currenti = h;
			flagd = true;
			current_distribution = '0';
		}
		else
		{
			cout << "你没有正在建造的建筑";
		}
		

	}

	if (m == 2)
	{
		
		if (endmeeting <= 0 && endshow <= 0 && endlogistics <= 0 ) cout << "当前未举办任何活动" << endl;
		else {
			cout << "当前正举办的活动有：" << endl;
			if (endmeeting > 0) cout << "学术会议 " << "还需" <<endmeeting<<"点生产力" <<endl;
			if (endshow > 0) cout << "漫展 " << "还需" << endshow << "点生产力"<<endl;
			if (endlogistics > 0) cout << "工业物流 " << "还需" << endlogistics << "点生产力"<<endl;
			
			int newinput = 0;
			int status = 0;
			
			if (endmeeting > 0 && endshow > 0 && endlogistics >0) status = 1;	//123
			if (endmeeting > 0 && endshow > 0 && endlogistics <= 0) status = 2;	//12
			if (endmeeting > 0 && endshow <= 0 && endlogistics > 0) status = 3;	//13
			if (endmeeting <= 0 && endshow > 0 && endlogistics > 0) status = 4;	//23
			if (endmeeting > 0 && endshow <= 0 && endlogistics <= 0) status = 5;	//1
			if (endmeeting <= 0 && endshow <= 0 && endlogistics > 0) status = 6;	//3
			if (endmeeting <= 0 && endshow > 0 && endlogistics <= 0) status = 7;	//2

			switch (status) {
			case 1:
				cout << "请选择分配生产力的活动：" << endl;
				cout << "1 学术会议\n2 漫展\n3 工业物流\n";
				cin >> newinput;
				if (newinput == 1) {
					endmeeting -= prod ;
					current_distribution = '1';
					cout << "分配成功！" << endl;
					flagd = true;
				}
				else if (newinput == 2) {
					endshow -= prod ;
					current_distribution = '2';
					cout << "分配成功！" << endl;
					flagd = true;
				}
				else if (newinput == 3) {
					endlogistics -= prod ;
					current_distribution = '3';
					cout << "分配成功！" << endl;
					flagd = true;
				}
				else cout << "分配失败" << endl;
				break;
			case 2:
				cout << "请选择分配生产力的活动：" << endl;
				cout << "1 学术会议\n2 漫展\n";
				cin >> newinput;
				if (newinput == 1) {
					endmeeting -= prod;
					current_distribution = '1';
					cout << "分配成功！" << endl;
					flagd = true;
				}
				else if (newinput == 2) {
					endshow -= prod;
					current_distribution = '2';
					cout << "分配成功！" << endl;
					flagd = true;
				}
				else cout << "分配失败" << endl;
				break;
			case 3:
				cout << "请选择分配生产力的活动：" << endl;
				cout << "1 学术会议\n2 工业物流\n";
				cin >> newinput;
				if (newinput == 1) {
					endmeeting -= prod ;
					current_distribution = '1';
					cout << "分配成功！" << endl;
					flagd = true;
				}
				else if (newinput == 2) {
					endlogistics -= prod;
					current_distribution = '3';
					cout << "分配成功！" << endl;
					flagd = true;
				}
				else cout << "分配失败" << endl;
				break;
			case 4:
				cout << "请选择分配生产力的活动：" << endl;
				cout << "1 漫展\n2 工业物流\n";
				cin >> newinput;
				if (newinput == 1) {
					endshow -= prod;
					current_distribution = '2';
					cout << "分配成功！" << endl;
					flagd = true;
				}
				else if (newinput == 2) {
					endlogistics -= prod ;
					current_distribution = '3';
					cout << "分配成功！" << endl;
					flagd = true;
				}
				else cout << "分配失败" << endl;
				break;
			case 5:
				endmeeting -= prod ;
				current_distribution = '1';
				cout << "分配成功！" << endl;
				break;
			case 6:
				endlogistics -= prod;
				current_distribution = '3';
				cout << "分配成功！" << endl;
				break;
			case 7:
				endshow -= prod ;
				current_distribution = '2';
				cout << "分配成功！" << endl;
				break;
			}
			
		}
	}
}

void Controller::updatepop()
{
	double y;
	y = 0.5 * food - allpop;
	if (y == 0) return;
	if (y > 0)
		x += 1 / (1 + 3 / y);
	if (y < 0)
		x -= 1 / (1 + 3 / ( - y));

	if (x >= 1)
	{
		x--;
		allpop++; centrepop++;
	}
	if (x <= -1)
	{
		x++;
		allpop--; mark_remove = 1;
	}
}

void Controller::expansion() {
	int row, col;
	if (allcul == 2 * previouscul) {
		cout << "您的文化值已翻倍，可以扩张一格土地" << endl;
		cout << "请选择是否扩张土地" << endl;
		cout << "0 否\n1 是\n";
		bool choice;
		cin >> choice;
		if (choice == 0) return;
		else {
			cout << "请输入要扩张为土地的坐标（两数字间以空格分隔）" << endl;
			
			cin >> row;
			
			cin >> col;

			bool status = map[row][col].ifpop == WILD && (map[row - 1][col].ifpop != WILD || map[row + 1][col].ifpop != WILD || map[row][col - 1].ifpop != WILD || map[row][col + 1].ifpop != WILD);
				if (status == true) {
					map[row][col].ifpop == OWNED;
				}
				else {
					cout << "该片土地相邻地区为WILD，不能扩张土地" << endl;
					cout << "请输入接下来的操作：" << endl;
					cout << "0 退出扩张土地\n1 重新选择扩张土地坐标" << endl;
					cin >> choice;
					if (choice == 0) return;
					else expansion();
				}
			previouscul = 2 * allcul;
		}
}
	
}



//以下为case1
//static int k = 0;//k用于判断是否第二步，内部运算
bool select_poptrsf(Controller& controller)//调入的类型以cell为主，直接用map【】【】来获取某格子的数据
{
	int m1, n1, m, n;//m is 横坐标，n is 纵坐标
	if (coord_1(controller,m, n) == false) { return false; }
	if (judge_coord_1(controller, m, n) == false) { return false; }
	if (coord_2(controller,m1, n1) == false) { return false; }
	if (judge_coord_2(controller, m1, n1) == false) { return false; }
	poptrsf_inner(controller, m1, n1, m, n);
}
bool coord_1(Controller& controller,int& m, int& n)
{
	cout << "请依次输入要迁移人口的目的土地横纵坐标：" << endl;
	cout << "返回控制面板输入-1;选定市中心输入快捷键-2 " << endl;
	cin >> m;
	if (m == -1) { return false; }
	else if (m == -2) { m = controller.m_centre; n= controller.n_centre; }
	else { cin >> n; }
	while (m < 0 || m>19 || n < 0 || n>19)
	{
		cout << "坐标范围为0-19，请重新输入 " << endl;
		cout << "请依次输入要迁移人口的目的土地横纵坐标：（返回控制面板输入-1）" << endl;
		cin >> m;
		if (m == -1) { return false; }
		cin >> n;
	}
	/*cin >> n;
	while (n < 0 || n>19)
	{
		cout << "坐标范围为0-19，请重新输入： " << endl;
		cout << "请输入横坐标：" << endl;
		cin >> n;
	}*/
	return true;
}
bool coord_2(Controller& controller,int& m1, int& n1)
{
	cout << "请依次输入要迁移人口目前所在土地横纵坐标：" << endl;
	cout << "返回控制面板输入-1;选定市中心输入快捷键-2 " << endl;
	cin >> m1;
	if (m1 == -1) { return false; }
	else if (m1 == -2) { m1 = controller.m_centre; n1 = controller.n_centre; }
	else { cin >> n1; }
	while (m1 < 0 || m1>19 || n1 < 0 || n1>19)
	{
		cout << "坐标范围为0-19，请重新输入 " << endl;
		cout << "请依次输入要迁移人口的目前土地横纵坐标：（返回控制面板输入-1）" << endl;
		cin >> m1;
		if (m1 == -1) { return false; }
		cin >> n1;
	}
	/*cin >> n;
	while (n < 0 || n>19)
	{
		cout << "坐标范围为0-19，请重新输入： " << endl;
		cout << "请输入横坐标：" << endl;
		cin >> n;
	}*/
	return true;
}
bool judge_coord_1(Controller& controller, int& m, int& n)
{
	int i = m;
	int j = n;
	if (controller.map[i][j].landform == OCEAN)
	{
		cout << "地形为深海，无法分配人口,请重新选择" << endl;
		if (coord_1(controller,m, n) == false) { return false; }
		judge_coord_1(controller, m, n);
	}
	else if (controller.map[i][j].landform == MOUNTAIN)
	{
		cout << "地形为山脉，无法分配人口,请重新选择" << endl;
		if (coord_1(controller,m, n) == false) { return false; }
		judge_coord_1(controller, m, n);
	}
	else if (controller.map[i][j].ifpop == WILD)
	{
		cout << "土地未被开发,请重新选择" << endl;
		if (coord_1(controller,m, n) == false) { return false; }
		judge_coord_1(controller, m, n);
	}
	else if (controller.map[i][j].ifpop == COLONIZED)
	{
		cout << "土地人数已满，请重新选择" << endl;
		if (coord_1(controller,m, n) == false) { return false; }
		judge_coord_1(controller, m, n);
	}
	if (controller.map[i][j].ifpop == OWNED) {
		 return true;
	}//符合条件，结束分配
	
}
bool judge_coord_2(Controller& controller, int& m1, int& n1)//对1.中abcde等等判断
{
	
	if (controller.map[m1][n1].ifpop != COLONIZED)
	{
		if (controller.map[m1][n1].type != 6)
		{
			cout << "当前土地没有人，请重新选择" << endl;
			if (coord_2(controller,m1, n1) == false) { return false; }
			judge_coord_2(controller, m1, n1);
		}
		else
		{
			if (controller.centrepop == 0)
			{
				cout << "市中心目前人口为0，请重新选择" << endl;
				if (coord_2(controller,m1, n1) == false) { return false; }
				judge_coord_2(controller,m1, n1);
			}
		}
	}
	
		cout << "移入成功！" << endl;  system("pause"); return true;
	//符合条件，结束分配
}
void poptrsf_inner(Controller& controller, int m1, int n1, int m, int n)
{
	if (controller.map[m][n].type != 6)//先判定目的地块  1.是否为市中心
	{
		if (controller.map[m][n].type = 0)//￥这里填入，当没建筑时
		{
			controller.map[m][n].ifpop = COLONIZED;//令其为无建筑有人
			Landform s = controller.map[m][n].landform; // 判断地形，并修改人口加成
			switch (s)
			{
			case PLAIN:controller.perfood += (2 / controller.allpop); //++controller.prod;
			//case DESERT:++controller.prod;
			case SEA:++controller.perfood+=(1 / controller.allpop); //++controller.perprod;
			case HILLY:controller.perfood += (2 / controller.allpop);// controller.perprod += 2;
			}
		}
		else { controller.map[m][n].ifpop = COLONIZED; }//￥令其为有建筑有人；
	}


	else
	{
		++controller.centrepop;
		controller.perfood += (0.5 / controller.allpop);
		/*controller.pertech += 0.7; controller.percul += 0.3;
		controller.perprod += 0.5; ;*/
	}//是市中心时,人口值加1,其余各值随之增加

	if (controller.map[m1][n1].type != 6)//再判断迁出的地块，不是市中心
	{
		if (controller.map[m1][n1].type = 0)//￥这里填入，当没建筑时
		{
			controller.map[m1][n1].ifpop = OWNED;//￥令其为无建筑无人
			Landform s = controller.map[m1][n1].landform; // 判断地形，并修改人口加成
			switch (s)
			{
			case PLAIN:controller.perfood -= (2 / controller.allpop); //--controller.perprod;
			//case DESERT:--controller.perprod;
			case SEA:--controller.perfood; //--controller.perprod;
			case HILLY:controller.perfood -= (2 / controller.allpop); //controller.perprod -= 2;
			}
		}
		else { controller.map[m1][n1].ifpop = OWNED; }//￥令其为有建筑无人；
	}


	else//是市中心
	{
		--controller.centrepop; controller.perfood -= (0.5 / controller.allpop);
		/*controller.pertech -= 0.7; controller.percul -= 0.3;
		controller.perprod -= 0.5; */
	}//是市中心时,人口迁出使得人口值减一,其余各值随之减少

}


bool Controller::removepop_judge(int& m, int& n)
{
	if (map[m][n].ifpop != COLONIZED)
	{
		if (map[m][n].type != 6)
		{
			cout << "当前土地没有人，请重新选择" << endl;
			cout << "请依次输入土地横纵坐标: " << endl;
			cout << "返回控制面板输入-1;选定市中心输入快捷键-2 " << endl;
			removepop_input(m, n);
		}
		else
		{
			if (centrepop == 0)
			{
				cout << "市中心目前人口为0，请重新选择" << endl;
				cout << "请依次输入土地横纵坐标: " << endl;
				cout << "返回控制面板输入-1;选定市中心输入快捷键-2 " << endl;
				removepop_input(m, n);
			}
			else {
				--centrepop; mark_remove = 0; 
				cout << "完成！" << endl; system("pause"); return true;
			}
		}
	}
	else {
		map[m][n].ifpop = OWNED; mark_remove = 0;
		cout << "完成！" << endl; system("pause"); return true;
	}
}
bool Controller::removepop_input(int&m,int&n)
{
	cin >> m;
	if (m == -1) { return false; }
	if (m == -2) {
		m = m_centre, n = n_centre; 
		removepop_judge(m, n);
	}
	else
	{
		cin >> n;
		removepop_judge(m, n);
	}
	while (m < 0 || m>19 || n < 0 || n>19)
	{
		cout << "坐标范围为0-19，请重新输入 " << endl;
		cout << "请依次输入土地横纵坐标: " << endl;
		cout << "返回控制面板输入-1;选定市中心输入快捷键-2 " << endl;
		cin >> m;
		if (m == -1) { return false; }
		if (m == -2) {
			m = m_centre, n = n_centre;
			removepop_judge(m, n);
		}
		else
		{
			cin >> n;
			removepop_judge(m, n);
		}
	}
	return true;
}
void Controller::removepop()
{   
	int m=0, n=0;
	cout << "由于食物不足，总人口减少了。请选择一块土地减少人口：" << endl;
	cout << "目前市中心人口为 " << centrepop << endl;
	cout << "请依次输入土地横纵坐标: " << endl;
	cout << "返回控制面板输入-1;选定市中心输入快捷键-2 " << endl;
	if (removepop_input(m,n) == false) {
		return;
	}
}

void Controller::setpopBonus()
{
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (map[i][j].ifpop ==COLONIZED)
			{
				if (map[i][j].type == 0)
				{
					switch (map[i][j].landform)
					{
					case OCEAN:
						foodbonus += 1;
						prodbonus += 1;
						break;
					case HILLY:
						foodbonus += 2;
						prodbonus += 2;
						break;
					
					case DESERT:
						foodbonus += 0;
						prodbonus += 1;
						break;
					case SEA:
						foodbonus += 1;
						prodbonus += 0;
				
					case MOUNTAIN:
						foodbonus += 0;
						prodbonus += 0;
						break;
					case PLAIN:
						foodbonus += 2;
						prodbonus += 1;
					default:
						break;
					}
				}
			}
		}
	}

}

void Controller::showall()
{
	
	int i = 0;
	cout << "可用人口为：" << this->allpop << endl;
	cout << "市中心人口为：" << this->centrepop << endl;
	cout << "可用食物为：" << this->food << endl;
	cout << "当前生产力为：" << this->prod << endl;
	cout << "科技值为：" << this->alltech << endl;
	cout << "文化值为：" << this->allcul << endl;
	cout << "分数为：" << this->score << endl;
	cout << "当前正在修建的建筑有：" << endl;

	while (zao[i].type != 0)
	{
		if (zao[i].oktime > 0)
		{
			cout << zao[i].xx << ',' << zao[i].yy << "  ";
			switch (zao[i].type)
			{
			case 1:
				cout << "学院";
				break;
			case 2:
				cout << "剧院广场";
				break;

			case 3:
				cout << "奇观";
				break;

			case 4:
				cout << "工业区";
				break;

			default:
				break;
			}
			cout << " 还需" << zao[i].oktime << "点生产力" << endl;
		}

		i++;
	}

	cout << "当前正在举办的活动有：" << endl;

	if (endmeeting > 0) cout << "学术会议" << ' ' << "还需" << endmeeting << "点生产力" << endl;
	if (endshow > 0) cout << "漫展" << ' ' << "还需" << endshow << "点生产力" << endl;
	if (endlogistics > 0) cout << "工业物流" << ' ' << "还需" << endlogistics << "点生产力" << endl;

	cout << "当前提供的加成有：" << endl;

	int countmeeting = 1, countshow = 1, countlogistics = 1;	//记录活动编号

	for (int j = 0; j < 100; j++) {
		if (lastmeeting[j] > 0) {
			cout << "学术会议" << countmeeting << " 还有 " << lastmeeting[j] << " 回合" << endl;
			countmeeting++;
		}
	}
	for (int k = 0; k < 100; k++) {
		if (lastshow[k] > 0) {
			cout << "漫展" << countshow<<" 还有 " << lastshow[k] << " 回合" << endl;
			countshow++;
		}
	}
	for (int s = 0; s < 100; s++) {
		if (lastlogistics[s] > 0) {
			cout << "工业物流" << countlogistics << " 还有 " << lastlogistics[s] << " 回合" << endl;
			countlogistics++;
		}
		}
	
}