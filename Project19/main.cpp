#include <iostream>
using namespace std;
#include"Display.h"//Ψһ�Ķ���ͷ����






int main()
{


    Loading start;//��ʼ������
    Grid grid;//��ͼ��
    Controller controller;//�����࣬�����㷨����������

    start.showstart();//����浵�ĺ�������
    controller.map = start.selectmap(grid);//map���洢������������
    controller.length = grid.height;
    controller.width = grid.width;

    int flag01 = 1;//ÿ�ֽ����ı�־
    //int flag02 = 0;//�Ƿ����case4
    


    /*
      �������һ����Ԫ����ʾΪ����  Ҫ ��0.0Ϊ�� map[0][0].ifpop =OWNED��COLONIZED���ڵ�ͼ����ʾΪ�н���
      ��Ҫ��ʾ�������������һ��Ҫ��map[0][0].ifpop =COLONIZED���ſ��ԣ�ֻ��pop�ǲ����Եġ�
    */
    start.showmap(controller.map, grid.height, grid.width);
    controller.selectcenter();



    while (1)
    {
        controller.round++;//�Ǿ���
        controller.flagp = false;
        controller.flagd = false;

        flag01 = 1;
       // flag02 = 1; //�ж��Ƿ񱾻غ��½��˳ǳػ�ٰ��˻
       
        if (controller.flagv == true)
        {
            return 0;
        }
        while (flag01)
        {
            
            // ÿ�غ��������ֵҪ����
            controller.prod = 0;
            controller.allcul = 0;
            controller.alltech = 0;
            controller.food = 0;
            controller.foodbonus = 0;
            controller.perprod = 0.5;
            controller.percul = 0.3;
            controller.pertech = 0.7;
            
            controller.tongji();
            controller.setpopBonus();//ͳ�����ؼӳ�
            controller.tongji2();   //�����ɻ���ӵĿƼ����Ļ���������
            controller.tongji3();//�����ܵĿƼ����Ļ���������
            controller.victory();//�ж�ʤ������

            if (controller.mark_remove == 1) {
                controller.removepop();
            }
            start.showmap(controller.map, grid.height, grid.width);//ÿ����ʾ��ͼ�ĺ�������
            controller.showall();
            
            char select = start.selectmove(controller.round);//ѡ�����
            switch (select)
            {
            case '0':
                //�������غ�
                cout << "���غϽ���:" << endl;
                flag01 = 0;
                system("cls");
                break;
            case '1':
                //�����˿�  
                select_poptrsf(controller);
                system("cls");
                break;
            case '2':
            {
                if (controller.flagp == true)
                {
                    cout << "�˻غ��Ѿ��½�������ٰ�" << endl;
                }
                else
                {
                    controller.build(); //�½��ǳ�
                }
                
                system("pause");
                system("cls");
                break;
            }
            case '3':
            {
                if (controller.flagp == true)
                {
                    cout << "�˻غ��Ѿ��½��ǳػ�ٰ�" << endl;
                }
                else
                {
                    controller.activity();//�ٰ�  
                }
                
                system("pause");
                system("cls");
                break;
            }
            case '4':
                //ѡ����غ�Ҫ��������Ͷ�������ڽ��Ļ/������
                if (controller.flagd == true)
                {
                    cout << "�˻غ��Ѿ�Ͷ���������" << endl;
                }
                else
                {
                    controller.distribute();//������������������
                }

                system("pause");
                system("cls");
                break;
          
            case '5':
                //�˳���Ϸ
                system("cls");
                cout << "��Ϸ��������л���棺" << endl;
                return 0;
                break;
            default:
            {
                cout << "���ִ��Ŵ������������룺" << endl;
                system("pause");
                system("cls");
                break;
            }
            }


        }
        
        if (controller.flagd == false)
        {
            controller.default_statistics(controller.current_distribution);
           // controller.morendistribute();
        }
        controller.updatepop();
        controller.expansion();
        

    }

    for (int i = 0; i < grid.height; i++)//�ͷ�map���ڴ�
    {
        delete[] controller.map[i];
    }
    delete[] controller.map;
    return 0;
}


