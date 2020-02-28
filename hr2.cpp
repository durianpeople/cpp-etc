#include <bits/stdc++.h>

using namespace std;

class USM
{
public:
    string substring;
    unordered_map<char, int> map;
    int number_found = 0;
};

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s)
{
    int found_pairs = 0;
    for (int substring_length = 1; substring_length < s.size(); substring_length++)
    {
        if (substring_length == 2)
        {
            int sink = 0;
        }
        vector<USM *> usms;
        for (int pointer = 0; pointer <= s.size() - substring_length; pointer++)
        {
            bool found_a_pair = false;
            string substr = s.substr(pointer, substring_length);
            for (USM *usm : usms)
            {
                unordered_map<char, int> map_copy = usm->map;
                bool skip_to_next_usm = false;
                for (char &c : substr)
                {
                    if (map_copy[c] > 0)
                        map_copy[c]--;
                    else
                    {
                        skip_to_next_usm = true;
                        break;
                    }
                }
                if (skip_to_next_usm)
                    continue;
                found_a_pair = true;
                usm->number_found++;
                found_pairs += usm->number_found;
            }
            if (!found_a_pair)
            {
                USM *new_usm = new USM;
                for (char &c : substr)
                {
                    new_usm->map[c]++;
                }
                new_usm->substring = substr;
                usms.push_back(new_usm);
            }
        }
    }
    return found_pairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
