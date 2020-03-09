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
};

position::~position() {}

std::size_t position_asterisk(const std::string & wildcard);
// 返回 * 所在的位置

std::vector<std::string> split(const std::string & wildcard);
// 按 * 分割

std::vector<position> match(const std::string &to_match, const std::vector<std::string> &wildcards);

int get_str_len(const int & pre_position, const int & sub_position, const int & sub_len);

void out_put(const std::vector<position> & answer);

int main(int argc, char ** argv)
{
    std::string wildcard, to_match;
    std::cin >> wildcard >> to_match;
    std::vector<std::string> wildcards = split(wildcard);
    if (wildcards.size() == 1)
    {
        // 没有 *
        if (wildcard == to_match)
        {
            std::cout << "0 " << wildcard.length() << std::endl;
        }else
        {
            std::cout << "0 -1" << std::endl;
        }
    } else
    {
        std::vector<position> answer = match(to_match, wildcards);
        out_put(answer);
    }
    
    
    
    return 0;
}

std::size_t position_asterisk(const std::string & wildcard) 
{
    std::size_t ret = wildcard.find('*');
    return ret;
}

std::vector<std::string> split(const std::string & wildcard)
{
    std::vector<std::string> ret;
    std::string sub = wildcard;
    std::size_t position = position_asterisk(sub);
    while (position != std::string::npos)
    {
        std::string pre = wildcard.substr(0, position);
        ret.push_back(pre);
        sub = wildcard.substr(position + 1);
    }
    ret.push_back(sub);
    return ret;
}

std::vector<position> match(const std::string &to_match, const std::vector<std::string> &wildcards)
{
    // std::cout << "to match:" << to_match << " pre: "<< pre << " sub:" << sub << std::endl;
    std::vector<position> ret;
    std::string start = *wildcards.begin();
    std::size_t start_position = to_match.find(start);
    while (start_position != std::string::npos)
    {
        for (auto i = wildcards.begin()+1; i != wildcards.end(); i++)
        {
            /* code */
        }
        
    }
    
    return ret;
}

int get_str_len(const int & pre_position, const int & sub_position, const int & sub_len) 
{
    return sub_position - pre_position + sub_len;
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
