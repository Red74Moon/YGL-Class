#include <iostream>
#include "Editor.h"
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

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
	for (auto Object : Shapes)
	{
		Object->Draw();
	}
}

void Editor::Save()
{
	std::cout << "===========================" << std::endl;
	std::cout << "저장하는 내용입니다." << std::endl;
	std::cout << "===========================" << std::endl;
	for (auto Object : Shapes)
	{
		// 심각형이라면 밑변의 길이, 높이가 필요
		if (dynamic_cast<Triangle*>(Object) != nullptr)
		{
			Triangle* T = dynamic_cast<Triangle*>(Object);

			std::cout << T->GetName() << std::endl;
			std::cout << T->GetX() << std::endl;
			std::cout << T->GetY() << std::endl;
			std::cout << T->GetEdge() << std::endl;
		}
		else if (dynamic_cast<Rectangle*>(Object) != nullptr)
		{
			Rectangle* T = dynamic_cast<Rectangle*>(Object);

			std::cout << T->GetName() << std::endl;
			std::cout << T->GetX() << std::endl;
			std::cout << T->GetY() << std::endl;
			std::cout << T->GetWidth() << std::endl;
			std::cout << T->GetHeight() << std::endl;
		}
		else if (dynamic_cast<Circle*>(Object) != nullptr)
		{
			Circle* T = dynamic_cast<Circle*>(Object);

			std::cout << T->GetName() << std::endl;
			std::cout << T->GetX() << std::endl;
			std::cout << T->GetY() << std::endl;
			std::cout << T->GetRadius() << std::endl;
		}

		Object->GetX();
		Object->GetY();
		std::cout << "저장완료." << std::endl << std::endl;
	}
	std::cout << "===========================" << std::endl << std::endl;
}

void Editor::Load()
{
}

void Editor::AddShape(Shape* NewShape)
{
	Shapes.push_back(NewShape);
}
