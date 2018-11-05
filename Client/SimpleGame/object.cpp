#include "stdafx.h"
#include "object.h"
#include <math.h>
#include <float.h>

float maxVelocity = 500.f;
float minVelocity = -500.f;

object::object()
{
	posX = 0;	posY = 0;
	sizeX = 0;	sizeY = 0;
	accX = 0;	accY = 0;

}


object::~object()
{
	delete this;
}

void object::Update(float elapsed_time_in_sec)
{

	float gz = mass * 9.8;
	float friction = coefFriction * gz;

	

	//������ ũ�� (ũ��, ���� �Ѵ� ������ ����)
	VelMag = sqrtf(velX * velX + velY * velY);

	if (VelMag < FLT_EPSILON) {
		velX = 0.f;
		velY = 0.f;
	}
	else { // �����¿� ���� �ӵ� ��ȭ
		
		//���� ���ϱ� ����ȭ
		frictionX = -friction * velX / VelMag;
		frictionY = -friction * velY / VelMag;

		float frictionAccX = frictionX / mass;
		float frictionAccY = frictionY / mass;

		float newVelX = velX + frictionAccX * elapsed_time_in_sec;	// ���� �ӵ� + (�����¿� ���� �ӵ� : ���������� ����ӵ� �ݴ����)
		float newVelY = velY + frictionAccY * elapsed_time_in_sec;

		if (newVelX*velX < 0.f)
			velX = 0.f;
		else
			velX = newVelX;
		if (newVelY*velY < 0.f)
			velY = 0.f;
		else
			velY = newVelY;
	}
	// ���� �ӵ� ���
	velX = velX + (accX * elapsed_time_in_sec);
	velY = velY + (accY * elapsed_time_in_sec);

	SetPreLocation(posX, posY);
	//���ŵ� ��ġ = ���� ��ġ + �ӵ� * �ð� 
	posX = posX + velX * elapsed_time_in_sec;
	posY = posY + velY * elapsed_time_in_sec;


	if (velX - maxVelocity > FLT_EPSILON)
		velX = maxVelocity;

	if (velX - minVelocity < FLT_EPSILON)
		velX = minVelocity;

	if (velY - maxVelocity > FLT_EPSILON)
		velY = maxVelocity;

	if (velY - minVelocity < FLT_EPSILON)
		velY = minVelocity;

}


void object::SetLocation(float x, float y)
{
	posX = x;
	posY = y;

}

void object::GetLocation(float *x, float *y)
{
	*x = posX;
	*y = posY;

}

void object::SetPreLocation(float x, float y)
{
	pre_posX = x;
	pre_posY = y;
}

void object::GetPreLocation(float * x, float * y)
{
	*x = pre_posX;
	*y = pre_posY;
}

void object::SetSize(float sizeX, float sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;

}

void object::GetSize(float *sizeX, float *sizeY)
{
	*sizeX = this->sizeX;
	*sizeY = this->sizeY;

}

void object::SetVelocity(float velX, float velY)
{
	this->velX = velX;
	this->velY = velY;
}

void object::GetVelocity(float * velX, float * velY)
{
	*velX = this->velX;
	*velY = this->velY;
}

void object::SetAcc(float accX, float accY)
{
	this->accX = accX;
	this->accY = accY;
}

void object::GetAcc(float * accX, float * accY)
{
	*accX = this->accX;
	*accY = this->accY;
}

void object::SetForce(float ForceX, float ForceY)
{
	this->ForceX = ForceX;
	this->ForceY = ForceY;
}

void object::GetForce(float * ForceX, float * ForceY)
{
	*ForceX = this->ForceX;
	*ForceY = this->ForceY;
}

void object::SetMass(float mass)
{
	this->mass = mass;
}

void object::GetMass(float * mass)
{
	*mass = this->mass;
}

void object::SetCoefFriction(float coefFriction)
{
	this->coefFriction = coefFriction;

}

void object::GetCoefFriction(float * coefFriction)
{

	*coefFriction = this->coefFriction;

}

void object::SetKind(int kind)
{
	this->kind = kind;
}

void object::GetKind(int * kind)
{
	*kind = this->kind;

}

void object::SetIsVisible(bool isVisible)
{
	this->isVisible = isVisible;
}

bool object::GetIsVisible()
{
	return isVisible;
}

void object::ApplyForce(float ForceX, float ForceY, float elapsed_time_in_sec)
{
	//���ӵ� ��� ��/����
	accX = ForceX / mass;
	accY = ForceY / mass;

	//�ӵ� ���
	velX = velX + accX * elapsed_time_in_sec;
	velY = velY + accY * elapsed_time_in_sec;

	accX = 0;
	accY = 0;

}

void object::BreakMovement(bool W_KeyIsDown, bool S_KeyIsDown, bool D_KeyIsDown, bool A_KeyIsDown, float elapsed_time_in_sec)
{
	if (!W_KeyIsDown)
	{
		if (velY > 0)
		{
			velY = velY + (frictionY * elapsed_time_in_sec / (mass *0.01f));
		}

	}
	if (!S_KeyIsDown)
	{
		if (velY < 0)
		{
			velY = velY + (frictionY * elapsed_time_in_sec / (mass *0.01f));
		}
	}
	if (!D_KeyIsDown)
	{
		if (velX > 0)
		{
			velX = velX + (frictionX * elapsed_time_in_sec / (mass *0.01f));

		}
	}
	if (!A_KeyIsDown)
	{
		if (velX < 0)
		{
			velX = velX + (frictionX * elapsed_time_in_sec / (mass *0.01f));
		}
	}

}

void object::PingpongBall() {
	velX = rand() % 6000 - 3000;
	velY = rand() % 6000 - 3000;
}
