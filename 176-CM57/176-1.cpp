class Population
{
    string year;
    int number;
    int dead;
    int birth;
    Population(string year, int number, int dead, int birth) : year(year), number(number), birth(birth) {}
    double birthRate()
    {
        return birth / number;
    }
    double deadRate()
    {
        return dead / number;
    }
    ~Population() {}
};