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
#include <cmath>

using namespace std;

int intersection(float x, float y, float r, float a, float b, float c, float d, float xy[][2]);

int main()
{
	float x;
	float y;
	float r;

	float a;
	float b;
	float c;
	float d;

	int n;

	float xy[2][2];

	while (1)
	{
		cout << "원의 중심좌표 입력" << endl;
		cout << "x좌표 >> ";
		cin >> x;

		cout << "y좌표 >> ";
		cin >> y;

		cout << "반경 : ";
		cin >> r;

		cout << "직선의 두 점 입력" << endl;
		cout << "첫번째 점의 x좌표 >> ";
		cin >> a;
		cout << "첫번째 점의 y좌표 >> ";
		cin >> b;
		cout << "두번째 점의 x좌표 >> ";
		cin >> c;
		cout << "두번째 점의 y좌표 >> ";
		cin >> d;

		n = intersection(x, y, r, a, b, c, d, xy);

		if (n == 0)
			cout << "직선과 원은 만나지 않습니다." << endl;
		else if (n == 1)
			cout << "직선과 한 점(" << xy[0][0] << ", " << xy[0][1] << ")에서 만납니다." << endl;
		else if (n == 2)
			cout << "직선과 원은 두 점(" << xy[0][0] << ", " << xy[0][1] << ")와 " << xy[1][0] << ", (" << xy[1][1] << ")에서 만납니다." << endl;

		break;
	}
	return 0;
}

/*
 원의 중심을 x, y, 반경을 r
 두점(a,b),(c,d)를 지나는 직선을
 Y = mX + n라고 하면
 m = (d-b)/(c-a)
 n = (bc-ad)/(c-a)

 1) m에서 분모 c!=a이면
   (X - x)^2 + (Y - y)^2 = r^2 에 Y = mX + n를 대입
   X^2 - 2Xx + x^2 + (mX + (n-y))^2 - r^2 = 0

   X^2 - 2Xx + x^2 + (m^2X^2 + 2mX(n-y) + n^2-2ny+y^2) - r^2 = 0
   X^2( 1 + m^2) + 2X(m(n-y)-x) + (x^2 + n^2 - 2ny + y^2 - r^2) = 0
   X^2( m^2 + 1 ) + 2X( mn-my-x) + (x^2 + y^2 - r^2 + n^2 - 2ny) = 0

   위는 이차 방정식이므로
   AX^2 + 2BX + C = 0 로 하면
   A = m^2 + 1, B = 2(mn-my-x), C = (x^2 + y^2 - r^2 + n^2 - 2ny)
   B = 2B'로 두면 B' = mn-my-x
   판별식 D = B'^2 - AC

 2) m에서 분모가 0( c==a )이면 수직선이므로
	X == a라는 수직선의 위치에 따라서 달라진다.
*/

int intersection(float x, float y, float r, float a, float b, float c, float d, float xy[][2])
{
	float m, n;

	// A,B1,C 원과 직선으로부터 얻어지는 2차방정식의 계수들
	// D: 판별식
	// X,Y: 교점의 좌표
	float A, B1, C, D;
	float X, Y;

	// A,B1,C,D게산
	if (c != a)
	{
		// m, n계산
		m = (d - b) / (c - a);
		n = (b * c - a * d) / (c - a);

		A = m * m + 1;
		B1 = (m * n - m * y - x);
		C = (x * x + y * y - r * r + n * n - 2 * n * y);
		D = B1 * B1 - A * C;

		if (D < 0)
			return 0;
		else if (D == 0)
		{
			X = -B1 / A;
			Y = m * X + n;
			xy[0][0] = X;
			xy[0][1] = Y;
			return 1;
		}
		else
		{
			X = -(B1 + sqrt(D)) / A;
			Y = m * X + n;
			xy[0][0] = X;
			xy[0][1] = Y;

			X = -(B1 - sqrt(D)) / A;
			Y = m * X + n;
			xy[1][0] = X;
			xy[1][1] = Y;
			return 2;
		}
	}
	else
	{
		// a == c 인 경우는 수직선이므로
		// 근을 가지려면 a >= (x-r) && a <=(x+r) )
		// (a-x)*(a-x)
		// 1. 근이 없는 경우
		// a < (x-r) || a > (x+r)

		// 근이 없음
		if (a < (x - r) || a >(x + r))
			return 0;
		// 하나의 중근
		else if (a == (x - r) || a == (x + r))
		{
			X = a;
			Y = y;
			xy[0][0] = X;
			xy[0][1] = Y;

			return 1;
		}
		// 두개의 근
		else
		{
			// x = a를 대입하여 Y에 대하여 풀면
			X = a;
			Y = y + sqrt(r * r - (a - x) * (a - x));
			xy[0][0] = X;
			xy[0][1] = Y;

			Y = y - sqrt(r * r - (a - x) * (a - x));
			xy[1][0] = X;
			xy[1][1] = Y;

			return 2;
		}
	}
}

/*

void main()
{

	float opointx;
	float opointy;
	float r;
	float pointx1;
	float pointx2;
	float pointy1;
	float pointy2;
	float m;
	float a;
	float b;
	float c;
	float d;

	cout << "한원의 원점을 입력하세요 (예) 1,-2 : ";
	cin >> opointx;
	cin >> opointy;
	cout << "반지름을 입력하세요 ; ";
	cin >> r;
	cout << "점 1을 입력하세요 (예) 1,2 : ";
	cin >> pointx1;
	cin >> pointx2;
	cout << "점 2을 입력하세요 (예) 1,2 : ";
	cin >> pointy1;
	cin >> pointy2;

	m = (pointy2 - pointy1) / (pointx2 - pointx1);
	a = m;
	b = -1;
	c = -m * pointx1 + pointy1;
	d = sqrt((a * opointx + b * opointy + c) * (a * opointx + b * opointy + c) / (a * a) + (b * b));

	if (d < r)
	{
		cout << "교점은 2개입니다." << endl;
	}
	else if (d = r)
	{
		cout << "교점은 1개입니다." << endl;
	}
	else
	{
		cout << "교점은 없습니다." << endl;
	}

	return 0;
}
*/