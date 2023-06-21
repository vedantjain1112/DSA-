#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int getLength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int getMid(Node *&head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        Node *slow = head;
        Node *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
}

int maxElement(Node *&head)
{
    if (head == NULL)
    {
        return 0;
    }

    Node *temp = head;
    int maxi = temp->data;
    while (temp != NULL)
    {
        if (temp->data > maxi)
        {
            maxi = temp->data;
        }
        temp = temp->next;
    }
    return maxi;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = tail->next;
    }
}

void insertAtposition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *nodeToinsert = new Node(data);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}

void deleteFromHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Cannot Delete.";
    }
    else
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

void deleteFromTail(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Cannot Delete.";
        return;
    }

    if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    delete tail;
    temp->next = NULL;
    tail = temp;

    if (temp == NULL)
    {
        tail = NULL;
    }
}

void deleteFromPosition(Node *&head, Node *&tail, int position)
{
    if (position < 1 || position > getLength(head))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (position == 1)
    {
        deleteFromHead(head, tail);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1 && temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Cannot delete." << endl;
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    if (nodeToDelete == tail)
    {
        tail = temp;
    }

    delete nodeToDelete;
}

bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    Node *slow = head;
    Node *fast = head->next;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow == fast)
    {
        return true;
    }
    return false;
}

Node *reverseLinkedList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nextNode = NULL;

    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

bool isIdentical(Node *&head1, Node *&head2)
{
    if (head1 == NULL && head2 == NULL)
    {
        return true;
    }

    if ((head1 != NULL || head2 == NULL) && (head1 == NULL || head2 != NULL))
    {
        return false;
    }

    else
    {
        Node *temp1 = head1;
        Node *temp2 = head2;

        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data != temp2->data)
            {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
}

bool palindrome(Node *&head)
{
    Node *reversedHead = reverseLinkedList(head);
    Node *temp1 = head;
    Node *temp2 = reversedHead;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            reverseLinkedList(reversedHead);
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    reverseLinkedList(reversedHead);
    return true;
}

void isCircular(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is not Circular.";
        return;
    }

    Node *temp = head;
    while (temp->next != NULL && temp->next != head)
    {
        temp = temp->next;
    }

    if (temp->next == head)
    {
        cout << "Linked List is Circular.";
    }
    else
    {
        cout << "Linked List is not Circular.";
    }
}

void print0_1_2(Node *&head)
{
    Node *temp = head;
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else if (temp->data == 2)
        {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }

    cout << "After sorting linked list of 0's 1's and 2's, the Linked List : " << endl;
    Node *tempo = head;
    while (tempo != NULL)
    {
        cout << tempo->data << " → ";
        tempo = tempo->next;
    }
    cout << "NULL";
}

void sortLinkedList(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is empty.";
        return;
    }

    bool isSwapped = true;
    while (isSwapped)
    {
        isSwapped = false;
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->data > temp->next->data)
            {
                swap(temp->data, temp->next->data);
                isSwapped = true;
            }
            temp = temp->next;
        }
    }

    cout << "After sorting, the linked list is: ";
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL";
    cout << endl;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " → ";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << endl;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        insertAtTail(head, tail, data);
    }
    cout << endl
         << endl;
    cout << "Linked List is: ";
    printLinkedList(head);
    cout << endl
         << endl;

    int pos;
    cout << "Enter the position from where you want to delete the data : ";
    cin >> pos;

    cout << endl
         << endl;

    sortLinkedList(head);
    cout << endl
         << endl;

    cout << "Reversed Linked List is: ";
    head = reverseLinkedList(head);
    printLinkedList(head);
    cout << endl
         << endl;

    int length = getLength(head);
    cout << "Length of the Linked List is: " << length << endl
         << endl;

    int midElement = getMid(head);
    cout << "Middle element of the Linked List is : " << midElement;
    cout << endl
         << endl;

    int maximum = maxElement(head);
    cout << "Maximum element in the linked list is: " << maximum << endl
         << endl;

    cout << endl;

    int distinctCount = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data >= 0 && temp->data <= 2)
        {
            distinctCount++;
        }
        temp = temp->next;
    }

    if (distinctCount == getLength(head))
    {
        print0_1_2(head);
    }
    else
    {
        cout << "Linked List does not contain only 0s, 1s, and 2s." << endl;
    }

    cout << endl
         << endl;

    deleteFromHead(head, tail);
    cout << "Linked List after deleting head: ";
    printLinkedList(head);
    cout << endl
         << endl;

    cout << "Afer deleting data from position " << pos << " the linked list is : ";
    cout << endl;
    deleteFromPosition(head, tail, pos);
    printLinkedList(head);

    cout << endl
         << endl;

    isCircular(head);
    cout << endl
         << endl;

    bool ans = detectLoop(head);
    if (ans)
    {
        cout << "Loop is present in the linked list!" << endl;
    }
    else
    {
        cout << "Loop is not present in the linked list!" << endl;
    }

    cout << endl
         << endl;
    return 0;
};
