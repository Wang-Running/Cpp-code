#define _CRT_SECURE_NO_WARNINGS

//118. �������
//class Solution {
//public:
//	vector<vector<int>> generate(int numRows) {
//		vector<vector<int>> vv;
//		//���ռ�--vector<int> ����=����
//		vv.resize(numRows);
//		//��ʼ��
//		for (size_t i = 0; i<vv.size(); i++)
//		{
//			//�г�ʼ��
//			vv[i].resize(i + 1, 0);
//			//ÿ�е�һ��Ϊ1
//			vv[i][0] = 1;
//			//ÿ�����һ��Ϊ1
//			vv[i][vv[i].size() - 1] = 1;
//		}
//
//		for (size_t i = 0; i<vv.size(); i++)
//		{
//			for (size_t j = 0; j<vv[i].size(); j++)
//			{
//				if (vv[i][j] == 0)
//				{
//					//�м�λ��=��һ���еĵ�j-1�͵�j�����
//					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//				}
//			}
//		}
//		return vv;
//	}
//};

//JZ42 ���������������
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
//			//��С��0--array[i]��С
//			else
//			{
//				//�����Ƚ�
//				if (array[i]>max)
//				{
//					max = array[i];
//				}
//				//������Ͽ�����ʼ�µ�һ�Ρ����Ͽ���Խ��ԽС
//				sum = array[i];
//			}
//		}
//		return max;
//	}
//};

//26. ɾ�����������е��ظ���
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//
//		//��ȣ�i++���ҵ�����ȵ������j++Ų����Ҫ����λ�ã����и���
//		int j = 0;
//		for (int i = 1; i < nums.size(); i++)
//		{
//			if (nums[i] != nums[j])
//			{
//				j++;
//				nums[j] = nums[i];
//			}
//		}
//		//jΪ�±�λ�ã�ʼ�ձȳ���С1������ʱ�ǵü���
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

//137. ֻ����һ�ε����� II
//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		//������
//		//��һ���͵ڶ����Ƚϣ��������εıض���������
//		//��������iλ�þ��ǳ���һ�ε�
//		//size()-1,�Ƿ�ֹ�����������һ��λ�ã�����Խ��
//		sort(nums.begin(), nums.end());
//		int i = 0;
//		for (i = 0; i<nums.size() - 1; i += 3)
//		{
//			if (nums[i] != nums[i + 1])
//			{
//				return nums[i];
//			}
//		}
//		//��������һ��λ�ã���ֱ�ӷ���
//		return nums[i];
//	}
//};



//260. ֻ����һ�ε����� III
//class Solution {
//public:
//	vector<int> singleNumber(vector<int>& nums) {
//		vector<int> arr;
//		sort(nums.begin(), nums.end());
//		int i = 0;
//
//		//����Ҫ���������
//		//1.������һ�ε����������ʱ��ǰ�����ļ��ÿ����2
//		//2.ÿ�ζ�������һλ�����Ƚϣ�Ϊ�˷�ֹԽ��size()-1
//		//3.���м��г�����һ�ε�������ô����������������1���������i--,Ȼ��+=2����������һ��
//		//4.ĩβ���������arr��û����û��������ô���ǣ�1223���������ָ�����3����3��arr
//		//�������������122344���ոպã����ؼ���
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

//JZ39 �����г��ִ�������һ�������
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		int max = 0;
//		//�ҵ����ֵ
//		for (auto e : numbers)
//		{
//			if (e>max)
//			{
//				max = e;
//			}
//		}
//		//���ٿռ䣬��ʼ��0����ϣ����ӳ��
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