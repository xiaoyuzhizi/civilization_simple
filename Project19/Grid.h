#ifndef GRID_H
#define GRID_H



#pragma once
#include<fstream>


enum Civilized { WILD = 0, OWNED, COLONIZED };//这个枚举判定网格的土地类型    空地，拥有的但未有人，殖民的有人的
enum Landform { OCEAN, SEA, PLAIN, HILLY, DESERT, MOUNTAIN, NOTYPE };

class Cell
{
public:
    Landform landform = PLAIN;//土地形式  平地或沙漠等
    Civilized ifpop = WILD;   // 是否有人 ***这个wild不要动***要不然会报错 和地图类是连着的
    int type = 0;



};

class Grid
{
public:

    Cell** getmap(const char* filename);//一个函数解决地图读取
    void savemap();//保存地图，在写，看你们要用多少基础数据，决定怎么存储
public:
    Cell** grid = NULL;
    int height = 0, width = 0;//地图的长和宽

};

#endif 
