#include<iostream>
#include<iomanip>
#include"loading.h"
using namespace std;
void Loading::showstart()
{
    cout << "************************************" << endl;
    cout << "******��   ��          ��   ��******" << endl;
    cout << "************************************" << endl;
    system("pause");
    system("cls");
}
Cell** Loading::selectmap(Grid& grid)
{
    char i;
    cout << "******����ɹ�******" << endl;
    cout << "��ѡ��浵ģʽ��" << endl;
    cout << "1---�������е�ͼ�Ĵ浵" << endl;
    cout << "2---�½���ͼ�浵����" << endl;
    cout << "���������ִ��ţ�" << endl;
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
        cout << "���ִ��Ŵ���������ѡ��" << endl;
        cout << "���������ִ��ţ�" << endl;
        cin >> i;
    }
    if (i == '1')
    {
        cout << "�������´浵��" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << "��������" << maplist[i] << endl;;
        }
        cout << "" << endl;
        char select;
        cin >> select;
        while (select < '1' || select>'5')
        {
            cout << "���ִ��Ŵ���������ѡ��" << endl;
            cout << "���������ִ��ţ�" << endl;
            cin >> select;
        }
        while (maplist[select - '1'] == "empty")
        {
            cout << "�˴浵�ڲ�Ϊ��" << endl;
            cout << "�������������ִ��ţ�" << endl;
            cin >> select;
        }
        cout << "���д浵������ɣ�" << endl;
        cout << "��Ϸ������ʼ��ף������졣" << endl;
        system("pause");
        system("cls");
        return grid.getmap(maplist[select - '1'].c_str());

    }
    else
    {
        cout << "�Ѵ����µĴ浵������ɳ�ʼ��" << endl;
        cout << "��Ϸ������ʼ��ף������졣" << endl;
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

                    cout << "\033[" << "38;5;" << 27 << "m" << "�\t" << "\033[m";
                    break;
                case SEA:

                    cout << "\033[" << "38;5;" << 45 << "m" << "����\t" << "\033[m";
                    break;
                case PLAIN:

                    cout << "\033[" << "38;5;" << 47 << "m" << "ƽԭ\t" << "\033[m";
                    break;
                case HILLY:
                    cout << "\033[" << "38;5;" << 167 << "m" << "����\t" << "\033[m";
                    break;
                case DESERT:

                    cout << "\033[" << "38;5;" << 227 << "m" << "ɳĮ\t" << "\033[m";
                    break;
                case MOUNTAIN:

                    cout << "\033[" << "38;5;" << 196 << "m" << "ɽ��\t" << "\033[m";
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

                        cout << "\033[" << "38;5;" << 27 << "m" << "�\t" << "\033[m";
                        break;
                    case SEA:

                        cout << "\033[" << "38;5;" << 45 << "m" << "����\t" << "\033[m";
                        break;
                    case PLAIN:

                        cout << "\033[" << "38;5;" << 47 << "m" << "ƽԭ\t" << "\033[m";
                        break;
                    case HILLY:
                        cout << "\033[" << "38;5;" << 167 << "m" << "����\t" << "\033[m";
                        break;
                    case DESERT:

                        cout << "\033[" << "38;5;" << 227 << "m" << "ɳĮ\t" << "\033[m";
                        break;
                    case MOUNTAIN:

                        cout << "\033[" << "38;5;" << 196 << "m" << "ɽ��\t" << "\033[m";
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
                            cout << "\033[" << "38;5;" << 47 << "m" << "*ѧԺ\t" << "\033[m";
                        }
                        if (map[i][j1].type == 2)
                        {
                            cout << "\033[" << "38;5;" << 47 << "m" << "*��Ժ\t" << "\033[m";
                        }
                        if (map[i][j1].type == 3)
                        {
                            cout << "\033[" << "38;5;" << 47 << "m" << "*���\t" << "\033[m";
                        }
                        if (map[i][j1].type == 4)
                        {
                            cout << "\033[" << "38;5;" << 47 << "m" << "*����\t" << "\033[m";
                        }
                        if (map[i][j1].type == -1)
                        {
                            cout << "\033[" << "38;5;" << 47 << "m" << "*�ڽ�\t" << "\033[m";
                        }
                        if (map[i][j1].type == 6)
                        {
                            cout << "\033[" << "38;5;" << 47 << "m" << "������\t" << "\033[m";
                        }

                    }
                    else if (map[i][j1].landform == HILLY)
                    {
                        if (map[i][j1].type == 1)
                        {
                            cout << "\033[" << "38;5;" << 167 << "m" << "*ѧԺ\t" << "\033[m";
                        }
                        if (map[i][j1].type == 2)
                        {
                            cout << "\033[" << "38;5;" << 167 << "m" << "*��Ժ\t" << "\033[m";
                        }
                        if (map[i][j1].type == 3)
                        {
                            cout << "\033[" << "38;5;" << 167 << "m" << "*���\t" << "\033[m";
                        }
                        if (map[i][j1].type == 4)
                        {
                            cout << "\033[" << "38;5;" << 167 << "m" << "*����\t" << "\033[m";
                        }
                        if (map[i][j1].type == -1)
                        {
                            cout << "\033[" << "38;5;" << 167 << "m" << "*�ڽ�\t" << "\033[m";
                        }
                        if (map[i][j1].type == 6)
                        {
                            cout << "\033[" << "38;5;" << 167 << "m" << "������\t" << "\033[m";
                        }

                    }
                    else if (map[i][j1].landform == DESERT)
                    {
                        if (map[i][j1].type == 1)
                        {
                            cout << "\033[" << "38;5;" << 227 << "m" << "*ѧԺ\t" << "\033[m";
                        }
                        if (map[i][j1].type == 2)
                        {
                            cout << "\033[" << "38;5;" << 227 << "m" << "*��Ժ\t" << "\033[m";
                        }
                        if (map[i][j1].type == 3)
                        {
                            cout << "\033[" << "38;5;" << 227 << "m" << "*���\t" << "\033[m";
                        }
                        if (map[i][j1].type == 4)
                        {
                            cout << "\033[" << "38;5;" << 227 << "m" << "*����\t" << "\033[m";
                        }
                        if (map[i][j1].type == -1)
                        {
                            cout << "\033[" << "38;5;" << 227 << "m" << "*�ڽ�\t" << "\033[m";
                        }
                        if (map[i][j1].type == 6)
                        {
                            cout << "\033[" << "38;5;" << 227 << "m" << "������\t" << "\033[m";
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
                cout << "��\t";
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
    cout << "\033[1;31m��" << round << "�غ�\033[0m" << endl;
    cout << "/----------------------------------\\" << endl;
    cout << "|0.�˳����غ�                      |" << endl;
    cout << "|1.�����˿�                        |" << endl;
    cout << "|2.�½�����                        |" << endl;
    cout << "|3.�ٰ�                        |" << endl;
    cout << "|4.ѡ��Ͷ�����������ڽ��Ľ�����|" << endl;
    cout << "|5.�˳�����Ϸ                      |" << endl;
    cout << "\\----------------------------------/" << endl;
    cout << endl;
    char select;
    cout << "���������ִ��ţ�" << endl;
    cin >> select;
    while (select < '0' && select>'5')
    {
        cout << "���ִ��Ŵ���������ѡ��" << endl;
        cout << "���������ִ��ţ�" << endl;
        cin >> select;
    }
    return select;
}