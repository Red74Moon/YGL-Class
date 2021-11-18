/*
������ ���� ������

������ �������� ����� ���� �������� �־� ������ ������ �̷�� ������ ������ ����� ���� �浹 �ϴ� �� Ȯ���ϴ� Ȯ���� �غ�����.

�Է�
[0, 0]
[10, 10]
[5, 5, 5]

���
�浹

�Է�
[0, 0]
[10, 10]
[20, 20, 1]

���
�浹


�Է��� �迭�� �Լ��� ȣ�� �˴ϴ�.

����)
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
		cout << "���� �߽���ǥ �Է�" << endl;
		cout << "x��ǥ >> ";
		cin >> x;

		cout << "y��ǥ >> ";
		cin >> y;

		cout << "�ݰ� : ";
		cin >> r;

		cout << "������ �� �� �Է�" << endl;
		cout << "ù��° ���� x��ǥ >> ";
		cin >> a;
		cout << "ù��° ���� y��ǥ >> ";
		cin >> b;
		cout << "�ι�° ���� x��ǥ >> ";
		cin >> c;
		cout << "�ι�° ���� y��ǥ >> ";
		cin >> d;

		n = intersection(x, y, r, a, b, c, d, xy);

		if (n == 0)
			cout << "������ ���� ������ �ʽ��ϴ�." << endl;
		else if (n == 1)
			cout << "������ �� ��(" << xy[0][0] << ", " << xy[0][1] << ")���� �����ϴ�." << endl;
		else if (n == 2)
			cout << "������ ���� �� ��(" << xy[0][0] << ", " << xy[0][1] << ")�� " << xy[1][0] << ", (" << xy[1][1] << ")���� �����ϴ�." << endl;

		break;
	}
	return 0;
}

/*
 ���� �߽��� x, y, �ݰ��� r
 ����(a,b),(c,d)�� ������ ������
 Y = mX + n��� �ϸ�
 m = (d-b)/(c-a)
 n = (bc-ad)/(c-a)

 1) m���� �и� c!=a�̸�
   (X - x)^2 + (Y - y)^2 = r^2 �� Y = mX + n�� ����
   X^2 - 2Xx + x^2 + (mX + (n-y))^2 - r^2 = 0

   X^2 - 2Xx + x^2 + (m^2X^2 + 2mX(n-y) + n^2-2ny+y^2) - r^2 = 0
   X^2( 1 + m^2) + 2X(m(n-y)-x) + (x^2 + n^2 - 2ny + y^2 - r^2) = 0
   X^2( m^2 + 1 ) + 2X( mn-my-x) + (x^2 + y^2 - r^2 + n^2 - 2ny) = 0

   ���� ���� �������̹Ƿ�
   AX^2 + 2BX + C = 0 �� �ϸ�
   A = m^2 + 1, B = 2(mn-my-x), C = (x^2 + y^2 - r^2 + n^2 - 2ny)
   B = 2B'�� �θ� B' = mn-my-x
   �Ǻ��� D = B'^2 - AC

 2) m���� �и� 0( c==a )�̸� �������̹Ƿ�
	X == a��� �������� ��ġ�� ���� �޶�����.
*/

int intersection(float x, float y, float r, float a, float b, float c, float d, float xy[][2])
{
	float m, n;

	// A,B1,C ���� �������κ��� ������� 2���������� �����
	// D: �Ǻ���
	// X,Y: ������ ��ǥ
	float A, B1, C, D;
	float X, Y;

	// A,B1,C,D�Ի�
	if (c != a)
	{
		// m, n���
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
		// a == c �� ���� �������̹Ƿ�
		// ���� �������� a >= (x-r) && a <=(x+r) )
		// (a-x)*(a-x)
		// 1. ���� ���� ���
		// a < (x-r) || a > (x+r)

		// ���� ����
		if (a < (x - r) || a >(x + r))
			return 0;
		// �ϳ��� �߱�
		else if (a == (x - r) || a == (x + r))
		{
			X = a;
			Y = y;
			xy[0][0] = X;
			xy[0][1] = Y;

			return 1;
		}
		// �ΰ��� ��
		else
		{
			// x = a�� �����Ͽ� Y�� ���Ͽ� Ǯ��
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

	cout << "�ѿ��� ������ �Է��ϼ��� (��) 1,-2 : ";
	cin >> opointx;
	cin >> opointy;
	cout << "�������� �Է��ϼ��� ; ";
	cin >> r;
	cout << "�� 1�� �Է��ϼ��� (��) 1,2 : ";
	cin >> pointx1;
	cin >> pointx2;
	cout << "�� 2�� �Է��ϼ��� (��) 1,2 : ";
	cin >> pointy1;
	cin >> pointy2;

	m = (pointy2 - pointy1) / (pointx2 - pointx1);
	a = m;
	b = -1;
	c = -m * pointx1 + pointy1;
	d = sqrt((a * opointx + b * opointy + c) * (a * opointx + b * opointy + c) / (a * a) + (b * b));

	if (d < r)
	{
		cout << "������ 2���Դϴ�." << endl;
	}
	else if (d = r)
	{
		cout << "������ 1���Դϴ�." << endl;
	}
	else
	{
		cout << "������ �����ϴ�." << endl;
	}

	return 0;
}
*/