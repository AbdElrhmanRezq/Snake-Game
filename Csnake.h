#include<iostream>
#include "Objects.cpp"
#include<windows.h>
#include <conio.h>
#include <time.h>
#pragma warning (disable:4996);
using namespace std;
#define snake_is_here snake.pos.x == i && snake.pos.y == j
#define snake_eat snake.pos.x == fruit.pos.x && snake.pos.y == fruit.pos.y
#define snake_over snake.pos.x == 0 || snake.pos.y == 0 || snake.pos.x==24 ||snake.pos.y==24
#define snake_bite 
#define DIM 25
bool gameover;
char buffer[25][25];
int mat[DIM][DIM];
int body_pos_x[625];
int body_pos_y[625];
Snake snake;
Fruit fruit;
/*void increase() {
	for (int x = 0; x < 25; x++) {
		for (int y = 0; y < 25; y++) {
			if (mat[x][y] > 0) {
				mat[x][y]++;
			}
		}
	}
}
*/
void setup() {
	gameover = false;
	snake.head = 'O';
	snake.body = '+';
	snake.pos.x = 25 / 2;
	snake.pos.y = 25 / 2;
	fruit.pos.x = rand() % 23 + 1;
	fruit.pos.y = rand() % 23 + 1;
	fruit.icon = '@';
	snake.length = 1;
}
void random() {
	fruit.pos.x = rand() % 23 + 1;
	fruit.pos.y = rand() % 23 + 1;
	while (buffer[fruit.pos.x][fruit.pos.y] == '+' || buffer[fruit.pos.x][fruit.pos.y] == 'O') {
		fruit.pos.x = rand() % 23 + 1;
		fruit.pos.y = rand() % 23 + 1;
	}
}
void render() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (i == 0 || j == 0 || i == 24 || j == 24)
				buffer[i][j] = '#';
			else
				buffer[i][j] = ' ';
			for (int g = 1; g < snake.length; g++) {
				buffer[body_pos_x[g]][body_pos_y[g]] = '+';
			}
			if (snake_is_here) {
				if (snake_over)
					gameover = true;
				else {
					//mat[i][j]+=snake.length;
					buffer[i][j] = snake.head;
				}
			}
			/*if (mat[i][j] > 0 && buffer[i][j] != snake.head) {
				buffer[i][j] = snake.body;
			}
			*/
			buffer[fruit.pos.x][fruit.pos.y] = fruit.icon;
			if (snake_eat) {
				snake.length++;
				//increase();
				random();
			}
		}
	}
}
void display() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			cout << buffer[i][j]<<' ';
		}
		cout << endl;
	}
}
void command() {
	char input = ' ';
	clock_t tstart = clock();
	while ((clock() - tstart) < 1) {

		if (kbhit()) {
			input = getch();
			break;
		}
	}

	if (input == 'w') {
		if (buffer[snake.pos.x - 1][snake.pos.y] == '+') {
			gameover = true;
		}
		else {
			snake.saver.x = -1;
			snake.saver.y = 0;
			snake.pos.x--;
		}
	}
	else if (input == 'a') {
		if (buffer[snake.pos.x][snake.pos.y - 1] == '+') {
			gameover = true;
		}
		else {
			snake.saver.x = 0;
			snake.saver.y = -1;
			snake.pos.y--;
		}
	}
	else if (input == 's') {
		if (buffer[snake.pos.x + 1][snake.pos.y] == '+') {
			gameover = true;
		}
		else {
			snake.saver.x = 1;
			snake.saver.y = 0;
			snake.pos.x++;
		}
	}
	else if (input == 'd') {
		if (buffer[snake.pos.x][snake.pos.y + 1] == '+') {
			gameover = true;
		}
		else {
			snake.saver.x = 0;
			snake.saver.y = 1;
			snake.pos.y++;
		}
	}
	else {
		if (buffer[snake.pos.x + snake.saver.x][snake.pos.y + snake.saver.y] == '+') {
			gameover = true;
		}
		else {
			snake.pos.x += snake.saver.x;
			snake.pos.y += snake.saver.y;
		}
	}
}

/*void chop() {
	for (int k = 0; k < 25; k++) {
		for (int l = 0; l < 25; l++) {
			if (mat[k][l] > 0) {
				mat[k][l]--;
			}
		}
	}
}
*/
void welcome() {
	cout << "***Welcome to snake***" << endl<<endl;
	cout << "*************Rules*************" << endl<<endl;
	cout << "1.Your SCORE will be displayed down the screen.\n\n2.Use (w,a,s,d) to navigate" << endl<<endl;
	cout << "3.If you hit any '#' of '+' You will lose\n\nYou complete the game when scoring 529 points\n\nHave fun!" << endl<<endl;
	cout << "NOTE: Language must be switched to english";
}
void save() {
	if (body_pos_x[0] == snake.pos.x && body_pos_y[0] == snake.pos.y) {
		return;
	}
	else {
		for (int v = snake.length; v > -1; v--) {
			body_pos_x[v] = body_pos_x[v - 1];
			body_pos_y[v] = body_pos_y[v - 1];
		}
		body_pos_x[0] = snake.pos.x;
		body_pos_y[0] = snake.pos.y;
	}
}
//Make a function that saves your last action
//Modify the tail
