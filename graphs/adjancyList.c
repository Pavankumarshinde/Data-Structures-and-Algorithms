#include <stdio.h>
#include <stdio.h>
#define n 10

struct link
{
    // int
    int key;
    int next;
};
struct AjList
{
    struct link Arr[n];
};
// void addLink(struct link * node, int x)
// {

// }

int main()
{
    struct AjList *Ad;

    for (int i = 0; i < n; i++)
    {
        // Ad->Arr[i]->key=i;
        Ad->Arr[i].key=i;
    }
    // }
}