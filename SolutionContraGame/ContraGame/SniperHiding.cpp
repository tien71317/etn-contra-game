#include "SniperHiding.h"

SniperHiding::SniperHiding()
{}

SniperHiding::SniperHiding(D3DXVECTOR3 _position, eDirection _direction, eObjectID _objectID) 
	: DynamicObject(_position, _direction, _objectID)
{}

void SniperHiding::Shoot()
{
	switch (m_DirectAttack)
	{
	case AD_LEFT:
		break;
	case AD_RIGHT:
		break;
	default:
		break;	
	}
}

D3DXVECTOR3 SniperHiding::GetStartPositionOfBullet()
{
	switch(m_DirectAttack)
	{
	case AD_LEFT:
		break;
	case AD_RIGHT:
		break;
	default:
		break;	
	}
	return D3DXVECTOR3();
}

void SniperHiding::Initialize()
{
	m_ObjectState = eObjectState::STATE_ALIVE_IDLE;
	sprite_alive_hiding = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_SNIPER_HIDING));
	sprite_dead = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_SNIPER_HIDING_EXPLOISION));
	isShoot = false;
}

void SniperHiding::UpdateAnimation()
{	
	if(CGlobal::Rambo_X < m_Position.x)
	{
		m_Direction = eDirection::LEFT;
		m_DirectAttack = eDirectAttack::AD_LEFT;
	}
	else
	{
		m_Direction = eDirection::RIGHT;
		m_DirectAttack = eDirectAttack::AD_RIGHT;
	}

	switch (m_ObjectState)
	{
	case STATE_ALIVE_IDLE: // cant be attack by rambo bullet
		break;
	case STATE_SHOOTING:
		break;
	case STATE_BEFORE_DEATH:
		m_Sprite = sprite_dead;
		m_Sprite->UpdateAnimation(250);
		break;
	case STATE_DEATH:
		break;
	default:
		break;
	}	
	if(m_Direction == eDirection::LEFT)
	{
		m_Sprite->setSpriteEffect(ESpriteEffect::None);
	}

	else
	{
		if(m_Direction == eDirection::RIGHT)
		{
			m_Sprite->setSpriteEffect(ESpriteEffect::Horizontally);
		}
	}
}


void SniperHiding::UpdateCollision(Object* checkingObject)
{
	IDDirection collideDirection = this->m_Collision->CheckCollision(this, checkingObject);

	if(collideDirection != IDDirection::DIR_NONE)
	{
		switch (checkingObject->getID())
		{
			case eObjectID ::BULLET_RAMBO:
				break;
			default:
				break;
		}

	}
}

void SniperHiding:: UpdateMovement()
{
}

void SniperHiding::Update()
{
	_distance_X = abs(CGlobal::Rambo_X - this->getPositionVec2().x);
	if(_distance_X < 300)
	{
		switch (m_ObjectState)
		{
		case STATE_ALIVE_IDLE:
			m_TimeChangeState += (int)CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
			if(m_TimeChangeState > 5000)
			{
				m_TimeChangeState = 0;
				m_ObjectState = eObjectState::STATE_SHOOTING;
				isShoot = true;
			}
			break;
		case STATE_SHOOTING:
			if(isShoot == true)
			{
				Shoot();
				isShoot = false;
			}
			m_TimeChangeState += (int)CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
			if(m_TimeChangeState > 5000)
			{
				m_TimeChangeState = 0;
				m_ObjectState = eObjectState::STATE_ALIVE_IDLE;
			}
			break;
		case STATE_BEFORE_DEATH:
			m_TimeChangeState += (int)CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
			if(m_TimeChangeState > 1000)
			{
				m_ObjectState = eObjectState::STATE_DEATH;
				m_TimeChangeState = 0;
			}
			break;
		case STATE_DEATH:
			this->Release();
			break;
		default:
			break;
		}
	}
	
}
void SniperHiding::Render(SPRITEHANDLE spriteHandle)
{
	if(m_Sprite != 0)
	{
		m_Sprite->Render(spriteHandle, 
						getPositionVec2(), 
						m_Sprite->getSpriteEffect(), 
						m_Sprite->getRotate(), 
						m_Sprite->getScale(), 
						m_Position.z);
	}
}


void SniperHiding::Release()
{
	m_Sprite = 0;
	sprite_alive_hiding->Release();
	//sprite_alive_shooting->Release();
	sprite_dead->Release();
}

SniperHiding::~SniperHiding()
{

}