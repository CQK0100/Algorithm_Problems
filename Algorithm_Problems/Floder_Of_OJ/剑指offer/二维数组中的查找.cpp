/*
��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
 		int rowLen = array.size();
        int colLen = array[0].size();
        int i,j;
        for(i=rowLen-1,j=0;i>=0&&j<colLen;)
        {
            if(target == array[i][j])
                return true;
            if(target < array[i][j])
            {
                i--;
                continue;
            }
            if(target > array[i][j])
            {
                j++;
                continue;
            }
        }
        return false;
    }
};