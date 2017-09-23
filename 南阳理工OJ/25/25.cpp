#include<map>
#include<string>
#include<iostream>
using namespace std;

map<string,string> dict;

void init()
{
    dict["A#"] = "Bb";
    dict["Bb"] = "A#";
    dict["C#"] = "Db";
    dict["Db"] = "C#";
    dict["D#"] = "Eb";
    dict["Eb"] = "D#";
    dict["F#"] = "Gb";
    dict["Gb"] = "F#";
    dict["G#"] = "Ab";
    dict["Ab"] = "G#";
}

int main()
{
    init();
    int T = 1;
    string s1,s2;
    while(cin >> s1 >> s2)
    {
        cout << "Case " << T++ << ": ";
        if(dict.count(s1) == 0) cout << "UNIQUE\n";
        else cout << dict[s1] << " " << s2 << endl;
    }
    return 0;
}
