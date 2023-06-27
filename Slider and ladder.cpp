#include<iostream>
#include<map>
using namespace std;
int main()
{
  map<int,int> ladders{{17,26},{4,9},{8,28},{7,19}};
  map<int,int>slides{{13,2},{25,14},{29,20}};
int nop;
cin>>nop;
string players_names[nop];
for( auto i = 0 ;i < nop ; i++)
  cin>>players_names[i];
string start_name;
cin>>start_name;
int count_dice_throws;
cin>> count_dice_throws;
int dice_values[count_dice_throws];
for( auto i = 0; i < count_dice_throws ; i++)
cin>>dice_values[i];
string currPlayer=start_name;
int currPlayerPos ;
for( int i = 0 ; i < nop ; i++)
if( players_names[i]==start_name){
  currPlayerPos = i;
  break;
}
int playersCurrentPos[nop]={0};

for( auto i: dice_values){
 
  if( playersCurrentPos[currPlayerPos] == 0)
  {
    if( i == 1){
        playersCurrentPos[currPlayerPos]=1;
    }
    
  }
  else{
      int curr  = playersCurrentPos[currPlayerPos]+i;
      cout<<curr<<endl<<endl;
      if( curr <= 30 ){
        
      if (ladders.find(curr)!=ladders.end())
          curr = ladders.find(curr)->second;
      else if( slides.find(curr) != slides.end())
        curr = slides.find(curr) ->second;
      
      playersCurrentPos[currPlayerPos] = curr;
      cout<<"CURR: "<<curr<<endl;   
      for( int j = 0 ; j < nop ; j++){
        if(j != currPlayerPos &&  curr == j  ){
           playersCurrentPos[j] = 1;
           break;
        }
      }
      } 

  }
  if ( playersCurrentPos[currPlayerPos] ==30)
  {
    cout<<"The winner is"<<players_names[currPlayerPos];
    break;
  }
  if( i!= 1&& i!= 5)
  {
    currPlayerPos = (currPlayerPos+1) % nop;
  }

}




}

/*
cout<<nop<<endl;
for( auto i:players_names)
cout<<i<<" ";
cout<<endl<<start_name<<endl<<count_dice_throws;
for( auto i:dice_values)
cout<<i<<" ";
2
A
B
A
7
1
2
3
4
5
1
2
Sample 2
2
A
B
A
11
2
1
1
1
2
5
1
2
3
2
2

*/
/*
2
A
B
A
11
2->A
1->B
1->B
1->B
2->B -> 28
5->A
1->A
2->a
3->B->31X
2->A
2-B
*/
