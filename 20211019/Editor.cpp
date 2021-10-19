#include "Editor.h"
#include "Shape.h"

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
}

void Editor::Load()
{
}

void Editor::AddShape(Shape* NewShape)
{
	Shapes.push_back(NewShape);
}
