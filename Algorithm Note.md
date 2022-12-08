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

## 哈希表

* 49：Group-Anagrams

  * 方法一：用排序后的string作为key：
    注意：
    要跳出用c来编程的思想，熟练运用容器！
    比如这题就要果断用sort函数，unordered_map容器，以及对应的emplace_back方法，因为这个方法比push_back要快！

  * **方法二：**本题很值得反复琢磨！

    * 参考链接：

      [(179条消息) 面试题 10.02：变位词组(自定义哈希函数)_菊头蝙蝠的博客-CSDN博客](https://blog.csdn.net/qq_21539375/article/details/122003817#:~:text=其中 [fn %3D hash {}] 是初始化捕获列表%2C也就是说定义了一个,auto fn %3D hash {}%3B 供后续使用)

    * lambda函数写法：
      ```c++
      auto arrayHash = [ fn = hash<int>{} ] (const array<int, 26> &arr) 
          -> size_t {
          	return accumulate(arr.begin(). arr.end(), 0u, 
      					[&](size_t acc, int num) {
                          	return (acc<<1)^fn(num);
      					}
                  	);
      	};
      unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> 
          mp(0, arrayHash);
      ```

    * 仿函数的写法：
      class实现，类函数

      ```c++
      class arrayHash {
      public:
          size_t operator()(const array<int, 26> &arr) const {
              hash<int> fn;
              return accumulate(arr.begin(), arr.end(), 0u, 
                                [&](size_t acc, int num) {
                                    return (acc<<1)^fn(num);
                                }
      					);
          }
      };
      unordered_map<array<int,26>,vector<string>,arrayHash> map(0,arrayHash());
      //arrayHash是一个类,arrayHash()是一个函数名(仿函数)
      ```

      * 注：这里的`[&](size_t acc, int num)` 中的[&]的含义是：
        **隐式引用捕获**，注意，若将变量名写入捕获列表，则为显示捕获！

    * struct的写法：
      ```c++
      struct arrayHash{
                  size_t operator()(const array<int,26>& arr) const{
                      hash<int> fn;
                      return accumulate(arr.begin(),arr.end(),0u,[&](size_t acc,int num){
                          return (acc<<1)^fn(num);
                      });
                  }
              };
      unordered_map<array<int,26>,vector<string>,arrayHash> map;
      ```

    * 静态函数的写法：
      ```c++
      static size_t arrayHash(const array<int,26>& arr){
              return accumulate(arr.begin(),arr.end(),0u,[&,fn=hash<int>{}](size_t acc,int num){
                          return (acc<<1)^fn(num);
                      });
          }
      unordered_map<array<int,26>,vector<string>,decltype(&arrayHash)> map(0,arrayHash);
      ```

      

* 349：Intersection-of-two-Arrays
  这题很简单，但是我们需要学习的是C++中容器的用法

  * 选择最优容器：
    题目说了答案不许重复，我们直接考虑set
    又因为题目用哈希表方便，故选择unordered_set
  * 用了容器就要用c++给定的容器操作！
    * 初始化：
      `unordered_set<int> nums_set(nums1.begin(), nums1.end());`
      用范围迭代器初始化更方便，不要自己写一个for循环，那是c的思想！
    * for循环：用c++新定义的冒号循环！
      `for(int num : nums) {}`
    * 插入：
      注意用`insert`！或者`emplace`！

  * 用set的缺点：
    占用空间大，速度慢！

  * 注意题目的限制

    * `1 <= nums1.length, nums2.length <= 1000`
    * `0 <= nums1[i], nums2[i] <= 1000`

    所以我们可以用数组来做哈希表！

* 202: Happy_number
  * 自己的ac记录
    * 第一次，while的逻辑搞错了
    * 第二次，结束的判断条件搞错了
    * 第三次决定用unordered_set!
    * 最后的结果ac：
      - Your runtime beats 6.3 % of cpp submissions
      - Your memory usage beats 5 % of cpp submissions (6.8 MB)
  * 启示录上的优化
    就是把俩函数改为一个就行了

* K-sum问题

  * 题目汇总：2-sum，3-sum，4-sum，4-sum II

  * 其中4-sum II只需要返回个数，更简单，直接用哈希表存对应数字即可！

  * 其他几个sum，都是可以用哈希表
    其中2-sum直接哈希，3-sum可以哈希，但是去重比较麻烦，可以考虑双指针法，去重更加简单！
    但是都需要先排序！

  * 去重的逻辑：

    * a 如果重复了怎么办，a是nums里遍历的元素，那么应该直接跳过去。

      但这里有一个问题，是判断 nums[i] 与 nums[i + 1]是否相同，还是判断 nums[i] 与 nums[i-1] 是否相同。都是和 nums[i]进行比较，是比较它的前一个，还是比较他的后一个。

      如果我们的写法是 这样：

      ```c++
      if (nums[i] == nums[i + 1]) { // 去重操作
          continue;
      }
      ```

      那就我们就把 三元组中出现重复元素的情况直接pass掉了。 例如{-1, -1 ,2} 这组数据，当遍历到第一个-1 的时候，判断 下一个也是-1，那这组数据就pass了。

      **我们要做的是 不能有重复的三元组，但三元组内的元素是可以重复的！**

      那么应该这么写：

      ```c++
      if (i > 0 && nums[i] == nums[i - 1]) {
          continue;
      }
      ```

    * b与c的去重

    * 很多同学写本题的时候，去重的逻辑多加了 对right 和left 的去重：（代码中注释部分）

      ```c++
      while (right > left) {
          if (nums[i] + nums[left] + nums[right] > 0) {
              right--;
              // 去重 right
              while (left < right && nums[right] == nums[right + 1]) right--;
          } else if (nums[i] + nums[left] + nums[right] < 0) {
              left++;
              // 去重 left
              while (left < right && nums[left] == nums[left - 1]) left++;
          } else {
          }
      }
      ```

      但细想一下，这种去重其实对提升程序运行效率是没有帮助的。

      拿right去重为例，即使不加这个去重逻辑，依然根据 `while (right > left)` 和 `if (nums[i] + nums[left] + nums[right] > 0)` 去完成right-- 的操作。

      多加了 `while (left < right && nums[right] == nums[right + 1]) right--;` 这一行代码，其实就是把 需要执行的逻辑提前执行了，但并没有减少 判断的逻辑。

      最直白的思考过程，就是right还是一个数一个数的减下去的，所以在哪里减的都是一样的。

      所以这种去重 是可以不加的。 仅仅是 把去重的逻辑提前了而已

  * 为什么不建议2sum用双指针
    因为两数之和要求返回的是索引下标， 而双指针法一定要排序，一旦排序之后原数组的索引就被改变了。
  * 如果两数之和要求返回的是数值的话，就可以使用双指针法了。



## 字符串

* 344：Reverse-String

  * swap的两种实现方式：

    * 常见的用一个temp来交换数值

    * 位运算
      用异或的性质！

      ```c++
      s[i] ^= s[j];
      s[j] ^= s[i];
      s[i] ^= s[j];
      ```

      

* 151：Reverse-Words-in-a-String
  **其实很多数组填充类的问题，都可以先预先给数组扩容带填充后的大小，然后在从后向前进行操作。**

  * 快慢指针的思想：
    ```c++
     // 用快指针掠过空格，用慢指针记录 
            for( ; fastIndex < s.size(); fastIndex++) {
                if(fastIndex - 1 > 0
                        && s[fastIndex - 1] == s[fastIndex]
                        && s[fastIndex] == ' ') {
                    continue;
                } else 
                    s[slowIndex++] = s[fastIndex];
            }
    ```

    * 用移除元素的思想，能使得代码更简洁
      ```c++
      void removeExtraSpaces(string& s) {
              int slow = 0;
              for(int i = 0; i < s.size(); ++i) {
                  if(s[i] != ' ') {
                      if(slow != 0)   // 第一个单词前不应该有空格
                          s[slow++] = ' ';
                      while(i < s.size() && s[i] != ' ')
                          s[slow++] = s[i++];
                  }
              }
              s.resize(slow);
          }
      ```

      

  * 记得要考虑**头尾的空格**！

* 剑指offer 58： 左旋字符串
  * **局部翻转再全局翻转的思想！**

* 28： KMP字符串匹配
  * KMP
    * 前缀表与Next数组
      next 数组考虑的是除当前字符外的最长相同前缀后缀。所以就是前缀表后移一位！（当然也可以不移）
      模式串中的某个字符跟文本串中的某个字符匹配失配时，模式串下一步应该跳到哪个位置。如模式串中在j 处的字符跟文本串在i 处的字符匹配失配时，下一步用next [j] 处的字符继续跟文本串i 处的字符匹配，相当于模式串向右移动 j - next[j] 位。
      * 问题的关键就是寻找模式串中最大长度的相同前缀和后缀，找到了模式串中每个字符之前的前缀和后缀公共部分的最大长度后，便可基于此匹配。而这个最大长度便正是next 数组要表达的含义。
      
    * KMP的其中一种优化代码：
      ```c++
      void GetNextval(char* p, int next[]) {  
          int pLen = strlen(p);  
          next[0] = -1;  
          int k = -1;  
          int j = 0;  
          while (j < pLen - 1) {  
              //p[k]表示前缀，p[j]表示后缀    
              if (k == -1 || p[j] == p[k]) {  
                  ++j;  
                  ++k;  
                  //较之前next数组求法，改动在下面4行  
                  if (p[j] != p[k])  
                      next[j] = k;   //之前只有这一行  
                  else  
                      //因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]  
                      next[j] = next[k];  
              }  
              else  
                  k = next[k];  
          }  
      }  
      ```
    
      
  * BM算法
  * Sunday算法
