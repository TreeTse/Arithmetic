/*
题目描述：请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为
We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/


class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL && length <= 0){
            return;
        }
               /*original_length为字符串str的实际长度*/
        int original_length = 0;            //原始长度
        int number_blank = 0;				//空格数
        int i;
        while(str[i++] != '\0'){				//遍历字符串
            ++original_length;				//长度+1
            if(str[i] == ' '){
                ++number_blank;				//遇到空格+1
            }
        }
        /*new_length为把空格替换成'%20'之后的长度*/
        int new_length = original_length + 2 * number_blank;
        int index_original = original_length;	//原始字符串末尾索引值
        int index_new = new_length;				//计算长度后的字符串末尾索引值
        
        /*index_original指针开始向前移动，如果遇到空格，替换成'%20'，否则进行复制操作*/
        while(index_original >= 0 && index_new > index_original){
            if(str[index_original] == ' '){
                str[index_new--] = '0';
                str[index_new--] = '2';
                str[index_new--] = '%';
            }
            else{
                str[index_new--] = str[index_original];
            }
            --index_original;
        }
	}
};