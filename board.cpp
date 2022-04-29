#include "board.h"

#include <iostream>
#include <algorithm>
#include <cassert>
#include <string>

board::board() : m_data(std::vector<int> (ITEMS_COUNT, 0)){};

int board::get_cell_vallue(int r, int c) const
{
	assert(is_valid_index(r,c));
	return m_data[r * ROW_COUNT + c];
}

void board::set_cell_vallue(int r, int c, int value)
{
	assert(is_valid_index(r, c));
	assert(is_valid_value(value));
	int& v = m_data[r * ROW_COUNT + c];
	if (!v)
	{
		v = value;
	}
}

void board::draw()
{
	for (size_t r = 0;r < ROW_COUNT;++r)
	{
		if (r == 0)
		{
			std::cout << "____________________________________" << std::endl;
		}
		for (size_t c = 0;c < COLUMN_COUNT;++c)
		{
			if (c == 0)
			{
				std::cout << "| ";
			}
			const int data = m_data[r * ROW_COUNT + c];
			std::cout << std::string(data > 0 ? std::to_string(data) : " ");
			std::cout << " |";
			if (c < COLUMN_COUNT - 1)
			{
				std::cout << " ";
			}
		} std::cout << std::endl;
		if (r != ROW_COUNT - 1)
		{
			std::cout << "------------------------------------" << std::endl;
		}
	}
	std::cout << "____________________________________" << std::endl;
}

bool board::is_valid_index(int r, int c) const
{
	return(r >= 0 && (size_t)r < ROW_COUNT) && (c >= 0 && (size_t)c < COLUMN_COUNT);
}

bool board::is_valid_value(int value) const
{
	return value > 0 && value < 10;
}

bool board::are_filled() const
{
	for (size_t r = 0;r < ITEMS_COUNT;++r)
	{
		if (m_data[r] == 0)
			return true;
	}
	return false;
}

bool board::isValidRows(int n,int m,int val)
{
	set_cell_vallue(n, m, val);
	for (int row = 0;row < 9;++row)
	{
		for (int col = 0;col < 9;++col)
		{
			int number = m_data[row * 9 + col];
			if (number == 0)
				continue;
			for (int i = col + 1;i < 9;++i)
			{
				if ((number == m_data[row * 9 + i]))
				{
					m_data.erase(m_data.begin() + (n * 9) + m);
					m_data.insert(m_data.begin() + (n * 9) + m, 0);
					return false;
				}
			}
		}
	}
	return true;
}

bool board::isValidCols(int n, int m, int val)
{
	set_cell_vallue(n, m, val);
	for (int col = 0;col < 9;++col)
	{
		for (int row = 0;row < 9;++row)
		{
			int number = m_data[row * 9 + col];
			if (number == 0)
				continue;
			for (int i = row + 1;i < 9;++i)
			{
				if ((number == m_data[i * 9 + col]))
				{
					m_data.erase(m_data.begin() + (n * 9) + m);
					m_data.insert(m_data.begin() + (n * 9) + m, 0);
					return false;
				}
			}
		}
	}
}

bool board::isValidSquares(int n, int m, int val)
{
	set_cell_vallue(n, m, val);
	for (int row = 0; row < 9; row += 3) 
	{
		for (int col = 0; col < 9; col += 3)
		{
			std::vector<int> square;
			for (int r = 0; r < 3; ++r)
			{
				for (int c = 0; c < 3; ++c)
				{
					square.push_back(m_data[(row + r) * 9 + col + c]);
				}
			}
			for (int i = 0; i < 9; ++i)
			{
				int number = square[i];
				if (number == 0) 
				{
					continue;
				}
				for (int j = i + 1; j < 9; ++j)
				{
					if (number == square[j])
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}