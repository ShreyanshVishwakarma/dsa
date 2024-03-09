#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  map<int, int> mp;

  int array[n];
  for (size_t i = 0; i < n; i++)
  {
    cin >> array[i];
    mp[array[i]]++;
  }
  int q;
//  cout<<"How many numbers do you want to know its frequency of ?"<<endl;
//  cin>>q;
//  while (q--)
//  {
//   cin>>n;
//   cout<<"frequency of "<<n<<"is"<<mp[n];
//  }
for(auto it : mp){
  cout<<"frequency of "<<it.first<<" is "<<it.second<<endl;
}
 
  return 0;
}