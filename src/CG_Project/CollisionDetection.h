#pragma once

bool check_collision(int sa, int sb);
bool check_view(int sa);
bool isLegalToMove(int cur,GLdouble posX, GLdouble posY, GLdouble posZ);
void changePosition(int cur);
void changeView();
bool isLegalToMoveView();
/******************�������ײ���*********************/
/*
#include <float.h>
#include <limits.h>
class AABBBox {
	private:
	float minX;//x����Сλ��
	float maxX;//x�����λ��
	float minY;//y����Сλ��
	float maxY;//y�����λ��
	float minZ;//z����Сλ��
	float maxZ;//z�����λ��

public:
	AABBBox(float vertices[])
	{
		init();
		findMinAndMax(vertices);
	}

	AABBBox(float minX, float maxX, float minY, float maxY, float minZ, float maxZ)
	{
		this->minX = minX;
		this->maxX = maxX;
		this->minY = minY;
		this->maxY = maxY;
		this->minZ = minZ;
		this->maxZ = maxZ;
	}
	//��ʼ����Χ�е���С�Լ���󶥵�����
    void init()
	{
		minX = FLT_MIN;
		maxX = FLT_MAX;
		minY = FLT_MIN;
		maxY = FLT_MAX;
		minZ = FLT_MIN;
		maxZ = FLT_MAX;
	}
	//��ȡ��Χ�е�ʵ����С�Լ���󶥵�����
	 void findMinAndMax(float vertices[])
	{
		for (int i = 0; i < 2; i++)
		{
			//�ж�X�����С�����λ��
			if (vertices[i * 3] < minX)
			{
				minX = vertices[i * 3];
			}
			if (vertices[i * 3] > maxX)
			{
				maxX = vertices[i * 3];
			}
			//�ж�Y�����С�����λ��
			if (vertices[i * 3 + 1] < minY)
			{
				minY = vertices[i * 3 + 1];
			}
			if (vertices[i * 3 + 1] > maxY)
			{
				maxY = vertices[i * 3 + 1];
			}
			//�ж�Z�����С�����λ��
			if (vertices[i * 3 + 2] < minZ)
			{
				minZ = vertices[i * 3 + 2];
			}
			if (vertices[i * 3 + 2] > maxZ)
			{
				maxZ = vertices[i * 3 + 2];
			}
		}
	}
	//�������ƽ�ƺ��AABB��Χ��
	 void getCurrAABBBox(float currPosition[])
	{
		 this->minX + currPosition[0];
		 this->maxX + currPosition[0];
		 this->minY + currPosition[1];
		 this->maxY + currPosition[1];
		 this->minZ + currPosition[2];
		this->maxZ + currPosition[2];
	}
};
*/


