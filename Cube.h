#pragma once
#include "Mesh.h"
class Cube : public Mesh
{
public:
	Vertex* m_pSVertex;

	Cube();
	virtual ~Cube();

	void Initialize();
	void Render();
	void Release();
};
