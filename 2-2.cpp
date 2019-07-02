/* 优化算法：分房子和空地两种类型，只记录房子的坐标
计算空地到各个房间的距离返回最小值
 */

/* 进一步优化的空间：
    1. 不使用vector 
    2. 计算距离时就可以求出最小值，不必分开求解
    */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

class Coordinate {
    private:
    int x;
    int y;
    public:
    Coordinate()
    {
        x = 0;
        y = 0;
    }
    Coordinate(const int & x, const int & y):x(x),y(y){}

    int distance(const Coordinate & c)
    {
        return abs(this->x-c.x) + abs(this->y-c.y);
    }
};

void input(std::vector<Coordinate> & house, std::vector<Coordinate> & space,const int &size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j) 
        {
            int temp = 0;
            std::cin >> temp;
            if (temp == 0)
            {
                space.push_back(Coordinate(i,j));
            } else 
            {
                house.push_back(Coordinate(i,j));
            }
        }
    }
}

std::vector<int> all_distance(std::vector<Coordinate> & house, std::vector<Coordinate> & space)
{
    std::vector<int> ret;
    //返回空地到其他地方的距离
    for (auto i = space.begin(); i != space.end(); i++)
    {
        int distance = 0;
        for (auto j = house.begin(); j != house.end(); j++)
        {
            distance += i->distance(*j);
        }
        ret.push_back(distance);
    }

    return ret;
    
}

int min_distance(const std::vector<int> & distances)
{
    int ret = -1;
    if (!distances.empty())
    {
        ret = *std::min_element(distances.begin(), distances.end());
    }
    return ret;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<Coordinate> house;
    std::vector<Coordinate> space;
    input(house, space, N);
    std::cout<< min_distance(all_distance(house, space)) <<std::endl;
    return 0;
}