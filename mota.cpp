///*
//    1.�������ӻ�����
//
//	 1.1 initgraph(int width int height)
//	 1.2 clisegaph()//�رմ���
//	2.��ͼ����
//	   2.1 IMAGE img;
//	   2.2 ������ͼƬ�� loadimage��&img��"IMGURL");
//	   2.3 ��ʾͼƬ putimage(int x, int y,&img);
//	3.����
//	4.����
//	5.�û���������������
//
//*/
///*
//��ɫ�ı�ʾ��
//1 ��ɫ���ʾ��ɫ  ��дӢ��
//2 ��ԭɫRGB��������
//���Ļ���
//rectangle(0, 0, 100, 100);  ��һ������  ���Ͻ�����+���½�����
//circle(100, 100, 50);   ��һ��Բ   Բ������+�뾶��С
//��䣺
//1.�б߽��ߣ�
//  fillrectangle������fillcircle������
//2.�ޱ߽��ߣ�
//  solidrectangle������solidcircle������
//
//
// ��ɫ���ã�
// 1.������ɫ��
// setbkcolor();
// cleardevice;
// 2.����ɫ
// setlinecolor��RED);
// 3.������ɫ
// settextcolor();
//
// 4�����ɫ
// ���������
// ֻ������ַ�����
//
// 1.�������
// outtextxy(int x,int y,char *str);
//
// 2.ȥ�����ֱ���
// setbkmode��TRANSPARENT);
//  3.  ������������
//  1.  ���ָ�ʽ����
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
//	initgraph(640, 480);//�綨���ڵĴ�С
//	IMAGE mm;
//	//for (int i = 0; i < 640; i+=10)
//	//{
//	//	setlinecolor(RED);
//	//	putpixel(i, 240, RED);//��һ����
//	//	line(0, 0, i, 240);//��һ����
//	//}
//	//
//	//rectangle(0, 0, 100, 100);
//	//setfillcolor(BLUE);//�����ɫ
//	//fillrectangle(50, 50, 200, 200);
//	/*setlinecolor(RGB(254, 188, 252));
//	fillcircle(100+100, 100+100, 50);*/
//	for (int i = 0; i < 300; i += 20)
//	{
//		settextcolor(BLUE);
//		settextstyle(i, 0, "����");
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