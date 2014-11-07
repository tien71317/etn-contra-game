#ifndef __BULLET_MOVING_H__
#define __BULLET_MOVING_H__
#include "DynamicObject.h"
#include "CInputDx9.h"

class GifBulletMoving : public DynamicObject
{
	//Physic*			m_Physic;
	D3DXVECTOR3		m_startPosition;
public:
	GifBulletMoving();
	Physic*			getPhysic() const { return m_Physic; }
	GifBulletMoving(D3DXVECTOR3 _position, eDirection _direction, eObjectID _objectID);
	void Initialize();
	void UpdateAnimation();
	void UpdateCollision(Object* checkingObject);
	void UpdateMovement();
	void Update();
	void Render(SPRITEHANDLE spriteHandle);
	void Release();
	virtual ~GifBulletMoving();
	float Moving(D3DXVECTOR3& a);
};

#endif