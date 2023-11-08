#include <bits/stdc++.h>

 using namespace std;


 int main()
 {
     string s1, s2;
     getline(cin, s1);
     getline(cin, s2);
     map <char, char> symb;
     vector <char> getter;
     for(int i=0; i<s1.length(); i++)
     {
         char c = s1[i];
         char d = s2[i];
         if(c != d && find(getter.begin(), getter.end(), c) == getter.end() && find(getter.begin(), getter.end(), d) == getter.end())
         {

             getter.push_back(c);
             symb[c] = d;
         }
         for(int j=0; j<s2.length(); j++)
         {
             if(s1[j] == c && s2[j] == d)
                 continue;
             else if(s1[j] == c || s2[j] == d)
             {
                 cout << -1;
                 return 0;
             }
         }
     }
     cout << getter.size()  << endl;
     for(auto v : getter)
     {
         cout << v << ' ' << symb[v] << endl;
     }
 }