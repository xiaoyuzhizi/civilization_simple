#ifndef GRID_H
#define GRID_H



#pragma once
#include<fstream>


enum Civilized { WILD = 0, OWNED, COLONIZED };//���ö���ж��������������    �յأ�ӵ�еĵ�δ���ˣ�ֳ������˵�
enum Landform { OCEAN, SEA, PLAIN, HILLY, DESERT, MOUNTAIN, NOTYPE };

class Cell
{
public:
    Landform landform = PLAIN;//������ʽ  ƽ�ػ�ɳĮ��
    Civilized ifpop = WILD;   // �Ƿ����� ***���wild��Ҫ��***Ҫ��Ȼ�ᱨ�� �͵�ͼ�������ŵ�
    int type = 0;



};

class Grid
{
public:

    Cell** getmap(const char* filename);//һ�����������ͼ��ȡ
    void savemap();//�����ͼ����д��������Ҫ�ö��ٻ������ݣ�������ô�洢
public:
    Cell** grid = NULL;
    int height = 0, width = 0;//��ͼ�ĳ��Ϳ�

};

#endif 
