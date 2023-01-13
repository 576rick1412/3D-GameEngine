#pragma once
#include "Mesh.h"
class Tetra : public Mesh
{
public:
	Vertex* m_pSVertex;

	Tetra();
	virtual ~Tetra();

	void Initialize();
	void Render();
	void Release();
};

