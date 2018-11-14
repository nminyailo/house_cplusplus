// house.cpp 
#include <iostream>
#include <string>
using namespace std;
class Parquet {
public:
	void setParquet() {
		length = 1 + rand() % 100;
		width = 1 + rand() % 100;
	}

	void getParquet() {
		cout << "\n Parquet's length: " << length << ", width: " << width;
	}
private:
	double length;
	double width;
};


class Window {
public:
	void setWindow() {
		width = 1 + rand() % 100;
		height = 1 + rand() % 100;
	}

	void getWindow() {
		cout << "\n Window's width: " << width << ", height: " << height;
	}

private:
	double width;
	double height;
};



class Room {
public:

	int colorPaint[4] = { 0, 0, 0, 0 };
	string colorsList[4] = { "white", "yellow", "green", "grey" };

	void setRoom() {
		length = 1 + rand() % 100;
		width = 1 + rand() % 100;
		height = 1 + rand() % 100;
		int index = rand() % 4;
		color = colorsList[index];
		litresM2 = 1 + rand() % 100;
		calculatePaint(index, litresM2);
		parquet.setParquet();
		windowsNumber = 1 + rand() % 4;
		//        windows = new Window[windowsNumber];
		for (int i = 0; i < windowsNumber; ++i) {
			windows[i].setWindow();
		}
		//        delete [] windows;
	}

	void getRoom() {
		cout << " Length: " << length << ", width: " << width << ", height: " << height << "\n Color: " << color << "\n Litres per m2: " << litresM2 << windowsNumber;
		parquet.getParquet();
		for (int i = 0; i < windowsNumber; ++i) {
			windows[i].getWindow();
		}
	}

	void calculatePaint(int index, int lM2) {
		for (int i = 0; i < sizeof(colorPaint); ++i) {
			if (i == index) {
				colorPaint[i] += lM2;
			}
		}
	}

	void getPaint() {
		cout << "\n\n\n";
		for (int i = 0; i < sizeof(colorPaint); ++i) {
			cout << colorsList[i] << " - " << colorPaint[i];
		}
	}

private:
	double length;
	double width;
	double height;
	string color;
	double litresM2;
	Parquet parquet;
	int windowsNumber;
	Window windows[10];
};



class Flat {
public:
	void setFlat() {
		cout << "Enter number of rooms: ";
		cin >> roomsNumber;
		rooms = new Room[roomsNumber];
		for (int i = 0; i < roomsNumber; ++i) {
			//            cout<<"Room #" << i+1;
			rooms[i].setRoom();
		}
		delete[] rooms;
	}
	void getFlat() {
		cout << "\nNumber of rooms " << roomsNumber << "\n";
		for (int i = 0; i < roomsNumber; ++i) {
			cout << "\nRoom #" << i + 1;
			rooms[i].getRoom();
			//            rooms[i].getPaint();
		}
	}
private:
	int roomsNumber;
	Room *rooms;
};

class House {
public:
	void setHouse() {
		cout << "Enter number of floors: ";
		cin >> floors;
		cout << "Enter nubmer of flats per floor: ";
		cin >> flatsPerFloor;
		flats = new Flat[flatsPerFloor*floors];
		for (int i = 0; i < flatsPerFloor*floors; ++i) {
			cout << "\n\nFlat #" << i + 1 << "\n";
			flats[i].setFlat();
		}
		delete[] flats;
	}
	void getHouse() {
		cout << "\n\nNumber of flats " << flatsPerFloor * floors << "\n";
		for (int i = 0; i < flatsPerFloor*floors; ++i) {
			cout << "\nFlat #" << i + 1;
			flats[i].getFlat();
		}
	}

private:
	int floors;
	int flatsPerFloor;
	Flat *flats;

};

int main(int argc, const char * argv[]) {

	House house;
	house.setHouse();
	house.getHouse();

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
