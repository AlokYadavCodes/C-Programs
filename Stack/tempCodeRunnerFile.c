int main()
{
    while (1)
    {
        printf("\n 1.Push \n 2.Pop\n 3.Print the top element\n 4.Print all the elements \n 5.Quit\n");
        printf("Enter your choice:");
        int choice,data;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the element to push:");
            scanf("%d",&data);
            push(data);
            break;

            case 2:
            data=pop();
            printf("Deleted element is %d\n",data);
            break;

            case 3:
            printf("Topmost element is %d\n",peek());
            break;

            case 4:
            print();
            break;

            case 5:
            exit(0);

            default:
            printf("Invalid Choice\n");

        }
    }
    
    return 0;
}