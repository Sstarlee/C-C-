/*
地图部分
用0,1分别代表 某个图形模块  在制作地图时  直接填充地图 就可以完成地图

*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<string>
#pragma comment(lib,"Winmm.lib")

using namespace std;
//地图
int map[13][13] =
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,16,1,4,8,8,1,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,1,0,
	0,6,1,1,2,1,0,0,1,1,1,1,0,
	0,4,11,1,0,1,0,0,13,0,0,1,0,
	0,0,2,0,0,1,2,10,18,5,0,1,0,
	0,4,1,1,0,1,0,0,0,0,0,1,0,
	0,1,11,1,0,1,0,0,0,0,0,1,0,
	0,0,2,0,0,1,1,0,0,0,0,1,0,
	0,1,1,1,0,0,2,0,0,0,0,2,0,
	0,6,17,4,0,4,1,4,0,1,10,1,0,
	0,6,1,4,0,1,15,1,0,9,7,9,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,

};
int map2[13][13] =
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,15,0,1,10,5,0,0,6,0,8,1,0,
	0,1,0,1,0,0,0,0,11,0,0,18,0,
	0,6,1,1,1,1,0,0,1,1,1,1,0,
	0,0,0,0,1,0,0,0,1,0,0,10,0,
	0,1,1,1,1,0,1,2,1,3,6,1,0,
	0,1,0,0,1,0,6,11,10,0,0,9,0,
	0,1,1,0,1,0,0,0,1,0,18,5,0,
	0,1,1,11,1,1,1,1,1,0,7,14,0,
	0,1,0,0,0,0,1,0,10,0,0,11,0,
	0,1,0,5,1,3,1,0,1,2,10,1,0,
	0,1,18,6,5,0,1,0,6,0,0,16,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,
};
int map3[13][13] =
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,16,1,4,8,8,1,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,1,0,
	0,6,1,1,2,1,0,0,1,1,1,1,0,
	0,4,11,1,0,1,0,0,13,0,0,1,0,
	0,0,2,0,0,1,2,10,18,5,0,1,0,
	0,4,1,1,0,1,0,0,0,0,0,1,0,
	0,1,11,1,0,1,0,0,0,0,0,1,0,
	0,0,2,0,0,1,1,0,0,0,0,1,0,
	0,1,1,1,0,0,2,0,0,0,0,2,0,
	0,6,17,4,0,4,1,4,0,1,10,1,0,
	0,6,1,4,0,1,15,1,0,9,7,9,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,

};
//角色信息
struct gameRole
{
	char RoleName[20];
	int  HP;
	int  MP;
	int  Defender;
	int  Attrack;
	int  Bule;
	int  Yellow;
	int  LV;
	int  JY;
	int  QZ;
}role;//只有一个角色  所以全局角色
struct monster
{
	int HP;
	int Attrack;
	int Defender;
	int JY;
};
monster  BIANFU = { 20,10,9,50 };//界定蝙蝠怪物的属性 
monster  FASHI = { 40,20,20,70 };//界定法师怪物的属性
monster  KULOU = { 100,30,50,150 };
IMAGE img[19], roleInfo;//roleinfo 是角色信息图片
IMAGE PIAN;//开局背景图
HWND hwnd;  //用来显示战斗时的消息框
void gotoxy(int y, int x)//定位显示
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//定位打字

 //初始化角色信息 
void inputRoleName()
{
	//初始化角色
	role.Attrack = 50;
	role.Defender = 38;
	role.LV = 0;
	role.Yellow = 0;
	role.Bule = 0;
	role.MP = 250;
	role.HP = 500;
	role.JY = 0;
	role.QZ = 0;
}
void loadResource()
{
	//加载资源
	loadimage(&roleInfo, "info.jpg");
	for (int i = 0; i < 19; i++)
	{
		char fileName[20] = "";
		sprintf(fileName, "%d.jpg", i);
		loadimage(img + i, fileName, 55, 55);//界定位图大小
	}

}
//把整形转换为字符串
char str[20] = "";
char *intToWchar(int xNum)
{
	sprintf(str, "%d", xNum);
	return str;
}//将数据转格式 用以输出在图形界面山上
void drawMap()
{
	int i, j;
	int x, y;

	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{
			x = 55 * j;
			y = 55 * i;
			putimage(x, y, &img[map[i][j]]);
		}
	}

	putimage(55 * 13, 0, &roleInfo);
	outtextxy(55 * 13 + 12, 100 - 8, role.RoleName);
	outtextxy(55 * 13 + 12, 165, intToWchar(role.LV));
	outtextxy(55 * 13 + 12, 214, intToWchar(role.JY));
	outtextxy(55 * 13 + 12, 336, intToWchar(role.HP));
	outtextxy(55 * 13 + 12, 383, intToWchar(role.MP));
	outtextxy(55 * 13 + 12, 475, intToWchar(role.Attrack));
	outtextxy(55 * 13 + 12, 520, intToWchar(role.Defender));
	outtextxy(55 * 13 + 12, 630, intToWchar(role.Yellow));
	outtextxy(55 * 13 + 12, 693, intToWchar(role.Bule));
}
bool bloodPK(struct  monster MONSTER)
{
	int count = 0;
	int CLV = 0;
	role.HP -= MONSTER.Attrack - role.Defender*0.3 + MONSTER.Defender*0.3;
	role.MP -= (MONSTER.HP / role.Attrack*0.7);
	if (role.HP <= 0)
		return false;
	else
	{
		role.JY += MONSTER.JY;
		if (role.JY / 400 > 0)
		{
			CLV = role.JY / 400;
			count = role.JY % 400;
			role.JY = count;
			role.LV += CLV;
		}
		return true;
	}
}

static int Floor = 2;
void keyDown()
{
	int floor = Floor;
	char userKey;
	int i = 0, j = 0;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{
			if (map[i][j] == 15)
			{
				break;
			}

		}
		if (map[i][j] == 15)
			break;
	}
	userKey = _getch();
	switch (userKey)
	{
	case'A':
	case'a':
	case'75':
		//当要去的地方是空地
		if (map[i][j - 1] == 1)
		{
			map[i][j] = 1;
			map[i][j - 1] = 15;
		}
		//吃钥匙
		if (map[i][j - 1] == 4)
		{
			map[i][j] = 1;
			map[i][j - 1] = 15;
			role.Bule++;
		}
		//开门
		if (map[i][j - 1] == 2 && role.Bule > 0)
		{
			role.Bule--;
			map[i][j] = 1;
			map[i][j - 1] = 15;
		}
		//蝙蝠
		if (map[i][j - 1] == 10)
		{
			int ID = MessageBox(hwnd, "你遇到蝙蝠了 ", "是否攻击？ ", MB_YESNO);
			if (ID == IDYES)
			{
				//打架
				if (bloodPK(BIANFU) == true)
				{
					map[i][j] = 1;
					map[i][j - 1] = 15;
				}
				else
				{
					int beginID = MessageBox(hwnd, "你死球了！", "花钱复活不？", MB_YESNO);
				}
			}

		}
		//遇到法师
		if (map[i][j - 1] == 18)
		{
			int ID = MessageBox(hwnd, "你遇到法师了 ", "是否攻击？ ", MB_YESNO);
			if (ID == IDYES)
			{
				//打架
				if (bloodPK(FASHI) == true)
				{
					map[i][j] = 1;
					map[i][j - 1] = 15;
				}
				else
				{
					int beginID = MessageBox(hwnd, "你死球了！", "花钱复活不？", MB_YESNO);
				}
			}

		}
		//遇到红水晶
		if (map[i][j - 1] == 13)
		{
			map[i][j] = 1;
			map[i][j - 1] = 15;
			role.Attrack += 50;
			role.Defender += 30;
		}
		//遇到血瓶
		if (map[i][j - 1] == 6)
		{
			map[i][j] = 1;
			map[i][j - 1] = 15;
			role.HP += 75;
			role.MP += 70;
		}
		//遇到绿豆豆
		if (map[i][j - 1] == 9)
		{
			map[i][j] = 1;
			map[i][j - 1] = 15;
			role.LV += 1;
			role.Defender += 50;
			role.Attrack += 50;
		}
		//遇到红豆豆
		if (map[i][j - 1] == 8)
		{
			map[i][j] = 1;
			map[i][j - 1] = 15;
			role.HP -= 70;
			role.MP -= 50;
			role.Defender -= 10;
			role.Attrack += 25;
		}
		//骷髅
		if (map[i][j - 1] == 11)
		{
			int ID = MessageBox(hwnd, "你遇到骷髅了 ", "是否攻击？ ", MB_YESNO);
			if (ID == IDYES)
			{
				//打架
				if (bloodPK(KULOU) == true)
				{
					map[i][j] = 1;
					map[i][j - 1] = 15;
				}
				else
				{
					int beginID = MessageBox(hwnd, "你死球了！", "花钱复活不？", MB_YESNO);
				}
			}
			else
			{
				cout << "此路不通！！！" << endl;
			}
		}
		//权杖
		if (map[i][j - 1] == 17)
		{
			role.QZ += 1;
			map[i][j] = 1;
			map[i][j - 1] = 15;
		}
		//蓝瓶
		if (map[i][j - 1] == 7)
		{
			map[i][j] = 1;
			map[i][j - 1] = 15;
			role.MP += 70;
		}
		//去下一层
		if (map[i][j - 1] == 16)
		{
			if (floor == 2)
			{
				for (int q = 0; q < 13; q++)
				{
					for (int k = 0; k < 13; k++)
					{
						map[q][k] = map2[q][k];
					}
				}
			}
			if (floor == 3)
			{
				for (int q = 0; q < 13; q++)
				{
					for (int k = 0; k < 13; k++)
					{
						map[q][k] = map3[q][k];
					}
				}

			}
			Floor++;

		}
		//吃黄钥匙
		if (map[i][j - 1] == 5)
		{
			map[i][j] = 1;
			map[i][j - 1] = 15;
			role.Yellow++;
		}
		//开黄门
		if (map[i][j - 1] == 3 && role.Yellow > 0)
		{
			role.Yellow--;
			map[i][j] = 1;
			map[i][j - 1] = 15;
		}

		//遇到蓝水晶
		if (map[i][j - 1] == 14)
		{
			map[i][j] = 1;
			map[i][j - 1] = 15;
			role.Attrack += 30;
			role.Defender += 55;
		}
		break;
	case'W':
	case'w':
	case'72':
		if (map[i - 1][j] == 1)
		{
			map[i][j] = 1;
			map[i - 1][j] = 15;
		}
		if (map[i - 1][j] == 4)
		{
			map[i][j] = 1;
			map[i - 1][j] = 15;
			role.Bule++;
		}
		if (map[i - 1][j] == 2 && role.Bule > 0)
		{
			role.Bule--;
			map[i][j] = 1;
			map[i - 1][j] = 15;
		}
		if (map[i - 1][j] == 10)
		{
			int ID = MessageBox(hwnd, "你遇到蝙蝠了 ", "是否攻击？ ", MB_YESNO);
			if (ID == IDYES)
			{
				//打架
				if (bloodPK(BIANFU) == true)
				{
					map[i][j] = 1;
					map[i - 1][j] = 15;
				}
				else
				{
					int beginID = MessageBox(hwnd, "你死球了！", "花钱复活不？", MB_YESNO);
				}
			}

		}
		if (map[i - 1][j] == 18)
		{
			int ID = MessageBox(hwnd, "你遇到法师了 ", "是否攻击？ ", MB_YESNO);
			if (ID == IDYES)
			{
				//打架
				if (bloodPK(FASHI) == true)
				{
					map[i][j] = 1;
					map[i - 1][j] = 15;
				}
				else
				{
					int beginID = MessageBox(hwnd, "你死球了！", "花钱复活不？", MB_YESNO);
				}
			}

		}
		//遇到红水晶
		if (map[i - 1][j] == 13)
		{
			map[i][j] = 1;
			map[i - 1][j] = 15;
			role.Attrack += 50;
			role.Defender += 30;
		}
		//遇到血瓶
		if (map[i - 1][j] == 6)
		{
			map[i][j] = 1;
			map[i - 1][j] = 15;
			role.HP += 75;
			role.MP += 70;
		}
		//遇到绿豆豆
		if (map[i - 1][j] == 9)
		{
			map[i][j] = 1;
			map[i - 1][j] = 15;
			role.LV += 1;
			role.Defender += 50;
			role.Attrack += 50;
		}
		//遇到红豆豆
		if (map[i - 1][j] == 8)
		{
			map[i][j] = 1;
			map[i - 1][j] = 15;
			role.HP -= 70;
			role.MP -= 50;
			role.Defender -= 10;
			role.Attrack += 25;
		}
		//骷髅
		if (map[i - 1][j] == 11)
		{
			int ID = MessageBox(hwnd, "你遇到骷髅了 ", "是否攻击？ ", MB_YESNO);
			if (ID == IDYES)
			{
				//打架
				if (bloodPK(KULOU) == true)
				{
					map[i][j] = 1;
					map[i - 1][j] = 15;
				}
				else
				{
					int beginID = MessageBox(hwnd, "你死球了！", "花钱复活不？", MB_YESNO);
				}
			}
			else
			{
				cout << "此路不通！！！" << endl;
			}
		}
		//权杖
		if (map[i - 1][j] == 17)
		{
			role.QZ += 1;
			map[i][j] = 1;
			map[i - 1][j] = 15;
		}
		//蓝瓶
		if (map[i - 1][j] == 7)
		{
			map[i][j] = 1;
			map[i - 1][j] = 15;
			role.MP += 70;
		}
		//去第二层
		if (map[i - 1][j] == 16 && floor == 2)
		{

			for (int q = 0; q < 13; q++)
			{
				for (int k = 0; k < 13; k++)
				{
					//map[q][k] = map2[q][k];
				}
			}
			floor++;
		}
		//吃黄钥匙
		if (map[i - 1][j] == 5)
		{
			map[i][j] = 1;
			map[i - 1][j] = 15;
			role.Yellow++;
		}
		//开黄门
		if (map[i - 1][j] == 3 && role.Yellow > 0)
		{
			role.Yellow--;
			map[i][j] = 1;
			map[i - 1][j] = 15;
		}
		//遇到蓝水晶
		if (map[i - 1][j] == 14)
		{
			map[i][j] = 1;
			map[i - 1][j] = 15;
			role.Attrack += 30;
			role.Defender += 55;
		}
		break;
	case's':
	case'S':
	case'80':
		if (map[i + 1][j] == 1)
		{
			map[i][j] = 1;
			map[i + 1][j] = 15;
		}
		if (map[i + 1][j] == 4)
		{
			map[i][j] = 1;
			map[i + 1][j] = 15;
			role.Bule++;
		}
		if (map[i + 1][j] == 2 && role.Bule > 0)
		{
			role.Bule--;
			map[i][j] = 1;
			map[i + 1][j] = 15;
		}
		if (map[i + 1][j] == 10)
		{
			int ID = MessageBox(hwnd, "你遇到蝙蝠了 ", "是否攻击？ ", MB_YESNO);
			if (ID == IDYES)
			{
				//打架
				if (bloodPK(BIANFU) == true)
				{
					map[i][j] = 1;
					map[i + 1][j] = 15;
				}
				else
				{
					int beginID = MessageBox(hwnd, "你死球了！", "花钱复活不？", MB_YESNO);
				}
			}

		}
		if (map[i + 1][j] == 18)
		{
			int ID = MessageBox(hwnd, "你遇到法师了 ", "是否攻击？ ", MB_YESNO);
			if (ID == IDYES)
			{
				//打架
				if (bloodPK(FASHI) == true)
				{
					map[i][j] = 1;
					map[i + 1][j] = 15;
				}
				else
				{
					int beginID = MessageBox(hwnd, "你死球了！", "花钱复活不？", MB_YESNO);
				}
			}
		}
		//遇到红水晶
		if (map[i + 1][j] == 13)
		{
			map[i][j] = 1;
			map[i + 1][j] = 15;
			role.Attrack += 50;
			role.Defender += 30;
		}
		//遇到血瓶
		if (map[i + 1][j] == 6)
		{
			map[i][j] = 1;
			map[i + 1][j] = 15;
			role.HP += 75;
			role.MP += 70;
		}
		//遇到绿豆豆
		if (map[i + 1][j] == 9)
		{
			map[i][j] = 1;
			map[i + 1][j] = 15;
			role.LV += 1;
			role.Defender += 50;
			role.Attrack += 50;
		}
		//遇到红豆豆
		if (map[i + 1][j] == 8)
		{
			map[i][j] = 1;
			map[i + 1][j] = 15;
			role.HP -= 70;
			role.MP -= 50;
			role.Defender -= 10;
			role.Attrack += 25;
		}
		//骷髅
		if (map[i + 1][j] == 11)
		{
			int ID = MessageBox(hwnd, "你遇到骷髅了 ", "是否攻击？ ", MB_YESNO);
			if (ID == IDYES)
			{
				//打架
				if (bloodPK(KULOU) == true)
				{
					map[i][j] = 1;
					map[i + 1][j] = 15;
				}
				else
				{
					int beginID = MessageBox(hwnd, "你死球了！", "花钱复活不？", MB_YESNO);
				}
			}
			else
			{
				cout << "此路不通！！！" << endl;
			}
		}
		//权杖
		if (map[i + 1][j] == 17)
		{
			role.QZ += 1;
			map[i][j] = 1;
			map[i + 1][j] = 15;
		}
		//蓝瓶
		if (map[i + 1][j] == 7)
		{
			map[i][j] = 1;
			map[i + 1][j] = 15;
			role.MP += 70;
		}
		//去下一层
		if (map[i + 1][j] == 16)
		{
			if (floor == 2)
			{
				for (int q = 0; q < 13; q++)
				{
					for (int k = 0; k < 13; k++)
					{
						map[q][k] = map2[q][k];
					}
				}
			}
			if (floor == 3)
			{
				for (int q = 0; q < 13; q++)
				{
					for (int k = 0; k < 13; k++)
					{
						map[q][k] = map3[q][k];
					}
				}
			}
			Floor++;
		}
		//吃黄钥匙
		if (map[i + 1][j] == 5)
		{
			map[i][j] = 1;
			map[i + 1][j] = 15;
			role.Yellow++;
		}
		//开黄门
		if (map[i + 1][j] == 3 && role.Yellow > 0)
		{
			{
				role.Yellow--;
				map[i][j] = 1;
				map[i + 1][j] = 15;
			}
		}
		//遇到蓝水晶
		if (map[i + 1][j] == 14)
		{
			map[i][j] = 1;
			map[i + 1][j] = 15;
			role.Attrack += 30;
			role.Defender += 55;
		}


		if (map[i][j - 1] == 16)
		{
			if (floor == 2)
			{
				for (int q = 0; q < 13; q++)
				{
					for (int k = 0; k < 13; k++)
					{
						//map[q][k] = map2[q][k];
					}
				}
				floor++;
			}
			if (floor == 3)
			{
				for (int q = 0; q < 13; q++)
				{
					for (int k = 0; k < 13; k++)
					{
						map[q][k] = map3[q][k];
					}
				}
			}
		}
		break;
	case'D':
	case'd':
	case'77':
		if (map[i][j + 1] == 1)
		{
			map[i][j] = 1;
			map[i][j + 1] = 15;
		}
		if (map[i][j + 1] == 4)
		{
			map[i][j] = 1;
			map[i][j + 1] = 15;
			role.Bule++;
		}
		if (map[i][j + 1] == 2 && role.Bule > 0)
		{
			role.Bule--;
			map[i][j] = 1;
			map[i][j + 1] = 15;
		}
		if (map[i][j + 1] == 10)
		{
			int ID = MessageBox(hwnd, "你遇到蝙蝠了 ", "是否攻击？ ", MB_YESNO);
			if (ID == IDYES)
			{
				//打架
				if (bloodPK(BIANFU) == true)
				{
					map[i][j] = 1;
					map[i][j + 1] = 15;
				}
				else
				{
					int beginID = MessageBox(hwnd, "你死球了！", "花钱复活不？", MB_YESNO);
				}
			}

		}
		if (map[i][j + 1] == 18)
		{
			int ID = MessageBox(hwnd, "你遇到法师了 ", "是否攻击？ ", MB_YESNO);
			if (ID == IDYES)
			{
				//打架
				if (bloodPK(FASHI) == true)
				{
					map[i][j] = 1;
					map[i][j + 1] = 15;
				}
				else
				{
					int beginID = MessageBox(hwnd, "你死球了！", "花钱复活不？", MB_YESNO);
				}
			}

		}
		//遇到红水晶
		if (map[i][j + 1] == 13)
		{
			map[i][j] = 1;
			map[i - 1][j + 1] = 15;
			role.Attrack += 50;
			role.Defender += 30;
		}
		//遇到血瓶
		if (map[i][j + 1] == 6)
		{
			map[i][j] = 1;
			map[i][j + 1] = 15;
			role.HP += 75;
			role.MP += 70;
		}
		//遇到绿豆豆
		if (map[i][j + 1] == 9)
		{
			map[i][j] = 1;
			map[i][j + 1] = 15;
			role.LV += 1;
			role.Defender += 50;
			role.Attrack += 50;
		}
		//遇到红豆豆
		if (map[i][j + 1] == 8)
		{
			map[i][j] = 1;
			map[i][j + 1] = 15;
			role.HP -= 70;
			role.MP -= 50;
			role.Defender -= 10;
			role.Attrack += 25;
		}
		//骷髅
		if (map[i][j + 1] == 11)
		{
			int ID = MessageBox(hwnd, "你遇到骷髅了 ", "是否攻击？ ", MB_YESNO);
			if (ID == IDYES)
			{
				//打架
				if (bloodPK(KULOU) == true)
				{
					map[i][j] = 1;
					map[i][j + 1] = 15;
				}
				else
				{
					int beginID = MessageBox(hwnd, "你死球了！", "花钱复活不？", MB_YESNO);
				}
			}
			else
			{
				cout << "此路不通！！！" << endl;
			}
		}
		//权杖
		if (map[i][j + 1] == 17)
		{
			role.QZ += 1;
			map[i][j] = 1;
			map[i][j + 1] = 15;
		}
		//蓝瓶
		if (map[i][j + 1] == 7)
		{
			map[i][j] = 1;
			map[i][j + 1] = 15;
			role.MP += 70;
		}
		//去第二层
		if (map[i][j + 1] == 16 && floor == 2)
		{

			for (int q = 0; q < 13; q++)
			{
				for (int k = 0; k < 13; k++)
				{
					//map[q][k] = map2[q][k];
				}
			}
			floor++;

		}
		//吃黄钥匙
		if (map[i][j + 1] == 5)
		{
			map[i][j] = 1;
			map[i][j + 1] = 15;
			role.Yellow++;
		}
		//开黄门
		if (map[i][j + 1] == 3 && role.Yellow > 0)
		{
			role.Yellow--;
			map[i][j] = 1;
			map[i][j + 1] = 15;
		}
		//蓝水晶
		if (map[i][j + 1] == 14)
		{
			map[i][j] = 1;
			map[i][j + 1] = 15;
			role.Attrack += 30;
			role.Defender += 55;
		}
		break;

	}



}

void beijing1()
{
	initgraph(55 * 13, 55 * 13);
	IMAGE PIAN;
	loadimage(&PIAN, "191.jpg", 55 * 14, 55 * 13);
	putimage(0, 0, &PIAN);
}
void beijing2()
{
	initgraph(55 * 13, 55 * 13);
	IMAGE PIAN;
	loadimage(&PIAN, "192.jpg", 55 * 14, 55 * 13);
	putimage(0, 0, &PIAN);
}
void beijing3()
{
	initgraph(55 * 13, 55 * 13);
	IMAGE PIAN;
	loadimage(&PIAN, "193.jpg", 55 * 14, 55 * 13);
	putimage(0, 0, &PIAN);
}

int  choose(int y)
{

	char userKey;
	userKey = _getch();
	switch (userKey)
	{
	case'w':
	case'W':
	case 72:
		if (y == 191)
		{
			beijing1();
			return 191;
		}
		if (y == 192)
		{
			beijing1();	return 191;

		}
		if (y == 193)
		{
			beijing2();		return 192;
		}
		break;
	case 's':
	case 'S':
	case 80:
		if (y == 191)
		{
			beijing2();
			return 192;
		}
		if (y == 192)
		{
			beijing3();	return 193;
		}
		if (y == 193)
		{
			beijing3();
			return 193;
		}
		break;
	case 13:
		return 200; break;
	default: break;
	}
}

void qiang(int x)
{
	if (x == 1)
		cout << "what color is this?";
	if (x == 2)
		cout << " 什么垃圾游戏？";
	if (x == 3)
		cout << "what fuck？";
	if (x == 4)
		cout << "ni ma lgbd";
	if (x == 5)
		cout << "马化腾女儿今天过生日";
	if (x == 6)
		cout << "转发此消息5000条";
	if (x == 7)
		cout << "你就能得到傻逼证明书";
	if (x == 8)
		cout << "什么鬼？";
	if (x == 9)
		cout << "hey man！";
}
void wen()
{

	int ID = MessageBox(hwnd, "是否花费五元创建一个角色 ", "欢迎来到魔塔单机 ", MB_YESNO);
	if (ID == IDYES)
	{
		system("cls");
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 5);
		gotoxy(10, 30);
		cout << "是否花费十元给角色起个名字：";
		cin.get(role.RoleName, 20);
	}
	else {
		system("cls");
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 5);
		gotoxy(10, 30);
		cout << "阁下牛批，告辞！";
		Sleep(1500);
		exit(0);
	}
	ID = MessageBox(hwnd, "您打算给这游戏充钱吗？ ", "欢迎来到魔塔单机 ", MB_YESNO);
	if (ID == IDYES)
	{
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		gotoxy(10, 30);
		SetConsoleTextAttribute(hConsole, 5);
		cout << "充钱你会变得更强，我欣赏你，年轻人！";
		Sleep(1500);


	}
	else
	{
		system("cls");
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		gotoxy(10, 30);
		SetConsoleTextAttribute(hConsole, 5);
		cout << "不充钱就别玩了，告辞！";
		Sleep(1500);
		exit(0);

	}

}
void init()
{
	int y = 191;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int j = 1; j > 0; j--)
	{
		for (int i = 255; i >= 0; i--)
		{
			int count = rand() % 9 + 1;
			SetConsoleTextAttribute(hConsole, i);
			qiang(count);
			Sleep(18);
		}
	}
	wen();//窗口询问
	beijing1();
	while (1)
	{
		y = choose(y);
		if (y == 200)
			break;
	}
	inputRoleName();
}
void donghua()
{
	IMAGE PIAN;
	loadimage(&PIAN, "300.jpg");
	for (int i = 0; i < 55 * 13; i++)
	{
		putimage(0, 0, 55 * 14, i, &PIAN, 0, 0);
		Sleep(5);
	}
}


int main()
{
	init();
	mciSendString(_T("open 1.mp3 alias mymusic"), NULL, 0, NULL);
	mciSendString(_T("play mymusic"), NULL, 0, NULL);
	inputRoleName();
	loadResource();
	hwnd = initgraph(55 * 14, 55 * 13);
	donghua();

	while (1)
	{
		drawMap();
		keyDown();
	}
	closegraph();
	cin.get();
	return 0;
}
