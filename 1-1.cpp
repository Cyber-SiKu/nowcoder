#include <iostream>
using namespace std;

const int MAX = 100000;

int min_child_array(const int array[],int size);
int max(const int array[], int size);
bool all_non_positive(const int array[], int size);

int MaxSubSum(int array[], int len);

int main(int argc, char **argv){
    int N = 0;
    int array[MAX] = {0};
    cin>>N;
    int flag = true; // 记录全员是否是负数
    for(int i = 0; i < N; ++i){
        cin >> array[i];
    }
    cout << min_child_array(array, N) << std::endl;
    return 0;
}

int min_child_array(const int array[],int size) {
    // 把所有连续的正整数加在一起，负数加在一起形成新的数组
    // 新的数组中的负数和左右两边的数字进行比较，如果两边数大于该数，三数相加
    // 重复上述步骤，直至不在增加
   
    if (!all_non_positive(array,size))
    {   
        int answer[MAX] = {0};
        int count = 0;
        for (int i = 0, j = 0; i < size; ++i) {
            if (answer[j]*array[i] < 0) {
                // 当前数字和正在计算的符号不同
                ++j;
                ++count;
            }
            answer[j] += array[i];
        }
        ++count;
        // std::cout << "answer:\n";
        //  for (int i = 0; i < count; ++i) {
        //     std::cout << answer[i] << std::endl;
        // }

        for(int i = 0;i < count; ++i) {
            if (i > 0 && i < count){
                if(answer[i] < 0) {
                if((answer[i-1] + answer[i] > 0) 
                    &&(answer[i+1]+ answer[i] > 0)) {
                    answer[i-1] = answer[i-1] + answer[i] + answer[i+1];
                    answer[i] = answer[i+1] = 0;
                    if(answer[count-1] > 0){
                        answer[i] = answer[count-2];
                        answer[i+1] = answer[count-1];
                    } else {
                        answer[i] = answer[count-1];
                        answer[i+1] = answer[count-2];
                    }
                    i -= 2;
                    count -= 2;
                    continue;
                    }
                }
            }
        }
        return max(answer, count);
    }
    return max(array, size);
}

int max(const int array[], int size) {
    int max = array[0];
    // std::cout << "array:\n";
    for(int i = 0;i < size;++i){
        // std::cout<<array[i]<<std::endl;
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

bool all_non_positive(const int array[], int size) {
    bool ret = true;
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] > 0)
        {
            ret = false;
            break;
        }
    }
    return ret;    
}

int MaxSubSum(int array[], int len) {
    // 最优算法
    /*
    当数字有负有正时，和最大的子序列的第一个元素一定是正数
    当全为非负数时一定是最大元素
     */
    if (!all_non_positive(array, len))
    {
        /* 当数字有负有正时 */
        int i;
	    int MaxSum = 0;
	    int CurSum = 0;
	    for(i=0;i<len;i++)
	    {
		    CurSum += array[i];
		    if(CurSum > MaxSum)
            {
                MaxSum = CurSum;
            }
		    //如果累加和出现小于0的情况，
		    //则和最大的子序列肯定不可能包含前面的元素，
		    //这时将累加和置0，从下个元素重新开始累加
		    if(CurSum < 0)
            {
			    CurSum = 0;
            }
	    }
	    return MaxSum;
    } else
    {
        return max(array, len);
    }
    
    
}