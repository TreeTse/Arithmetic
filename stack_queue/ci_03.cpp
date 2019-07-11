/*
题目描述：
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压
栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序
列的长度是相等的）
*/


/*
思路：建立辅助栈，将栈的压入序列压入到辅助栈；
压入的最后一个元素跟弹出序列进行比较，如果辅助栈顶元素与弹出序列相等就弹出；
判断辅助栈元素是否被完全弹出，如果完全弹出就返回true，否则返回false
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> temp;
        vector<int>::iterator it1;
        vector<int>::iterator it2;
        it2 = popV.begin();
        if(pushV.empty()){
            return false;
        }
        for(it1 = pushV.begin(); it1!=pushV.end(); it1++){
            temp.push(*it1);
            while(!temp.empty()&&temp.top() == (*it2)){
                temp.pop();
                it2++;
            }
        }
        if(temp.empty())
            return true;
        else
            return false;
    }
};



