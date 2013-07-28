#include "Character.h"
#include "Queue.h"
#include "GameInfo.h"

void Character::onEnter()
{
	MovingEntity::onEnter();

	m_bIsMoving = false;
}

void Character::onExit()
{
	MovingEntity::onExit();
}

bool Character::onMove()
{
	// �����ƶ��У��������>_<
	if (m_bIsMoving)
	{
		return false;
	}

	CCPoint moveDelta = m_vCurMoveVector * GI.GridSize;
	//CCPoint curPos = getPosition();
	CCPoint targetPosition = getPosition() + moveDelta;
	if (this != GI.Me->getHead())
	{
		targetPosition = GI.Me->getPrivousCharacter(this)->getPosition();
	}

	// �ƶ���Ŀ��λ��֮�󣬵���onMoveDone��m_bIsMoving��Ϊfalse
	CCAction* action = CCSequence::create(
		CCMoveTo::create(1.f, targetPosition),
		CCCallFunc::create(this, callfunc_selector(Character::onMoveDone)),
		NULL
		);

	this->runAction(action);

	return (m_bIsMoving = true);
}

// �Ѿ��ƶ���Ŀ�����
void Character::onMoveDone()
{
	m_bIsMoving = false;
}

void Character::kill() 
{
}


