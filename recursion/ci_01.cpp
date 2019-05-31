/*题目描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法(剑指offer)*/
/*采用了递归，但注意如果line 9处判断条件是if(number==1)的话，会导致算法复杂度过高*/  

<<<<<<< HEAD

=======
>>>>>>> refs/remotes/origin/master
class Solution {   
public:   
    int jumpFloor(int number) {  
        if(number<0)  
　　　　    return 0;  
　　     int fib[]={0,1,2};   
　　     if(number<3)  
　　　　    return fib[number];  
　　     return jumpFloor(number-1)+jumpFloor(number-2);  
    }  
};  

  

