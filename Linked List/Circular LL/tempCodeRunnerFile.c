    struct node *temp=(*tail)->link;
    (*tail)->link=(*tail)->link->link;
    free(temp); temp=NULL;
}

void delLast(struct node **tail)
{
    struct node *temp=*tail;
    while(temp->link!=*tail)
    {
        temp=temp->link;
    }
    temp->link=(*tail)->link;
    struct node *temp2=*tail;
    *tail=temp;
    free(temp2); temp2=NULL;
}

int length(struct node *tail)
{
    int count=1;
    if(tail==NULL) return 0;
    struct node *temp=tail->link;
    while(temp!=tail)
    {
        count++;
        temp=temp->link;
    }
    return count;
}

void delNode(struct node **tail,int n)
{
    if(n<1)
    {
        printf("Invalid Input\n");
        return ;
    }
    if(n==1)
    {
        delFirst(*tail);
        return;
    }

}

int main()