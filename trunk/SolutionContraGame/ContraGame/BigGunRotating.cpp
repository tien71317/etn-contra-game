﻿#include "BigGunRotating.h"



BigGunRotating::BigGunRotating()
{

}

BigGunRotating::BigGunRotating(D3DXVECTOR3 _position, eDirection _direction, eObjectID _objectID) 
	: DynamicObject(_position, _direction, _objectID)
{
	//m_Position = _position;
}

void BigGunRotating::Initialize()
{
	m_ObjectState = eObjectState::STATE_ALIVE_IDLE;
	sprite_alive = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_BIG_GUN_ROATING));
	sprite_dead = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_EXPLOISION));
	m_Sprite = sprite_alive;
}

void BigGunRotating::UpdateAnimation()
{	
	// tư tưởng thằng này:
	// Tính khoảng cách theo trục X, Y
	// Dựa vào Khoảng cách đó mà thực hiện set Frame hiện tại cho mỗi trường hợp:
	switch (m_ObjectState)
	{
	case STATE_ALIVE_IDLE: // cant be attack by rambo bullet
		m_Sprite = sprite_alive;
		_distance_X = abs(CGlobal::Rambo_X - this->getPositionVec2().x);
		_distance_Y = CGlobal::Rambo_Y - this->getPositionVec2().y;

		if(_distance_X > 350)
		{
			this->getSprite()->getAnimation()->setCurrentFrame(0);
		}
		else
		{
			if(_distance_X > 350 && _distance_X >= 100)
			{
				if( _distance_Y == 0 )
				{
					this->getSprite()->getAnimation()->setIndexStart(0);
					this->getSprite()->getAnimation()->setIndexEnd(2);
				}
				if( _distance_Y > 0 && _distance_Y < 50)
						{
							this->getSprite()->getAnimation()->setIndexStart(3);
							this->getSprite()->getAnimation()->setIndexEnd(5);
						}
				
			}
			else if( _distance_X <= 100)
			{
			if( _distance_Y >= 50)
			{
				this->getSprite()->getAnimation()->setIndexStart(6);
				this->getSprite()->getAnimation()->setIndexEnd(8);			
			}			
			}
			
			
		}
	
		m_Sprite->UpdateAnimation(1000);
		break;
	case STATE_BEFORE_DEATH:
		m_Sprite = sprite_dead;
		m_Sprite->UpdateAnimation(120);
		break;
	case STATE_DEATH:
		break;
	default:
		break;
	}	
}


void BigGunRotating::UpdateCollision(Object* checkingObject)
{
	switch (checkingObject->getID())
	{
	case eObjectID::RAMBO:

		break;
	case eObjectID::BULLET_RAMBO:

		break;
	default:
		break;
	}
}

void BigGunRotating:: UpdateMovement()
{}
void BigGunRotating::Update()
{
	switch (m_ObjectState)
	{
	case STATE_ALIVE_IDLE:
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
void BigGunRotating::Render(SPRITEHANDLE spriteHandle)
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


void BigGunRotating::Release()
{
	m_Sprite = 0;
	sprite_alive->Release();
	sprite_dead->Release();
}

BigGunRotating::~BigGunRotating()
{

}