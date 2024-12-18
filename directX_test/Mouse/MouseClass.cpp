#include "MouseClass.h"

void MouseClass::OnLeftPressed(int x, int y)
{
	this->leftIsDown = true;
	MouseEvent me(MouseEvent::EventType::LPress, x, y);
	this->eventBuffer.push(me);
}

void MouseClass::OnLeftReleased(int x, int y)
{
	this->leftIsDown = false;
	MouseEvent me(MouseEvent::EventType::LRelease, x, y);
	this->eventBuffer.push(me);
}

void MouseClass::OnRightPressed(int x, int y)
{
	this->rightIsDown = true;
	MouseEvent me(MouseEvent::EventType::RPress, x, y);
	this->eventBuffer.push(me);
}

void MouseClass::OnRightReleased(int x, int y)
{
	this->rightIsDown = false;
	MouseEvent me(MouseEvent::EventType::RRelease, x, y);
	this->eventBuffer.push(me);
}

void MouseClass::OnMiddlePressed(int x, int y)
{
	this->middleIsDown = true;
	MouseEvent me(MouseEvent::EventType::MPress, x, y);
	this->eventBuffer.push(me);
}

void MouseClass::OnMiddleReleased(int x, int y)
{
	this->middleIsDown = false;
	MouseEvent me(MouseEvent::EventType::MRelease, x, y);
	this->eventBuffer.push(me);
}

void MouseClass::OnWheelDown(int x, int y)
{
	MouseEvent me(MouseEvent::EventType::WheelDown, x, y);
	this->eventBuffer.push(me);
}

void MouseClass::OnWheelUp(int x, int y)
{
	MouseEvent me(MouseEvent::EventType::WheelUp, x, y);
	this->eventBuffer.push(me);
}

void MouseClass::OnMouseMove(int x, int y)
{
	this->x = x;
	this->y = y;
	MouseEvent me(MouseEvent::EventType::Move, x, y);
	this->eventBuffer.push(me);

}

void MouseClass::OnMouseMoveRaw(int x, int y)
{
	MouseEvent me(MouseEvent::EventType::RAW_MOVE, x, y);
	this->eventBuffer.push(me);
}

bool MouseClass::IsLeftDown()
{
	return this->leftIsDown;
}

bool MouseClass::IsRightDown()
{
	return this->rightIsDown;
}

bool MouseClass::IsMiddleDown()
{
	return this->middleIsDown;
}

int MouseClass::GetPosX()
{
	return this->x;
}

int MouseClass::GetPosY()
{
	return this->y;
}

MousePoint MouseClass::GetPos()
{
	return { this->x, this->y };
}

bool MouseClass::EventBufferIsEmpty()
{
	return this->eventBuffer.empty();
}

MouseEvent MouseClass::ReadEvent()
{
	if (this->eventBuffer.empty()) 
	{
		return MouseEvent();
	}
	else 
	{
		MouseEvent me = this->eventBuffer.front();
		this->eventBuffer.pop();
		return me;
	}
}



