#pragma once

#include <vector>

class Shape;

class Editor
{
public:
	Editor();
	virtual ~Editor();

	void Draw();
	void Save(); // Serialize
	void Load(); // Deseialize

	void AddShape(Shape* NewShape);

private:
	std::vector<Shape*> Shapes;
};