/* 一般算法，遍历矩阵，计算每一个0点到1点的距离之和，返回其中的最小值*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 100

void input_array(int array[][MAX],const int & size);
// 输入数据

std::vector<int> all_distance(int array[][MAX],const int & size);
// 返回从各个0点到1点距离之和

int distance_to_other(int array[][MAX], const int & size, const int & i, const int & j);
// 返回点i,j到1点的距离之和

int min_distance(std::vector<int> distances);

int main(int argc, char **argv) 
{
    int array[MAX][MAX];
    int N;
    std::cin >> N;
    input_array(array, N);
    std::cout << min_distance(all_distance(array, N)) << std::endl;
    return 0;
}

void input_array(int array[][MAX],const int & size) 
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j) 
        {
            std::cin >> array[i][j];
        }
    }
}

std::vector<int> all_distance(int array[][MAX],const int & size)
{
    std::vector<int> distances;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] == 0)
            {
                int distance = distance_to_other(array, size, i, j);
                distances.push_back(distance);
            }
        }
        
    }
    return distances;
}

int distance_to_other(int array[][MAX], const int & size, const int & i, const int & j) {
    int distance = 0;
    for (int i_ = 0; i_ < size; i_++)
    {
        for (int j_ = 0; j_ < size; j_++)
        {
            if ((i != i_) || (j != j_))
            {
               if (array[i_][j_] == 1)
                {
                    distance = distance + abs(i-i_) + abs(j-j_);
                }
            }
        }   
    }
    return distance;
}

int min_distance(std::vector<int> distances)
{
    int ret = -1;
    if (!distances.empty())
    {
        ret = *distances.begin();
        for (auto i = distances.begin()+1; i != distances.end(); i++)
        {
            if(ret > *i) 
            {
                ret = *i;
            }
        }
        
    }
    return ret;
}