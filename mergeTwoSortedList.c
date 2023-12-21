struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // function to create new node
    struct ListNode* createNode(int data)
    {
        struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
        if(newNode==NULL)
        return NULL;
        newNode->val=data;
        newNode->next=NULL;
        return newNode;
    }
    struct ListNode* dummy = createNode(0);
    struct ListNode* current = dummy;
    while(list1 && list2)
    {
        if(list1->val<=list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current=current->next;
    }
    //if any of the list is not empty
    if(list1)
    current->next = list1;
    if(list2)
    current->next = list2;

    struct ListNode* mergeList=dummy->next;
    free(dummy);
    
   return mergeList;
}