/*
题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串
"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14",
"1.2.3","+-5"和"12e+4.3"都不是。
*/




class Solution {
public:
    bool isNumeric(char* str) {
        bool sign = false, point = false, charaE = false;
        for(int i = 0; str[i] != '\0'; i++){
            if(str[i] == 'E' || str[i] == 'e'){
                //此字符不能出现两次
                if(charaE == true) return false;
                //后面不能跟'.'，不能在串尾
                if(str[i + 1] == '.' || str[i + 1] == '\0') return false;
                //前面必须为数字且不是在串首
                if(!isdigit(str[i - 1]) && (i <= 0)) return false;
                charaE = true;
            }
            else if(str[i] == '+' || str[i] == '-'){
                //第二次出现，则必须跟在'E'或'e'后面且不是在串尾
                if(sign && str[i - 1] != 'E' && str[i - 1] != 'e')
                    return false;
                //第一次出现，且不是在串首则必须跟在字符'e'或'E'后面
                if(!sign && i > 0 && str[i - 1] != 'E' && str[i - 1] != 'e')
                    return false;
                sign = true;
            }
            else if(str[i] == '.'){
                //'.'只能出现一次 E后面不能接小数点
                if(point || charaE) return false;
                //只能跟在数字后面，且后面跟数字
                if(!isdigit(str[i + 1])) return false;
                point = true;
            }
            else if(str[i] > '9' || str[i] < '0')
                return false;
        }
        return true;
    }
};