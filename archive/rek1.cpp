#include <iostream>
#include <vector>

using namespace std;
const int CAMEL = 1;
const int SNAKE = 2;

int main()
{
    string input;
    cin >> input;
    string buffer;

    vector<string> words;
    int type = 0;

    for (char &c : input)
    {
        switch (type)
        {
        case 0:
            if ((int)c < 95) // is capital
            {
                type = CAMEL;
                if (!buffer.empty())
                    words.push_back(buffer);
                buffer.clear();
                buffer.append(string(1, c));
            }
            else if (c == '_')
            {
                type = SNAKE;
                if (!buffer.empty())
                    words.push_back(buffer);
                buffer.clear();
            }
            else
            {
                buffer.append(string(1, c));
            }
            break;
        case CAMEL:
            if ((int)c < 95) // is capital
            {
                if (!buffer.empty())
                    words.push_back(buffer);
                buffer.clear();
            }
            buffer.append(string(1, c));
            break;
        case SNAKE:
            if (c == '_')
            {
                if (!buffer.empty())
                    words.push_back(buffer);
                buffer.clear();
            }
            else
            {
                buffer.append(string(1, c));
            }
            break;
        }
    }
    if (!buffer.empty())
        words.push_back(buffer);

    for (int i = 0; i < words.size(); i++)
    {
        switch (type)
        {
        case CAMEL:
            words[i][0] = words[i][0] + 32; // Downcase to be snake
            break;
        case SNAKE:
            words[i][0] = words[i][0] - 32; // Upcase to be camel
        }
    }

    bool first = true;
    for (string member : words)
    {
        if (first)
        {
            first = false;
        }
        else if (type == CAMEL)
        { // if camel, add _ to be snake
            cout << "_";
        }
        cout << member;
    }
    cout << endl;

    return 0;
}