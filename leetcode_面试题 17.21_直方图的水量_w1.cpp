/* ------------------------------------------------------------------|
给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为 1。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的直方图，在这种情况下，可以接 6 个单位的水（蓝色部分表示水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/volume-of-histogram-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.1 MB, 在所有 C++ 提交中击败了81.94%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*	双指针法
*
*	执行用时：8 ms, 在所有 C++ 提交中击败了61.71%的用户
*	内存消耗：13.7 MB, 在所有 C++ 提交中击败了30.57%的用户
*/
int trap(vector<int>& height) {
    int sum = 0;
    int l = 0;
    int r = height.size() - 1;
    int lmax = 0;
    int rmax = 0;
    while (l < r) {
        //如果左指针的值小于右指针的值
        //说明右边可以给左边兜底
        //左指针向右操作即可
        if (height[l] <= height[r]) {
            if (height[l] >= lmax) {
                lmax = height[l];
            }
            else {
                sum += lmax - height[l];
            }
            l++;
        }
        //反之亦然
        else {
            if (height[r] >= rmax) {
                rmax = height[r];
            }
            else {
                sum += rmax - height[r];
            }
            r--;
        }
    }
    return sum;
}
/*	单调栈法
*
*	执行用时：8 ms, 在所有 C++ 提交中击败了61.71%的用户
*	内存消耗：13.7 MB, 在所有 C++ 提交中击败了30.57%的用户
*/
//int trap(vector<int>& height) {
//    stack<int> s;
//    int sum = 0;
//    for (int i = 0; i < height.size(); ++i) {
//        while (!s.empty() && height[i] >= height[s.top()]) {
//            int pre = s.top();
//            s.pop();
//            if (s.empty()) {
//                break;
//            }
//            int dis = i - s.top() - 1;
//            int h = min(height[i], height[s.top()]) - height[pre];
//            sum += dis * h;
//        }
//        s.emplace(i);
//    }
//    return sum;
//}

int main() {
    vector<int> h = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << trap(h) << endl;
}