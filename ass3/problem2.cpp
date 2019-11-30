#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    std::string phrase;
    std::cout << "Enter a phrase: ";
    std::getline(std::cin, phrase);
    std::cout << phrase.size() << std::endl;
    int word_start = 0, temp_end = 0, word_end = 0, words = 0, proper = 0, repeat = 0;
    while (word_end != std::string::npos) {     
        word_end = phrase.find(" ", word_start);
        if(word_end == std::string::npos)
        {
            temp_end = phrase.size();
        }
        else
        {
            temp_end = word_end;
        }
        std::cout << phrase.substr(word_start, temp_end - word_start) << std::endl;
        words++;
        bool is_proper = true;
        bool is_repeat = false;
        char previous_letter = phrase[word_start];
        for(int i = 0; i < (temp_end - word_start); i++)
        {
            if (!is_repeat)
            {
                if (i > 0)
                {
                    if (phrase[word_start + i] == previous_letter)
                    {
                        is_repeat = true;
                    }
                }
            }
            if (is_proper)
            {
                if (i == 0)
                {
                    if (!(phrase[word_start + i] >= 'A' && phrase[word_start + i] <= 'Z'))
                    {
                        is_proper = false;
                    }
                }
                else // i > 1
                {
                    if (!(phrase[word_start + i] >= 'a' && phrase[word_start + i] <= 'z'))
                    {
                        is_proper = false;
                    }
                }
            }
            previous_letter = phrase[word_start + i];
        }
        if(is_proper)
        {
            proper++;
        }
        if(is_repeat)
        {
            repeat++;
        }
        word_start = word_end + 1;
    }
    std::cout << words << std::endl;
    std::cout << proper << std::endl;
    std::cout << repeat << std::endl;
}