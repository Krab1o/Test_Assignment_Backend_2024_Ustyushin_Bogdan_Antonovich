#include <iostream>
#include <fstream>
#include <string>
#include <map>

void solveTask(std::string filename)
{
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file" << std::endl;
        return;
    }

    std::map<std::string, int> wordCount;
    std::string line, word;
    size_t start = 0;

    while (std::getline(file, line))
    {
        for (auto ch : line)
        {
            if (ch == ' ')
            {
                wordCount[word]++;
                word = "";
            }
            else
            {
                word.push_back(ch);
            }
        }
        wordCount[word]++;
        word = "";
    }

    for (auto el : wordCount)
    {
        std::cout << el.first << " " << el.second << std::endl;
    }
}

int main()
{
    solveTask("text.txt");
    return 0;
}