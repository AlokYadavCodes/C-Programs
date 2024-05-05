#include <stdio.h>
struct node
{
    int data;
    struct node *link;
};
void fun(struct node *hi)
{
    hi->data=33;
    printf("%d\n",hi->data);
}
int main()
{
    struct node hello,bye;
    hello.data=44;
//  hello->data=44;   this will generate error
    bye.data=22;
    hello.link=&bye;
    printf("%d\n",hello.link->data);
    printf("%d\n",hello.data);
    fun(&hello);
    printf("%d\n",hello.data);
    return 0;
}