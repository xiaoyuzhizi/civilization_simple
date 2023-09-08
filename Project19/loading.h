#ifndef LOADING_H
#define LOADING_H
#include"Grid.h"
class Loading
{
public:
	void showstart();
	Cell** selectmap(Grid& grid);
	void showmap(Cell** map, int m, int n);
	char selectmove(int round);

};
#endif 