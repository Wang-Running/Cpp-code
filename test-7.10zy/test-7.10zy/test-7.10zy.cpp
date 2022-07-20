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