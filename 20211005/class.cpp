#include <string>

using namespace std;

class Charcter
{
public:
	string id;
	string Name;
	int Str;
	int Dex;
};

class Vector2D
{
public:
	int X;
	int Y;
};

class Color
{
public:
	int Red;
	int Green;
	int Blue;
};
class Image
{
public:
	Vector2D Position;
	Color RGB;
};

int main()
{
	Charcter Chracters[3];

	Chracters[0].id = "hong";
	Chracters[0].Name = "È«±æµ¿";
	Chracters[0].Str = 100;
	Chracters[0].Dex = 90;

	Chracters[1].id = "hong2";
	Chracters[1].Name = "È«±æ¼ø";
	Chracters[1].Str = 50;
	Chracters[1].Dex = 30;

	Chracters[2].id = "ko";
	Chracters[2].Name = "°í±æµ¿";
	Chracters[2].Str = 10;
	Chracters[2].Dex = 10;

	return 0;
}