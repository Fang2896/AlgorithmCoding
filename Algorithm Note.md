# Algorithm Note

## 基础



## 数组

* 67：Sqrt-X
  * 二分查找法：
    x平方根的整数部分是ans是满足$k^2 <= x$的最大k值，所以我们可以对$k$ 进行二分查找。
    下界为0，上界可以为x/2。二分查找的每一步，只需要比较中间元素mid的平方与x的大小关系，并通过比较的结果调整上下界的范围。
    * 注意事项：注意考虑极端例子：x=1的时候 

* 367：Valid-Perfect-Square：
  * 评论区看到的一个解法：
    前n个奇数的和 = n的平方
    也就是，完全平方数肯定是连续n个奇数的和
  * 二分法：
    同理67题
    * 注意事项：
      * 考虑特殊值1
      * 考虑边界，int的大小！
        `long long temp = (long)mid*mid;`

* 26、27：Remove-Dulplicate from Sorted Array

  * 双指针法：
    为什么可以用？ 因为题目要求我们将一个数组，分为俩部分！所以可以用！
    * 26的小优化
      如果数组所有都不重复，就会原地复制一圈，显然是不必要的，所以可以增加判断，当fastIndex-slowIndex > 1的时候，才进行复制。

* 844：退格字符串比较

  * 思路：
    从后往前遍历 SSS，所遇情况有三，如下所示： 

    * 2.1 若当前字符是 #，则 skipS 自增 
    * 2.2 若当前字符不是 #，且 skipS 不为 0，则 skipS 自减 1 
    * 2.3 若当前字符不是 #，且 skipS 为 0，则代表当前字符不会被消除，我们可以用来和 T 中的当前字符作比较。

  * 注意事项：

    * 逆序的思路！因为我们不能从左到右预测要消除的字符

    * 注意字符串的长度应该减一！

    * 抓住核心思想，两个字符串比较！所以要严格控制边界

    * 注意vscode插件leetcode测试字符串自己输入的时候
      要这样输入测试用例：

      ```c++
      ""abc#"\n"ab""
      ```

* 977：Squares-of-a-Sorted-Array

  * 关键点：
    还是双指针，因为数组也可以分为两个结构！
  * 注意事项：
    * 可以考虑逆序放入答案！因为负数的平方和正数的平方大小刚好相反！
    * 双指针也有两个思路
      * 一个是逆序放入，操作更简单
      * 一个是找到分界点！然后再进行合并

* 209：Minimum-Size-Subarray-Sum
  * 常规的滑动窗口法
    * 注意for循环用于整个数组的遍历
      然后里面用一个while来进行筛选，保证子数组是加起来要不小于target！

* 904：Fruit-into-Basket
  本质就是找一个数组中，仅包含俩个值的最长子串

  * 滑动窗口

  * 这里引出了滑动窗口可以和哈希表结合在一起，来判断滑动窗口的性质
    ```c++
    unordered_map<int, int> cnt;
    // 常用操作
    cnt.find(key);
    cnt.erase(it);
    ```

    



## 链表

链表写法：
```c++
// 单链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) ： val(x),next(NULL) { }	// 构造函数
};
```

* 206：Reverse-Linked-List

  * 有3种主流写法：

    1. 双指针法，记得用temp暂存下一个结点

    2. 从前往后递归法：
       ```c++
       class Solution {
       public:
           ListNode* reverse(ListNode* pre, ListNode* cur) {
               if(cur == nullptr) return pre;
               ListNode* temp = cur->next;
               cur->next = pre;
               return reverse(cur, temp)
           }
           ListNode* reverseList(ListNode* head) {
               return reverse(nullptr, head);
           }
       }
       ```

       这种的思路是loop-invariant，循环不变量思想，假设前面的链表已经翻转完成，我们继续向后翻转。这种思路考虑的是，交界处的翻转处理，pre相当于翻转完成的链表的头！因为我们的return判断条件是`cur==nullptr`！

    3. 从后往前递归法
       ```c++
       class Solution {
       public:
           
           ListNode* reverseList(ListNode* head) {
               if(head==nullptr) return nullptr;
               if(head->next==nullptr) return head;
               // 介于假设，我们直接将head->next后面的链表全部翻转
               ListNode* last = reverseList(head->next);
               // 现在只剩一个没有翻转的了
               head->next->next = head;
               head->next = nullptr;
               // 现在所有结点都转换完成，直接返回即可
               return last;	
           }
       }
       ```

       不需要辅助函数，我们直接假设这个函数，可以成功实现head后的链表翻转功能！记住：递归开头一定是写边界条件！该题有2个，一是head本身就空，一个是head已经到了边界，其next为空。
       这种思想相当于，**数学归纳法！**
