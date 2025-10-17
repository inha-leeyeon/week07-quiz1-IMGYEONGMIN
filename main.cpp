

#include<iostream>
#include<string>
#include<vector>
#include"Point.h"
#include"Square.h"

using namespace std;


Point::Point(int px, int py)
{
	x = px;
	y = py;
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

void Point::setX(int i)
{
	x = i;
}

void Point::setY(int i)
{
	y = i;
}


// --- Square Class Implementation ---
Square::Square(const string s, int i, int j, unsigned int k) :Point(i, j)
{
	name = s;
	side = k;
	area = side * side;
}

unsigned int Square::getSide() const
{
	return side;
}

unsigned int Square::getArea() const
{
	// 생성자에서 계산된 area 멤버 변수를 반환하는 것이 더 일관성 있습니다.
	return area;
}

string Square::getName() const
{
	return name;
}

void Square::setSide(unsigned int p)
{
	side = p;
	area = side * side;
}

void Square::setArea(unsigned int a)
{
	area = a;
}

void Square::setName(string s)
{
	name = s;
}


int main() {
	int n;
	cin >> n;

	
	vector<Square> squares;

	for (int i = 0; i < n; i++) {
		string name;
		int x, y;
		unsigned int side;
		cin >> name >> x >> y >> side;
		
		squares.push_back(Square(name, x, y, side));
	}

	cout << endl;
	vector<Square> sortedByArea = squares;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (sortedByArea[j].getArea() > sortedByArea[j + 1].getArea()) {
				Square temp = sortedByArea[j];
				sortedByArea[j] = sortedByArea[j + 1];
				sortedByArea[j + 1] = temp;
			}
		}
	}

	cout << "Squares in increasing order of area" << endl;

	for (int i = 0; i < n; i++) {
		cout << sortedByArea[i].getName() << "(" << sortedByArea[i].getX() << ", " << sortedByArea[i].getY() << ") side=" << sortedByArea[i].getSide() << ", area=" << sortedByArea[i].getArea() << endl;
	}
	cout << endl << endl;

	vector<Square> sortedByMaxX = squares;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if ((sortedByMaxX[j].getX() + sortedByMaxX[j].getSide()) > (sortedByMaxX[j + 1].getX() + sortedByMaxX[j + 1].getSide())) {
				Square temp = sortedByMaxX[j];
				sortedByMaxX[j] = sortedByMaxX[j + 1];
				sortedByMaxX[j + 1] = temp;
			}
		}
	}
	
	cout << "Squares in increasing order of max x-coordinate" << endl;
	for (int i = 0; i < n; i++) {
		cout << sortedByMaxX[i].getName() << "(" << sortedByMaxX[i].getX() + sortedByMaxX[i].getSide() << ", " << sortedByMaxX[i].getY() << ") side=" << sortedByMaxX[i].getSide() << ", area=" << sortedByMaxX[i].getArea() << endl;
	}

	cout << endl << endl;

	vector<Square> sortedByMaxY = squares;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			
			if ((sortedByMaxY[j].getY() + sortedByMaxY[j].getSide()) > (sortedByMaxY[j + 1].getY() + sortedByMaxY[j + 1].getSide())) {
				Square temp = sortedByMaxY[j];
				sortedByMaxY[j] = sortedByMaxY[j + 1];
				sortedByMaxY[j + 1] = temp;
			}
		}
	}
	
	cout << "Squares in increasing order of max y-coordinate" << endl;
	for (int i = 0; i < n; i++) {
		cout << sortedByMaxY[i].getName() << "(" << sortedByMaxY[i].getX() << ", " << sortedByMaxY[i].getY() + sortedByMaxY[i].getSide() << ") side=" << sortedByMaxY[i].getSide() << ", area=" << sortedByMaxY[i].getArea() << endl;
	}
}
