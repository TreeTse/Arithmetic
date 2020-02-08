/*
题目描述：
题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,
他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的
找出所有和为S的连续正数序列? Good Luck!
输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/

//直接穷举


class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > ans;
        for(int i = 1; i <= sum - 2; i++){
            int s = 0;
            int j = i;
            s += j;
            while(s < sum){
                j++;
                s += j;
                if(s == sum){
                    vector<int> tmp;
                    for(int k = i; k <= j; k++)
                        tmp.push_back(k);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};