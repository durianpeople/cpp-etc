#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long nChoosek(long n, long k)
{
    if (k > n)
        return 0;
    if (k * 2 > n)
        k = n - k;
    if (k == 0)
        return 1;

    int result = n;
    for (int i = 2; i <= k; ++i)
    {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

class Streak
{
public:
    vector<int> sequence;
};

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r)
{
    int triplets = 0;
    vector<Streak *> streaks;
    unordered_map<int, int> number_frequency;
    for (int i : arr)
    {
        number_frequency[i]++;
        bool found_a_streak = false;
        for (Streak *streak : streaks)
        {
            if (i / streak->sequence.back() == r)
            {
                found_a_streak = true;
                streak->sequence.push_back(i);
            }
            else if (i == streak->sequence.back())
                found_a_streak = true;
        }
        if (!found_a_streak)
        {
            Streak *streak = new Streak;
            streak->sequence.push_back(i);
            streaks.push_back(streak);
        }
    }

    for (Streak *streak : streaks)
    {
        if (streak->sequence.size() < 3)
            continue;
        if (r == 1)
        {
            triplets += nChoosek(streak->sequence.size(), 3);
            continue;
        }
        int multiplier = 1;
        for (int i : streak->sequence)
        {
            multiplier *= number_frequency[i];
        }
        triplets += (streak->sequence.size() - 3 + 1) * multiplier;
    }

    return triplets;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++)
    {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
