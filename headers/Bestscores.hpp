#ifndef BESTSCORES_HPP
#define BESTSCORES_HPP

#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <iostream>

class BestScores
{

public:
    std::vector<std::pair<std::string, int>> scores;

    void writescores()
    {
        remove("scores.txt");

        std::sort(this->scores.begin(), this->scores.end(), [](const std::pair<std::string, int> &lhs, const std::pair<std::string, int> &rhs) { return lhs.second > rhs.second; });

        std::fstream file;
        file.open("scores.txt", std::ios::out);
        if (file.good())
        {
            for (auto i : this->scores)
            {
                file << i.first;
                file << std::endl;
                file << i.second;
                file << std::endl;
            }
            file.close();
        }
    }

    void readscores()
    {
        scores.clear();
        std::string s;
        int a;
        std::fstream file;
        file.open("scores.txt", std::ios::in);
        if (file.good())
        {

            while (!file.eof())
            {
                file >> s;
                file >> a;
                scores.push_back(make_pair(s, a));
            }
            scores.pop_back();
            file.close();
        }
    }

    void addscore(int _score)
    {
        scores.push_back(make_pair(currentDateTime(), _score));
        writescores();
    }

    const std::string currentDateTime()
    {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        localtime_s(&tstruct,&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d||%X", &tstruct);

        return buf;
    }

    BestScores()
    {
        readscores();
    }
    ~BestScores()
    {
        writescores();
    }
};

#endif