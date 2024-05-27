#include<vector>
#include<fstream>
#include <iostream>
#include<string>
using namespace std;

bool punctuation_marks(char ch)
{
    string punctuation = " .,:;!?-()"; // добавлен символ новой строки
    return punctuation.find(ch) != string::npos;
}

int main()
{
    string line;
    vector<string> words;
    int n;
    cout << "enter the size of line: ";
    cin >> n;

    ifstream infile("old.txt");
    if (!infile.is_open())
    {
        cout << "error" << endl;
    }

    while (getline(infile, line))
    {
        string word;
        for (int i = 0; i < line.size(); i++)
        {
            char ch = line[i];
            if (punctuation_marks(ch))
            {
                if (!word.empty() && word.size() == n)
                {
                    /*cout << "Line: " << line << "\n";
                    cout << "Word: " << word << "\n";*/
                    words.push_back(word);
                }
                word.clear();
            }
            else
            {
                word += ch;
            }
        }
        if (!word.empty() && word.size() == n)
        {
            cout << "Line: " << line << "\n";
            cout << "Word: " << word << "\n";
            words.push_back(word);
        }
    }

    infile.close();

    ofstream outfile("new.txt");
    if (!outfile.is_open())
    {
        cout << "error2" << endl;
    }

    // Записываем слова в файл в обратном порядке
    for (auto it = words.rbegin(); it != words.rend(); ++it)
    {
        outfile << *it << "\n";
    }

    outfile.close();

    return 0;
}
