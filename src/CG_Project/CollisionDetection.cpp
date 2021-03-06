#include"project.h"
#define INTEVAL -0.1
#define STEP 2.0
#define VIEW 1.2
#define SPHERE_INTEVEL 0.1
extern vector<Sphere> SphereVector;
extern float eye[3], r_eye;
// ���������֮�䣬true Ϊ��ײ
bool check_collision(int sa, int sb) {
	GLfloat xdis = SphereVector[sa].getX() - SphereVector[sb].getX();
	GLfloat ydis = SphereVector[sa].getY() - SphereVector[sb].getY();
	GLfloat zdis = SphereVector[sa].getZ() - SphereVector[sb].getZ();
	GLfloat rdis = SphereVector[sa].getRadius() + SphereVector[sb].getRadius();
	GLfloat dis = xdis * xdis + ydis * ydis + zdis * zdis;
	return dis < (rdis + INTEVAL)*(rdis + INTEVAL);
}
// if true, view is in sphere
bool check_view(int sa) {
	GLfloat xdis = SphereVector[sa].getX() - eye[0];
	GLfloat ydis = SphereVector[sa].getY() - eye[1];
	GLfloat zdis = SphereVector[sa].getZ() - eye[2];
	GLfloat rdis = SphereVector[sa].getRadius();
	GLfloat dis = sqrt(xdis * xdis + ydis * ydis + zdis * zdis);
	/*printf("SPHERE:%d,x:%f,y:%f,z:%f\n", sa, SphereVector[sa].getX(), 
			SphereVector[sa].getY(), SphereVector[sa].getZ());
	printf("EYE:x:%f,y:%f,z:%f\n", eye[0], eye[1], eye[2]);
	printf("SPERE:%d,DIS:%f,RDIS:%f\n",sa,dis,rdis);*/
	return dis < rdis + VIEW;
}
//������Ƿ�����ƶ�
bool isLegalToMove(int cur,GLdouble posX, GLdouble posY, GLdouble posZ) {
	int size = SphereVector.size();
		for (int i = 0; i < size; i++) {
				/*if (check_collision(i, cur)) {
					//int xsign = SphereVector[cur].getX() - SphereVector[i].getX() > 0 ? 1 : 0;
					//int ysign = SphereVector[cur].getY() - SphereVector[i].getY() > 0 ? 1 : 0;
					int zsign = SphereVector[cur].getZ() - SphereVector[i].getZ() > 0 ? 1 : 0;
					while (check_collision(i,cur)) {
						//SphereVector[cur].changePosition(xsign*SPHERE_INTEVEL, ysign*SPHERE_INTEVEL, zsign*SPHERE_INTEVEL);
						SphereVector[cur].changePosition(0, 0, zsign*SPHERE_INTEVEL);
						printf("CHANGE_SPHERE\n");
					}
					return false;
				}*/
			if (i != cur) {
				GLfloat xdis = SphereVector[i].getX() - posX;
				GLfloat ydis = SphereVector[i].getY() - posY;
				GLfloat zdis = SphereVector[i].getZ() - posZ;
				GLfloat rdis = SphereVector[i].getRadius() + SphereVector[cur].getRadius();
				GLfloat dis = xdis * xdis + ydis * ydis + zdis * zdis;
				if (dis < (rdis + INTEVAL)*(rdis + INTEVAL))
					return false;
			}				
		}
		return true;
}
//�ı��½����λ��
void changePosition(int cur) {
	int size = SphereVector.size();
		for (int i = 0; i < size; i++) {
			if (i != cur)
				while (check_collision(i, cur)) {
					if(rand()%2)
						SphereVector[cur].changePosition(0, STEP,0);
					if (rand() % 2)
						SphereVector[cur].changePosition(STEP,0, 0);
					if (rand() % 2)
						SphereVector[cur].changePosition(0,0,STEP);
				}
					
	}
}
//change the position of view
void changeView() {
	int size = SphereVector.size();
	for (int i = 0; i < size; i++) {
		while (check_view(i)) {
			eye[2] += 0.5;
			r_eye = sqrt(eye[0] * eye[0] + eye[1] * eye[1] + eye[2] * eye[2]);
		}
			
	}
}
// judge if the view can move
bool isLegalToMoveView() {
	int size = SphereVector.size();
	for (int i = 0; i < size; i++) {
			//printf("CHECK_VIEW:%d,%d\n",i, check_view(i));
			if (check_view(i))
				return false;
	}
	return true;
}