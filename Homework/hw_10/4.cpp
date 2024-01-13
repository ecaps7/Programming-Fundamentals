//用链表判断回文
#include<iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr){}
};

//创建链表
Node* createList(int n)
{
    Node* head = nullptr;
    Node* current = head;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }
    current->next = nullptr;
    return head;
}

//复制链表
Node* copyList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* newHead = new Node(head->value);
    Node* currentNew = newHead;
    Node* currentOld = head->next;

    while (currentOld != nullptr) {
        currentNew->next = new Node(currentOld->value);
        currentOld = currentOld->next;
        currentNew = currentNew->next;
    }

    return newHead;
}

//反转链表
Node* reverseLink(Node* head)
{
    Node* pre = nullptr;
    Node* cur = head;
    Node* nex = nullptr;
    
    while (cur != nullptr)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }//pre 在往回走，cur 在正向遍历
    
    return pre;
}

//判断链表是否回文
bool isPalindrome(Node* list1, Node* list2)
{
    // if (list1 == nullptr || list1->next == nullptr) {
    //     return true;
    // }
    while (list1 != nullptr)
    {
        if (list1->value != list2->value)
        {
            return false;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return true;
}

//输出链表
void output(Node* head)
{
    while (head != nullptr)
    {
        if (head->next == nullptr)
        {
            cout << head->value;
            head = head->next;
        }
        else
        {
            cout << head->value << " ";
            head = head->next;
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    Node* list1 = createList(n);
    Node* list3 = copyList(list1);
    Node* list2 = reverseLink(list1);
    Node* list4 = list2;
    output(list2);
    bool result = isPalindrome(list3, list4);
    cout << (result ? "true" : "false") << endl;
    Node* current = list1;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    return 0;
}