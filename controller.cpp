#include <iostream>
#include "board.h";
#include "controller.h"

#include <string>
#include <vector>
#include <cassert>
#include <unordered_set>

controller* controller::instance = nullptr;
controller* controller::get_instance()
{
	if (!instance)
	{
		instance = new controller;
	}
	return instance;
}

void controller::fill_board()
{
	m_board->set_cell_vallue(0, 0, 3);
	m_board->set_cell_vallue(0, 2, 7);
	m_board->set_cell_vallue(0, 7, 2);
	m_board->set_cell_vallue(1, 4, 7);
	m_board->set_cell_vallue(1, 6, 1);
	m_board->set_cell_vallue(2, 0, 8);
	m_board->set_cell_vallue(2, 3, 3);
	m_board->set_cell_vallue(2, 4, 2);
	m_board->set_cell_vallue(2, 7, 6);
	m_board->set_cell_vallue(3, 1, 7);
	m_board->set_cell_vallue(3, 6, 6);
	m_board->set_cell_vallue(3, 7, 8);
	m_board->set_cell_vallue(3, 8, 4);
	m_board->set_cell_vallue(4, 3, 7);
	m_board->set_cell_vallue(4, 5, 9);
	m_board->set_cell_vallue(5, 0, 1);
	m_board->set_cell_vallue(5, 1, 8);
	m_board->set_cell_vallue(5, 2, 2);
	m_board->set_cell_vallue(5, 7, 5);
	m_board->set_cell_vallue(6, 1, 4);
	m_board->set_cell_vallue(6, 4, 1);
	m_board->set_cell_vallue(6, 5, 8);
	m_board->set_cell_vallue(6, 8, 6);
	m_board->set_cell_vallue(7, 2, 1);
	m_board->set_cell_vallue(7, 4, 4);
	m_board->set_cell_vallue(8, 1, 2);
	m_board->set_cell_vallue(8, 6, 9);
	m_board->set_cell_vallue(8, 8, 1);
}

controller::controller() :m_board(new board)
{
	fill_board();
}


int controller::exec_game_loop()
{
	static int m_mistakes = 0;
	std::cout << "------------   SUDOKU   ------------" << std::endl;
	m_board->draw();
	while (m_board->are_filled())
	{
		std::string i, j, value;
		std::cout << "Enter firs_cell: ";
		std::cin >> i;
		std::cout << std::endl;
		std::cout << "Enter second_cell: ";
		std::cin >> j;
		std::cout << std::endl;
		std::cout << "Enter threed_cell: ";
		std::cin >> value;
		try {
			if (stoi(i) >= 0 && stoi(i) < 9);
		}
		catch (...)
		{
			std::cout << "Syntax error: " << std::endl;
			system("CLS");
			std::cout << "------------   SUDOKU   ------------" << std::endl;
			m_board->draw();
			continue;
		}

		try {
			if (stoi(j) >= 0 && stoi(j) < 9);
		}
		catch (...)
		{
			std::cout << "Syntax error: " << std::endl;
			system("CLS");
			std::cout << "------------   SUDOKU   ------------" << std::endl;
			m_board->draw();
			continue;
		}

		try {
			if (stoi(value) > 0 && stoi(value) < 10);
		}
		catch (...)
		{
			std::cout << "Syntax error: " << std::endl;
			system("CLS");
			std::cout << "------------   SUDOKU   ------------" << std::endl;
			m_board->draw();
			continue;
		}

		if(m_board->isValidRows(stoi(i), stoi(j), stoi(value)) == false
			|| m_board->isValidCols(stoi(i), stoi(j), stoi(value)) == false
			|| m_board->isValidSquares(stoi(i), stoi(j), stoi(value)) == false)
		{
			++m_mistakes;
			system("CLS");
			std::cout << "------------   SUDOKU   ------------" << std::endl;
			m_board->draw();
			std::cout << "mistake->" << m_mistakes<<'\n';
		}

		if (m_mistakes > MAX_MISTAKES)
		{
			std::cout << "mistake->" << m_mistakes << '\n';
			system("CLS");
			std::cout << "------------   GAME OVER   ------------ ";
			return 0;
		}
		
		system("CLS");
		std::cout << "------------   SUDOKU   ------------" << std::endl;
		m_board->draw();
	}
	return 0;
}