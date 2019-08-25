//
// Created by whao on 19-7-1.
//
#include <iostream>
#include <vector>
using namespace std;


// 交换函数
void swap(vector<int> &str, int l, int r)
{
    int temp=str[l];
    str[l]=str[r];
    str[r]=temp;
}

// 维护一个堆
void maxheadify(vector<int> &str, int index, int len)
{
    int li = 2*index+1;       // 左孩子
    int ri = li+1;            // 右孩子
    int max = li;             // 最大值下标， 初始化为左孩子值最大
    if(li>len)
    {
        return;
    }
    if(ri<=len&&str[ri]>str[li])                 // 如果右孩子值比左孩子值大， 交换左右两个孩子
    {
        max = ri;
    }
    if(str[max]>str[index])                    // 如果左孩子或右孩子比根节点值大
    {
        swap(str, max, index);              // 交换两个值
        maxheadify(str, max, len);         //  重新维护下堆
    }
}

void sort(vector<int> &str, int len) {
//    int len = str.size()-1;
    int beginIndex = (len - 1) / 2;                      //从根节点开始
    for (int i = beginIndex; i >= 0; i--) {
        maxheadify(str, i, len);
    }
    // 将根节点不断与最后一个节点交换， 同时长度减一
    for (int i = len; i > 0; i--) {
        swap(str, 0, i);
        maxheadify(str, 0, i - 1);
    }

}
void topk(vector<int> &str, int len, int k)
{
    sort(str, k);
    for(int i=k;i<len;i++)
    {
        if(str[k]<str[0])
        {
            swap(str, 0, k);
            maxheadify(str, 0, k);
        }
    }

}
int main()
{
    vector<int> nums;
    int i=0;
    do{
        cin>>i;
        nums.push_back(i);

    }while(getchar()!='\n');
//    sort(nums, 6, 5);              nums排序
//    topk(nums, 6, 5);               nums数组的topk

    for(int k=0;k<5;k++)
    {
        cout<<nums[k]<<" ";
    }
    cout<<endl;
}