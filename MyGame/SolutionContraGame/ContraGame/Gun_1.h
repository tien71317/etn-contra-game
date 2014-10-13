#ifndef __Gun1_H__
#define __Gun1_H__
#include "CObjectDx9.h"
#include "CInputDx9.h"

class Gun_1 : public Object
{
	Physic*			m_Physic;
public:
	Gun_1();
	Physic*			getPhysic() const { return m_Physic; }
	Gun_1(D3DXVECTOR3 _position, eDirection _direction, eObjectID _objectID);
	void Initialize();
	void UpdateAnimation();
	void UpdateCollision(Object* checkingObject);
	void UpdateMovement();
	void Render(SPRITEHANDLE spriteHandle);
	void Release();
	virtual ~Gun_1();
};

#endif