#include"Display.h"


void Controller::selectcenter()
{
	int m, n;
	cout << "«Î—°‘Ò –÷––ƒµƒ◊¯±Í£∫(¡Ω ˝◊÷º‰“‘ø’∏Ò∑÷∏Ù)" << endl;

	cin >> m;

	cin >> n;
	while (this->map[m][n].landform == OCEAN || this->map[m][n].landform == SEA || this->map[m][n].landform == MOUNTAIN)
	{
		cout << " –÷––ƒ≤ªø…Ω®‘⁄…Ω¬ˆ£¨Ω¸∫££¨…Ó∫££¨«Î÷ÿ–¬—°‘Ò£∫" << endl;
		cout << "«Î ‰»Î∫·◊¯±Í£∫" << endl;
		cin >> m;
		cout << "«Î ‰»Î◊›◊¯±Í£∫" << endl;
		cin >> n;
	}
	
	map[m][n].ifpop = OWNED;
	map[m][n].type = 6;
	
	map[m + 1][n].ifpop = OWNED;
	map[m - 1][n].ifpop = OWNED;
	map[m][n + 1].ifpop = OWNED;
	map[m][n - 1].ifpop = OWNED;
	this->m_centre = m; this->n_centre = n;
	cout << " –÷––ƒ—°‘ÒÕÍ≥…£∫" << endl;
	system("pause");
	system("cls");
}

void Controller::build()
{
	int n, x, y;

	//if (zao[2].type == 0) cout << "√ªµΩ’‚";
	
	cout << "«Î ‰»Î∂‘”¶ ˝◊÷“‘—°‘Òƒ„œÎΩ®‘ÏµƒΩ®÷˛÷÷¿‡" << endl << "1:—ß‘∫" << endl << "2:æÁ‘∫π„≥°" << endl << "3:∆Êπ€" << endl << "4:π§“µ«¯" << endl << "5:≤Èø¥∞Ô÷˙" << endl;
	cout << "6:∑µªÿ…œ“ªº∂≤Àµ•" << endl;

	do {
		cin >> n;




		switch (n)
		{
		case 1:
			//	cout << "–Ë“™" << 100 / prod << "∏ˆªÿ∫œÕÍπ§"<<endl;
			zao[idx].oktime = round;
			zao[idx].type = n;
			



			break;
		case 2:
			//	cout << "–Ë“™" << 100 / prod << "∏ˆªÿ∫œÕÍπ§" << endl;

			zao[idx].oktime = round;
			zao[idx].type = n;
			
			break;
		case 3:
			//cout << "–Ë“™" << 250 / prod << "∏ˆªÿ∫œÕÍπ§" << endl;
			zao[idx].oktime = 2.5 * round;
			zao[idx].type = n;
			
			break;
		case 4:
			//cout << "–Ë“™" << 100 / prod << "∏ˆªÿ∫œÕÍπ§" << endl;
			zao[idx].oktime = round;
			zao[idx].type = n;
			
			break;
		case 5:
			cout << "—ß‘∫£∫µ±”–»Àø⁄‘⁄¥Àµ•‘™∏Ò ±£¨+1ø∆ºº÷µ£¨√ø∏ˆ»Àø⁄Ã·π©µƒø∆ºº÷µ+0.2£¨√øœ‡¡⁄“ª∏ˆ«¯”Ú+1ø∆ºº÷µ£¨√øœ‡¡⁄“ª∏ˆ…Ω¬ˆµÿ√≤+1ø∆ºº÷µ°£’Ê µ…˙≤˙¡¶œ˚∫ƒŒ™£∫" <<round<< endl;
			cout << "æÁ‘∫π„≥°£∫µ±”–»Àø⁄‘⁄¥Àµ•‘™∏Ò ±£¨ + 1ŒƒªØ÷µ£¨√ø∏ˆ»Àø⁄Ã·π©µƒŒƒªØ÷µ + 0.2£¨√øœ‡¡⁄“ª∏ˆ«¯”Ú + 1ŒƒªØ÷µ£¨√øœ‡¡⁄“ª∏ˆ∆Êπ€ + 1ŒƒªØ÷µ£®º¥∆Êπ€Ω®÷˛ + 2ŒƒªØ÷µ£©°£’Ê µ…˙≤˙¡¶œ˚∫ƒŒ™£∫"<<round << endl;
			cout << "∆Êπ€£∫ + 20ŒƒªØ÷µ°£√øœ‡¡⁄“ª∏ˆ∆Êπ€ + 5ŒƒªØ÷µ°£’Ê µ…˙≤˙¡¶œ˚∫ƒŒ™£∫" <<2.5*round<< endl;
			cout << "π§“µ«¯£∫µ±”–»Àø⁄‘⁄¥Àµ•‘™∏Ò ±£¨ + 2…˙≤˙¡¶£¨√ø∏ˆ»Àø⁄Ã·π©µƒ…˙≤˙¡¶ + 2£¨√øœ‡¡⁄“ª∏ˆ«¯”Ú + 1…˙≤˙¡¶°£’Ê µ…˙≤˙¡¶œ˚∫ƒŒ™£∫" <<round<< endl;
			cout << "±∏◊¢£∫’Ê µ…˙≤˙¡¶œ˚∫ƒ£®º¥À˘–Ë“™Õ∂»Îµƒ…˙≤˙¡¶£©=…˙≤˙¡¶ª˘¥°÷µ*µ±«∞ªÿ∫œ ˝/ªÿ∫œ◊‹ ˝°£" << endl;
			cout << "Ω®÷˛÷ªƒ‹Ω®‘⁄≥« –¡Ïµÿƒ⁄£¨≤ªƒ‹Ω®‘⁄Ω¸∫£°¢…Ó∫£ªÚ…Ω¬ˆ…œ" << endl;
			break;

		case 6:
			return;

		



		}

	} while (n == 5);

	cout << "«Î ‰»Îƒ˙œÎΩ®‘Ï≥« –µƒµ•‘™∏Ò◊¯±Í£®¡Ω ˝◊÷º‰”√ø’∏Ò∑÷∏Ù£©" << endl;
	cin >> x >> y;
	while (bo[x][y] != 0||map[x][y].ifpop==WILD|| map[x][y].landform==OCEAN|| map[x][y].landform == SEA || map[x][y].landform == MOUNTAIN  )
	{
		cout << "±ß«∏£¨ƒ˙µ±«∞Œﬁ∑®—°‘Ò¥Àµ•‘™∏Ò£¨«Î—°‘Ò∆‰À˚µ•‘™∏Ò" << endl;
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
	cout << "«Î—°‘Ò“™Ω¯––µƒ≤Ÿ◊˜" << endl;
	cout << "1£∫¥˙±Ì—ß ıª·“È" << endl;
	cout << "2£∫¥˙±Ì¬˛’π" << endl;
	cout << "3£∫¥˙±Ìπ§“µŒÔ¡˜" << endl;
	cout << "4£∫≤Èø¥∞Ô÷˙" << endl;
	cout << "5£∫∑µªÿ…œ“ªº∂≤Àµ•" << endl;
	cin >> name;
	there1:
	if (name == '1') {
		if (!check('1', endmeeting)) {
			cout << "Œﬁ∑®Ω¯––—ß ıª·“È" << endl << "«Î—°‘ÒΩ”œ¬¿¥≥¢ ‘µƒ≤Ω÷Ë:" << endl;
			cout << "0 ¥˙±ÌÕÀ≥ˆæŸ––ª·“È\n1 ¥˙±Ì÷ÿ–¬—°‘Ò\n";
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
			cout << "Œﬁ∑®Ω¯––¬˛’π" << endl << "«Î—°‘ÒΩ”œ¬¿¥≥¢ ‘µƒ≤Ω÷Ë:" << endl;
			cout << "0 ¥˙±ÌÕÀ≥ˆæŸ––ª·“È\n1 ¥˙±Ì÷ÿ–¬—°‘Ò\n";
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
			cout << "Œﬁ∑®Ω¯––π§“µŒÔ¡˜" << endl << "«Î—°‘ÒΩ”œ¬¿¥≥¢ ‘µƒ≤Ω÷Ë:" << endl;
			cout << "0 ¥˙±ÌÕÀ≥ˆæŸ––ª·“È\n1 ¥˙±Ì÷ÿ–¬—°‘Ò\n";
			cin >> name;
			if (name == '0') return;
			else activity();
		}
		else {
			endlogistics = logistics * round / 100;
			flagp = true;
		}
	}

	if (name == '4') { //≤Èø¥∞Ô÷˙
		cout << "—ß ıª·“È£∫±æªÿ∫œ–Ë“™œ˚∫ƒ’Ê µ…˙≤˙¡¶Œ™" << 50.0 * prod / 100 << " ÕÍ≥… ±Ã·π©5ªÿ∫œµƒ30popµ„ø∆ºº÷µ"<<endl;
		cout << "¬˛’π£∫±æªÿ∫œ–Ë“™œ˚∫ƒ’Ê µ…˙≤˙¡¶Œ™" << 50.0 * prod / 100 << " ÕÍ≥… ±Ã·π©5ªÿ∫œµƒ30popµ„ŒƒªØ÷µ" << endl;
		cout << "π§“µŒÔ¡˜£∫±æªÿ∫œ–Ë“™œ˚∫ƒ’Ê µ…˙≤˙¡¶Œ™" << 50.0 * prod / 100 << " ÕÍ≥… ±Ã·π©5ªÿ∫œµƒ30popµ„…˙≤˙¡¶" << endl;
		cout << "«Î ‰»ÎΩ”œ¬¿¥µƒ≤Ÿ◊˜£∫" << endl;
		cout << "1£∫¥˙±Ì—ß ıª·“È\n2£∫¥˙±Ì¬˛’π\n3£∫¥˙±Ìπ§“µŒÔ¡˜\n4£∫∑µªÿ…œ“ªº∂≤Àµ•\n";
		cin >> name;
		if (name == '4') name = '5';
		goto there1;

	}

	if (name == '5') {	//∑µªÿ…œ“ªº∂
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
		cout << "πßœ≤ƒ„£° §¿˚¿≤£°";
		flagv = true;
	}
}


bool Controller::check(char name, int endtime) {

	
	    if (name == '1') {
	        if (endmeeting>0) {
	            cout << "µ±«∞ªÓ∂Ø’˝‘⁄Ω¯––£¨«Î÷ÿ–¬—°‘ÒªÓ∂Ø" << endl;
	            return false;
	        }
	    }
	    if (name == '2') {
	        if (endshow > 0) {
	            cout << "µ±«∞ªÓ∂Ø’˝‘⁄Ω¯––£¨«Î÷ÿ–¬—°‘ÒªÓ∂Ø" << endl;
	            return false;
	        }
	    }
	    if (name == '3') {
	        if (endlogistics > 0) {
	            cout << "µ±«∞ªÓ∂Ø’˝‘⁄Ω¯––£¨«Î÷ÿ–¬—°‘ÒªÓ∂Ø" << endl;
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
			cout << "Œ¥ºÏ≤‚µΩ”–—ß‘∫" << endl;
			return false; 
			break;
		case '2': 
			for (int row = 0; row <= 19; row++) {
				for (int col = 0; col <= 19; col++) {
					if (map[row][col].type == 2) return true;
				}
			}
			cout << "Œ¥ºÏ≤‚µΩ”–æÁ‘∫π„≥°" << endl;
			return false; 
			break;
		case '3':
			for (int row = 0; row <= 19; row++) {
				for (int col = 0; col <= 19; col++) {
					if (map[row][col].type == 3) return true;
				}
			}
			cout << "Œ¥ºÏ≤‚µΩ”–π§“µ«¯" << endl;
			return false;
			break;

	    }
		return false;
}

void Controller::default_statistics(char current_distribution) {
	if (current_distribution == '1') {  // —ß ıª·“È
		endmeeting -= prod ;
		if (endmeeting <= 0) lastmeeting[round] = 5;
	}
	if (current_distribution == '2') {  // ¬˛’π
		endshow -= prod ;
		if (endshow <= 0) lastshow[round] = 5;
	}
	if (current_distribution == '3') {  // π§“µŒÔ¡˜
		endlogistics -= prod ;
		if (endlogistics <= 0) lastlogistics[round] = 5;
	}
	if (current_distribution == '0') {  // π§“µŒÔ¡˜
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
	cout << " ‰»Î1±Ì æ”√”⁄Ω®‘ÏΩ®÷˛"<<endl<<" ‰»Î2±Ì æ”√”⁄æŸ∞ÏªÓ∂Ø"<<endl<<" ‰»Î3±Ì æ∑µªÿ…œ“ªº∂≤Àµ•"<<endl;
	
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
					cout << ii << ":‘⁄" << zao[ii].xx << "," << zao[ii].yy << "—ß‘∫Ω®‘Ï÷–£¨ªπ–Ë…˙≤˙¡¶" << zao[ii].oktime << "µ„" << endl;
				if (zao[ii].type == 2)
					cout << ii << ":‘⁄" << zao[ii].xx << "," << zao[ii].yy << "æÁ‘∫π„≥°Ω®‘Ï÷–£¨ªπ–Ë…˙≤˙¡¶" << zao[ii].oktime << "µ„" << endl;
				if (zao[ii].type == 3)
					cout << ii << ":‘⁄" << zao[ii].xx << "," << zao[ii].yy << "∆Êπ€Ω®‘Ï÷–£¨ªπ–Ë…˙≤˙¡¶" << zao[ii].oktime << "µ„" << endl;
				if (zao[ii].type == 4)
					cout << ii << ":‘⁄" << zao[ii].xx << "," << zao[ii].yy << "π§“µ«¯Ω®‘Ï÷–£¨ªπ–Ë…˙≤˙¡¶" << zao[ii].oktime << "µ„" << endl;
			}
				
		}
		if (flag == true)
		{
			cout << "«Î ‰»Î—°œÓ«∞µƒ±‡∫≈¿¥—°‘ÒΩ´…˙≤˙¡¶Õ∂»ÎƒƒœÓªÓ∂Ø÷–" << endl;
			cin >> h;
			zao[h].oktime -= prod;
			currenti = h;
			flagd = true;
			current_distribution = '0';
		}
		else
		{
			cout << "ƒ„√ª”–’˝‘⁄Ω®‘ÏµƒΩ®÷˛";
		}
		

	}

	if (m == 2)
	{
		
		if (endmeeting <= 0 && endshow <= 0 && endlogistics <= 0 ) cout << "µ±«∞Œ¥æŸ∞Ï»Œ∫ŒªÓ∂Ø" << endl;
		else {
			cout << "µ±«∞’˝æŸ∞ÏµƒªÓ∂Ø”–£∫" << endl;
			if (endmeeting > 0) cout << "—ß ıª·“È " << "ªπ–Ë" <<endmeeting<<"µ„…˙≤˙¡¶" <<endl;
			if (endshow > 0) cout << "¬˛’π " << "ªπ–Ë" << endshow << "µ„…˙≤˙¡¶"<<endl;
			if (endlogistics > 0) cout << "π§“µŒÔ¡˜ " << "ªπ–Ë" << endlogistics << "µ„…˙≤˙¡¶"<<endl;
			
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
				cout << "«Î—°‘Ò∑÷≈‰…˙≤˙¡¶µƒªÓ∂Ø£∫" << endl;
				cout << "1 —ß ıª·“È\n2 ¬˛’π\n3 π§“µŒÔ¡˜\n";
				cin >> newinput;
				if (newinput == 1) {
					endmeeting -= prod ;
					current_distribution = '1';
					cout << "∑÷≈‰≥…π¶£°" << endl;
					flagd = true;
				}
				else if (newinput == 2) {
					endshow -= prod ;
					current_distribution = '2';
					cout << "∑÷≈‰≥…π¶£°" << endl;
					flagd = true;
				}
				else if (newinput == 3) {
					endlogistics -= prod ;
					current_distribution = '3';
					cout << "∑÷≈‰≥…π¶£°" << endl;
					flagd = true;
				}
				else cout << "∑÷≈‰ ß∞‹" << endl;
				break;
			case 2:
				cout << "«Î—°‘Ò∑÷≈‰…˙≤˙¡¶µƒªÓ∂Ø£∫" << endl;
				cout << "1 —ß ıª·“È\n2 ¬˛’π\n";
				cin >> newinput;
				if (newinput == 1) {
					endmeeting -= prod;
					current_distribution = '1';
					cout << "∑÷≈‰≥…π¶£°" << endl;
					flagd = true;
				}
				else if (newinput == 2) {
					endshow -= prod;
					current_distribution = '2';
					cout << "∑÷≈‰≥…π¶£°" << endl;
					flagd = true;
				}
				else cout << "∑÷≈‰ ß∞‹" << endl;
				break;
			case 3:
				cout << "«Î—°‘Ò∑÷≈‰…˙≤˙¡¶µƒªÓ∂Ø£∫" << endl;
				cout << "1 —ß ıª·“È\n2 π§“µŒÔ¡˜\n";
				cin >> newinput;
				if (newinput == 1) {
					endmeeting -= prod ;
					current_distribution = '1';
					cout << "∑÷≈‰≥…π¶£°" << endl;
					flagd = true;
				}
				else if (newinput == 2) {
					endlogistics -= prod;
					current_distribution = '3';
					cout << "∑÷≈‰≥…π¶£°" << endl;
					flagd = true;
				}
				else cout << "∑÷≈‰ ß∞‹" << endl;
				break;
			case 4:
				cout << "«Î—°‘Ò∑÷≈‰…˙≤˙¡¶µƒªÓ∂Ø£∫" << endl;
				cout << "1 ¬˛’π\n2 π§“µŒÔ¡˜\n";
				cin >> newinput;
				if (newinput == 1) {
					endshow -= prod;
					current_distribution = '2';
					cout << "∑÷≈‰≥…π¶£°" << endl;
					flagd = true;
				}
				else if (newinput == 2) {
					endlogistics -= prod ;
					current_distribution = '3';
					cout << "∑÷≈‰≥…π¶£°" << endl;
					flagd = true;
				}
				else cout << "∑÷≈‰ ß∞‹" << endl;
				break;
			case 5:
				endmeeting -= prod ;
				current_distribution = '1';
				cout << "∑÷≈‰≥…π¶£°" << endl;
				break;
			case 6:
				endlogistics -= prod;
				current_distribution = '3';
				cout << "∑÷≈‰≥…π¶£°" << endl;
				break;
			case 7:
				endshow -= prod ;
				current_distribution = '2';
				cout << "∑÷≈‰≥…π¶£°" << endl;
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
	if (allcul >= 2 * previouscul) {
		cout << "ƒ˙µƒŒƒªØ÷µ“—∑≠±∂£¨ø…“‘¿©’≈“ª∏ÒÕ¡µÿ" << endl;
		cout << "«Î—°‘Ò «∑Ò¿©’≈Õ¡µÿ" << endl;
		cout << "0 ∑Ò\n1  «\n";
		bool choice;
		cin >> choice;
		if (choice == 0) return;
		else {
			
			cout << "«Î ‰»Î“™¿©’≈Œ™Õ¡µÿµƒ◊¯±Í£®¡Ω ˝◊÷º‰“‘ø’∏Ò∑÷∏Ù£©" << endl;
			
			cin >> row;
			
			cin >> col;

			bool status = map[row][col].ifpop == WILD && (map[row - 1][col].ifpop != WILD || map[row + 1][col].ifpop != WILD || map[row][col - 1].ifpop != WILD || map[row][col + 1].ifpop != WILD);
				if (status == true) {
					map[row][col].ifpop = OWNED;
				}
				else {
					cout << "∏√∆¨Õ¡µÿœ‡¡⁄µÿ«¯Œ™WILD£¨≤ªƒ‹¿©’≈Õ¡µÿ" << endl;
					cout << "«Î ‰»ÎΩ”œ¬¿¥µƒ≤Ÿ◊˜£∫" << endl;
					cout << "0 ÕÀ≥ˆ¿©’≈Õ¡µÿ\n1 ÷ÿ–¬—°‘Ò¿©’≈Õ¡µÿ◊¯±Í" << endl;
					cin >> choice;
					if (choice == 0) return;
					else expansion();
				}
			previouscul = 2 * allcul;
		}
}
	
}



//“‘œ¬Œ™case1
//static int k = 0;//k”√”⁄≈–∂œ «∑Òµ⁄∂˛≤Ω£¨ƒ⁄≤ø‘ÀÀ„
bool select_poptrsf(Controller& controller)//µ˜»Îµƒ¿‡–Õ“‘cellŒ™÷˜£¨÷±Ω””√map°æ°ø°æ°ø¿¥ªÒ»°ƒ≥∏Ò◊”µƒ ˝æ›
{
	int m1, n1, m, n;//m is ∫·◊¯±Í£¨n is ◊›◊¯±Í
	if (coord_1(controller,m, n) == false) { return false; }
	if (judge_coord_1(controller, m, n) == false) { return false; }
	if (coord_2(controller,m1, n1) == false) { return false; }
	if (judge_coord_2(controller, m1, n1) == false) { return false; }
	poptrsf_inner(controller, m1, n1, m, n);
}
bool coord_1(Controller& controller,int& m, int& n)
{
	cout << "«Î“¿¥Œ ‰»Î“™«®“∆»Àø⁄µƒƒøµƒÕ¡µÿ∫·◊›◊¯±Í£∫" << endl;
	cout << "∑µªÿøÿ÷∆√Ê∞Â ‰»Î-1;—°∂® –÷––ƒ ‰»ÎøÏΩ›º¸-2 " << endl;
	cin >> m;
	if (m == -1) { return false; }
	else if (m == -2) { m = controller.m_centre; n= controller.n_centre; }
	else { cin >> n; }
	while (m < 0 || m>19 || n < 0 || n>19)
	{
		cout << "◊¯±Í∑∂ŒßŒ™0-19£¨«Î÷ÿ–¬ ‰»Î " << endl;
		cout << "«Î“¿¥Œ ‰»Î“™«®“∆»Àø⁄µƒƒøµƒÕ¡µÿ∫·◊›◊¯±Í£∫£®∑µªÿøÿ÷∆√Ê∞Â ‰»Î-1£©" << endl;
		cin >> m;
		if (m == -1) { return false; }
		cin >> n;
	}
	/*cin >> n;
	while (n < 0 || n>19)
	{
		cout << "◊¯±Í∑∂ŒßŒ™0-19£¨«Î÷ÿ–¬ ‰»Î£∫ " << endl;
		cout << "«Î ‰»Î∫·◊¯±Í£∫" << endl;
		cin >> n;
	}*/
	return true;
}
bool coord_2(Controller& controller,int& m1, int& n1)
{
	cout << "«Î“¿¥Œ ‰»Î“™«®“∆»Àø⁄ƒø«∞À˘‘⁄Õ¡µÿ∫·◊›◊¯±Í£∫" << endl;
	cout << "∑µªÿøÿ÷∆√Ê∞Â ‰»Î-1;—°∂® –÷––ƒ ‰»ÎøÏΩ›º¸-2 " << endl;
	cin >> m1;
	if (m1 == -1) { return false; }
	else if (m1 == -2) { m1 = controller.m_centre; n1 = controller.n_centre; }
	else { cin >> n1; }
	while (m1 < 0 || m1>19 || n1 < 0 || n1>19)
	{
		cout << "◊¯±Í∑∂ŒßŒ™0-19£¨«Î÷ÿ–¬ ‰»Î " << endl;
		cout << "«Î“¿¥Œ ‰»Î“™«®“∆»Àø⁄µƒƒø«∞Õ¡µÿ∫·◊›◊¯±Í£∫£®∑µªÿøÿ÷∆√Ê∞Â ‰»Î-1£©" << endl;
		cin >> m1;
		if (m1 == -1) { return false; }
		cin >> n1;
	}
	/*cin >> n;
	while (n < 0 || n>19)
	{
		cout << "◊¯±Í∑∂ŒßŒ™0-19£¨«Î÷ÿ–¬ ‰»Î£∫ " << endl;
		cout << "«Î ‰»Î∫·◊¯±Í£∫" << endl;
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
		cout << "µÿ–ŒŒ™…Ó∫££¨Œﬁ∑®∑÷≈‰»Àø⁄,«Î÷ÿ–¬—°‘Ò" << endl;
		if (coord_1(controller,m, n) == false) { return false; }
		judge_coord_1(controller, m, n);
	}
	else if (controller.map[i][j].landform == MOUNTAIN)
	{
		cout << "µÿ–ŒŒ™…Ω¬ˆ£¨Œﬁ∑®∑÷≈‰»Àø⁄,«Î÷ÿ–¬—°‘Ò" << endl;
		if (coord_1(controller,m, n) == false) { return false; }
		judge_coord_1(controller, m, n);
	}
	else if (controller.map[i][j].ifpop == WILD)
	{
		cout << "Õ¡µÿŒ¥±ªø™∑¢,«Î÷ÿ–¬—°‘Ò" << endl;
		if (coord_1(controller,m, n) == false) { return false; }
		judge_coord_1(controller, m, n);
	}
	else if (controller.map[i][j].ifpop == COLONIZED)
	{
		cout << "Õ¡µÿ»À ˝“—¬˙£¨«Î÷ÿ–¬—°‘Ò" << endl;
		if (coord_1(controller,m, n) == false) { return false; }
		judge_coord_1(controller, m, n);
	}
	if (controller.map[i][j].ifpop == OWNED) {
		 return true;
	}//∑˚∫œÃıº˛£¨Ω· ¯∑÷≈‰
	
}
bool judge_coord_2(Controller& controller, int& m1, int& n1)//∂‘1.÷–abcdeµ»µ»≈–∂œ
{
	
	if (controller.map[m1][n1].ifpop != COLONIZED)
	{
		if (controller.map[m1][n1].type != 6)
		{
			cout << "µ±«∞Õ¡µÿ√ª”–»À£¨«Î÷ÿ–¬—°‘Ò" << endl;
			if (coord_2(controller,m1, n1) == false) { return false; }
			judge_coord_2(controller, m1, n1);
		}
		else
		{
			if (controller.centrepop == 0)
			{
				cout << " –÷––ƒƒø«∞»Àø⁄Œ™0£¨«Î÷ÿ–¬—°‘Ò" << endl;
				if (coord_2(controller,m1, n1) == false) { return false; }
				judge_coord_2(controller,m1, n1);
			}
		}
	}
	
		cout << "“∆»Î≥…π¶£°" << endl;  system("pause"); return true;
	//∑˚∫œÃıº˛£¨Ω· ¯∑÷≈‰
}
void poptrsf_inner(Controller& controller, int m1, int n1, int m, int n)
{
	if (controller.map[m][n].type != 6)//œ»≈–∂®ƒøµƒµÿøÈ  1. «∑ÒŒ™ –÷––ƒ
	{
		if (controller.map[m][n].type = 0)//£§’‚¿ÔÃÓ»Î£¨µ±√ªΩ®÷˛ ±
		{
			controller.map[m][n].ifpop = COLONIZED;//¡Ó∆‰Œ™ŒﬁΩ®÷˛”–»À
			Landform s = controller.map[m][n].landform; // ≈–∂œµÿ–Œ£¨≤¢–ﬁ∏ƒ»Àø⁄º”≥…
			switch (s)
			{
			case PLAIN:controller.perfood += (2 / controller.allpop); //++controller.prod;
			//case DESERT:++controller.prod;
			case SEA:++controller.perfood+=(1 / controller.allpop); //++controller.perprod;
			case HILLY:controller.perfood += (2 / controller.allpop);// controller.perprod += 2;
			}
		}
		else { controller.map[m][n].ifpop = COLONIZED; }//£§¡Ó∆‰Œ™”–Ω®÷˛”–»À£ª
	}


	else
	{
		++controller.centrepop;
		controller.perfood += (0.5 / controller.allpop);
		/*controller.pertech += 0.7; controller.percul += 0.3;
		controller.perprod += 0.5; ;*/
	}// « –÷––ƒ ±,»Àø⁄÷µº”1,∆‰”‡∏˜÷µÀÊ÷Æ‘ˆº”

	if (controller.map[m1][n1].type != 6)//‘Ÿ≈–∂œ«®≥ˆµƒµÿøÈ£¨≤ª « –÷––ƒ
	{
		if (controller.map[m1][n1].type = 0)//£§’‚¿ÔÃÓ»Î£¨µ±√ªΩ®÷˛ ±
		{
			controller.map[m1][n1].ifpop = OWNED;//£§¡Ó∆‰Œ™ŒﬁΩ®÷˛Œﬁ»À
			Landform s = controller.map[m1][n1].landform; // ≈–∂œµÿ–Œ£¨≤¢–ﬁ∏ƒ»Àø⁄º”≥…
			switch (s)
			{
			case PLAIN:controller.perfood -= (2 / controller.allpop); //--controller.perprod;
			//case DESERT:--controller.perprod;
			case SEA:--controller.perfood; //--controller.perprod;
			case HILLY:controller.perfood -= (2 / controller.allpop); //controller.perprod -= 2;
			}
		}
		else { controller.map[m1][n1].ifpop = OWNED; }//£§¡Ó∆‰Œ™”–Ω®÷˛Œﬁ»À£ª
	}


	else// « –÷––ƒ
	{
		--controller.centrepop; controller.perfood -= (0.5 / controller.allpop);
		/*controller.pertech -= 0.7; controller.percul -= 0.3;
		controller.perprod -= 0.5; */
	}// « –÷––ƒ ±,»Àø⁄«®≥ˆ πµ√»Àø⁄÷µºı“ª,∆‰”‡∏˜÷µÀÊ÷Æºı…Ÿ

}


bool Controller::removepop_judge(int& m, int& n)
{
	if (map[m][n].ifpop != COLONIZED)
	{
		if (map[m][n].type != 6)
		{
			cout << "µ±«∞Õ¡µÿ√ª”–»À£¨«Î÷ÿ–¬—°‘Ò" << endl;
			cout << "«Î“¿¥Œ ‰»ÎÕ¡µÿ∫·◊›◊¯±Í: " << endl;
			cout << "∑µªÿøÿ÷∆√Ê∞Â ‰»Î-1;—°∂® –÷––ƒ ‰»ÎøÏΩ›º¸-2 " << endl;
			removepop_input(m, n);
		}
		else
		{
			if (centrepop == 0)
			{
				cout << " –÷––ƒƒø«∞»Àø⁄Œ™0£¨«Î÷ÿ–¬—°‘Ò" << endl;
				cout << "«Î“¿¥Œ ‰»ÎÕ¡µÿ∫·◊›◊¯±Í: " << endl;
				cout << "∑µªÿøÿ÷∆√Ê∞Â ‰»Î-1;—°∂® –÷––ƒ ‰»ÎøÏΩ›º¸-2 " << endl;
				removepop_input(m, n);
			}
			else {
				--centrepop; mark_remove = 0; 
				cout << "ÕÍ≥…£°" << endl; system("pause"); return true;
			}
		}
	}
	else {
		map[m][n].ifpop = OWNED; mark_remove = 0;
		cout << "ÕÍ≥…£°" << endl; system("pause"); return true;
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
		cout << "◊¯±Í∑∂ŒßŒ™0-19£¨«Î÷ÿ–¬ ‰»Î " << endl;
		cout << "«Î“¿¥Œ ‰»ÎÕ¡µÿ∫·◊›◊¯±Í: " << endl;
		cout << "∑µªÿøÿ÷∆√Ê∞Â ‰»Î-1;—°∂® –÷––ƒ ‰»ÎøÏΩ›º¸-2 " << endl;
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
	cout << "”…”⁄ ≥ŒÔ≤ª◊„£¨◊‹»Àø⁄ºı…Ÿ¡À°£«Î—°‘Ò“ªøÈÕ¡µÿºı…Ÿ»Àø⁄£∫" << endl;
	cout << "ƒø«∞ –÷––ƒ»Àø⁄Œ™ " << centrepop << endl;
	cout << "«Î“¿¥Œ ‰»ÎÕ¡µÿ∫·◊›◊¯±Í: " << endl;
	cout << "∑µªÿøÿ÷∆√Ê∞Â ‰»Î-1;—°∂® –÷––ƒ ‰»ÎøÏΩ›º¸-2 " << endl;
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
	cout << "ø…”√»Àø⁄Œ™£∫" << this->allpop << endl;
	cout << " –÷––ƒ»Àø⁄Œ™£∫" << this->centrepop << endl;
	cout << "ø…”√ ≥ŒÔŒ™£∫" << this->food << endl;
	cout << "µ±«∞…˙≤˙¡¶Œ™£∫" << this->prod << endl;
	cout << "ø∆ºº÷µŒ™£∫" << this->alltech << endl;
	cout << "ŒƒªØ÷µŒ™£∫" << this->allcul << endl;
	cout << "∑÷ ˝Œ™£∫" << this->score << endl;
	cout << "µ±«∞’˝‘⁄–ﬁΩ®µƒΩ®÷˛”–£∫" << endl;

	while (zao[i].type != 0)
	{
		if (zao[i].oktime > 0)
		{
			cout << zao[i].xx << ',' << zao[i].yy << "  ";
			switch (zao[i].type)
			{
			case 1:
				cout << "—ß‘∫";
				break;
			case 2:
				cout << "æÁ‘∫π„≥°";
				break;

			case 3:
				cout << "∆Êπ€";
				break;

			case 4:
				cout << "π§“µ«¯";
				break;

			default:
				break;
			}
			cout << " ªπ–Ë" << zao[i].oktime << "µ„…˙≤˙¡¶" << endl;
		}

		i++;
	}

	cout << "µ±«∞’˝‘⁄æŸ∞ÏµƒªÓ∂Ø”–£∫" << endl;

	if (endmeeting > 0) cout << "—ß ıª·“È" << ' ' << "ªπ–Ë" << endmeeting << "µ„…˙≤˙¡¶" << endl;
	if (endshow > 0) cout << "¬˛’π" << ' ' << "ªπ–Ë" << endshow << "µ„…˙≤˙¡¶" << endl;
	if (endlogistics > 0) cout << "π§“µŒÔ¡˜" << ' ' << "ªπ–Ë" << endlogistics << "µ„…˙≤˙¡¶" << endl;

	cout << "µ±«∞Ã·π©µƒº”≥…”–£∫" << endl;

	int countmeeting = 1, countshow = 1, countlogistics = 1;	//º«¬ºªÓ∂Ø±‡∫≈

	for (int j = 0; j < 100; j++) {
		if (lastmeeting[j] > 0) {
			cout << "—ß ıª·“È" << countmeeting << " ªπ”– " << lastmeeting[j] << " ªÿ∫œ" << endl;
			countmeeting++;
		}
	}
	for (int k = 0; k < 100; k++) {
		if (lastshow[k] > 0) {
			cout << "¬˛’π" << countshow<<" ªπ”– " << lastshow[k] << " ªÿ∫œ" << endl;
			countshow++;
		}
	}
	for (int s = 0; s < 100; s++) {
		if (lastlogistics[s] > 0) {
			cout << "π§“µŒÔ¡˜" << countlogistics << " ªπ”– " << lastlogistics[s] << " ªÿ∫œ" << endl;
			countlogistics++;
		}
		}
	
}
