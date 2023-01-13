#pragma once
class Matrix44
{
public:
	union {
		struct
		{
			float m11, m12, m13, m14;
			float m21, m22, m23, m24;
			float m31, m32, m33, m34;
			float m41, m42, m43, m44;
		};
		float M[4][4];
	};

public:
	Matrix44();
	~Matrix44();
	void Zero(); //��� ���� �׵��
	void Identity(); //��� ���� �׵��

	void Translate(float dx, float dy, float dz); //�̵���ȯ ���
	void Scale(float s); //ũ�⺯ȯ ���
	void RotateX(int Dho); //X�� ȸ����ȯ ���
	void RotateY(int Dho); //Y�� ȸ����ȯ ���
	void RotateZ(int Dho); //Z�� ȸ����ȯ ���

	void ScreenCoordTranslate(int cx, int cy); // ��ǥ�� ��ȭ ���

	Matrix44 Multiply(Matrix44 mat); //��� ���ϱ� ������
	Matrix44 Multiply(Matrix44 mat_1, Matrix44 mat_2, Matrix44 mat_3, Matrix44 mat_4, Matrix44 mat_5, Matrix44 mat_6); // ��� ���� �����ε�
	Vertex Transform(Vertex v); //Vertex�� ��Ľ� ����

	void Output(int dx, int dy);
};

