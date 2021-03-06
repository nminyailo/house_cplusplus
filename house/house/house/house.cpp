#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Parquet {
private:
	double length;
	double width;
public:
	void setParquet() {
		length = 1 + rand() % 100;
		width = 1 + rand() % 100;
	}
	void getParquet() {
		cout << "\n Parquet's length: " << length << ", width: " << width;
	}
};

class Window {
public:
	void setWindow() {
		width = 1 + rand() % 10;
		height = 1 + rand() % 10;
	}
	void getWindow() {
		cout << "\n Window's width(m) = " << width << ", height(m) = " << height;
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
		height = 1 + rand() % 10;
		int index = rand() % 4;
		color = colorsList[index];
		litresM2 = 1 + rand() % 100;
		calculatePaint(index, litresM2);
		parquet.setParquet();
		windowsNumber = 1 + rand() % 4;
		for (int i = 0; i < windowsNumber; ++i) {
			windows[i].setWindow();
		}
	}
	void getRoom() {
		cout << " Length(m) = " << length << ", width(m) = " << width << ", height(m) = " << height << "\n Room color = " << color << "; paint(m2): " << litresM2 << windowsNumber;
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
		cout << "\n";
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
		cout << "How many rooms = ";
		cin >> 	roomsNumber ;
		for (int i = 0; i < roomsNumber; ++i) {
			rooms[i].setRoom();
		}
	}
	void getFlat() {
		cout << "\nNumber of rooms = " << roomsNumber << "\n";
		for (int i = 0; i < roomsNumber; ++i) {
			cout << "\nRoom #" << i + 1;
			rooms[i].getRoom();
		}
	}
private:
	int roomsNumber;
	Room rooms[10];
};

class House {
public:
	void setHouse() {
		cout << "How many floors = ";
		cin >> 	floors ;
		cout << "How many flats per floor = ";
		cin >>	flatsPerFloor ;
		for (int i = 0; i < flatsPerFloor*floors; ++i) {
			cout << "\nFlat #" << i + 1 << "\n";
			flats[i].setFlat();
		}
	}
	void getHouse() {
		cout << "\nNumber of flats = " << flatsPerFloor * floors << "\n";
		for (int i = 0; i < flatsPerFloor*floors; ++i) {
			cout << "\nFlat #" << i + 1;
			flats[i].getFlat();
		}
	}
	
private:
	int floors;
	int flatsPerFloor;
	Flat flats[10];
};

int main(int argc, const char * argv[]) {
	House house;
	house.setHouse();
	house.getHouse();
	return 0;
}