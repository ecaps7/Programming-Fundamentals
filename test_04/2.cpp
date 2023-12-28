/*任务描述
假定一架飞机沿着与赤道重合的航线 在本初子午线到 180 度经线之间 自西向东飞行，其行驶轨迹的多个采样点（经度）存储在一个单向链表中，采样点数目>2。采样点类型如下：
typedef struct Point Pt;
struct Point 
{
    int lon;    // 0＜lon≤18000
    Pt* next;
};
现在已知存在一个噪声节点，其经度超过所有节点的均值或为0。请你设计C/C++程序去除该噪声节点，使得链表成为一个升序链表。要求实现链表的创建、输出、节点删除、整个链表的撤销和main函数。

输入格式
一行：若干个非负整数（代表原始链表，其中有且只有一个噪声节点），最后还有一个 -1

输出格式
一行：若干个正整数（代表去除噪声节点后的升序链表）

样例1
输入：
11112 11123 11133 0 11153 -1
预期输出：
11112 11123 11133 11153

样例2
输入：
11177 23 33 53 -1
预期输出：
23 33 53*/
#include <iostream>
#include <cstring>
using namespace std;

typedef struct Point Pt;
struct Point 
{
    int lon;    // 0＜lon≤18000
    Pt* next;
};

Pt* createList()
{
    Pt* head = nullptr;
    Pt* current = head;
    int x;
    cin >> x;
    while (x != -1)
    {
        Pt* newNode = new Pt;
        newNode->lon = x;
        newNode->next = nullptr;
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
        cin >> x;
    }
    return head;
}

void sortList(Pt* head)
{
    if (head == nullptr || head ->next == nullptr)
    {
        return;
    }
    for (Pt* cur1 = head; cur1 ->next != nullptr; cur1 = cur1->next)
    {
        Pt* cur_min = cur1;
        for (Pt* cur2 = cur1->next; cur2 != nullptr; cur2 = cur2->next)
        {
            if (cur2->lon < cur_min->lon)
            {
                cur_min = cur2;
            }
        }
        if (cur_min != cur1)
        {
            swap(cur1->lon, cur_min->lon);
        }
    }
}

Pt* deleteList(Pt* head)
{
    Pt* dummyNode = new Pt;
    dummyNode->lon = -1;
    dummyNode->next = head;
    if (head->lon == 0)
    {
        dummyNode->next = head->next;
        delete head;
        return dummyNode->next;
    }
    else
    {
        Pt* pre = dummyNode;
        Pt* cur = head;
        while (cur->next != nullptr)
        {
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
        return dummyNode->next;
    }
}

void outputList(Pt* head)
{
    if (head == nullptr)
    {
        return;
    }
    Pt* current = head;
    while (current != nullptr)
    {
        cout << current->lon << " ";
        current = current->next;
    }
}

int main()
{
    Pt* point = createList();
    sortList(point);
    // outputList(point);
    point = deleteList(point);
    outputList(point);

    Pt* current = point;
    while (point != nullptr)
    {
        Pt *temp = point;
        point = point->next;
        delete temp;
    }
    return 0;
}