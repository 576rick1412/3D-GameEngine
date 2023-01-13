#pragma once
#include "framework.h"

const int TRIANGLE = 3;

Cube ::Cube()
{

}

Cube ::~Cube()
{

}

void Cube::Initialize()
{
	// �ﰢ���� 4 4 
	// ������ü 8 12 
	this->m_nVertex = 8;
	this->m_nTriangle = 12;
	this->m_pSVertex = new Vertex[m_nVertex];
	this->m_pVertex = new Vertex[m_nVertex];
	this->m_pTI = new int[m_nTriangle * TRIANGLE];

	/*
	for (int i = 0; i < 4; i++)
	{
		this->m_pVertex[i].x = ;
		this->m_pVertex[i].y = ;
		this->m_pVertex[i].z = ;
		this->m_pVertex[i].w = ;
	} */
	/*
			0
		 /     \
	   /         \
	 /	    3	   \
	1 - - - - - - - 2

	< �޼���ǥ�� >
	0 1 3 ->
	0 3 2 ->
	1 2 3 ->
	0 2 1
	*/
	/* �ﰢ�� 
	this->m_pVertex[0] = Vertex(0.f, 100.f, 0.f);
	this->m_pVertex[1] = Vertex(-100.f, -100.f, -50.f);
	this->m_pVertex[2] = Vertex(-100.f, -100.f, 50.f);
	this->m_pVertex[3] = Vertex(100.f, -100.f, 50.f);
	*/

	/* ������ü */
	this->m_pVertex[0] = Vertex( -10.f,  10.f,  10.f );
	this->m_pVertex[1] = Vertex(  10.f,  10.f,  10.f );
	this->m_pVertex[2] = Vertex( -10.f,  10.f, -10.f );
	this->m_pVertex[3] = Vertex(  10.f,  10.f, -10.f );
	this->m_pVertex[4] = Vertex( -10.f, -10.f,  10.f );
	this->m_pVertex[5] = Vertex(  10.f, -10.f,  10.f );
	this->m_pVertex[6] = Vertex( -10.f, -10.f, -10.f );
	this->m_pVertex[7] = Vertex(  10.f, -10.f, -10.f );
	

	// ��
	this->m_pTI[0]  = 0;  this->m_pTI[1]  = 2;  this->m_pTI[2]  = 3;
	this->m_pTI[3]  = 0;  this->m_pTI[4]  = 3;  this->m_pTI[5]  = 1;
	this->m_pTI[6]  = 2;  this->m_pTI[7]  = 6;  this->m_pTI[8]  = 7;
	this->m_pTI[9]  = 3;  this->m_pTI[10] = 2;  this->m_pTI[11] = 7;
	this->m_pTI[12] = 1;  this->m_pTI[13] = 3;  this->m_pTI[14] = 5;
	this->m_pTI[15] = 3;  this->m_pTI[16] = 7;  this->m_pTI[17] = 5;

	// ��
	this->m_pTI[18] = 0;  this->m_pTI[19] = 1;  this->m_pTI[20] = 4;
	this->m_pTI[21] = 1;  this->m_pTI[22] = 5;  this->m_pTI[23] = 4;
	this->m_pTI[24] = 2;  this->m_pTI[25] = 0;  this->m_pTI[26] = 4;
	this->m_pTI[27] = 0;  this->m_pTI[28] = 4;  this->m_pTI[29] = 6;
	this->m_pTI[30] = 6;  this->m_pTI[31] = 5;  this->m_pTI[32] = 7;
	this->m_pTI[33] = 4;  this->m_pTI[34] = 5;  this->m_pTI[35] = 6;
}

void Cube::Render()
{
	gdi->GreenPen();

	for (int i = 0; i < m_nVertex; i++) m_pSVertex[i] = this->m_Mat.Transform(m_pVertex[i]);


	for (int i = 0; i < m_nTriangle * TRIANGLE; i += 3)
	{

		gdi->Line(m_pSVertex[m_pTI[i + 0]].x, m_pSVertex[m_pTI[i + 0]].y,
				  m_pSVertex[m_pTI[i + 1]].x, m_pSVertex[m_pTI[i + 1]].y);


		gdi->Line(m_pSVertex[m_pTI[i + 1]].x, m_pSVertex[m_pTI[i + 1]].y,
				  m_pSVertex[m_pTI[i + 2]].x, m_pSVertex[m_pTI[i + 2]].y);


		gdi->Line(m_pSVertex[m_pTI[i + 2]].x, m_pSVertex[m_pTI[i + 2]].y,
				  m_pSVertex[m_pTI[i + 0]].x, m_pSVertex[m_pTI[i + 0]].y);

		/*
		gdi->Line(v1.x, v1.y, v2.x, v2.y);
		gdi->Line(v2.x, v2.y, v3.x, v3.y);
		gdi->Line(v3.x, v3.y, v1.x, v1.y);

		gdi->Line(v1.x + cx, -v1.y + cy, v2.x + cx, -v2.y + cy);
		gdi->Line(v2.x + cx, -v2.y + cy, v3.x + cx, -v3.y + cy);
		gdi->Line(v3.x + cx, -v3.y + cy, v1.x + cx, -v1.y + cy);
		*/
	}

	for (int i = 0; i < m_nVertex; i++) YellowDot(m_pVertex[i].x, m_pVertex[i].y);

	/*
	YellowDot(v1.x + cx, -v1.y + cy);
	YellowDot(v2.x + cx, -v2.y + cy);
	YellowDot(v3.x + cx, -v3.y + cy);
	*/
}

void Cube::Release()
{
	delete[] this->m_pVertex;
}

/*
this->m_nTriangle = 4;
this->m_pTriangle = new Triangle[m_nTriangle];

this->m_pTriangle[0].v1.x = ;
this->m_pTriangle[0].v1.y = ;
this->m_pTriangle[0].v1.z = ;
this->m_pTriangle[0].v1.w = ;

this->m_pTriangle[0].v2.x = ;
this->m_pTriangle[0].v2.y = ;
this->m_pTriangle[0].v2.z = ;
this->m_pTriangle[0].v2.w = ;

this->m_pTriangle[0].v3.x = ;
this->m_pTriangle[0].v3.y = ;
this->m_pTriangle[0].v3.z = ;
this->m_pTriangle[0].v3.w = ;
*/