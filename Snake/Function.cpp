/**
̰���߹��ܺ���ʵ��
���ߣ�luye@nankai.edu.cn
ʱ�䣺2018��3��5��
*/
#pragma once
#include"Function.h"

Snake *head, *food;//ȫ��ָ�룬head����Զָ���һ���ڵ��ָ�룬food��ָ��ʳ���ָ��
Snake *q;//�������������õ���ָ��
int condition;//����������������Ѱ�����������ֱ�������ֵ��������������Ҳ��int ����
int end_condition = 0;//��ʾ�����������=1��ײǽ��=2��ҧ���Լ���=3���Լ�����;4 ײ���ϰ������
int score = 0, add = 1;//�÷ֺ�ÿ��ʳ��ķ���
int color = 0;//��ʾ�Ե�ʳ�����ɫ��=1����ɫ��=2����ɫ��=3����ɫ��=4����ɫ
int change_color = 0;//��ʾ�Ե�ĳ��ʳ�������ɫ��=0,��ɫ��=1����ɫ��=2����ɫ��=3����ɫ��=4����ɫ
int speed = 0;//��ʾ�Ե�ĳ����ɫ��ʳ�����ٶȣ�=0�����䣻=1�����٣�=2������
Obstacle o[33];//����һ������ϰ���Ľṹ�������������ÿһ���ϰ����x��y����

inline void Green_color()//�����õ�һ��SetConsoleTextAttribute����API���ÿ���̨������ɫ���Եĺ���������;������
{                               // ������ɫΪ��ɫ
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_GREEN |//������ɫ
		FOREGROUND_INTENSITY);//�������ø�������
}

inline void Red_color()//������ɫΪ��ɫ
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_INTENSITY);//intensity����������������ɫ����
}

inline void Yellow_color()//������ɫΪ��ɫ
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_GREEN |
		FOREGROUND_INTENSITY);
}

inline void Blue_color()//������ɫΪ��ɫ
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_BLUE |
		FOREGROUND_INTENSITY);//intensity����������������ɫ����
}

inline void Purple_color()//������ɫΪ��ɫ
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_BLUE |
		FOREGROUND_INTENSITY);
}

inline void Cyan_color()//������ɫΪ��ɫ
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_BLUE |
		FOREGROUND_GREEN |
		FOREGROUND_INTENSITY);
}

inline void White_color()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_GREEN |
		FOREGROUND_BLUE |
		FOREGROUND_INTENSITY);
}

void Set_location(int x, int y)//��λ�����������Ƕ�λ���������λ�÷����ӡ����Ҫ�Ķ���
{
	COORD cd;
	HANDLE hOut;
	cd.X = x;
	cd.Y = y;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, cd);//��λ����
}
void Creat_obs(Obstacle o[], int n)//�����ϰ���,һ�������ϰ�������ڲ������ѭ��
{
	int a = 14, b = 24, c = 8, d = 40, e = 32, f = 10;//��Щ���������Լ��漴��ѡ�ģ��ǿ��Ը����ģ�ֻҪ��������ͼ��Χ
	for (int i = 0; i < 6; i++)
	{
		o[i].x = a;
		a += 2;//�����+2����Ϊ���ڴ�ӡ"��"������ռ����������ռһ��
		o[i].y = c;
	}
	a = 15; b = 24; c = 8; d = 40; e = 32; f = 10;
	for (int i = 6; i < 15; i++)
	{
		o[i].x = b;
		o[i].y = c++;
	}
	a = 15; b = 23; c = 8; d = 40; e = 10; f = 17;
	for (int i = 15; i < 20; i++)
	{
		o[i].x = e;
		e += 2;
		o[i].y = f;
		f++;
	}
	a = 15; b = 23; c = 8; d = 40; e = 32; f = 13;
	for (int i = 20; i < 26; i++)
	{
		o[i].x = d;
		o[i].y = f;
		f++;
	}
	a = 15; b = 23; c = 8; d = 40; e = 44; f = 4;
	for (int i = 26; i < 30; i++)
	{
		o[i].x = e;
		e -= 2;
		o[i].y = f;
	}
	a = 15; b = 23; c = 8; d = 40; e = 46; f = 24;
	for (int i = 30; i < 33; i++)
	{
		o[i].x = e;
		e += 2;
		o[i].y = f;
		f--;
	}
	a = 15; b = 23; c = 8; d = 40; e = 32; f = 10;
	for (int i = 0; i < 33; i++)//���������õ��ϰ����ӡ����ͼ��
	{
		if(i < 15)
		{
			//Red_color();
		    Set_location(o[i].x, o[i].y);
		    cout << "��";
		    Set_location(o[i].x, o[i].y);
		    cout << "��";
		}
		else if(i < 20)
        {
			//Blue_color();
		    Set_location(o[i].x, o[i].y);
		    cout << "��";
		}
		else if(i < 26)
        {
			//Cyan_color();
		    Set_location(o[i].x, o[i].y);
		    cout << "��";
		}
		else if(i < 30)
        {
			//Purple_color();
		    Set_location(o[i].x, o[i].y);
		    cout << "��";
		}
		else
        {
			//Green_color();
		    Set_location(o[i].x, o[i].y);
		    cout << "��";
		}
	}
}


void Initial()//��ʼ���ߣ���һ��ʼ���Ľ�
{
	Snake *tail;
	int i;
	tail = new Snake;
	head = tail;
	head->s_x = 24;//����ͷ����x��y������ֵ
	head->s_y = 5;//���������ֵ�����Լ����ģ����Ը��ģ��Ӷ��ﵽ��������ʼλ�õ�Ŀ�ģ����ǲ��ܳ�Խ��ͼ��Χ�Ĵ�С
	head->next = NULL;
	for (i = 1; i <= 4; i++)//�����ĸ��ռ�����ĸ��ߵ�����
	{
		head = new Snake;
		head->next = tail;
		head->s_x = 24 + 2 * i;
		head->s_y = 5;
		tail = head;
	}
	while (tail->next != NULL)//��ͷ��β���������
	{
		Set_location(tail->s_x, tail->s_y);
		Green_color();
		cout << "��";
		tail = tail->next;
	}
}
void creat_food()//�������ʳ��ĺ���
{
	loop:Snake *food_1;//���������ʳ��������food_1ָ��ģ��ȴ�����ʳ��֮���ٸ�ֵ��ȫ��foodָ��
	srand((unsigned)time(NULL));//��srandһ�����ӣ�����rand������������ģ�ͬѧ�ǿ��Բ�һ�������������������Լ�Ϊʲô��α���
	food_1 = new Snake;
	while ((food_1->s_x % 2) != 0)    //��֤��Ϊż����ʹ��ʳ��������ͷ����,����Ϊż������Ϊ����������ռ2��λ�ã�����ռ1��λ��
	{
		food_1->s_x = (rand() % 52) + 2;//%52��ʾ��0��51�ĺ����귶Χ�����
	}
	food_1->s_y = (rand() % 24) + 1;//ͬ��
	q = head;//q�Ƕ����һ��ȫ��ָ�룬����������������
	while (q->next != NULL)
	{
		if (q->s_x == food_1->s_x && q->s_y == food_1->s_y) //�ж������Ƿ���ʳ���غ�
		{
			delete food_1;//������������ʳ��ʹ��ڵ��ߵ������غϾ�Ҫɾ�����ʳ�����´���һ��ʳ��
			goto loop;
			//creat_food();
		}
		q = q->next;
	}
	for (int i = 0; i < 33; i++)
	{
		if (o[i].x == food_1->s_x && o[i].y == food_1->s_y)
		{
			delete food_1;//���ʳ��͵�ͼ�е��ϰ����غϣ���Ҫɾ��ʳ�����´���ʳ��
			goto loop;
			//creat_food();
		}
	}
	Set_location(food_1->s_x, food_1->s_y);//����ʳ��ɹ���Ҫ��ʳ���ӡ����
	food = food_1;
	if(rand() % 10 <= 2)
	{
		color = 1;
	    Red_color();//��ʳ���ɺ�ɫ
	    cout << "��";//���ʳ��
	}
	else if(rand() % 10 < 5)
	{
		color = 2;
		Cyan_color();//��ʳ������ɫ
		cout << "��";
	}
	else if(rand() % 10 < 8)
	{
		color = 3;
		Blue_color();//��ʳ������ɫ
		cout << "��";
	}
	else
	{
		color = 4;
		Purple_color();//��ʳ������ɫ
		cout << "��";
	}
}
void creatMap()//������ͼ
{
	int i;
	for (i = 0; i<58; i += 2)//��ӡ���±߿�,����������ͬʱ��ӡ
	{
		Set_location(i, 0);
		cout << "��";
		Set_location(i, 26);
		cout << "��";
	}
	Set_location(10, 0);//��ӡ����Խ��
	cout << " ";
	Set_location(50, 26);
	cout << " ";
	for (i = 1; i<26; i++)//��ӡ���ұ߿�����ͬʱ��ӡ
	{
		Set_location(0, i);
		cout << "��";
		Set_location(56, i);
		cout << "��";
	}
	Set_location(0, 20);
	cout << " ";
	Set_location(56, 6);
	cout << " ";
	Creat_obs(o, 33);//��ӡ�ϰ���
}

void pause()//��ͣ�����������¿ո񣬱�ʾҪ��ͣ��Ϸ
{
	while (1)
	{
		Sleep(300);//��ʱ������1000��ʾ��ʱ1s����������ʱ0.3s
		if (GetAsyncKeyState(VK_SPACE))//VK��ʾ���̰�����Ϊ����_����ʾ����һ�������������ж��ǿո񰴼�
			break;                   //�����ж����������SPACE ��Ҫ��ֹ��Ϸ  async�첽�ģ�ͬ���첽�ĸ���ͬѧ�ǻ��ڴ��ʱѧ����
	}
}
void Start()//��ʼ��Ϸ
{
	system("mode con cols=100 lines=30");//�������п�Ĵ�С��������Լ������
	//White_color();
	int i;
	for (i = 33; i<60; i += 2)//��ӡ���±߿�,����������ͬʱ��ӡ������ͬʱ��ӡ
	{
		Set_location(i, 10);
		cout << "��";
		Set_location(i, 14);
		cout << "��";
	}
	for (i = 10; i<15; i++)//��ӡ���ұ߿�
	{
		Set_location(33, i);
		cout << "��";
		Set_location(61, i); 
		cout << "��";
	}
	Set_location(36, 12);
	cout << "Colorful Greedy Snake@_@" << endl;
	system("pause");//�ǻ���ͣ���ڵ�ǰ
	system("cls");//����
	Set_location(30, 12);
	cout << "�á�.��.��.���ֱ�����ߵ��ƶ�" << endl;
	Set_location(30, 13);
	cout << "��Ϸ����ʱ�������̰���߿��Դ�Խͼ���ϰ��ﲻ����ײ��"<<endl;
	Set_location(30,14);
	cout << "��ͷ���Ҳ࣬��Ϸ��ʼʱ�����߻�ҧ���Լ���" << endl;
	system("pause");
	system("cls");
	Set_location(22,8);
	cout << "��Ϸ˵����" << endl;
	Set_location(22,9);
	cout << "1.�Ե�������ɫ��ʳ�̰���߾ͻ���������ɫ" << endl;
	Set_location(22,10);
	cout << "2.�Ե���ɫʳ�����٣�����״̬��ÿ��ʳ��3��" << endl;
	Set_location(22,11);
	cout << "3.�Ե���ɫʳ�����٣�����״̬��ÿ��ʳ��1��" << endl;
	Set_location(22,12);
	cout << "4.̰���߳�ʼ״̬Ϊ��ɫ��������Խ�ź�̰���߱����ɫ" << endl;
	Set_location(22,13);
	cout << "5.����Ϸ��������15�ֺ󣬳Ե���ɫʳ��̰���߽�����������" << endl;
	Set_location(22,14);
	cout << "6.����Ϸ��������15�ֺ󣬳Ե���ɫʳ��̰���߽���һֱ����ֱ���Ե���һ��ʳ��" << endl;
	Set_location(22,15);
	cout << "7.��Ϸ��5��Ϊһ���ؿ�����ͬ�ؿ���̰�����ٶȻ��𽥼ӿ죨������Ϊ�ٶ����ޣ�" << endl;
	Set_location(22,16);
	cout << "8.���Ĺغ���ͨ�ٶ��´�����Խ�ţ��Ե��ĵ�һ��ʳ��Ϊ4��" << endl;
	Set_location(22,17);
	cout << "9.����غ����״̬�´�����Խ�ţ��Ե��ĵ�һ��ʳ��Ϊ5��" << endl;
	system("pause");
	system("cls");
	creatMap();
	Initial();
	creat_food();
}
void Playing()//������Ϸ��
{
	Set_location(74,5);
	Cyan_color();
	cout << "��һ��" << endl;
	Set_location(64, 15);
	Yellow_color();
	cout << "���ܴ�ǽ������ҧ���Լ�" << endl;
	Set_location(64, 16);
	Yellow_color();
	cout << "�á�.��.��.���ֱ�����ߵ��ƶ�" << endl;
	Set_location(64, 17);
	Yellow_color();
	cout << "̰���߿��Դ�Խ������ϰ��ﲻ����ײ��"<<endl;
    Set_location(64,18);
	Yellow_color();
	cout << "��Ϸ��ʼʱ�����߻�ҧ���Լ���" << endl;
	Set_location(64,19);
	Yellow_color();
	cout << "������Խ��̰���߱����ɫ" << endl;
	Set_location(64, 20);
	Yellow_color();
	cout << "ESC ���˳���Ϸ.space����ͣ��Ϸ" ;
	while (1)//
	{
		Set_location(64, 10);
		Yellow_color();
		cout << "Score=" << score;
		Set_location(64,11);
		Yellow_color();
		cout << "��ͨʳ��2��" << endl;
		Set_location(64,12);
		Yellow_color();
		cout << "����״̬��ÿ��ʳ��3��" << endl;
		Set_location(64,13);
		Yellow_color();
		cout << "����״̬��ÿ��ʳ��1��" << endl;
		if (GetAsyncKeyState(VK_UP) && condition != DOWN)//�жϰ���״̬����
			condition = UP;
		else if (GetAsyncKeyState(VK_DOWN) && condition != UP)
			condition = DOWN;
		else if (GetAsyncKeyState(VK_LEFT) && condition != RIGHT)
			condition = LEFT;
		else if (GetAsyncKeyState(VK_RIGHT) && condition != LEFT)
			condition = RIGHT;
		else if (GetAsyncKeyState(VK_SPACE))
			pause();
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			end_condition = 3;
			break;
		}
		Set_location(74,5);
	    Cyan_color();
	    if(score <= 5)
		    cout << "��һ��" << endl;
	    else if(score <= 10)
		    cout << "�ڶ���" << endl;
    	else if(score <= 15)
		    cout << "������" << endl;
	    else if(score <= 20)
		    cout << "���Ĺ�" << endl;
		else if(score <= 25)
			cout << "�����" << endl;
		else
			cout << "���޹ؿ�..." << endl;
		if(change_color == 1)
		{
			speed = 0;
			if(score <=5)//��������ͬ�������ٶȲ�ͬ
				Sleep(225);
			else if(score <= 10)
				Sleep(200);
			else if(score <= 15)
				Sleep(175);
			else
				Sleep(150);
		}
		else if(change_color == 2)//�����ɫ�����
		{
			speed = 1;
			if(score <=5)//��������ͬ�������ٶȲ�ͬ
				Sleep(200);
			else if(score <= 10)
				Sleep(175);
			else if(score <= 15)
				Sleep(150);
			else
				Sleep(125);
		}
		else if(change_color == 3)//�����ɫ�����
		{
			speed = 2;
			if(score <=5)//��������ͬ�������ٶȲ�ͬ
				Sleep(250);
			else if(score <= 10)
				Sleep(225);
			else if(score <= 15)
				Sleep(200);
			else
				Sleep(175);
		}
		else if(change_color == 4)
		{
			speed = 0;
			if(score <=5)//��������ͬ�������ٶȲ�ͬ
				Sleep(225);
			else if(score <= 10)
				Sleep(200);
			else if(score <= 15)
				Sleep(175);
			else
				Sleep(150);
		}
		else if(change_color == 0)
		{
			speed = 0;
			if(score <=5)//��������ͬ�������ٶȲ�ͬ
				Sleep(225);
			else if(score <= 10)
				Sleep(200);
			else if(score <= 15)
				Sleep(175);
			else
				Sleep(150);
		}
		head->Move();
	}
}

void Die()//��Ϸ����
{
	system("cls");
	Set_location(30, 12);
	if (end_condition == 1)//��ͬ����ᵼ����Ϸ����ʱ��ʵ�����ֲ�ͬ
	{
		Yellow_color();
		cout << "ײǽ��������������";
	}
	else if (end_condition == 2)
	{
		Yellow_color();
		cout << "��Ȼҧ���Լ���������";
	}

	else if (end_condition == 3)
	{
		Yellow_color();
		cout << "���Լ���������Ϸ������";
	}
	else if (end_condition == 4)
	{
		Yellow_color();
		cout << "��ײ�����ϰ��������";
	}
	Set_location(30, 13);
	Yellow_color();
	cout << "�÷֣�" << score << endl;
	system("pause");
    exit(0);
    //Start();
}