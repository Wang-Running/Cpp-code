#define _CRT_SECURE_NO_WARNINGS

//118. 杨辉三角
//class Solution {
//public:
//	vector<vector<int>> generate(int numRows) {
//		vector<vector<int>> vv;
//		//开空间--vector<int> 个数=行数
//		vv.resize(numRows);
//		//初始化
//		for (size_t i = 0; i<vv.size(); i++)
//		{
//			//行初始化
//			vv[i].resize(i + 1, 0);
//			//每行第一个为1
//			vv[i][0] = 1;
//			//每行最后一个为1
//			vv[i][vv[i].size() - 1] = 1;
//		}
//
//		for (size_t i = 0; i<vv.size(); i++)
//		{
//			for (size_t j = 0; j<vv[i].size(); j++)
//			{
//				if (vv[i][j] == 0)
//				{
//					//中间位置=上一个行的第j-1和第j个相加
//					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//				}
//			}
//		}
//		return vv;
//	}
//};

//JZ42 连续子数组的最大和
//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		if (array.size() == 0)
//			return 0;
//		int max = array[0];
//		int sum = array[0];
//		for (int i = 1; i<array.size(); i++)
//		{
//			if (sum>0)
//			{
//				sum += array[i];
//				if (sum>max)
//				{
//					max = sum;
//				}
//			}
//			//和小于0--array[i]很小
//			else
//			{
//				//负数比较
//				if (array[i]>max)
//				{
//					max = array[i];
//				}
//				//子区间断开，开始新的一段、不断开会越来越小
//				sum = array[i];
//			}
//		}
//		return max;
//	}
//};

//26. 删除有序数组中的重复项
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//
//		//相等，i++，找到不相等的情况后，j++挪动到要覆盖位置，进行覆盖
//		int j = 0;
//		for (int i = 1; i < nums.size(); i++)
//		{
//			if (nums[i] != nums[j])
//			{
//				j++;
//				nums[j] = nums[i];
//			}
//		}
//		//j为下标位置，始终比长度小1，返回时记得加上
//		return j + 1;
//	}
//};

#include <iostream>
#include <vector>
#include<algorithm>
//using namespace std;
//
//int main()
//{
//	vector<int> nums;
//	nums.push_back(2);
//	nums.push_back(2);
//	nums.push_back(3);
//	nums.push_back(2);
//	sort(nums.begin(), nums.end());
//	int i = 0;
//	for (i = 0; i<nums.size() - 1; i += 3)
//	{
//		if (nums[i] != nums[i + 1])
//		{
//			return nums[i];
//		}
//	}
//	return nums[i];
//	return 0;
//}

//137. 只出现一次的数字 II
//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		//先排序
//		//第一个和第二个比较，出现三次的必定是连续的
//		//不连续则i位置就是出现一次的
//		//size()-1,是防止单独的在最后一个位置，访问越界
//		sort(nums.begin(), nums.end());
//		int i = 0;
//		for (i = 0; i<nums.size() - 1; i += 3)
//		{
//			if (nums[i] != nums[i + 1])
//			{
//				return nums[i];
//			}
//		}
//		//如果在最后一个位置，则直接返回
//		return nums[i];
//	}
//};



//260. 只出现一次的数字 III
//class Solution {
//public:
//	vector<int> singleNumber(vector<int>& nums) {
//		vector<int> arr;
//		sort(nums.begin(), nums.end());
//		int i = 0;
//
//		//这里要理清情况：
//		//1.当出现一次的数都在最后时，前面数的间隔每次跳2
//		//2.每次都是与下一位置作比较，为了防止越界size()-1
//		//3.若中间有出现了一次的数，那么将其入容器，往后1，因此我们i--,然后+=2，就是走了一步
//		//4.末尾情况，看看arr满没满，没有满，那么就是：1223这种情况，指针最后到3，将3入arr
//		//满了则就是这种122344，刚刚好，返回即可
//
//		for (i; i<nums.size() - 1; i += 2)
//		{
//			if (nums[i] != nums[i + 1])
//			{
//				arr.push_back(nums[i]);
//				i--;
//			}
//		}
//		if (arr.size()<2)
//		{
//			arr.push_back(nums[i]);
//		}
//		return arr;
//	}
//};
//int main()
//{
//	vector<int> arr;
//	vector<int> nums;
//	nums.push_back(0);
//	nums.push_back(1);
//	nums.push_back(1);
//	nums.push_back(2);
//		sort(nums.begin(), nums.end());
//		int i = 0;
//		for (i;i<nums.size()-1;i++)
//		{
//			if (nums[i]!=nums[i+1])
//			{
//				arr.push_back(nums[i]);
//			}
//		}
//		if (arr.size()<2)
//		{
//			arr.push_back(nums[i - 1]);
//		}
//		return 0;
//}

//JZ39 数组中出现次数超过一半的数字
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		int max = 0;
//		//找到最大值
//		for (auto e : numbers)
//		{
//			if (e>max)
//			{
//				max = e;
//			}
//		}
//		//开辟空间，初始化0，哈希绝对映射
//		vector<int> arr;
//		arr.resize(max + 1, 0);
//		for (auto e : numbers)
//		{
//			arr[e]++;
//		}
//		for (int i = 0; i<arr.size(); i++)
//		{
//			if (arr[i]>(numbers.size() / 2))
//			{
//				return i;
//			}
//		}
//		return 0;
//	}
//};