/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return NULL;

	int count_days = 0;
	struct node *head1 = date1head;
	struct node *head2 = date2head;
	int flag = 0;
	while (head1->data != NULL)
	{
		if (head1->data != head2->data)
		{
			flag++;
		}
		head1->next = head1;
		head2->next = head2;
	}
	if (flag == 8)
		return 0;

	int d1 = (head1->data * 10) + (head1->next->data);
	int d2 = (head2->data * 10) + (head2->next->data);
	head1 = head1->next->next;
	head2 = head2->next->next;
	int m1 = (head1->data * 10) + (head1->next->data);
	int m2 = (head2->data * 10) + (head2->next->data);
	head1 = head1->next->next;
	head2 = head2->next->next;
	int y1 = (head1->data * 1000) + (head1->next->data * 100) + (head1->next->next->data * 10) + (head1->next->next->next->data);
	int y2 = (head2->data * 1000) + (head2->next->data * 100) + (head2->next->next->data * 10) + (head2->next->next->next->data);

	if (!(m2 >= 1 && m2 <= 12 && m1 >= 1 && m1 <= 12))
	{
		return -1;
	}
	else if (m2 >= 1 && m2 <= 12 && m1 >= 1 && m1 <= 12)
	{
		if (m1 % 2 == 0 && m1 != 2 && !(d1 >= 1 && d1 <= 30))
		{
			return -1;
		}
		if (m2 % 2 == 0 && m2 != 2 && !(d2 >= 1 && d2 <= 30))
		{
			return -1;
		}
		if (m1 == 2 && y1 % 4 == 0 && !(d1 >= 1 && d1 <= 29))
		{
			return -1;
		}
		if (m2 == 2 && y2 % 4 == 0 && !(d2 >= 1 && d2 <= 29))
		{
			return -1;
		}
		if (m1 == 2 && y1 % 4 != 0 && !(d1 >= 1 && d1 <= 28))
		{
			return -1;
		}
		if (m2 == 2 && y2 % 4 != 0 && !(d2 >= 1 && d2 <= 28))
		{
			return -1;
		}
		if (m1 % 2 != 0 && !(d1 >= 1 && d1 <= 31))
		{
			return -1;
		}
		if (m2 % 2 != 0 && !(d2 >= 1 && d2 <= 31))
		{
			return -1;
		}
	}

	if (y1 > y2 && y1 > 0 && y2 > 0)
	{
		for (int i = y2; i < y1; i++)
		{
			if (i % 4 == 0)
			{
				count_days = count_days + 366;
			}
			else
			{
				count_days = count_days + 365;
			}
		}
		if (m1 > m2)
		{
			for (int i = m2; i < m1; i++)
			{
				if (i % 2 == 0)
				{
					count_days = count_days + 30;
				}
				else
				{
					count_days = count_days + 31;
				}
			}
		}
	}

	return count_days;
}