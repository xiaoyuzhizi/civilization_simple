#ifndef GRID_H
#define GRID_H



#pragma once
#include<fstream>


enum Civilized { WILD = 0, OWNED, COLONIZED };//’‚∏ˆ√∂æŸ≈–∂®Õ¯∏ÒµƒÕ¡µÿ¿‡–Õ    ø’µÿ£¨”µ”–µƒµ´Œ¥”–»À£¨÷≥√Òµƒ”–»Àµƒ
enum Landform { OCEAN, SEA, PLAIN, HILLY, DESERT, MOUNTAIN, NOTYPE };

class Cell
{
public:
    Landform landform = PLAIN;//Õ¡µÿ–Œ Ω  ∆ΩµÿªÚ…≥ƒÆµ»
    Civilized ifpop = WILD;   //  «∑Ò”–»À ***’‚∏ˆwild≤ª“™∂Ø***“™≤ª»ªª·±®¥Ì ∫ÕµÿÕº¿‡ «¡¨◊≈µƒ
    int type = 0;



};

class Grid
{
public:

    Cell** getmap(const char* filename);//“ª∏ˆ∫Ø ˝Ω‚æˆµÿÕº∂¡»°
    void savemap();//±£¥ÊµÿÕº£¨‘⁄–¥£¨ø¥ƒ„√«“™”√∂‡…Ÿª˘¥° ˝æ›£¨æˆ∂®‘ı√¥¥Ê¥¢
public:
    Cell** grid = NULL;
    int height = 0, width = 0;//µÿÕºµƒ≥§∫ÕøÌ

};

#endif 
