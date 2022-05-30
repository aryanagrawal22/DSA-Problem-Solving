#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} * start;

void insert(int n);
int iterate(struct Node *node, int &n);

int getNthFromLast(struct Node *head, int n)
{
    int answer = iterate(head, n);
    if(answer == 0){
        return -1;
    }
    return answer;
}

int iterate(struct Node *node, int &n)
{
    int ans=0;
    if (node != NULL)
    {
        ans = iterate(node->next, n);
    }

    if (ans)
    {
        return ans;
    }

    if (n == 0)
    {
        return node->data;
    }

    n--;

    return 0;
}

int main()
{

    start = NULL;
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    insert(n);
    int res = getNthFromLast(start, k);
    printf("%d\n", res);

    return 0;
}

void insert(int n)
{
    int value, i;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        if (i == 0)
        {
            start = (struct Node *)malloc(sizeof(struct Node));
            start->data = value;
            start->next = NULL;
            temp = start;
            continue;
        }
        else
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
    }
}