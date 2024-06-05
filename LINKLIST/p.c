#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first, *second, *third;
void create(int arr[], int n)
{
    first = (struct node *)malloc(sizeof(struct node));
    struct node *p, *last;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = arr[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}
void create2(int arr[], int n)
{
    second = (struct node *)malloc(sizeof(struct node));
    struct node *p, *last;
    second->data = arr[0];
    second->next = NULL;
    last = second;
    for (int i = 1; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = arr[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}
void merg(struct node *p, struct node *q)
{
    third = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}
int main()
{
    int n;
    printf("Enter size of first linklist:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    create(arr, n);
    int m;
    printf("Enter size of second linklist:");
    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    create2(arr2, m);
    printf("\nfirst link list:\n");
    display(first);
    printf("\nfirst second list:\n");
    display(second);
    merg(first, second);
    printf("\nafter concatating:\n");
    display(third);
}