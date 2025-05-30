#include <iostream>
#include <vector>
using namespace std;

int main() { 
  int n;
  int c;
  cin>>n;
  vector<int> a(n);
  cin>>c;
  for (int i=0; i<n; i++)
  {
    cin>>a[i];
  }
  int left = 0;
  int right = n-1;
  while(left!=right)
  {
    if (a[left]+a[right]<c) {left+=1; continue;}
    if (a[left]+a[right]>c) {right-=1; continue;}
    if (a[left]+a[right]==c) {cout<<a[left]<<" "<<a[right]<<'\n'; break;}
  }
  cin.get();
  return 0; }
