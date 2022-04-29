#pragma once
#include "definitions.h"

#include <vector>

class board
{
public:
	board();
public:
	int get_cell_vallue(int, int)const;
	void set_cell_vallue(int, int, int);
	void draw();
	bool are_filled() const;
	bool isValidRows(int,int,int);
	bool isValidCols(int,int,int);
	bool isValidSquares(int,int,int);
private:
	bool is_valid_index(int, int) const;
	bool is_valid_value(int) const;
private:
	std::vector<int> m_data;
};