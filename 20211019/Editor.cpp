#include <iostream>
#include <fstream>

#include "Editor.h"
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Star.h"

Editor::Editor()
{
}

Editor::~Editor()
{
}

void Editor::Draw()
{
	//// 반복문, 크기만큼 반복
	//for (size_t i = 0; i < Shapes.size(); ++i)
	//{
	//	Shapes[i]->Draw();
	//}

	// iterator
	// for (std::vector<Shape*>::iterator iter = Shapes.begin(); iter != Shapes.end(); ++iter)
	//for (auto iter = Shapes.begin(); iter != Shapes.end(); ++iter)
	//{
	//	(*iter)->Draw();
	//}

	//// 뒤에서 부터 앞으로...r
	//for (auto iter = Shapes.rbegin(); iter != Shapes.rend(); ++iter)
	//{
	//	(*iter)->Draw();
	//}

	// range for
	
	std::cout << "그리기 시작" << std::endl;
	for (auto Object : Shapes)
	{
		Object->Draw();
	}
}

void Editor::Save()
{
	std::ofstream writeFile;
	writeFile.open("Editor.sav");

	for (auto Object : Shapes)
	{
		// 심각형이라면 밑변의 길이, 높이가 필요
		if (dynamic_cast<Triangle*>(Object) != nullptr)
		{
			Triangle* T = dynamic_cast<Triangle*>(Object);

			writeFile << T->GetName() << std::endl;
			writeFile << T->GetX()    << std::endl;
			writeFile << T->GetY()    << std::endl;
			writeFile << T->GetEdge() << std::endl;
		}
		else if (dynamic_cast<Rectangle*>(Object) != nullptr)
		{
			Rectangle* T = dynamic_cast<Rectangle*>(Object);

			writeFile << T->GetName()   << std::endl;
			writeFile << T->GetX()      << std::endl;
			writeFile << T->GetY()      << std::endl;
			writeFile << T->GetWidth()  << std::endl;
			writeFile << T->GetHeight() << std::endl;
		}
		else if (dynamic_cast<Circle*>(Object) != nullptr)
		{
			Circle* T = dynamic_cast<Circle*>(Object);

			writeFile << T->GetName()   << std::endl;
			writeFile << T->GetX()      << std::endl;
			writeFile << T->GetY()      << std::endl;
			writeFile << T->GetRadius() << std::endl;
		}
		else if (dynamic_cast<Star*>(Object) != nullptr)
		{
			Star* T = dynamic_cast<Star*>(Object);

			writeFile << T->GetName() << std::endl;
			writeFile << T->GetX() << std::endl;
			writeFile << T->GetY() << std::endl;
			writeFile << T->GetColor() << std::endl;
		}
	}
	writeFile.close();
}

void Editor::Load()
{
	std::ifstream readFile;
	readFile.open("Editor.sav");   

	std::cout << "불러오기 시작" << std::endl << std::endl;
	std::string str;
	while (getline(readFile, str))
	{
		if (str == "삼각형")
		{
			getline(readFile, str); // X
			int X = std::stoi(str);

			getline(readFile, str); // Y
			int Y = std::stoi(str);

			getline(readFile, str); // Edge
			int Edge = std::stoi(str);

			AddShape(new Triangle(X, Y, Edge));
		}
		else if (str == "사각형")
		{
			getline(readFile, str); // X
			int X = std::stoi(str);

			getline(readFile, str); // Y
			int Y = std::stoi(str);

			getline(readFile, str); // W
			int Width = std::stoi(str);

			getline(readFile, str); // H
			int Height = std::stoi(str);

			AddShape(new Rectangle(X, Y, Width, Height));
		}
		else if (str == "원")
		{
			getline(readFile, str); // X
			int X = std::stoi(str);

			getline(readFile, str); // Y
			int Y = std::stoi(str);

			getline(readFile, str); // R
			int Radius = std::stoi(str);

			AddShape(new Circle(X, Y, Radius));
		}
		else if (str == "별")
		{
			getline(readFile, str); // X
			int X = std::stoi(str);

			getline(readFile, str); // Y
			int Y = std::stoi(str);

			getline(readFile, str); // C
			int Color = std::stoi(str);

			AddShape(new Star(X, Y, Color));
		}
	}
	readFile.close(); 
	std::cout << "불러오기 끝" << std::endl << std::endl;
}

void Editor::AddShape(Shape* NewShape)
{
	Shapes.push_back(NewShape);
}


//class Vector
//{
//public:
//	int X;
//	int Y;
//
//	Vector& operator+(const Vector& RHS)
//	{
//		this->X += RHS.X;
//		this->Y += RHS.Y;
//
//		return *this;
//	}
//
//};
//
//Vector A;
//Vector B;
//Vector C;
//C = A + B;