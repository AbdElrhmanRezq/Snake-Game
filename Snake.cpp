#include "Csnake.h"

int main() {
	HANDLE wndHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	welcome();
	Sleep(9000);
	setup();
	while (gameover == false) {
		SetConsoleCursorPosition(wndHandle, { 0,0 });
		render();
		command();
		save();
		display();
		cout << "SCORE: " << snake.length<<endl;
		Sleep(200);
	}
	if (snake.length == 529) {
		cout << "Congratulations.. You win!!!" << endl;
		system("color 0A");
	}
	else {
		cout << "Game over.. Nice try " << endl;
		system("color 0C");
	}
	Sleep(4000);
	
}