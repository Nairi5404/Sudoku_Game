#pragma once


class board;

class controller
{
public:
	static controller* get_instance();
public:
	int exec_game_loop();
private:
	controller();
private:
	void fill_board();
private:
	board* m_board;
	static controller* instance;
};