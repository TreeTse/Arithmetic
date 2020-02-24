/*
题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取
数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/



//解法：求中位数，可以知道中位数的左边都是小数，右边都是大数，中位数左边可以用大顶堆来存储，右边可以用小顶堆
//来存储。在添加数的过程中，需要动态进行调整，使得大顶堆和小顶堆中的数量平衡。
//往堆中插入一个数据的时间复杂度为O(logn)，得到堆顶的数据的时间复杂度为O(1)


class Solution {
public:
    priority_queue<int, vector<int>, greater<int> > gdata;
    priority_queue<int, vector<int>, less<int> > ldata;
    void Insert(int num){
        if(ldata.empty() || num <= ldata.top())
            ldata.push(num);
        else
            gdata.push(num);
        if(gdata.size() + 2 == ldata.size()){
            gdata.push(ldata.top());
            ldata.pop();
        }
        if(gdata.size() == ldata.size() + 1){
            ldata.push(gdata.top());
            gdata.pop();
        }
    }

    double GetMedian(){ 
        return gdata.size() == ldata.size() ? 
            (gdata.top() + ldata.top()) * 0.5 : ldata.top();
    }

};