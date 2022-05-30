struct Vector {
	int x, y;
};
struct Snake {
	Vector pos;
	char head, body;
	int length;
	Vector saver;
	Snake() {
		length = 0;
		saver.x = 1;
		saver.y = 0;
	}
};
struct Fruit {
	Vector pos;
	char icon;
};