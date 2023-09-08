#include<iostream>
#include<iomanip>
#include"loading.h"
using namespace std;
void Loading::showstart()
{
    cout << "************************************" << endl;
    cout << "******《   文          明   》******" << endl;
    cout << "************************************" << endl;
    system("pause");
    system("cls");
}
Cell** Loading::selectmap(Grid& grid)
{
    char i;
    cout << "******载入成功******" << endl;
    cout << "请选择存档模式：" << endl;
    cout << "1---载入已有地图的存档" << endl;
    cout << "2---新建地图存档游玩" << endl;
    cout << "请输入数字代号：" << endl;
    cin >> i;
    string maplist[5];
    ifstream is;
    is.open("maplist.txt", ios::in);
    for (int i = 0; i < 5; i++)
    {
        is >> maplist[i];
    }
    is.close();
    while ((i != '1') && (i != '2'))
    {
        cout << "数字代号错误请重新选择：" << endl;
        cout << "请输入数字代号：" << endl;
        cin >> i;
    }
    if (i == '1')
    {
        cout << "现有如下存档：" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << "————" << maplist[i] << endl;;
        }
        cout << "" << endl;
        char select;
        cin >> select;
        while (select < '1' || select>'5')
        {
            cout << "数字代号错误请重新选择：" << endl;
            cout << "请输入数字代号：" << endl;
            cin >> select;
        }
        while (maplist[select - '1'] == "empty")
        {
            cout << "此存档内部为空" << endl;
            cout << "请重新输入数字代号：" << endl;
            cin >> select;
        }
        cout << "现有存档载入完成：" << endl;
        cout << "游戏即将开始，祝游玩愉快。" << endl;
        system("pause");
        system("cls");
        return grid.getmap(maplist[select - '1'].c_str());

    }
    else
    {
        cout << "已创建新的存档，并完成初始化" << endl;
        cout << "游戏即将开始，祝游玩愉快。" << endl;
    }
}
void Loading::showmap(Cell** map, int m, int n)
{

    for (int i = 0; i < m; i++)
    {

        for (int e = 0; e < n; e++)
        {
            cout << "--------";
        }
        cout << "-" << endl;

        for (int j1 = 0; j1 < n; j1++)
        {
            cout << "|";
            if (map[i][j1].ifpop == WILD)
            {
                switch (map[i][j1].landform)
                {
                case OCEAN:

                    cout << "\033[" << "38;5;" << 27 << "m" << "深海\t" << "\033[m";
                    break;
                case SEA:

                    cout << "\033[" << "38;5;" << 45 << "m" << "近海\t" << "\033[m";
                    break;
                case PLAIN:

                    cout << "\033[" << "38;5;" << 47 << "m" << "平原\t" << "\033[m";
                    break;
                case HILLY:
                    cout << "\033[" << "38;5;" << 167 << "m" << "丘陵\t" << "\033[m";
                    break;
                case DESERT:

                    cout << "\033[" << "38;5;" << 227 << "m" << "沙漠\t" << "\033[m";
                    break;
                case MOUNTAIN:

                    cout << "\033[" << "38;5;" << 196 << "m" << "山脉\t" << "\033[m";
                    break;
                default:
                    break;
                }
            }
            else
            {
                if (map[i][j1].type == 0)
                {
                    switch (map[i][j1].landform)
                    {
                    case OCEAN:

                        cout << "\033[" << "38;5;" << 27 << "m" << "深海\t" << "\033[m";
                        break;
                    case SEA:

                        cout << "\033[" << "38;5;" << 45 << "m" << "近海\t" << "\033[m";
                        break;
                    case PLAIN:

                        cout << "\033[" << "38;5;" << 47 << "m" << "平原\t" << "\033[m";
                        break;
                    case HILLY:
                        cout << "\033[" << "38;5;" << 167 << "m" << "丘陵\t" << "\033[m";
                        break;
                    case DESERT:

                        cout << "\033[" << "38;5;" << 227 << "m" << "沙漠\t" << "\033[m";
                        break;
                    case MOUNTAIN:

                        cout << "\033[" << "38;5;" << 196 << "m" << "山脉\t" << "\033[m";
                        break;
                    default:
                        break;
                    }
                }
                else
                {
                    if (map[i][j1].landform == PLAIN)
                    {
                        if (map[i][j1].type == 1)
                        {
                            cout << "\033[" << "38;5;" << 47 << "m" << "*学院\t" << "\033[m";
                        }
                        if (map[i][j1].type == 2)
                        {
                            cout << "\033[" << "38;5;" << 47 << "m" << "*剧院\t" << "\033[m";
                        }
                        if (map[i][j1].type == 3)
                        {
                            cout << "\033[" << "38;5;" << 47 << "m" << "*奇观\t" << "\033[m";
                        }
                        if (map[i][j1].type == 4)
                        {
                            cout << "\033[" << "38;5;" << 47 << "m" << "*工厂\t" << "\033[m";
                        }
                        if (map[i][j1].type == -1)
                        {
                            cout << "\033[" << "38;5;" << 47 << "m" << "*在建\t" << "\033[m";
                        }
                        if (map[i][j1].type == 6)
                        {
                            cout << "\033[" << "38;5;" << 47 << "m" << "市中心\t" << "\033[m";
                        }

                    }
                    else if (map[i][j1].landform == HILLY)
                    {
                        if (map[i][j1].type == 1)
                        {
                            cout << "\033[" << "38;5;" << 167 << "m" << "*学院\t" << "\033[m";
                        }
                        if (map[i][j1].type == 2)
                        {
                            cout << "\033[" << "38;5;" << 167 << "m" << "*剧院\t" << "\033[m";
                        }
                        if (map[i][j1].type == 3)
                        {
                            cout << "\033[" << "38;5;" << 167 << "m" << "*奇观\t" << "\033[m";
                        }
                        if (map[i][j1].type == 4)
                        {
                            cout << "\033[" << "38;5;" << 167 << "m" << "*工厂\t" << "\033[m";
                        }
                        if (map[i][j1].type == -1)
                        {
                            cout << "\033[" << "38;5;" << 167 << "m" << "*在建\t" << "\033[m";
                        }
                        if (map[i][j1].type == 6)
                        {
                            cout << "\033[" << "38;5;" << 167 << "m" << "市中心\t" << "\033[m";
                        }

                    }
                    else if (map[i][j1].landform == DESERT)
                    {
                        if (map[i][j1].type == 1)
                        {
                            cout << "\033[" << "38;5;" << 227 << "m" << "*学院\t" << "\033[m";
                        }
                        if (map[i][j1].type == 2)
                        {
                            cout << "\033[" << "38;5;" << 227 << "m" << "*剧院\t" << "\033[m";
                        }
                        if (map[i][j1].type == 3)
                        {
                            cout << "\033[" << "38;5;" << 227 << "m" << "*奇观\t" << "\033[m";
                        }
                        if (map[i][j1].type == 4)
                        {
                            cout << "\033[" << "38;5;" << 227 << "m" << "*工厂\t" << "\033[m";
                        }
                        if (map[i][j1].type == -1)
                        {
                            cout << "\033[" << "38;5;" << 227 << "m" << "*在建\t" << "\033[m";
                        }
                        if (map[i][j1].type == 6)
                        {
                            cout << "\033[" << "38;5;" << 227 << "m" << "市中心\t" << "\033[m";
                        }
                    }
                }
            }

        }
        cout << "|" << endl;

        for (int j2 = 0; j2 < n; j2++)
        {
            cout << "|";
            if (map[i][j2].ifpop == WILD)
            {
                cout << "\t";
            }
            else if (map[i][j2].ifpop == OWNED)
            {
                cout << "\t";
            }
            else
            {
                cout << "有\t";
            }

        }
        cout << "|";
        cout << endl;

        for (int j3 = 0; j3 < n; j3++)
        {
            if (map[i][j3].ifpop == WILD)
            {
                cout << "|" << i << "." << j3 << "\t";
            }
            else
            {
                cout << "|" << "\033[" << "38;5;" << 147 << "m" << i << "." << j3 << "\t"<< "\033[m"; 
            }

        }
        cout << "|" << endl;

    }

    for (int e = 0; e < n; e++)
    {
        cout << "--------";
    }
    cout << "-" << endl;
}




char Loading::selectmove(int round)
{
    cout << "\033[1;31m第" << round << "回合\033[0m" << endl;
    cout << "/----------------------------------\\" << endl;
    cout << "|0.退出本回合                      |" << endl;
    cout << "|1.分配人口                        |" << endl;
    cout << "|2.新建建筑                        |" << endl;
    cout << "|3.举办活动                        |" << endl;
    cout << "|4.选择投入生产力到在建的建筑或活动|" << endl;
    cout << "|5.退出本游戏                      |" << endl;
    cout << "\\----------------------------------/" << endl;
    cout << endl;
    char select;
    cout << "请输入数字代号：" << endl;
    cin >> select;
    while (select < '0' && select>'5')
    {
        cout << "数字代号错误请重新选择：" << endl;
        cout << "请输入数字代号：" << endl;
        cin >> select;
    }
    return select;
}