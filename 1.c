/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* ret = malloc(2*sizeof(int));
    int i=0,j=0;
    int temp,flag=0;
    for(;i<numsSize;i++)
    {
        temp = target - nums[i];
        for(j=i+1;j<numsSize;j++)
        {
            if(temp == nums[j])
            {
                ret[0] = i;
                ret[1] = j;
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
    return ret;
}