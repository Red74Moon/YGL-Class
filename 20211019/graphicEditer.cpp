/*
	�׷��� �����͸� ������� �մϴ�.
	�׷��� �����ʹ� �������� ����� ������ �� �ֽ��ϴ�.
	�� ����� ����, �׸�, ���׶���̸� ����� ��ġ�� �����ϸ� �׷����ϴ�.
	�׷��� �����ʹ� �� ������ ���� �� �� �ֽ��ϴ�.
*/

#include <iostream>
#include<fstream>

#include "Editor.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Star.h"

using namespace std;

int main()
{
	Editor* editor = new Editor();

	//editor->AddShape(new Triangle(10,10,10));
	//editor->AddShape(new Rectangle(20,20,10,20));
	//editor->AddShape(new Circle(5,5,5));
	//editor->AddShape(new Star(8, 8, 3));

	//editor->Draw();

	//editor->Save();

	editor->Load();
	
	editor->Draw();
	
	delete editor;

	return 0;
}