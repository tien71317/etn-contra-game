﻿#include "GunRotating.h"



GunRotating::GunRotating()
{

}

GunRotating::GunRotating(D3DXVECTOR3 _position, eDirection _direction, eObjectID _objectID) 
	: DynamicObject(_position, _direction, _objectID)
{
	m_Position.z = 0.4f;
}

void GunRotating::Shoot()
{
	switch (m_DirectAttack)
	{
	case ZERO_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::DEFAULT_BULLET_OF_RAMBO, this->m_Position, D3DXVECTOR2(0.0f, 2.0f), 0);
		break;
	case ONE_CLOCK_DIRECTION:
		break;
	case TWO_CLOCK_DIRECTION:
		break;
	case THREE_CLOCK_DIRECTION:
		break;
	case FOUR_CLOCK_DIRECTION:
		break;
	case FIVE_CLOCK_DIRECTION:
		break;
	case SIX_CLOCK_DIRECTION:
		break;
	case SEVEN_CLOCK_DIRECTION:
		break;
	case EIGHT_CLOCK_DIRECTION:
		break;
	case NINE_CLOCK_DIRECTION:
		break;
	case TEN_CLOCK_DIRECTION:
		break;
	case ELEVEN_CLOCK_DIRECTION:
		break;
	default:
		break;
	}
}

D3DXVECTOR3 GunRotating::GetStartPositionOfBullet()
{
	switch(m_DirectAttack)
	{
	case ZERO_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x, m_Position.y + 30, 1);
	case ONE_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x + 20, m_Position.y + 30, 1);
	case TWO_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x + 30, m_Position.y + 20, 1);
	case THREE_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x + 30, m_Position.y, 1);
	case FOUR_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x + 30, m_Position.y - 20, 1);
	case FIVE_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x + 20, m_Position.y - 30, 1);
	case SIX_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x, m_Position.y - 30, 1);
	case SEVEN_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x - 20, m_Position.y - 30, 1);
	case EIGHT_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x - 30, m_Position.y - 20, 1);
	case NINE_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x - 30, m_Position.y, 1);
	case TEN_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x - 30, m_Position.y + 20, 1);
	case ELEVEN_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x - 20, m_Position.y + 30, 1);
	default:
		break;	
	}
}

void GunRotating::Initialize()
{
	m_Position.z = 0.4f;
	m_ObjectState = eObjectState::STATE_ALIVE_IDLE;
	sprite_alive = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_GUN_ROTATING));
	sprite_dead = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_EXPLOISION));
	m_Sprite = sprite_alive;
	m_AttackCounter = 8;
}

void GunRotating::UpdateAnimation()
{		
	switch (m_ObjectState)
	{
	case STATE_ALIVE_IDLE:
		_distance_X = CGlobal::Rambo_X - this->getPositionVec2().x;
		_distance_Y = CGlobal::Rambo_Y - this->getPositionVec2().y;
		
		if (abs(_distance_Y) < 30)
		{
#pragma region AttackMid
			if (_distance_X < 0)
			{
				if (lastDirectAttack != eDirectAttack::NINE_CLOCK_DIRECTION)
				{
					m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
					if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
					{
						m_Sprite->getAnimationAction()->setCurrentFrame(11);
						m_DirectAttack = eDirectAttack::NINE_CLOCK_DIRECTION;
						lastDirectAttack = m_DirectAttack;
						m_TimeChangeDirectAttack = 0;
					}
				}
				else
				{
					m_TimeChangeDirectAttack = 0;
				}
			}
			else
			{
				if (lastDirectAttack != eDirectAttack::THREE_CLOCK_DIRECTION)
				{
					m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
					if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
					{
						m_Sprite->getAnimationAction()->setCurrentFrame(5);
						m_DirectAttack = eDirectAttack::THREE_CLOCK_DIRECTION;
						lastDirectAttack = m_DirectAttack;
						m_TimeChangeDirectAttack = 0;
					}
				}
				else
				{
					m_TimeChangeDirectAttack = 0;
				}
			}

#pragma endregion AttackMid
		}
		else
		{
			if (abs(_distance_X) < 20)
			{
#pragma region AttackTopBot
					if (_distance_Y < 0)
					{
						if (lastDirectAttack != eDirectAttack::SIX_CLOCK_DIRECTION)
						{
							m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
							if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
							{
								m_Sprite->getAnimationAction()->setCurrentFrame(8);
								m_DirectAttack = eDirectAttack::SIX_CLOCK_DIRECTION;
								lastDirectAttack = m_DirectAttack;
								m_TimeChangeDirectAttack = 0;
							}
						}
						else
						{
							m_TimeChangeDirectAttack = 0;
						}
					}
					else
					{
						if (lastDirectAttack != eDirectAttack::ZERO_CLOCK_DIRECTION)
						{
							m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
							if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
							{
								m_Sprite->getAnimationAction()->setCurrentFrame(2);
								m_DirectAttack = eDirectAttack::ZERO_CLOCK_DIRECTION;
								lastDirectAttack = m_DirectAttack;
								m_TimeChangeDirectAttack = 0;
							}
						}
						else
						{
							m_TimeChangeDirectAttack = 0;
						}
					}
#pragma endregion AttackTopBot
			}
			else
			{
				if (_distance_X > 0 && _distance_Y > 0)
				{ 
#pragma region AttackTopRight
					// Goc phan tu thu nhat
					if (_distance_Y - _distance_X > 0)
					{
						if (lastDirectAttack != eDirectAttack::ONE_CLOCK_DIRECTION)
						{
							m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
							if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
							{
								m_DirectAttack = eDirectAttack::ONE_CLOCK_DIRECTION;
								m_Sprite->getAnimationAction()->setCurrentFrame(3);
								lastDirectAttack = m_DirectAttack;
								m_TimeChangeDirectAttack = 0;
							}
						}
						else
						{
							m_TimeChangeDirectAttack = 0;
						}
					}
					else
					{
						if (lastDirectAttack != eDirectAttack::TWO_CLOCK_DIRECTION)
						{
							m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
							if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
							{
								m_DirectAttack = eDirectAttack::TWO_CLOCK_DIRECTION;
								m_Sprite->getAnimationAction()->setCurrentFrame(4);
								lastDirectAttack = m_DirectAttack;
								m_TimeChangeDirectAttack = 0;
							}
						}
						else
						{
							m_TimeChangeDirectAttack = 0;
						}
					}
#pragma endregion AttackTopRight
				}
				if (_distance_X > 0 && _distance_Y < 0)
				{
#pragma region AttackBotRight
					if (_distance_X + _distance_Y > 0)
					{
						if (lastDirectAttack != eDirectAttack::FOUR_CLOCK_DIRECTION)
						{
							m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
							if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
							{
								m_DirectAttack = eDirectAttack::FOUR_CLOCK_DIRECTION;
								m_Sprite->getAnimationAction()->setCurrentFrame(6);
								lastDirectAttack = m_DirectAttack;
								m_TimeChangeDirectAttack = 0;
							}
						}
						else
						{
							m_TimeChangeDirectAttack = 0;
						}
					}
					else
					{
						if (lastDirectAttack != eDirectAttack::FIVE_CLOCK_DIRECTION)
						{
							m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
							if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
							{
								m_DirectAttack = eDirectAttack::FIVE_CLOCK_DIRECTION;
								m_Sprite->getAnimationAction()->setCurrentFrame(7);
								lastDirectAttack = m_DirectAttack;
								m_TimeChangeDirectAttack = 0;
							}
						}
						else
						{
							m_TimeChangeDirectAttack = 0;
						}
					}
#pragma endregion AttackBotRight
				}
				if (_distance_X < 0 && _distance_Y < 0)
				{
#pragma region AttackBotLeft
					if (_distance_Y - _distance_X > 0)
					{
						if (lastDirectAttack != eDirectAttack::EIGHT_CLOCK_DIRECTION)
						{
							m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
							if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
							{
								m_DirectAttack = eDirectAttack::EIGHT_CLOCK_DIRECTION;
								m_Sprite->getAnimationAction()->setCurrentFrame(10);
								lastDirectAttack = m_DirectAttack;
								m_TimeChangeDirectAttack = 0;
							}
						}
						else
						{
							m_TimeChangeDirectAttack = 0;
						}
					}
					else
					{
						if (lastDirectAttack != eDirectAttack::SEVEN_CLOCK_DIRECTION)
						{
							m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
							if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
							{
								m_DirectAttack = eDirectAttack::SEVEN_CLOCK_DIRECTION;
								m_Sprite->getAnimationAction()->setCurrentFrame(9);
								lastDirectAttack = m_DirectAttack;
								m_TimeChangeDirectAttack = 0;
							}
						}
						else
						{
							m_TimeChangeDirectAttack = 0;
						}
					}
#pragma endregion AttackBotLeft
				}
				if (_distance_X < 0 && _distance_Y > 0)
				{
#pragma region AttackTopLeft
					if (_distance_X + _distance_Y > 0)
					{
						if (lastDirectAttack != eDirectAttack::ELEVEN_CLOCK_DIRECTION)
						{
							m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
							if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
							{
								m_DirectAttack = eDirectAttack::ELEVEN_CLOCK_DIRECTION;
								m_Sprite->getAnimationAction()->setCurrentFrame(13);
								lastDirectAttack = m_DirectAttack;
								m_TimeChangeDirectAttack = 0;
							}
						}
						else
						{
							m_TimeChangeDirectAttack = 0;
						}
					}
					else
					{
						if (lastDirectAttack != eDirectAttack::TEN_CLOCK_DIRECTION)
						{
							m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
							if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
							{
								m_DirectAttack = eDirectAttack::TEN_CLOCK_DIRECTION;
								m_Sprite->getAnimationAction()->setCurrentFrame(12);
								lastDirectAttack = m_DirectAttack;
								m_TimeChangeDirectAttack = 0;
							}
						}
						else
						{
							m_TimeChangeDirectAttack = 0;
						}
					}
#pragma endregion AttackToopLeft
				}
			}
		}
	
		break;
		case STATE_SHOOTING:
			
			break;
	case STATE_BEFORE_DEATH:
		m_Sprite = sprite_dead;
		m_Sprite->UpdateAnimation(300);
		break;
	case STATE_DEATH:
		break;
	default:
		break;
	}	
		
}

void GunRotating::UpdateCollision(Object* checkingObject)
{
	IDDirection collideDirection = this->m_Collision->CheckCollision(this, checkingObject);

	if(collideDirection != IDDirection::DIR_NONE)
	{
		if(checkingObject->getID() == eObjectID::BULLET_RAMBO)
		{
			Bullet* tempBullet = (Bullet*)(checkingObject);
			if(tempBullet->getTypeBullet() == eIDTypeBullet::DEFAULT_BULLET_OF_RAMBO)
			{
				if(m_AttackCounter > 0)
				{
					--m_AttackCounter;
				}
			}
			else if(tempBullet->getTypeBullet() == eIDTypeBullet::RED_BULLET_OF_RAMBO)
			{
				if(m_AttackCounter >= 2)
				{
					m_AttackCounter -= 2;
				}
			}
			else if(tempBullet->getTypeBullet() == eIDTypeBullet::FIRE_BULLET_OF_RAMBO)
			{
				if(m_AttackCounter > 0)
				{
					m_AttackCounter = 0;
				}
			}

			if(m_AttackCounter == 0)
			{
				m_ObjectState = eObjectState::STATE_BEFORE_DEATH;
			}
			checkingObject->setObjectState(eObjectState::STATE_DEATH);
			checkingObject->setObjectState(eObjectState::STATE_DEATH);
		}
	}
}

void GunRotating:: UpdateMovement()
{}
void GunRotating::Update()
{
	
	switch (m_ObjectState)
	{
	case STATE_ALIVE_IDLE:
		//m_TimeChangeState += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
		//if(m_TimeChangeState > 3000)
		//{
		//	m_ObjectState = STATE_SHOOTING;
		//	m_TimeChangeState = 0;
		//}
		break;
	case STATE_SHOOTING:
		Shoot();
		m_ObjectState == eObjectState::STATE_ALIVE_IDLE;
		// some fucking code to shoot bullet, then change to state-alive-idle
		break;
	case STATE_BEFORE_DEATH:
		isDead = true;
		m_TimeChangeState += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
		if(m_TimeChangeState > 1500)
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
void GunRotating::Render(SPRITEHANDLE spriteHandle)
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


void GunRotating::Release()
{
	m_Sprite = 0;
	sprite_alive->Release();
	sprite_dead->Release();
}

GunRotating::~GunRotating()
{

}