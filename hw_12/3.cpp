#include<iostream>
using namespace std;

struct Node
{
    long long int cost;
    Node* next;
};

Node* createList(int n)
{
    if (n == 0)
    {
        return nullptr;
    }
    Node* head = nullptr;
    Node* current = head;
    for (int i = 0; i < n; i++)
    {
        if (head == nullptr)
        {
            int cost_0;
            cin >> cost_0;
            head = new Node{ cost_0 };
            head->next = nullptr;
            current = head;
        }
        else
        {
            int cost_1;
            cin >> cost_1;
            current->next = new Node{ cost_1 };
            current->next->next = nullptr;
            current = current->next;
        }
    }
    return head;
}

void sortList(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    for (Node* cur1 = head; cur1->next != nullptr; cur1 = cur1->next)
    {
        Node* cur_min = cur1;
        for (Node* cur2 = cur1->next; cur2 != nullptr; cur2 = cur2->next)
        {
            if (cur2->cost < cur_min->cost)
            {
                cur_min = cur2;
            }
        }
        if (cur_min != cur1)
        {
            swap(cur1->cost, cur_min->cost);
        }
    }
}

int findLength(Node* head)
{
    int length = 0;
    Node* current = head;
    while (current->next != nullptr)
    {
        length++;
        current = current->next;
    }
    length++;
    return length;
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

int main() {
    int n;
    cin >> n;
    Node* students = createList(n);
    sortList(students);
    int length = findLength(students);
    Node* current = students;
    long long time = 0;
    while (current->next != nullptr)
    {
        time += length * current->cost;
        length--;
        current = current->next;
    }
    time += current->cost * length;
    cout << time << endl;
    remove(students);
}