#include <iostream>
#include "board.h"
#include "controller.h"



int main()
{
	controller* c =  controller::get_instance();
	return c->exec_game_loop();
}

