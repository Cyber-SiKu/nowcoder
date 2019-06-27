#include <iostream>
using namespace std;

const int MAX = 100000;

int min_child_array(const int array[],int size);
int max(const int array[], int size);

int main(int argc, char **argv){
    int N = 0;
    int array[MAX] = {0};
    cin>>N;
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
