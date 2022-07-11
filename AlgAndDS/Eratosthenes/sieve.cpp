#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);

  int stockPrice[1000000];
  int T_n, D_n;
  cin>>T_n;

  long long profitSum=0;
  int maxStock=0;

  for(int i = 0; i<T_n ; ++i){
    cin>>D_n;
    for(int day=0; day< D_n; ++day)
      cin>>stockPrice[day];
    
    profitSum=0;
    maxStock=0;
    for(int day=D_n -1 ; day>=0 ; --day){
      if(stockPrice[day] < maxStock)
        profitSum += (maxStock - stockPrice[day]);
      else
        maxStock = stockPrice[day];
    }
    cout<<profitSum<<endl;
  }

  return 0;
}