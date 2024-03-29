/*
题目描述
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,
自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个
数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选
礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小
朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋
友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)

如果没有小朋友，请返回-1
*/


//解法：使用list+迭代器实现环形链表，需要注意的是erase的迭代器失效问题。

class Solution {
public:
    int LastRemaining_Solution(int n, int m){
        if(n < 1 || m < 1)
            return -1;
        list<int> child;
        for(int i = 0; i < n; i++){
            child.push_back(i);
        }
        list<int>::iterator it = child.begin();
        while(child.size() > 1){
            for(int i = 1; i < m; i++){
                ++it;
                if(it == child.end())
                    it = child.begin();
            }
            list<int>::iterator next = ++it;
            if(next == child.end())
                next = child.begin();
            --it;
            child.erase(it);
            it = next;
        }
        return *it;
    }
};