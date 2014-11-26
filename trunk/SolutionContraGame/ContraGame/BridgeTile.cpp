#include "BridgeTile.h"

BridgeTile::BridgeTile(){}

BridgeTile::BridgeTile(D3DXVECTOR3 _position, eDirection _direction, eObjectID _objectID)
: DynamicObject(_position, _direction, _objectID)
{

}
BridgeTile::~BridgeTile(){}

void BridgeTile::Initialize()
{
	if (m_eObjectID == BRIDGE_HEAD)
	{
		m_BridgeSprite = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_BRIDGE_HEAD));
	}
	if (m_eObjectID == BRIDGE_TAIL)
	{
		m_BridgeSprite = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_BRIDGE_TAIL));
	}
	if (m_eObjectID == BRIDGE_BODY)
	{
		m_BridgeSprite = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_BRIDGE_BODY));
	}
	m_DeadSprite = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_EXPLOISION));
	m_Sprite = m_BridgeSprite; 
	m_ObjectState = STATE_ALIVE_IDLE;
}
void BridgeTile::UpdateAnimation()
{
	switch (m_ObjectState)
	{
	case STATE_ALIVE_IDLE:
		m_Sprite->UpdateAnimation(500);
		break;
	case STATE_BEFORE_DEATH:
		if (isDead != true)
		{
			m_Sprite = m_DeadSprite;
			isDead = true;
		}
		m_Sprite->UpdateAnimation(250);
		break;
	case STATE_DEATH:
		break;
	default:
		break;
	};
}
void BridgeTile::UpdateCollision(Object* checkingObject)
{

}
void BridgeTile::Update()
{
	switch (m_ObjectState)
	{
	case STATE_ALIVE_IDLE:
		break;
	case STATE_BEFORE_DEATH:
		m_TimeChangeState += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
		if (m_TimeChangeState > 1000)
		{
			m_ObjectState = eObjectState::STATE_DEATH;
			m_TimeChangeState = 0;
		}
		break;
	case STATE_DEATH:
		this->Release();
		break;
	}
}
void BridgeTile::Render(SPRITEHANDLE spriteHandle)
{
	if (m_Sprite)
	{
		m_Sprite->Render(spriteHandle, 
										getPositionVec2(), 
										m_Sprite->getSpriteEffect(), 
										m_Sprite->getRotate(), 
										m_Sprite->getScale(), 
										m_Position.z);
	}
}
void BridgeTile::Release()
{
	m_BridgeSprite->Release();
	m_DeadSprite->Release();
	m_Sprite = 0;
}
