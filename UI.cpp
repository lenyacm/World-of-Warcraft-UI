#include"pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 680
#define WIDTH 480

//˾�ͼƬ�ߴ�
#define Hw 100
#define Hh 100

//����ͼƬ�ߴ�
#define Cw 100
#define Ch 200

//��ʿͼƬ�ߴ�
#define Ww 70
#define Wh 70

//�л��س��ֵ�y����
#define APStart -ah-20

typedef struct Node
{
	int x;
	int y;
	struct Node* pnext;
}NODE;

NODE* p_bullet = NULL;
//MyPlane
NODE* p_MP = NULL;
//AttackPlane
NODE* p_AP = NULL;
//�ӵ�ʱ���
NODE* p_AP2 = NULL;
DWORD b1, b2, b3, b4, b5, b6;

IMAGE i_city;
IMAGE i_home0, i_dragon0, i_iceman0, i_lion0, i_ninja0, i_wolf0;
IMAGE i_home1, i_dragon1, i_iceman1, i_lion1, i_ninja1, i_wolf1;

void GameBackInit()
{
	loadimage(&i_city, L"city.png", Cw, Ch);

	loadimage(&i_home0, L"home0.png", Hw, Hh);
	loadimage(&i_dragon0, L"dragon0.png", Ww, Wh);
	loadimage(&i_iceman0, L"iceman0.png", Ww, Wh);
	loadimage(&i_lion0, L"lion0.png", Ww, Wh);
	loadimage(&i_ninja0, L"ninja0.png", Ww, Wh);
	loadimage(&i_wolf0, L"wolf0.png");

	loadimage(&i_home1, L"home1.png", Hw, Hh);
	loadimage(&i_dragon1, L"dragon1.png", Ww, Wh);
	loadimage(&i_iceman1, L"iceman1.png", Ww, Wh);
	loadimage(&i_lion1, L"lion1.png", Ww, Wh);
	loadimage(&i_ninja1, L"ninja1.png", Ww, Wh);
	loadimage(&i_wolf1, L"wolf1.png", Ww, Wh);
}

// ����PNGͼ��ȥ͸������
void drawAlpha(int  picture_x, int picture_y, IMAGE* picture) //xΪ����ͼƬ��X���꣬yΪY����
{

	// ������ʼ��
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
	int picture_width = picture->getwidth(); //��ȡpicture�Ŀ��ȣ�EASYX�Դ�
	int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
	int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ��ȣ�EASYX�Դ�
	int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
	int dstX = 0;    //���Դ������صĽǱ�

	// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
			int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //���Դ������صĽǱ�
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
			}
		}
	}
}

void show_ui()
{
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);//��������

	setfillcolor(WHITE);//���������ɫ

	GameBackInit();

	int time = 0;
	while (time < WINDOW_WIDTH - Ww) {
		//�廭��
		cleardevice();

		drawAlpha(0, WINDOW_HEIGHT - Hh, &i_home0);
		drawAlpha(WINDOW_WIDTH - Hw, WINDOW_HEIGHT - Hh, &i_home0);
		drawAlpha(time, WINDOW_HEIGHT - Wh, &i_dragon0);
		drawAlpha(WINDOW_WIDTH - Ww - time, WINDOW_HEIGHT - Wh, &i_iceman0);
		drawAlpha(500, 500, &i_lion0);
		drawAlpha(600, 600, &i_ninja0);


		Sleep(40);
		time += 1;
	}
	closegraph();
}