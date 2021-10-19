/*
	�׷��� �����͸� ������� �մϴ�.
	�׷��� �����ʹ� �������� ����� ������ �� �ֽ��ϴ�.
	�� ����� ����, �׸�, ���׶���̸� ����� ��ġ�� �����ϸ� �׷����ϴ�.
	�׷��� �����ʹ� �� ������ ���� �� �� �ֽ��ϴ�.
*/

#include <iostream>
#include "Editor.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

int main()
{
	Editor* editor = new Editor();

	editor->AddShape(new Trangle());
	editor->AddShape(new Rectangle());
	editor->AddShape(new Circle());

	editor->Draw();

	editor->Save();

	delete editor;
	return 0;
}