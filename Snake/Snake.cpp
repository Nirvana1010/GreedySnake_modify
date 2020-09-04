/**
̰�������Ա����ʵ��
���ߣ�luye@nankai.edu.cn
���ڣ�2018��3��5��
*/

#pragma once
#include"Function.h"

int Snake::Get_x()
{
	return s_x;
}

int Snake::Get_y()
{
	return s_y;
}

Snake *Snake::Get_next()
{
	return next;
}

bool Snake::Bite_self()//����Ƿ�ҧ���Լ�,���Ǽ��ͷ�ڵ��Ƿ������������κ�һ���ڵ�����
{
	Snake *self;//���������߼���Ƿ�ҧ���Լ���ָ��
				//�Ѿ�����һ��q����ָ�룬��q��һ��ȫ��ָ�룬������ɻ��ң����Կ��Զ���һ���ֲ���selfָ�룬ͬѧ��Ҳ���԰����Լ��ķ�ʽ����

	self = head->Get_next();//self����ͷ����һ���ڵ����
	while (self->Get_next() != NULL)//��û�б��������һ���ڵ�ʱ
	{
		if (self->Get_x() == head->Get_x() && self->Get_y() == head->Get_y())//���self��ָ���x��y����������ͷ��x��y��ȣ�˵��ҧ���Լ���
			return 1;//ҧ����
		self = self->Get_next();//self����һ���ڵ�
	}
	return 0;//ûҧ��
}

void Snake::Can_not_crowall()//������ǽ��ײ
{
	for (int i = 0; i < 33; i++)//���for�Ǳ��������ϰ���������Ƿ�ײ���ϰ���
	{
		if (head->s_x == o[i].x && head->s_y == o[i].y)
		{
			end_condition = 4;//�����end_condition�ǽ�������ı�־
			Die();
		}
	}
	if ((head->s_x == 0 && head->s_y != 20) || (head->s_x == 56 && head->s_y != 6) || (head->s_y == 0 && head->s_x != 10) || (head->s_y == 26 && head->s_x != 50))//����Ĳ���������Ϊ���ĸ����Ǵ�������ľ������꣬���ǿ���������
	{
		end_condition = 1;//�����end_condition�ǽ�������ı�־�����ݽ��������ֵ��
		Die();           //������Ӧ����Ľ�������

	}

}

void Snake::Move()//���ƶ��ĺ���
{
	Snake *nexthead;//����next_head������ߵ��ƶ�
	nexthead = new Snake;//next_head����������ƶ�����һ��λ�õĽڵ�
	head->Can_not_crowall();//Ҫ���ж�һ���Ƿ�ײǽ����Ϊ���ײǽ�Ͳ���move��

	if (condition == UP)//�ϵ����
	{
		//White_color();
		//Creat_obs(o,33);
		nexthead->s_x = head->s_x;//����ͷ�Ƶ�nexthead����ʵ���ǽ���ͷ�ĺ������긽��nexthead
		nexthead->s_y = head->s_y - 1;//����Ҫ˵���ߵ��˶�����
		if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 1)//Ҫ�˶�����һ��λ���к�ɫ��ʳ��
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 1;//�Ե�ʳ����ɫ
			nexthead->next = head;//����һ���µģ���Ҫ�˶����Ľڵ������е�ͷ�ڵ�����
			head = nexthead;//head������ǰ���ﵽhead��Զָ��ͷ��Ŀ��
			q = head;//����ȫ���qָ�����ڴ�head����
			if(score > 15)//�ɼ�����15��ʱ���Ե���ɫʳ���̰���߽�����������
			{
				while (q->next->next->next->next != NULL)
			    {              
				    Set_location(q->s_x, q->s_y);
				    Red_color();
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->next->next->s_x, q->next->next->s_y);
			    cout << " ";
			    Set_location(q->next->s_x, q->next->s_y);
			    cout << " ";
			    Set_location(q->s_x, q->s_y);
			    cout << " ";
			    delete q->next->next->next;
			    delete q->next->next;
			    delete q->next;
			    q->next = NULL;
			}
			else
			{
                while (q = NULL)//���Ǽٶ���ԭ���ǣ����ƶ���ˢ��Ȼ�����´�ӡ����������ʵͬѧ�ǿ�����ʵ��ʱ���ý���β�ڵ��޳���Ȼ���ټӵ��˶��������ͷλ�õķ�ʽ��
			    {              
				    Set_location(q->s_x, q->s_y);
				    Red_color();
				    cout << "��";
				    q = q->next;
			    }
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		else if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 2)//Ҫ�˶�����һ��λ������ɫ��ʳ��
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 2;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{              
				Set_location(q->s_x, q->s_y);
				Cyan_color();
				cout << "��";
				q = q->next;
			}
			score += add;
			creat_food();
		}
		else if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 3)//Ҫ�˶�����һ��λ������ɫ��ʳ��
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 3;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{              
				Set_location(q->s_x, q->s_y);
				Blue_color();
				cout << "��";
				q = q->next;
			}
			score += add;
			creat_food();
		}
		else if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 4)//Ҫ�˶�����һ��λ������ɫ��ʳ��
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 4;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{              
				Set_location(q->s_x, q->s_y);
				Purple_color();
				cout << "��";
				q = q->next;
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		else//��һ��λ��û��ʳ��
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			if(change_color == 1)//�Ե���ɫʳ���ɺ�ɫ
			{
			    while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_y < 0)//��ǽʵ�֣����Ǽ򵥵�����任�������ͷ��y����С��0��Ҳ�����ڵ�ͼ�����Ϸ�����ô�ͽ�������任
				    {
						change_color = 0;
					    q->s_y += 27;//�����x��y���任������Ϊ����ڲ����Ƕ���ģ����Ի���x��Ҳ�б仯
					    q->s_x += 40;//����Ϊʲô��27��40�Ǹ��ݴ�����趨λ��������������������Ҫͬѧ�Ǹ����Լ�����Ļ��С�����㡣
				    }
				    Set_location(q->s_x, q->s_y);
				    Red_color();//��ɺ�ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);//��λ�����һ���ڵ��λ��
			    cout <<" ";//�������ƶ��ˣ�������ʾ�����ľ�Ӧ����û���ߵ����壬�������һ���ո�
			    delete q->next;//�ߵ��ƶ��½�����һ���ڵ㣬����û�гԵ���ʵ�����������߶���һ���ڵ㣬����Ҫ������Ǹ��ڵ��ͷ�
			    q->next = NULL;
			}
			else if(change_color == 2)//�Ե���ɫʳ�������ɫ
			{
				while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_y < 0)
				    {
						change_color = 0;
					    q->s_y += 27;
					    q->s_x += 40;
				    }
				    Set_location(q->s_x, q->s_y);
				    Cyan_color();//�����ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);
			    cout <<" ";
				delete q->next;
			    q->next = NULL;
			}
			else if(change_color == 3)//�Ե���ɫʳ�������ɫ
			{
				while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_y < 0)
				    {
						change_color = 0;
					    q->s_y += 27;
					    q->s_x += 40;
				    }
				    Set_location(q->s_x, q->s_y);
				    Blue_color();//�����ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);
			    cout <<" ";
			    delete q->next;
			    q->next = NULL;
			}
			else if(change_color == 4)//�Ե���ɫʳ�������ɫ
			{
				if(score > 15)//��������15ʱ���Ե���ɫʳ��̰�����쳤����
				{
				    while (q->next != NULL)//���ߴ�ӡһ��
			        {
				        if (q->s_y < 0)
				        {
						    change_color = 0;
					        q->s_y += 27;
					        q->s_x += 40;
				        }
				        Set_location(q->s_x, q->s_y);
				        Purple_color();//�����ɫ
				        cout << "��";
				        q = q->next;
			        }
			        Set_location(q->s_x, q->s_y);
			        cout <<" ";
			    }
				else
				{
					while (q->next->next != NULL)//���ߴ�ӡһ��
			        {
				        if (q->s_y < 0)
				        {
						    change_color = 0;
					        q->s_y += 27;
					        q->s_x += 40;
				        }
				        Set_location(q->s_x, q->s_y);
				        Purple_color();//�����ɫ
				        cout << "��";
				        q = q->next;
			        }
			        Set_location(q->s_x, q->s_y);
			        cout <<" ";
			        delete q->next;
			        q->next = NULL;
			    }
			}
			else if(change_color == 0)//û�гԵ�ʳ��ʱΪ��ɫ
			{
				while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_y < 0)
				    {
					    q->s_y += 27;
					    q->s_x += 40;
				    }
				    Set_location(q->s_x, q->s_y);
				    Green_color();//��Ȼ����ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);
			    cout <<" ";
			    delete q->next;
			    q->next = NULL;
			}
		}
	}

	//����������������������������ԭ����ȫ��ͬ
	if (condition == DOWN)//�� ���
	{
		//White_color();
		//Creat_obs(o,33);
		nexthead->s_x = head->s_x;
		nexthead->s_y = head->s_y + 1;
		if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 1)
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 1;
			nexthead->next = head;
			head = nexthead;
			q = head;
			if(score > 15)//�ɼ�����15��ʱ���Ե���ɫʳ���̰���߽�����������
			{
				while (q->next->next->next->next != NULL)
			    {              
				    Set_location(q->s_x, q->s_y);
				    Red_color();
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->next->next->s_x, q->next->next->s_y);
			    cout << " ";
			    Set_location(q->next->s_x, q->next->s_y);
			    cout << " ";
			    Set_location(q->s_x, q->s_y);
			    cout << " ";
			    delete q->next->next->next;
			    delete q->next->next;
			    delete q->next;
			    q->next = NULL;
			}
			else
			{
                while (q = NULL)//���Ǽٶ���ԭ���ǣ����ƶ���ˢ��Ȼ�����´�ӡ����������ʵͬѧ�ǿ�����ʵ��ʱ���ý���β�ڵ��޳���Ȼ���ټӵ��˶��������ͷλ�õķ�ʽ��
			    {              
				    Set_location(q->s_x, q->s_y);
				    Red_color();
				    cout << "��";
				    q = q->next;
			    }
			}
			score += add;
			creat_food();
		}
		else if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 2)//Ҫ�˶�����һ��λ������ɫ��ʳ��
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 2;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{              
				Set_location(q->s_x, q->s_y);
				Cyan_color();
				cout << "��";
				q = q->next;
			}
			score += add;
			creat_food();
		}
		else if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 3)//Ҫ�˶�����һ��λ������ɫ��ʳ��
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 3;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{              
				Set_location(q->s_x, q->s_y);
				Blue_color();
				cout << "��";
				q = q->next;
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		else if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 4)//Ҫ�˶�����һ��λ������ɫ��ʳ��
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 4;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{              
				Set_location(q->s_x, q->s_y);
				Purple_color();
				cout << "��";
				q = q->next;
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		else//��һ��λ��û��ʳ��
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			if(change_color == 1)
			{
			    while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_y > 26)//��ǽʵ�֣����Ǽ򵥵�����任�������ͷ��y����С��0��Ҳ�����ڵ�ͼ�����Ϸ�����ô�ͽ�������任
				    {
						change_color = 0;
					    q->s_y -= 27;//�����x��y���任������Ϊ����ڲ����Ƕ���ģ����Ի���x��Ҳ�б仯
					    q->s_x -= 40;//����Ϊʲô��27��40�Ǹ��ݴ�����趨λ��������������������Ҫͬѧ�Ǹ����Լ�����Ļ��С�����㡣
				    }
				    Set_location(q->s_x, q->s_y);
				    Red_color();//��ɺ�ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);//��λ�����һ���ڵ��λ��
			    cout <<" ";//�������ƶ��ˣ�������ʾ�����ľ�Ӧ����û���ߵ����壬�������һ���ո�
			    delete q->next;//�ߵ��ƶ��½�����һ���ڵ㣬����û�гԵ���ʵ�����������߶���һ���ڵ㣬����Ҫ������Ǹ��ڵ��ͷ�
			    q->next = NULL;
			}
			else if(change_color == 2)
			{
				while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_y > 26)
				    {
						change_color = 0;
					    q->s_y -= 27;
					    q->s_x -= 40;
				    }
				    Set_location(q->s_x, q->s_y);
				    Cyan_color();//�����ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);
			    cout <<" ";
			    delete q->next;
			    q->next = NULL;
			}
			else if(change_color == 3)
			{
				while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_y > 26)
				    {
						change_color = 0;
					    q->s_y -= 27;
					    q->s_x -= 40;
				    }
				    Set_location(q->s_x, q->s_y);
				    Blue_color();//�����ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);
			    cout <<" ";
			    delete q->next;
			    q->next = NULL;
			}
			else if(change_color == 4)
			{
				if(score > 15)//��������15ʱ���Ե���ɫʳ��̰�����쳤����
				{
				    while (q->next != NULL)//���ߴ�ӡһ��
			        {
				        if (q->s_y < 0)
				        {
						    change_color = 0;
					        q->s_y -= 27;
					        q->s_x -= 40;
				        }
				        Set_location(q->s_x, q->s_y);
				        Purple_color();//�����ɫ
				        cout << "��";
				        q = q->next;
			        }
			        Set_location(q->s_x, q->s_y);
			        cout <<" ";
			    }
				else
				{
					while (q->next->next != NULL)//���ߴ�ӡһ��
			        {
				        if (q->s_y < 0)
				        {
						    change_color = 0;
					        q->s_y -= 27;
					        q->s_x -= 40;
				        }
				        Set_location(q->s_x, q->s_y);
				        Purple_color();//�����ɫ
				        cout << "��";
				        q = q->next;
			        }
			        Set_location(q->s_x, q->s_y);
			        cout <<" ";
			        delete q->next;
			        q->next = NULL;
			    }
			}
			else if(change_color == 0)
			{
				while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_y > 26)
				    {
					    q->s_y -= 27;
					    q->s_x -= 40;
				    }
				    Set_location(q->s_x, q->s_y);
				    Green_color();//��Ȼ����ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);
			    cout <<" ";
			    delete q->next;
			    q->next = NULL;
			}
		}
	}
	if (condition == LEFT)//�����
	{
		//White_color();
		//Creat_obs(o,33);
		nexthead->s_x = head->s_x - 2;
		nexthead->s_y = head->s_y;
		if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 1)
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 1;
			nexthead->next = head;
			head = nexthead;
			q = head;
			if(score > 15)//�ɼ�����15��ʱ���Ե���ɫʳ���̰���߽�����������
			{
				while (q->next->next->next->next != NULL)
			    {              
				    Set_location(q->s_x, q->s_y);
				    Red_color();
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->next->next->s_x, q->next->next->s_y);
			    cout << " ";
			    Set_location(q->next->s_x, q->next->s_y);
			    cout << " ";
			    Set_location(q->s_x, q->s_y);
			    cout << " ";
			    delete q->next->next->next;
			    delete q->next->next;
			    delete q->next;
			    q->next = NULL;
			}
			else
			{
                while (q = NULL)//���Ǽٶ���ԭ���ǣ����ƶ���ˢ��Ȼ�����´�ӡ����������ʵͬѧ�ǿ�����ʵ��ʱ���ý���β�ڵ��޳���Ȼ���ټӵ��˶��������ͷλ�õķ�ʽ��
			    {              
				    Set_location(q->s_x, q->s_y);
				    Red_color();
				    cout << "��";
				    q = q->next;
			    }
			}
			score += add;
			creat_food();
		}
		else if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 2)//Ҫ�˶�����һ��λ������ɫ��ʳ��
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 2;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{              
				Set_location(q->s_x, q->s_y);
				Cyan_color();
				cout << "��";
				q = q->next;
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		else if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 3)//Ҫ�˶�����һ��λ������ɫ��ʳ��
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 3;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{              
				Set_location(q->s_x, q->s_y);
				Blue_color();
				cout << "��";
				q = q->next;
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		else if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 4)//Ҫ�˶�����һ��λ������ɫ��ʳ��
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 4;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{              
				Set_location(q->s_x, q->s_y);
				Purple_color();
				cout << "��";
				q = q->next;
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			if(change_color == 1)
			{
			    while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_x < 0)//��ǽʵ�֣����Ǽ򵥵�����任�������ͷ��y����С��0��Ҳ�����ڵ�ͼ�����Ϸ�����ô�ͽ�������任
				    {
						change_color = 0;
					    q->s_x += 58;//�����x��y���任������Ϊ����ڲ����Ƕ���ģ����Ի���x��Ҳ�б仯
					    q->s_y -= 14;//����Ϊʲô��27��40�Ǹ��ݴ�����趨λ��������������������Ҫͬѧ�Ǹ����Լ�����Ļ��С�����㡣
				    }
				    Set_location(q->s_x, q->s_y);
				    Red_color();//��ɺ�ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);//��λ�����һ���ڵ��λ��
			    cout <<" ";//�������ƶ��ˣ�������ʾ�����ľ�Ӧ����û���ߵ����壬�������һ���ո�
			    delete q->next;//�ߵ��ƶ��½�����һ���ڵ㣬����û�гԵ���ʵ�����������߶���һ���ڵ㣬����Ҫ������Ǹ��ڵ��ͷ�
			    q->next = NULL;
			}
			else if(change_color == 2)
			{
				while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_x < 0)
				    {
						change_color = 0;
					    q->s_x += 58;
					    q->s_y -= 14;
				    }
				    Set_location(q->s_x, q->s_y);
				    Cyan_color();//�����ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);
			    cout <<" ";
			    delete q->next;
			    q->next = NULL;
			}
			else if(change_color == 3)
			{
				while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_x < 0)
				    {
						change_color = 0;
					    q->s_x += 58;
					    q->s_y -= 14;
				    }
				    Set_location(q->s_x, q->s_y);
				    Blue_color();//�����ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);
			    cout <<" ";
			    delete q->next;
			    q->next = NULL;
			}
			else if(change_color == 4)
			{
				if(score > 15)//��������15ʱ���Ե���ɫʳ��̰�����쳤����
				{
				    while (q->next != NULL)//���ߴ�ӡһ��
			        {
				        if (q->s_y < 0)
				        {
						    change_color = 0;
					        q->s_x += 58;
					        q->s_y -= 14;
				        }
				        Set_location(q->s_x, q->s_y);
				        Purple_color();//�����ɫ
				        cout << "��";
				        q = q->next;
			        }
			        Set_location(q->s_x, q->s_y);
			        cout <<" ";
			    }
				else
				{
					while (q->next->next != NULL)//���ߴ�ӡһ��
			        {
				        if (q->s_y < 0)
				        {
						    change_color = 0;
					        q->s_y -= 14;
					        q->s_x += 58;
				        }
				        Set_location(q->s_x, q->s_y);
				        Purple_color();//�����ɫ
				        cout << "��";
				        q = q->next;
			        }
			        Set_location(q->s_x, q->s_y);
			        cout <<" ";
			        delete q->next;
			        q->next = NULL;
			    }
			}
			else if(change_color == 0)
			{
				while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_x < 0)
				    {
					    q->s_x += 58;
					    q->s_y -= 14;
				    }
				    Set_location(q->s_x, q->s_y);
				    Green_color();//��Ȼ����ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);
			    cout <<" ";
			    delete q->next;
			    q->next = NULL;
			}
		}
	}
	if (condition == RIGHT)//�����
	{
		//White_color();
		//Creat_obs(o,33);
		nexthead->s_x = head->s_x + 2;
		nexthead->s_y = head->s_y;
		if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 1)
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 1;
			nexthead->next = head;
			head = nexthead;
			q = head;
			if(score > 15)//�ɼ�����15��ʱ���Ե���ɫʳ���̰���߽�����������
			{
				while (q->next->next->next->next != NULL)
			    {              
				    Set_location(q->s_x, q->s_y);
				    Red_color();
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->next->next->s_x, q->next->next->s_y);
			    cout << " ";
			    Set_location(q->next->s_x, q->next->s_y);
			    cout << " ";
			    Set_location(q->s_x, q->s_y);
			    cout << " ";
			    delete q->next->next->next;
			    delete q->next->next;
			    delete q->next;
			    q->next = NULL;
			}
			else
			{
                while (q = NULL)//���Ǽٶ���ԭ���ǣ����ƶ���ˢ��Ȼ�����´�ӡ����������ʵͬѧ�ǿ�����ʵ��ʱ���ý���β�ڵ��޳���Ȼ���ټӵ��˶��������ͷλ�õķ�ʽ��
			    {              
				    Set_location(q->s_x, q->s_y);
				    Red_color();
				    cout << "��";
				    q = q->next;
			    }
			}
			score += add;
			creat_food();
		}
		else if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 2)//Ҫ�˶�����һ��λ������ɫ��ʳ��
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 2;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{              
				Set_location(q->s_x, q->s_y);
				Cyan_color();
				cout << "��";
				q = q->next;
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		else if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 3)//Ҫ�˶�����һ��λ������ɫ��ʳ��
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 3;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{              
				Set_location(q->s_x, q->s_y);
				Blue_color();
				cout << "��";
				q = q->next;
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		else if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y && color == 4)//Ҫ�˶�����һ��λ������ɫ��ʳ��
		{
			if(speed == 0 && change_color == 0 && score > 15)//15�����ϴ�����Խ�ź�ĵ�һ��ʳ��4��
				add = 4;
		    else if(speed == 0)//��ͬ�ٶ���ʳ��ķ�����ͬ
				add = 2;
			else if(speed == 1 && change_color == 0 && score > 20)//20�������ڼ���״̬�´�����Խ�ŵĵ�һ��ʳ��5��
				add = 5;
			else if(speed == 1)
				add = 3;
			else if(speed == 2)
				add = 1;
			change_color = 4;
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{              
				Set_location(q->s_x, q->s_y);
				Purple_color();
				cout << "��";
				q = q->next;
			}
			score += add;//�Ե�ʳ��ӷ�
			creat_food();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			if(change_color == 1)
			{
			    while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_x > 56)//��ǽʵ�֣����Ǽ򵥵�����任�������ͷ��y����С��0��Ҳ�����ڵ�ͼ�����Ϸ�����ô�ͽ�������任
				    {
						change_color = 0;
					    q->s_x -= 58;//�����x��y���任������Ϊ����ڲ����Ƕ���ģ����Ի���x��Ҳ�б仯
					    q->s_y += 14;//����Ϊʲô��27��40�Ǹ��ݴ�����趨λ��������������������Ҫͬѧ�Ǹ����Լ�����Ļ��С�����㡣
				    }
				    Set_location(q->s_x, q->s_y);
				    Red_color();//��ɺ�ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);//��λ�����һ���ڵ��λ��
			    cout <<" ";//�������ƶ��ˣ�������ʾ�����ľ�Ӧ����û���ߵ����壬�������һ���ո�
			    delete q->next;//�ߵ��ƶ��½�����һ���ڵ㣬����û�гԵ���ʵ�����������߶���һ���ڵ㣬����Ҫ������Ǹ��ڵ��ͷ�
			    q->next = NULL;
			}
			else if(change_color == 2)
			{
				while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_x > 56)
				    {
						change_color = 0;
					    q->s_x -= 58;
					    q->s_y += 14;
				    }
				    Set_location(q->s_x, q->s_y);
				    Cyan_color();//�����ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);
			    cout <<" ";
			    delete q->next;
			    q->next = NULL;
			}
			else if(change_color == 3)
			{
				while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_x > 56)
				    {
						change_color = 0;
					    q->s_x -= 58;
					    q->s_y += 14;
				    }
				    Set_location(q->s_x, q->s_y);
				    Blue_color();//�����ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);
			    cout <<" ";
			    delete q->next;
			    q->next = NULL;
			}
			else if(change_color == 4)
			{
				if(score > 15)//��������15ʱ���Ե���ɫʳ��̰�����쳤����
				{
				    while (q->next != NULL)//���ߴ�ӡһ��
			        {
				        if (q->s_y < 0)
				        {
						    change_color = 0;
					        q->s_y += 14;
					        q->s_x -= 58;
				        }
				        Set_location(q->s_x, q->s_y);
				        Purple_color();//�����ɫ
				        cout << "��";
				        q = q->next;
			        }
			        Set_location(q->s_x, q->s_y);
			        cout <<" ";
			    }
				else
				{
					while (q->next->next != NULL)//���ߴ�ӡһ��
			        {
				        if (q->s_y < 0)
				        {
						    change_color = 0;
					        q->s_y += 14;
					        q->s_x -= 58;
				        }
				        Set_location(q->s_x, q->s_y);
				        Purple_color();//�����ɫ
				        cout << "��";
				        q = q->next;
			        }
			        Set_location(q->s_x, q->s_y);
			        cout <<" ";
			        delete q->next;
			        q->next = NULL;
			    }
			}
			else if(change_color == 0)
			{
				while (q->next->next != NULL)//���ߴ�ӡһ��
			    {
				    if (q->s_x > 56)
				    {
					    q->s_x -= 58;
					    q->s_y += 14;
				    }
				    Set_location(q->s_x, q->s_y);
				    Green_color();//��Ȼ����ɫ
				    cout << "��";
				    q = q->next;
			    }
			    Set_location(q->s_x, q->s_y);
			    cout <<" ";
			    delete q->next;
			    q->next = NULL;
			}
		}
	}
	if (Bite_self())//��ÿ���ƶ���Ҫ������ƶ����Ƿ�ҧ���Լ�,ֻ����move����п���ҧ���Լ����Է��ں����ж�
	{
		end_condition = 2;//���Ҫ���Լ���Ҫ��end_condition������Ӧ���������ֵ
		Die();//ҧ���Լ�����die����
	}
}