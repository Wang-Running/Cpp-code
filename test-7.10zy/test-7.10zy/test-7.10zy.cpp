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