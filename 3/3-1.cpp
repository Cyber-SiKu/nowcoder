#include <iostream>
#include <string>
#include <iterator>
#include <vector>

// TODO： 不止有 1 个 *（源代码假设仅有一个）
class position
{
private:
    int begin;
    int length;
public:
    position(int begin=0, int length=0): begin(begin), length(length) {};
    ~position();
    friend std::ostream & operator << (std::ostream & os, const position & p);
    friend void insert(std::vector<position> &a,const std::vector<position> & b, const std::size_t & pre_position);
};

position::~position() {}

std::size_t position_asterisk(const std::string & wildcard);
// 返回 * 所在的位置

void pre_sub(const std::string & wildcard, std::string &pre, std::string &sub);
// 利用参数返回 * 的前驱和后继子字符串

std::vector<position> match(const std::string &to_match, const std::string &pre, const std::string &sub, const int & base_len);

int get_str_len(const int & pre_position, const int & sub_position, const int & sub_len, const int & base_len);

void out_put(const std::vector<position> & answer);

void insert(std::vector<position> &a,const std::vector<position> & b, const std::size_t & pre_position);

int main(int argc, char ** argv)
{
    std::string wildcard, to_match;
    std::cin >> wildcard >> to_match;
    std::string pre, sub;
    pre_sub(wildcard, pre, sub);
    if (pre.empty() && sub.empty())
    {
        std::size_t position = position_asterisk(wildcard);
        if (position != std::string::npos)
        {
            // *
            size_t length = to_match.length();
            for (size_t i = 0; i < length; i++)
            {
                for (size_t j = 1; j < length - i + 1; j++)
                {
                    std::cout << i << " " << j << std::endl;
                }
            }
            
        }else
        {
            std::cout << "-1 0";
        }
        
        
    } else
    {
        std::vector<position> answer = match(to_match, pre, sub, 0);
        out_put(answer);
    }
    
    return 0;
}

std::size_t position_asterisk(const std::string & wildcard) 
{
    return wildcard.find('*');
}

void pre_sub(const std::string & wildcard, std::string &pre, std::string &sub) 
{
    std::size_t position = position_asterisk(wildcard);
    if (position != -1)
    {
        pre = wildcard.substr(0, position);
        sub = wildcard.substr(position + 1);
    }
}

std::vector<position> match(const std::string &to_match, const std::string &pre, const std::string &sub, const int & base_len)
{
    // std::cout << "to match:" << to_match << " pre: "<< pre << " sub:" << sub << " base_len:" << base_len << std::endl;
    std::vector<position> ret;
    std::size_t pre_position = to_match.find(pre);
    int len_pre = pre.length();
    int len_sub = sub.length();
    while (pre_position != std::string::npos)
    {
        int pa = position_asterisk(sub);
        // std::cout << "position asterisk:" << pa << std::endl;
        if (pa == -1) 
        {
            std::size_t sub_position = to_match.find(sub, pre_position+len_pre);
            while (sub_position != std::string::npos)
            {
                int temp = 0;
                if (base_len != 0)
                {
                    // 从其他 * 递归而来，pre_position 前面的符号有效
                    temp = pre_position;
                }
                ret.push_back(position(pre_position, get_str_len(pre_position, sub_position, len_sub, base_len + temp)));
                sub_position = to_match.find(sub, sub_position+1);
            }
        }else
        {
            // 仍然有其他 *
            std::string pre_, sub_;
            pre_sub(sub, pre_, sub_); // 对 第一个 * 后面的字符继续分组a
            std::vector<position> temp = match(to_match.substr(pre_position+len_pre), pre_, sub_, base_len+pre_position+len_pre);
            insert(ret, temp, pre_position);
        }
        pre_position = to_match.find(pre, pre_position+1);
    }
    return ret;
}

int get_str_len(const int & pre_position, const int & sub_position, const int & sub_len, const int & base_len) 
{
    return sub_position - pre_position + sub_len + base_len;
}

std::ostream & operator<<(std::ostream & os, const position & p)
{
    os << p.begin << " " << p.length;
    return os;
}

void out_put(const std::vector<position> & answer)
{
    if (answer.empty())
    {
        std::cout << "-1 0" <<std::endl;
    }else
    {
        for (auto i = answer.begin(); i != answer.end(); i++)
        {
            std::cout << *i << std::endl;
        }
    }
}

void insert(std::vector<position> &a,const std::vector<position> & b, const std::size_t & pre_position)
{
    for (auto i = b.begin(); i != b.end(); i++)
    {
        a.push_back(position(pre_position, i->length));
    }
}