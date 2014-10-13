#ifndef __FlyerSin_H__
#define __FlyerSin_H__
#include "CObjectDx9.h"
#include "CInputDx9.h"

class Flyer_Sin : public Object
{
	Physic*			m_Physic;
public:
	Flyer_Sin();
	Physic*			getPhysic() const { return m_Physic; }
	Flyer_Sin(D3DXVECTOR3 _position, eDirection _direction, eObjectID _objectID);
	void Initialize();
	void UpdateAnimation();
	void UpdateCollision(Object* checkingObject);
	void UpdateMovement();
	void Render(SPRITEHANDLE spriteHandle);
	void Release();
	virtual ~Flyer_Sin();
};

#endif