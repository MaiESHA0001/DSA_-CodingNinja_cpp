/*
Problem statement
Print the following pattern for the given N number of rows.

Pattern for N = 4
4444
4444
4444
4444
Detailed explanation ( Input/output format, Notes, Images )
Constraints
0 <= N <= 50
Sample Input 1:
7
Sample Output 1:
7777777
7777777
7777777
7777777
7777777
7777777
7777777
Sample Input 1:
6
Sample Output 1:
666666
666666
666666
666666
666666
666666
#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
  int n;

*/

#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
  int n;
  cin>>n;
  int i=1;
  while(i<=n)
  {
	  int j=1;
	  while(j<=n)
	  {
		  cout<<n;
		  j++;
	  }
	  cout<<endl;
	  i++;
  }
}

