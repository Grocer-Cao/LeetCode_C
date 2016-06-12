/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* ans;
    struct ListNode* temp1;
    struct ListNode* temp2;

    temp1 = ans = malloc(sizeof(struct ListNode));
    temp1->next = NULL;
    temp1->val = 0;
    int sum0=0,sum1=0,sum2=0;
    int flag1=1,flag2=1;

    do
    {


        if((l1->next!=NULL)&&(l2->next!=NULL))
        {
            sum0 = l1->val + l2->val + sum2;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if((l1->next==NULL)&&(l2->next!=NULL))
        {
            sum0 = l1->val + l2->val + sum2;
            l1->val = 0;
            l2 = l2->next;

            flag1 = 0;
        }
        else if((l1->next!=NULL)&&(l2->next==NULL))
        {
            sum0 = l1->val + l2->val + sum2;
            l1 = l1->next;
            l2->val = 0;

            flag2 = 0;
        }
        else
        {
            if((sum2!=0)||(flag1!=0)||(flag2!=0))
            {
                sum0 = l1->val + l2->val + sum2;
                l1->val = 0;
                l2->val = 0;

                flag1 = 0;
                flag2 = 0;
            }
            else
            {
                break;
            }
        }


        if(sum0>=10)
        {
            sum1 = sum0%10;
            sum2 = sum0/10;
        }
        else
        {
            sum1 = sum0;
            sum2 = 0;
        }

        temp1->val = sum1;

        if((sum2!=0)||(flag1!=0)||(flag2!=0))
        {
            temp2 = malloc(sizeof(struct ListNode));
            temp2->next = NULL;
            temp2->val = 0;
            temp1->next = temp2;
            temp1 = temp2;
        }


    }
    while(1);

    return ans;
}
