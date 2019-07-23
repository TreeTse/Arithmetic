/*
题目描述：请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为
We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

/*
解法：先统计出空格的个数，并计算出替换之后的字符串的长度。然后从后往前去替换
设置两个指针p1和p2，一个指向原始字符串末尾，一个指向替换后的字符串末尾，移动p1和p2，逐个把p1指向的
字符复制到p2指针的位置
*/

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL && length <= 0)
            return;
        int new_length = 0;   //新的字符串长度
        int count = 0;    //计算空格数
        int i;
        char *p_orign = NULL;    //用来定位到原始字符串末尾的指针
        char *p_new = NULL;       //用来定位到新字符串末尾的指针
        while(str[i++] != '\0'){
            if(str[i] == ' ')
                count++;
        }
        new_length = length + 2*count;    
        p_orign = str + length -1;
        p_new = str + new_length -1;
        while(length >= 0 && p_orign != p_new){
            if(*p_orign == ' '){
                *(p_new--) = '0';
                *(p_new--) = '2';
                *(p_new--) = '%';
            }
            else{
                *(p_new--) = *p_orign;
            }
            p_orign--;
        }
	}
};