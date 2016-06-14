struct Lined
{
    int val;
    struct Lined* next_max;
    struct Lined* pre_max;
    struct Lined* next_min;
    struct Lined* pre_min;
};

int *max_min(int* prices, int pricesSize)
{
    struct Lined* str=NULL;
    struct Lined* temp1=NULL;
    struct Lined* temp2=NULL;
    int i=0;
    int pre_min = 1;
    int pre_max = 0;
    for(;i<pricesSize;i++)
    {

        if(i==0)
        {
            if(prices[0]<prices[1])
            {
                temp2 = malloc(sizeof(struct Lined));

                temp2->val = prices[0];
                temp2->pre_max = NULL;
                temp2->pre_min = NULL;
                temp2->next_max = NULL;
                temp2->next_min =NULL;

                str = temp1 = temp2;
            }
        }
        else if(i==pricesSize-1)
        {
            if(prices[pricesSize-1]>prices[pricesSize-2])
            {

                temp2 = malloc(sizeof(struct Lined));

                temp2->val = prices[pricesSize-1];
                temp2->pre_max = temp1->pre_max;
                temp2->pre_min = temp1;
                temp2->next_max = NULL;
                temp2->next_min =NULL;

                temp1->next_max = temp2;

                temp1 = temp2;
            }
        }
        else
        {
            if((prices[i]<prices[i-1])&&(prices[i]<prices[i+1]))
            {
                if(str==NULL)
                {

                    temp2 = malloc(sizeof(struct Lined));

                    temp2->val = prices[i];
                    temp2->pre_max = NULL;
                    temp2->pre_min = NULL;
                    temp2->next_max = NULL;
                    temp2->next_min =NULL;

                    str = temp1 = temp2;
                }
                else
                {
                    temp2 = malloc(sizeof(struct Lined));

                    temp2->val = prices[i];
                    temp2->pre_max = temp1;
                    temp2->pre_min = temp1->next_min;
                    temp2->next_max = NULL;
                    temp2->next_min =NULL;

                    temp1->next_min = temp2;

                    temp1 = temp2;
                }
            }
            else if((prices[i]>prices[i-1])&&(prices[i]>prices[i+1]))
            {
                temp2 = malloc(sizeof(struct Lined));

                temp2->val = prices[i];
                temp2->pre_max = temp1->next_max;
                temp2->pre_min = temp1;
                temp2->next_max = NULL;
                temp2->next_min =NULL;

                temp1->next_max = temp2;

                temp1 = temp2;
            }

            else if((prices[i]<prices[i-1])&&(prices[i]==prices[i+1]))
            {
                pre_min = 1;
                pre_max = 0;
            }
            else if((prices[i]==prices[i-1])&&(prices[i]<prices[i+1]))
            {
                if(pre_min == 1)
                {
                    if(str==NULL)
                    {

                        temp2 = malloc(sizeof(struct Lined));

                        temp2->val = prices[i];
                        temp2->pre_max = NULL;
                        temp2->pre_min = NULL;
                        temp2->next_max = NULL;
                        temp2->next_min =NULL;

                        str = temp1 = temp2;
                    }
                    else
                    {
                        temp2 = malloc(sizeof(struct Lined));

                        temp2->val = prices[i];
                        temp2->pre_max = temp1;
                        temp2->pre_min = temp1->next_min;
                        temp2->next_max = NULL;
                        temp2->next_min =NULL;

                        temp1->next_min = temp2;

                        temp1 = temp2;
                    }
                }
                pre_max = 0;
                pre_min = 0;
            }

            else if((prices[i]>prices[i-1])&&(prices[i]==prices[i+1]))
            {
                pre_max = 1;
                pre_min = 0;
            }

            else if((prices[i]==prices[i-1])&&(prices[i]>prices[i+1]))
            {
                if(pre_max == 1)
                {
                    temp2 = malloc(sizeof(struct Lined));

                    temp2->val = prices[i];
                    temp2->pre_max = temp1->next_max;
                    temp2->pre_min = temp1;
                    temp2->next_max = NULL;
                    temp2->next_min =NULL;

                    temp1->next_max = temp2;

                    temp1 = temp2;
                }
                pre_max = 0;
                pre_min = 0;
            }

            else;
        }
    }

    return str;

}

int maxProfit(int* prices, int pricesSize) {
    int flag = 0;
    int profit = 0;
    int tp_profit = 0;
    int tp_min;
    int tp_max;
    struct Lined* tp_str;

    struct Lined* sstr = max_min(prices,pricesSize);

//    pprt(sstr);

    if(sstr==NULL)
    {
        return 0;
    }

    tp_min = tp_max = sstr->val;
    tp_str = sstr;

    while((tp_str->next_max!=NULL)||(tp_str->next_min!=NULL))
    {
        if(flag)
        {
            if(tp_str->val>tp_max)
            {
                tp_max = tp_str->val;

                tp_profit = tp_max - tp_min;
                if(tp_profit>profit)
                {
                    profit = tp_profit;
                }
                else;
            }
            else;

            tp_str = tp_str->next_min;
            flag = 0;
        }
        else
        {
            if(tp_str->val>=tp_min)
            {
                tp_str = tp_str->next_max;
                flag = 1;
            }
            else
            {
                tp_max = tp_min = tp_str->val;

                tp_str = tp_str->next_max;
                flag = 1;
            }

        }

    }
    if(flag)
    {
        if(tp_str->val>tp_max)
        {
            tp_max = tp_str->val;
            tp_profit = tp_max - tp_min;
            if(tp_profit>profit)
            {
                profit = tp_profit;
            }
            else;
        }
    }

//    printf("%d %d %d\n",tp_min,tp_max,tp_profit);
    return profit;
}