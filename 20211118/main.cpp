/*
직선과 원의 방정식

두점과 한점에서 생기는 원의 반지름이 주어 졌을때 두점이 이루는 직선과 한점에 생기는 원이 충돌 하는 지 확인하는 확인을 해보세요.

입력
[0, 0]
[10, 10]
[5, 5, 5]

출력
충돌

입력
[0, 0]
[10, 10]
[20, 20, 1]

출력
충돌


입력은 배열로 함수에 호출 됩니다.

참고)
http://blog.naver.com/PostView.nhn?blogId=elkiss&logNo=140045975518
*/

#include <iostream>

class Vector2D
{
public:
	Vector2D(float NewX = 0, float NewY = 0)
	{
		X = NewX;
		Y = NewY;
	}

	float X;
	float Y;
};

class Line
{
public:
	Line(Vector2D NewStart, Vector2D NewEnd)
	{
		Start = NewStart;
		End = NewEnd;
	}

	Vector2D Start;
	Vector2D End;
};

class Circle
{
public:
	Circle(Vector2D NewCenter, float NewR = 0)
	{
		Center = NewCenter;
		R = NewR;
	}

	Vector2D Center;
	float R;

	bool Intersection(Line CheckLine)
	{
		float m;

		m = (float)(CheckLine.End.Y - CheckLine.Start.Y) / (float)(CheckLine.End.X - CheckLine.Start.X);
		float a = m;
		float b = -1;
		float c = -m * CheckLine.Start.X + CheckLine.Start.Y;
		float d = sqrt((a * Center.X + b * Center.Y + c) * (a * Center.X + b * Center.Y + c) / (a * a) + (b * b));

		if (d <= R)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};



int main()
{
	//float First[2] = { 0, 0 };
	//float Second[2] = { 10, 10 };
	//float ACircle[3] = { 5, 5, 5 };

	float First[2] = { 0, 0 };
	float Second[2] = { 10, 10 };
	float ACircle[3] = { 20, 30, 1 };


	Line OneLine(Vector2D(First[0], First[1]), Vector2D(Second[0], Second[1]));

	Circle OneCircle(Vector2D(ACircle[0], ACircle[1]), ACircle[2]);

	std::cout << (OneCircle.Intersection(OneLine) ? "충돌" : "충돌X") << std::endl;


	return 0;
}