#include <iostream>
using namespace std;
#include"Display.h"//唯一的对外头函数

int main()
{


    Loading start;//开始加载类
    Grid grid;//地图类
    Controller controller;//控制类，各种算法包含在这里

    start.showstart();//载入存档的函数调用
    controller.map = start.selectmap(grid);//map里面储存了所有数据
    controller.length = grid.height;
    controller.width = grid.width;

    int flag01 = 1;//每局结束的标志
    //int flag02 = 0;//是否进行case4
    


    /*
      如果想让一个单元格显示为建筑  要 以0.0为例 map[0][0].ifpop =OWNED或COLONIZED才在地图上显示为有建筑
      而要显示这个格子里有人一定要把map[0][0].ifpop =COLONIZED；才可以，只改pop是不可以的。
    */
    start.showmap(controller.map, grid.height, grid.width);
    controller.selectcenter();



    while (1)
    {
        controller.round++;//是局数
        controller.flagp = false;
        controller.flagd = false;

        flag01 = 1;
       // flag02 = 1; //判断是否本回合新建了城池或举办了活动
       
        if (controller.flagv == true)
        {
            return 0;
        }
        while (flag01)
        {
            
            // 每回合下面的数值要清零
            controller.prod = 0;
            controller.allcul = 0;
            controller.alltech = 0;
            controller.food = 0;
            controller.foodbonus = 0;
            controller.perprod = 0.5;
            controller.percul = 0.3;
            controller.pertech = 0.7;
            
            controller.tongji();
            controller.setpopBonus();//统计土地加成
            controller.tongji2();   //计算由活动增加的科技、文化、生产力
            controller.tongji3();//计算总的科技、文化、生产力
            controller.victory();//判断胜利条件

            if (controller.mark_remove == 1) {
                controller.removepop();
            }
            start.showmap(controller.map, grid.height, grid.width);//每步显示地图的函数调用
            controller.showall();
            
            char select = start.selectmove(controller.round);//选择操作
            switch (select)
            {
            case '0':
                //结束本回合
                cout << "本回合结束:" << endl;
                flag01 = 0;
                controller.expansion();
                system("cls");
                break;
            case '1':
                //分配人口  
                select_poptrsf(controller);
                system("cls");
                break;
            case '2':
            {
                if (controller.flagp == true)
                {
                    cout << "此回合已经新建建筑或举办活动" << endl;
                }
                else
                {
                    controller.build(); //新建城池
                }
                
                system("pause");
                system("cls");
                break;
            }
            case '3':
            {
                if (controller.flagp == true)
                {
                    cout << "此回合已经新建城池或举办活动" << endl;
                }
                else
                {
                    controller.activity();//举办活动  
                }
                
                system("pause");
                system("cls");
                break;
            }
            case '4':
                //选择这回合要将生产力投入哪项在建的活动/建筑。
                if (controller.flagd == true)
                {
                    cout << "此回合已经投入过生产力" << endl;
                }
                else
                {
                    controller.distribute();//分配生产力到建筑或活动
                }

                system("pause");
                system("cls");
                break;
          
            case '5':
                //退出游戏
                system("cls");
                cout << "游戏结束，感谢游玩：" << endl;
                return 0;
                break;
            default:
            {
                cout << "数字代号错误，请重新输入：" << endl;
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
        
        

    }

    for (int i = 0; i < grid.height; i++)//释放map的内存
    {
        delete[] controller.map[i];
    }
    delete[] controller.map;
    return 0;
}


