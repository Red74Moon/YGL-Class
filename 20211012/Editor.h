#pragma once

#include <vector>

class Shape;

class Editor
{
public:
	Editor();
	virtual ~Editor();

	void Draw();
	void Save();
	void Load();

	void AddShape(Shape* NewShape);

private:
	std::vector<Shape*> Shapes;
};