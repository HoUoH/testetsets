#pragma once
#include "pch.h"

#define PlAYER_NUM 4
#define BALL_NUM 10
#define MAX_OBJECTS PlAYER_NUM + BALL_NUM
#define HERO_ID 0

#define KIND_HERO 0
#define KIND_BALL 1

#define WINDOW_SIZEX 600
#define WINDOW_SIZEY 600

#define PLAYER_SIZE 25
#define BALL_SIZE 15




struct sendData {
	int kind;
	float posX, posY;
	bool isVisible;
}typedef sendData;

struct recvData {
	float posX, posY;
	float velX, velY;
	u_char specialKey;	
}typedef recvData;

struct objects {
	int kind;					//����
	float posX, posY;			//��ġ
	float sizeX, sizeY;			//ũ��
	float pre_posX, pre_posY;	//���� ��ġ
	float velX, velY;			//�ӵ�
	float VelMag;				//�ӵ�ũ��
	float accX, accY;			//���ӵ�
	float ForceX, ForceY;		//��
	float frictionX, frictionY;	//������
	float mass;					//����
	float coefFriction;			//�������
	float elapsed_time_in_sec;	//����ð�
	bool isVisible;				//ǥ�ÿ���
}typedef objects;
