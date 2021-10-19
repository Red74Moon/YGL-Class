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
	//// �ݺ���, ũ�⸸ŭ �ݺ�
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

	//// �ڿ��� ���� ������...r
	//for (auto iter = Shapes.rbegin(); iter != Shapes.rend(); ++iter)
	//{
	//	(*iter)->Draw();
	//}

	// range for
	
	std::cout << "�׸��� ����" << std::endl;
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
		// �ɰ����̶�� �غ��� ����, ���̰� �ʿ�
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

	std::cout << "�ҷ����� ����" << std::endl << std::endl;
	std::string str;
	while (getline(readFile, str))
	{
		if (str == "�ﰢ��")
		{
			getline(readFile, str); // X
			int X = std::stoi(str);

			getline(readFile, str); // Y
			int Y = std::stoi(str);

			getline(readFile, str); // Edge
			int Edge = std::stoi(str);

			AddShape(new Triangle(X, Y, Edge));
		}
		else if (str == "�簢��")
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
		else if (str == "��")
		{
			getline(readFile, str); // X
			int X = std::stoi(str);

			getline(readFile, str); // Y
			int Y = std::stoi(str);

			getline(readFile, str); // R
			int Radius = std::stoi(str);

			AddShape(new Circle(X, Y, Radius));
		}
		else if (str == "��")
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
	std::cout << "�ҷ����� ��" << std::endl << std::endl;
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