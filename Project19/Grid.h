#include"Grid.h"
#include <iostream>
using namespace std;



Cell** Grid::getmap(const char* filename)
{
	ifstream ifs;

	ifs.open(filename, ios::in);

	ifs >> this->height;
	ifs >> this->width;
	this->grid = new Cell * [this->height];
	for (int i = 0; i < this->height; i++)
	{
		grid[i] = new Cell[this->width];
	}

	int a;
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{

			ifs >> a;
			grid[i][j].landform = Landform(a);
		}
	}
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			grid[i][j].type = 0;
		}
	}
	ifs.close();
	return this->grid;
}

void Grid::savemap()
{

}
