//用链表排序
#include<stdio.h>
#include<iostream>
struct Node
{
	int value;
	Node* next;
};
Node* input(int n)
{
	//Todo: 输入数据并建立链表
    Node* head = nullptr;
    Node* current = head;
    for (int i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        Node* newNode = new Node{val};
        if (head == nullptr)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }
    }
    current->next = nullptr;
    return head;
}

void sort(Node* head)
{
	//Todo: 对链表排序
    if (head == nullptr || head ->next == nullptr)
    {
        return;
    }
    for (Node* cur1 = head; cur1 ->next != nullptr; cur1 = cur1->next)
    {
        Node* cur_max = cur1;
        for (Node* cur2 = cur1->next; cur2 != nullptr; cur2 = cur2->next)
        {
            if (cur2->value > cur_max->value)
            {
                cur_max = cur2;
            }
        }
        if (cur_max != cur1)
        {
            std::swap(cur1->value, cur_max->value);
        }
    }
}

void output(Node* head)
{
	//Todo: 输出链表数据
    for (Node* p = head; p != nullptr; p = p->next)
    {
        std::cout << p->value << " ";
    }
}

void remove(Node* head)
{
    while (head != nullptr)
    {
        Node* p = head;
        head = head->next;
        delete p;
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	Node* pHead = input(n);
	sort(pHead);
	output(pHead);
    remove(pHead);
	return 0;
}