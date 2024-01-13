#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createList(int n)
{
    Node* head = nullptr;
    Node* current = head;
    for (int i = 0; i < n; i++)
    {
        Node* newNode = new Node;
        cin >> newNode->data;
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
    }
    return head;
}

Node* reverseList(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node* cur = head;
    Node* pre = nullptr;
    Node* nex = nullptr;
    while (cur != nullptr)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    return pre;
}

Node* reverse_plus(Node* head, int k)
{
    Node* dummyNode = new Node;
    dummyNode->data = -1;
    dummyNode->next = head;
    head = dummyNode;
    Node* current = head->next;
    Node* prev = head;
    while (current != nullptr)
    {
        if (current->data == k)
        {
            Node* temp = current;
            current = current->next;
            prev->next = current;
            delete temp;
        }
        else
        {
            current = current->next;
            prev = prev->next;
        }
    }
    head = head->next;
    return reverseList(head);
}

void outputList(Node* head)
{
    if (head == nullptr)
    {
        return;
    }
    Node* current = head;
    while (current->next != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << endl;
}

int main()
{
    int n;
    cin >> n;
    Node* nums = createList(n);
    int k;
    cin >> k;
    Node* res = reverse_plus(nums, k);
    outputList(res);

    Node* current = res;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    return 0;
}