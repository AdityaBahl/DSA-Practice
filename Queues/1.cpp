#include <iostream>
using namespace std;
typedef struct queues
{
    int data;
    struct queues *next;
} queue;
queue *root = NULL;
queue *head = NULL;
void enqueue(queue *temp)
{
    if (root == NULL)
    {
        root = temp;
        head = temp;
        return;
    }
    queue *node = root;
    while (node->next != NULL)
        node = node->next;
    node->next = temp;
}
queue *create(int info)
{
    queue *temp = (queue *)malloc(sizeof(queue));
    temp->data = info;
    temp->next = NULL;
    return temp;
}
void display()
{
    queue *temp = root;
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
}
inline void dequeue()
{
    root = root->next;
}
int main()
{
    int info, ch = 1;
    do
    {
        cout << "Enter Value\n";
        cin >> info;
        enqueue(create(info));
        cout << "To exit,press 0\n";
        cin >> ch;
    } while (ch);
    cout << "Before Dequeue:\n";
    display();
    do
    {
        cout << "\nWant to dequeue?(1 for yes,0 for no)\n";
        cin >> ch;
        if (ch)
            dequeue();
    } while (ch);
    cout << "After Dequeue:\n";
    display();
    return 0;
}