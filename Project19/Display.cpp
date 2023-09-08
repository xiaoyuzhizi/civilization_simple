#include"Display.h"


void Controller::selectcenter()
{
	int m, n;
	cout << "��ѡ�������ĵ����꣺(�����ּ��Կո�ָ�)" << endl;

	cin >> m;

	cin >> n;
	while (this->map[m][n].landform == OCEAN || this->map[m][n].landform == SEA || this->map[m][n].landform == MOUNTAIN)
	{
		cout << "�����Ĳ��ɽ���ɽ�������������������ѡ��" << endl;
		cout << "����������꣺" << endl;
		cin >> m;
		cout << "�����������꣺" << endl;
		cin >> n;
	}
	
	map[m][n].ifpop = OWNED;
	map[m][n].type = 6;
	
	map[m + 1][n].ifpop = OWNED;
	map[m - 1][n].ifpop = OWNED;
	map[m][n + 1].ifpop = OWNED;
	map[m][n - 1].ifpop = OWNED;
	this->m_centre = m; this->n_centre = n;
	cout << "������ѡ����ɣ�" << endl;
	system("pause");
	system("cls");
}

void Controller::build()
{
	int n, x, y;

	//if (zao[2].type == 0) cout << "û����";
	
	cout << "�������Ӧ������ѡ�����뽨��Ľ�������" << endl << "1:ѧԺ" << endl << "2:��Ժ�㳡" << endl << "3:���" << endl << "4:��ҵ��" << endl << "5:�鿴����" << endl;
	cout << "6:������һ���˵�" << endl;

	do {
		cin >> n;




		switch (n)
		{
		case 1:
			//	cout << "��Ҫ" << 100 / prod << "���غ��깤"<<endl;
			zao[idx].oktime = round;
			zao[idx].type = n;
			



			break;
		case 2:
			//	cout << "��Ҫ" << 100 / prod << "���غ��깤" << endl;

			zao[idx].oktime = round;
			zao[idx].type = n;
			
			break;
		case 3:
			//cout << "��Ҫ" << 250 / prod << "���غ��깤" << endl;
			zao[idx].oktime = 2.5 * round;
			zao[idx].type = n;
			
			break;
		case 4:
			//cout << "��Ҫ" << 100 / prod << "���غ��깤" << endl;
			zao[idx].oktime = round;
			zao[idx].type = n;
			
			break;
		case 5:
			cout << "ѧԺ�������˿��ڴ˵�Ԫ��ʱ��+1�Ƽ�ֵ��ÿ���˿��ṩ�ĿƼ�ֵ+0.2��ÿ����һ������+1�Ƽ�ֵ��ÿ����һ��ɽ����ò+1�Ƽ�ֵ����ʵ����������Ϊ��" <<round<< endl;
			cout << "��Ժ�㳡�������˿��ڴ˵�Ԫ��ʱ�� + 1�Ļ�ֵ��ÿ���˿��ṩ���Ļ�ֵ + 0.2��ÿ����һ������ + 1�Ļ�ֵ��ÿ����һ����� + 1�Ļ�ֵ������۽��� + 2�Ļ�ֵ������ʵ����������Ϊ��"<<round << endl;
			cout << "��ۣ� + 20�Ļ�ֵ��ÿ����һ����� + 5�Ļ�ֵ����ʵ����������Ϊ��" <<2.5*round<< endl;
			cout << "��ҵ���������˿��ڴ˵�Ԫ��ʱ�� + 2��������ÿ���˿��ṩ�������� + 2��ÿ����һ������ + 1����������ʵ����������Ϊ��" <<round<< endl;
			cout << "��ע����ʵ���������ģ�������ҪͶ�����������=����������ֵ*��ǰ�غ���/�غ�������" << endl;
			cout << "����ֻ�ܽ��ڳ�������ڣ����ܽ��ڽ��������ɽ����" << endl;
			break;

		case 6:
			return;

		



		}

	} while (n == 5);

	cout << "���������뽨����еĵ�Ԫ�����꣨�����ּ��ÿո�ָ���" << endl;
	cin >> x >> y;
	while (bo[x][y] != 0||map[x][y].ifpop==WILD|| map[x][y].landform==OCEAN|| map[x][y].landform == SEA || map[x][y].landform == MOUNTAIN  )
	{
		cout << "��Ǹ������ǰ�޷�ѡ��˵�Ԫ����ѡ��������Ԫ��" << endl;
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
	cout << "��ѡ��Ҫ���еĲ���" << endl;
	cout << "1������ѧ������" << endl;
	cout << "2��������չ" << endl;
	cout << "3������ҵ����" << endl;
	cout << "4���鿴����" << endl;
	cout << "5��������һ���˵�" << endl;
	cin >> name;
	there1:
	if (name == '1') {
		if (!check('1', endmeeting)) {
			cout << "�޷�����ѧ������" << endl << "��ѡ����������ԵĲ���:" << endl;
			cout << "0 �����˳����л���\n1 ��������ѡ��\n";
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
			cout << "�޷�������չ" << endl << "��ѡ����������ԵĲ���:" << endl;
			cout << "0 �����˳����л���\n1 ��������ѡ��\n";
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
			cout << "�޷����й�ҵ����" << endl << "��ѡ����������ԵĲ���:" << endl;
			cout << "0 �����˳����л���\n1 ��������ѡ��\n";
			cin >> name;
			if (name == '0') return;
			else activity();
		}
		else {
			endlogistics = logistics * round / 100;
			flagp = true;
		}
	}

	if (name == '4') { //�鿴����
		cout << "ѧ�����飺���غ���Ҫ������ʵ������Ϊ" << 50.0 * prod / 100 << " ���ʱ�ṩ5�غϵ�30pop��Ƽ�ֵ"<<endl;
		cout << "��չ�����غ���Ҫ������ʵ������Ϊ" << 50.0 * prod / 100 << " ���ʱ�ṩ5�غϵ�30pop���Ļ�ֵ" << endl;
		cout << "��ҵ���������غ���Ҫ������ʵ������Ϊ" << 50.0 * prod / 100 << " ���ʱ�ṩ5�غϵ�30pop��������" << endl;
		cout << "������������Ĳ�����" << endl;
		cout << "1������ѧ������\n2��������չ\n3������ҵ����\n4��������һ���˵�\n";
		cin >> name;
		if (name == '4') name = '5';
		goto there1;

	}

	if (name == '5') {	//������һ��
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
		cout << "��ϲ�㣡ʤ������";
		flagv = true;
	}
}


bool Controller::check(char name, int endtime) {

	
	    if (name == '1') {
	        if (endmeeting>0) {
	            cout << "��ǰ����ڽ��У�������ѡ��" << endl;
	            return false;
	        }
	    }
	    if (name == '2') {
	        if (endshow > 0) {
	            cout << "��ǰ����ڽ��У�������ѡ��" << endl;
	            return false;
	        }
	    }
	    if (name == '3') {
	        if (endlogistics > 0) {
	            cout << "��ǰ����ڽ��У�������ѡ��" << endl;
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
			cout << "δ��⵽��ѧԺ" << endl;
			return false; 
			break;
		case '2': 
			for (int row = 0; row <= 19; row++) {
				for (int col = 0; col <= 19; col++) {
					if (map[row][col].type == 2) return true;
				}
			}
			cout << "δ��⵽�о�Ժ�㳡" << endl;
			return false; 
			break;
		case '3':
			for (int row = 0; row <= 19; row++) {
				for (int col = 0; col <= 19; col++) {
					if (map[row][col].type == 3) return true;
				}
			}
			cout << "δ��⵽�й�ҵ��" << endl;
			return false;
			break;

	    }
		return false;
}

void Controller::default_statistics(char current_distribution) {
	if (current_distribution == '1') {  // ѧ������
		endmeeting -= prod ;
	}
	if (current_distribution == '2') {  // ��չ
		endshow -= prod ;
	}
	if (current_distribution == '3') {  // ��ҵ����
		endlogistics -= prod ;
	}
	if (current_distribution == '0') {  // ��ҵ����
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
	cout << "����1��ʾ���ڽ��콨��"<<endl<<"����2��ʾ���ھٰ�"<<endl<<"����3��ʾ������һ���˵�"<<endl;
	
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
					cout << ii << ":��" << zao[ii].xx << "," << zao[ii].yy << "ѧԺ�����У�����������" << zao[ii].oktime << "��" << endl;
				if (zao[ii].type == 2)
					cout << ii << ":��" << zao[ii].xx << "," << zao[ii].yy << "��Ժ�㳡�����У�����������" << zao[ii].oktime << "��" << endl;
				if (zao[ii].type == 3)
					cout << ii << ":��" << zao[ii].xx << "," << zao[ii].yy << "��۽����У�����������" << zao[ii].oktime << "��" << endl;
				if (zao[ii].type == 4)
					cout << ii << ":��" << zao[ii].xx << "," << zao[ii].yy << "��ҵ�������У�����������" << zao[ii].oktime << "��" << endl;
			}
				
		}
		if (flag == true)
		{
			cout << "������ѡ��ǰ�ı����ѡ��������Ͷ��������" << endl;
			cin >> h;
			zao[h].oktime -= prod;
			currenti = h;
			flagd = true;
			current_distribution = '0';
		}
		else
		{
			cout << "��û�����ڽ���Ľ���";
		}
		

	}

	if (m == 2)
	{
		
		if (endmeeting <= 0 && endshow <= 0 && endlogistics <= 0 ) cout << "��ǰδ�ٰ��κλ" << endl;
		else {
			cout << "��ǰ���ٰ�Ļ�У�" << endl;
			if (endmeeting > 0) cout << "ѧ������ " << "����" <<endmeeting<<"��������" <<endl;
			if (endshow > 0) cout << "��չ " << "����" << endshow << "��������"<<endl;
			if (endlogistics > 0) cout << "��ҵ���� " << "����" << endlogistics << "��������"<<endl;
			
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
				cout << "��ѡ������������Ļ��" << endl;
				cout << "1 ѧ������\n2 ��չ\n3 ��ҵ����\n";
				cin >> newinput;
				if (newinput == 1) {
					endmeeting -= prod ;
					current_distribution = '1';
					cout << "����ɹ���" << endl;
					flagd = true;
				}
				else if (newinput == 2) {
					endshow -= prod ;
					current_distribution = '2';
					cout << "����ɹ���" << endl;
					flagd = true;
				}
				else if (newinput == 3) {
					endlogistics -= prod ;
					current_distribution = '3';
					cout << "����ɹ���" << endl;
					flagd = true;
				}
				else cout << "����ʧ��" << endl;
				break;
			case 2:
				cout << "��ѡ������������Ļ��" << endl;
				cout << "1 ѧ������\n2 ��չ\n";
				cin >> newinput;
				if (newinput == 1) {
					endmeeting -= prod;
					current_distribution = '1';
					cout << "����ɹ���" << endl;
					flagd = true;
				}
				else if (newinput == 2) {
					endshow -= prod;
					current_distribution = '2';
					cout << "����ɹ���" << endl;
					flagd = true;
				}
				else cout << "����ʧ��" << endl;
				break;
			case 3:
				cout << "��ѡ������������Ļ��" << endl;
				cout << "1 ѧ������\n2 ��ҵ����\n";
				cin >> newinput;
				if (newinput == 1) {
					endmeeting -= prod ;
					current_distribution = '1';
					cout << "����ɹ���" << endl;
					flagd = true;
				}
				else if (newinput == 2) {
					endlogistics -= prod;
					current_distribution = '3';
					cout << "����ɹ���" << endl;
					flagd = true;
				}
				else cout << "����ʧ��" << endl;
				break;
			case 4:
				cout << "��ѡ������������Ļ��" << endl;
				cout << "1 ��չ\n2 ��ҵ����\n";
				cin >> newinput;
				if (newinput == 1) {
					endshow -= prod;
					current_distribution = '2';
					cout << "����ɹ���" << endl;
					flagd = true;
				}
				else if (newinput == 2) {
					endlogistics -= prod ;
					current_distribution = '3';
					cout << "����ɹ���" << endl;
					flagd = true;
				}
				else cout << "����ʧ��" << endl;
				break;
			case 5:
				endmeeting -= prod ;
				current_distribution = '1';
				cout << "����ɹ���" << endl;
				break;
			case 6:
				endlogistics -= prod;
				current_distribution = '3';
				cout << "����ɹ���" << endl;
				break;
			case 7:
				endshow -= prod ;
				current_distribution = '2';
				cout << "����ɹ���" << endl;
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
		cout << "�����Ļ�ֵ�ѷ�������������һ������" << endl;
		cout << "��ѡ���Ƿ���������" << endl;
		cout << "0 ��\n1 ��\n";
		bool choice;
		cin >> choice;
		if (choice == 0) return;
		else {
			cout << "������Ҫ����Ϊ���ص����꣨�����ּ��Կո�ָ���" << endl;
			
			cin >> row;
			
			cin >> col;

			bool status = map[row][col].ifpop == WILD && (map[row - 1][col].ifpop != WILD || map[row + 1][col].ifpop != WILD || map[row][col - 1].ifpop != WILD || map[row][col + 1].ifpop != WILD);
				if (status == true) {
					map[row][col].ifpop == OWNED;
				}
				else {
					cout << "��Ƭ�������ڵ���ΪWILD��������������" << endl;
					cout << "������������Ĳ�����" << endl;
					cout << "0 �˳���������\n1 ����ѡ��������������" << endl;
					cin >> choice;
					if (choice == 0) return;
					else expansion();
				}
			previouscul = 2 * allcul;
		}
}
	
}



//����Ϊcase1
//static int k = 0;//k�����ж��Ƿ�ڶ������ڲ�����
bool select_poptrsf(Controller& controller)//�����������cellΪ����ֱ����map������������ȡĳ���ӵ�����
{
	int m1, n1, m, n;//m is �����꣬n is ������
	if (coord_1(controller,m, n) == false) { return false; }
	if (judge_coord_1(controller, m, n) == false) { return false; }
	if (coord_2(controller,m1, n1) == false) { return false; }
	if (judge_coord_2(controller, m1, n1) == false) { return false; }
	poptrsf_inner(controller, m1, n1, m, n);
}
bool coord_1(Controller& controller,int& m, int& n)
{
	cout << "����������ҪǨ���˿ڵ�Ŀ�����غ������꣺" << endl;
	cout << "���ؿ����������-1;ѡ�������������ݼ�-2 " << endl;
	cin >> m;
	if (m == -1) { return false; }
	else if (m == -2) { m = controller.m_centre; n= controller.n_centre; }
	else { cin >> n; }
	while (m < 0 || m>19 || n < 0 || n>19)
	{
		cout << "���귶ΧΪ0-19������������ " << endl;
		cout << "����������ҪǨ���˿ڵ�Ŀ�����غ������꣺�����ؿ����������-1��" << endl;
		cin >> m;
		if (m == -1) { return false; }
		cin >> n;
	}
	/*cin >> n;
	while (n < 0 || n>19)
	{
		cout << "���귶ΧΪ0-19�����������룺 " << endl;
		cout << "����������꣺" << endl;
		cin >> n;
	}*/
	return true;
}
bool coord_2(Controller& controller,int& m1, int& n1)
{
	cout << "����������ҪǨ���˿�Ŀǰ�������غ������꣺" << endl;
	cout << "���ؿ����������-1;ѡ�������������ݼ�-2 " << endl;
	cin >> m1;
	if (m1 == -1) { return false; }
	else if (m1 == -2) { m1 = controller.m_centre; n1 = controller.n_centre; }
	else { cin >> n1; }
	while (m1 < 0 || m1>19 || n1 < 0 || n1>19)
	{
		cout << "���귶ΧΪ0-19������������ " << endl;
		cout << "����������ҪǨ���˿ڵ�Ŀǰ���غ������꣺�����ؿ����������-1��" << endl;
		cin >> m1;
		if (m1 == -1) { return false; }
		cin >> n1;
	}
	/*cin >> n;
	while (n < 0 || n>19)
	{
		cout << "���귶ΧΪ0-19�����������룺 " << endl;
		cout << "����������꣺" << endl;
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
		cout << "����Ϊ����޷������˿�,������ѡ��" << endl;
		if (coord_1(controller,m, n) == false) { return false; }
		judge_coord_1(controller, m, n);
	}
	else if (controller.map[i][j].landform == MOUNTAIN)
	{
		cout << "����Ϊɽ�����޷������˿�,������ѡ��" << endl;
		if (coord_1(controller,m, n) == false) { return false; }
		judge_coord_1(controller, m, n);
	}
	else if (controller.map[i][j].ifpop == WILD)
	{
		cout << "����δ������,������ѡ��" << endl;
		if (coord_1(controller,m, n) == false) { return false; }
		judge_coord_1(controller, m, n);
	}
	else if (controller.map[i][j].ifpop == COLONIZED)
	{
		cout << "��������������������ѡ��" << endl;
		if (coord_1(controller,m, n) == false) { return false; }
		judge_coord_1(controller, m, n);
	}
	if (controller.map[i][j].ifpop == OWNED) {
		 return true;
	}//������������������
	
}
bool judge_coord_2(Controller& controller, int& m1, int& n1)//��1.��abcde�ȵ��ж�
{
	
	if (controller.map[m1][n1].ifpop != COLONIZED)
	{
		if (controller.map[m1][n1].type != 6)
		{
			cout << "��ǰ����û���ˣ�������ѡ��" << endl;
			if (coord_2(controller,m1, n1) == false) { return false; }
			judge_coord_2(controller, m1, n1);
		}
		else
		{
			if (controller.centrepop == 0)
			{
				cout << "������Ŀǰ�˿�Ϊ0��������ѡ��" << endl;
				if (coord_2(controller,m1, n1) == false) { return false; }
				judge_coord_2(controller,m1, n1);
			}
		}
	}
	
		cout << "����ɹ���" << endl;  system("pause"); return true;
	//������������������
}
void poptrsf_inner(Controller& controller, int m1, int n1, int m, int n)
{
	if (controller.map[m][n].type != 6)//���ж�Ŀ�ĵؿ�  1.�Ƿ�Ϊ������
	{
		if (controller.map[m][n].type = 0)//���������룬��û����ʱ
		{
			controller.map[m][n].ifpop = COLONIZED;//����Ϊ�޽�������
			Landform s = controller.map[m][n].landform; // �жϵ��Σ����޸��˿ڼӳ�
			switch (s)
			{
			case PLAIN:controller.perfood += (2 / controller.allpop); //++controller.prod;
			//case DESERT:++controller.prod;
			case SEA:++controller.perfood+=(1 / controller.allpop); //++controller.perprod;
			case HILLY:controller.perfood += (2 / controller.allpop);// controller.perprod += 2;
			}
		}
		else { controller.map[m][n].ifpop = COLONIZED; }//������Ϊ�н������ˣ�
	}


	else
	{
		++controller.centrepop;
		controller.perfood += (0.5 / controller.allpop);
		/*controller.pertech += 0.7; controller.percul += 0.3;
		controller.perprod += 0.5; ;*/
	}//��������ʱ,�˿�ֵ��1,�����ֵ��֮����

	if (controller.map[m1][n1].type != 6)//���ж�Ǩ���ĵؿ飬����������
	{
		if (controller.map[m1][n1].type = 0)//���������룬��û����ʱ
		{
			controller.map[m1][n1].ifpop = OWNED;//������Ϊ�޽�������
			Landform s = controller.map[m1][n1].landform; // �жϵ��Σ����޸��˿ڼӳ�
			switch (s)
			{
			case PLAIN:controller.perfood -= (2 / controller.allpop); //--controller.perprod;
			//case DESERT:--controller.perprod;
			case SEA:--controller.perfood; //--controller.perprod;
			case HILLY:controller.perfood -= (2 / controller.allpop); //controller.perprod -= 2;
			}
		}
		else { controller.map[m1][n1].ifpop = OWNED; }//������Ϊ�н������ˣ�
	}


	else//��������
	{
		--controller.centrepop; controller.perfood -= (0.5 / controller.allpop);
		/*controller.pertech -= 0.7; controller.percul -= 0.3;
		controller.perprod -= 0.5; */
	}//��������ʱ,�˿�Ǩ��ʹ���˿�ֵ��һ,�����ֵ��֮����

}


bool Controller::removepop_judge(int& m, int& n)
{
	if (map[m][n].ifpop != COLONIZED)
	{
		if (map[m][n].type != 6)
		{
			cout << "��ǰ����û���ˣ�������ѡ��" << endl;
			cout << "�������������غ�������: " << endl;
			cout << "���ؿ����������-1;ѡ�������������ݼ�-2 " << endl;
			removepop_input(m, n);
		}
		else
		{
			if (centrepop == 0)
			{
				cout << "������Ŀǰ�˿�Ϊ0��������ѡ��" << endl;
				cout << "�������������غ�������: " << endl;
				cout << "���ؿ����������-1;ѡ�������������ݼ�-2 " << endl;
				removepop_input(m, n);
			}
			else {
				--centrepop; mark_remove = 0; 
				cout << "��ɣ�" << endl; system("pause"); return true;
			}
		}
	}
	else {
		map[m][n].ifpop = OWNED; mark_remove = 0;
		cout << "��ɣ�" << endl; system("pause"); return true;
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
		cout << "���귶ΧΪ0-19������������ " << endl;
		cout << "�������������غ�������: " << endl;
		cout << "���ؿ����������-1;ѡ�������������ݼ�-2 " << endl;
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
	cout << "����ʳ�ﲻ�㣬���˿ڼ����ˡ���ѡ��һ�����ؼ����˿ڣ�" << endl;
	cout << "Ŀǰ�������˿�Ϊ " << centrepop << endl;
	cout << "�������������غ�������: " << endl;
	cout << "���ؿ����������-1;ѡ�������������ݼ�-2 " << endl;
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
	cout << "�����˿�Ϊ��" << this->allpop << endl;
	cout << "�������˿�Ϊ��" << this->centrepop << endl;
	cout << "����ʳ��Ϊ��" << this->food << endl;
	cout << "��ǰ������Ϊ��" << this->prod << endl;
	cout << "�Ƽ�ֵΪ��" << this->alltech << endl;
	cout << "�Ļ�ֵΪ��" << this->allcul << endl;
	cout << "����Ϊ��" << this->score << endl;
	cout << "��ǰ�����޽��Ľ����У�" << endl;

	while (zao[i].type != 0)
	{
		if (zao[i].oktime > 0)
		{
			cout << zao[i].xx << ',' << zao[i].yy << "  ";
			switch (zao[i].type)
			{
			case 1:
				cout << "ѧԺ";
				break;
			case 2:
				cout << "��Ժ�㳡";
				break;

			case 3:
				cout << "���";
				break;

			case 4:
				cout << "��ҵ��";
				break;

			default:
				break;
			}
			cout << " ����" << zao[i].oktime << "��������" << endl;
		}

		i++;
	}

	cout << "��ǰ���ھٰ�Ļ�У�" << endl;

	if (endmeeting > 0) cout << "ѧ������" << ' ' << "����" << endmeeting << "��������" << endl;
	if (endshow > 0) cout << "��չ" << ' ' << "����" << endshow << "��������" << endl;
	if (endlogistics > 0) cout << "��ҵ����" << ' ' << "����" << endlogistics << "��������" << endl;

	cout << "��ǰ�ṩ�ļӳ��У�" << endl;

	int countmeeting = 1, countshow = 1, countlogistics = 1;	//��¼����

	for (int j = 0; j < 100; j++) {
		if (lastmeeting[j] > 0) {
			cout << "ѧ������" << countmeeting << " ���� " << lastmeeting[j] << " �غ�" << endl;
			countmeeting++;
		}
	}
	for (int k = 0; k < 100; k++) {
		if (lastshow[k] > 0) {
			cout << "��չ" << countshow<<" ���� " << lastshow[k] << " �غ�" << endl;
			countshow++;
		}
	}
	for (int s = 0; s < 100; s++) {
		if (lastlogistics[s] > 0) {
			cout << "��ҵ����" << countlogistics << " ���� " << lastlogistics[s] << " �غ�" << endl;
			countlogistics++;
		}
		}
	
}