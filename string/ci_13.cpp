/*
题目描述：
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿
！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可
以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2
和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的
运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。
*/


//解法一：自己原先的解法，可能有点理解错题意，题目是要求抽出的牌数是5张牌。
//不过这种解法可以通过，麻烦点而已


class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int len = numbers.size();
        if(len == 0)
            return false;
        sort(numbers.begin(), numbers.end());
        int zCount = 0;
        bool start = false;
        for(int i = 0; i < len; i++){
            if(numbers[i] == 0){
                zCount++;
                continue;
            }
            if(start == false){
                start = true;
                continue;
            }
            if(numbers[i] - numbers[i - 1] != 1){
                if((numbers[i] - numbers[i - 1] > zCount + 1) || 
                   (numbers[i] - numbers[i - 1] == 0))
                    return false;
                else{
                    zCount = zCount - (numbers[i] - numbers[i - 1] - 1);
                }
            }
        }
        return true;
    }
};


//解法二：所以先将所有非0的数遍历，如果有重复的数或是两数之差>=5，输出false


class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5) return false;
        sort(numbers.begin(),numbers.end());
        int i=0;
        while(numbers[i] == 0) i++;
        for(int j = i; j < numbers.size() - 1; j++){
            if(numbers[j] == numbers[j + 1]) return false;
            if(numbers[j + 1] - numbers[i] >= 5) return false;
        }
        return true;
    }
};