/*
题目描述：
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压
栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序
列的长度是相等的）
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> m_data;
        vector<int>::iterator iter1,iter2;
        iter2=popV.begin();
        if(pushV.size()==0)
            return false;
        for(iter1=pushV.begin();iter1!=pushV.end();iter1++)
        {
            m_data.push(*iter1);
            while(!m_data.empty()&&m_data.top()==(*iter2))
            {
                m_data.pop();
                iter2++;
            }
        }
        if(m_data.empty())
            return true;
        return false;
    }
};


