#include"pch.h"
#include"UI.h"

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

// 载入PNG图并去透明部分
void UI::drawAlpha(int  picture_x, int picture_y, IMAGE* picture) //x为载入图片的X坐标，y为Y坐标
{

	// 变量初始化
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
	int dstX = 0;    //在显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //在显存里像素的角标
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}

void UI::init_ui()
{
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);//创建窗口

	setfillcolor(WHITE);//设置填充颜色

	GameBackInit();
}