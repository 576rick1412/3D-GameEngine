#pragma once
#include "framework.h"

const int TRIANGLE = 3;

Tetra::Tetra()
{

}

Tetra::~Tetra()
{

}

void Tetra :: Initialize()
{
	// »ï°¢»ÔÀº 4 4 
	// Á¤À°¸éÃ¼ 8 12 
	this->m_nVertex   = 4;
	this->m_nTriangle = 4;
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

	< ¿Þ¼ÕÁÂÇ¥°è >
	0 1 3 ->
	0 3 2 -> 
	1 2 3 ->
	0 2 1
	*/
	/* »ï°¢»Ô */
	this->m_pVertex[0]= Vertex(	   0.f,	 100.f,   0.f);
	this->m_pVertex[1]= Vertex( -100.f, -100.f, -50.f);
	this->m_pVertex[2]= Vertex( -100.f, -100.f,  50.f);
	this->m_pVertex[3]= Vertex(  100.f, -100.f,  50.f);
	

	/*
	this->m_pVertex[0] = Vertex( -10.f,  10.f,  10.f);
	this->m_pVertex[1] = Vertex(  10.f,  10.f,  10.f);
	this->m_pVertex[2] = Vertex( -10.f,  10.f, -10.f);
	this->m_pVertex[3] = Vertex(  10.f,  10.f, -10.f);
	this->m_pVertex[4] = Vertex( -10.f, -10.f,  10.f);
	this->m_pVertex[5] = Vertex(  10.f, -10.f,  10.f);
	this->m_pVertex[6] = Vertex( -10.f, -10.f, -10.f);
	this->m_pVertex[7] = Vertex(  10.f, -10.f, -10.f);
	*/


	this->m_pTI[0] = 0; this->m_pTI[ 1] = 1; this->m_pTI[ 2] = 3;
	this->m_pTI[3] = 0; this->m_pTI[ 4] = 3; this->m_pTI[ 5] = 2;
	this->m_pTI[6] = 1; this->m_pTI[ 7] = 2; this->m_pTI[ 8] = 3;
	this->m_pTI[9] = 0; this->m_pTI[10] = 2; this->m_pTI[11] = 1;
}

void Tetra :: Render()
{
	gdi->GreenPen();

	for (int i = 0; i < m_nVertex; i++) m_pSVertex[i] = this->m_Mat.Transform(m_pVertex[i]);


	for (int i = 0; i < m_nTriangle * TRIANGLE; i+=3)
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

void Tetra :: Release()
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