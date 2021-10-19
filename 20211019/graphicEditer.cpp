/*
	그래픽 데이터를 만드려고 합니다.
	그래픽 에디터는 여러가지 모양을 저장할 수 있습니다.
	그 모양은 세모, 네모, 동그라미이며 모양의 위치를 지정하면 그려집니다.
	그래픽 에디터는 이 모양들을 저장 할 수 있습니다.
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

	editor->AddShape(new Triangle(10,10,10));
	editor->AddShape(new Rectangle(20,20,10,20));
	editor->AddShape(new Circle(5,5,5));

	editor->Draw();

	editor->Save();

	delete editor;
	return 0;
}