#ifndef _UI_H_
#define _UI_H_

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

class UI {
public:
	void init_ui();
	void drawAlpha(int  picture_x, int picture_y, IMAGE* picture);
};
#endif // !_UI_H_
