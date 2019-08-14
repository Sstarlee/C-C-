///*
//    1.创建可视化窗口
//
//	 1.1 initgraph(int width int height)
//	 1.2 clisegaph()//关闭窗口
//	2.贴图操作
//	   2.1 IMAGE img;
//	   2.2 变量和图片绑定 loadimage（&img，"IMGURL");
//	   2.3 显示图片 putimage(int x, int y,&img);
//	3.语言
//	4.交互
//	5.用户交互：按键交互
//
//*/
///*
//颜色的表示：
//1 颜色宏表示颜色  大写英语
//2 三原色RGB自行配置
//空心画：
//rectangle(0, 0, 100, 100);  画一个矩形  左上角坐标+右下角坐标
//circle(100, 100, 50);   画一个圆   圆心坐标+半径大小
//填充：
//1.有边界线：
//  fillrectangle（）；fillcircle（）；
//2.无边界线：
//  solidrectangle（）；solidcircle（）；
//
//
// 颜色设置：
// 1.背景颜色：
// setbkcolor();
// cleardevice;
// 2.线颜色
// setlinecolor（RED);
// 3.文字颜色
// settextcolor();
//
// 4填充颜色
// 文字输出：
// 只能输出字符串：
//
// 1.输出文字
// outtextxy(int x,int y,char *str);
//
// 2.去掉文字背景
// setbkmode（TRANSPARENT);
//  3.  文字字体设置
//  1.  文字格式设置
//      settextstyle(25,0,char  *frontName)
//
//
//
//
//*/
//#include<iostream>
//#include<graphics.h>
//#include<stdlib.h>
//#include<conio.h>
//using namespace std;
//int main()
//{
//	initgraph(640, 480);//界定窗口的大小
//	IMAGE mm;
//	//for (int i = 0; i < 640; i+=10)
//	//{
//	//	setlinecolor(RED);
//	//	putpixel(i, 240, RED);//画一个点
//	//	line(0, 0, i, 240);//画一条线
//	//}
//	//
//	//rectangle(0, 0, 100, 100);
//	//setfillcolor(BLUE);//填充颜色
//	//fillrectangle(50, 50, 200, 200);
//	/*setlinecolor(RGB(254, 188, 252));
//	fillcircle(100+100, 100+100, 50);*/
//	for (int i = 0; i < 300; i += 20)
//	{
//		settextcolor(BLUE);
//		settextstyle(i, 0, "宋体");
//		//setbkmode(TRANSPARENT);
//		cleardevice();
//		outtextxy(100, 100, "sadasdasd456465");
//		Sleep(500);
//		//system("cls");
//	}
//	cin.get();
//	closegraph();
//	cin.get();
//	cin.get();
//	return 0;
//}