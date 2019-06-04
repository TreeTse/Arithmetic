/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,
5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2
,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4
,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/


class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> maxInWindows;
        // 数组大小要大于等于窗口大小，并且窗口大小大于等于1
        if(num.size() >= size && size >= 1){
            deque<int> index;
            for(unsigned int i = 0; i < size; i++){
                // 如果index非空，并且新添加的数字大于等于队列中最小的数字，则删除队列中最小的数字
                while(!index.empty() && num[i] >= num[index.back()]){
                    index.pop_back();
                }
                index.push_back(i);
            }
            for(unsigned int i = size; i < num.size(); i++){
                maxInWindows.push_back(num[index.front()]);
                while(!index.empty() && num[i] >= num[index.back()]){
                    index.pop_back();
                }
                // 控制窗口大小为size
                if(!index.empty() && index.front() <= int(i - size)){
                    index.pop_front();
                }
                index.push_back(i);
            }
            maxInWindows.push_back(num[index.front()]);
        }
        return maxInWindows;
    }
};

