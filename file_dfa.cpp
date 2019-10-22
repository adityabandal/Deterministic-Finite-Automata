#include <bits/stdc++.h>
using namespace std;
void print_matrix(vector<vector<int>> v,int row,int col)
{
	cout<<"Number of rows"<<v.size()<<endl;
	int i,j;
	for (i = 0; i < row; ++i)
	{
		cout<<"size of row"<<v[i].size()<<endl;
		for (j = 0; j < col; ++j)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool accepts(vector<vector<int>> v,vector<char> sym,int row,int col,string str)
{
	int l,i,j,found,k,curr_state=0;
	l=str.length();
	for (i = 0; i < l; ++i)
	{
		j=0;
		found=0;
		while(j<col && !found)
		{
			if(sym[j]==str.at(i))
			{
				found=1;
			}
			else
			{
				j++;
			}
		}
		if(j==col)
		{
			return 0;
		}
		else{
			curr_state=v[curr_state][j];
			if(curr_state==-1)
			{
				return 0;
			}
		}
	}
	if(curr_state==row-1)
	{
		return 1;
	}
	else{
		return 0;
	}
}
int main()
{
	int num_states,num_sym,i,j,x;
	vector<char> sym;
	char ch;
	ifstream infile;
	infile.open("input.txt");
	// cout<<"Enter number of symbols: ";
	infile>>num_sym;
	// cout<<"Enter number of states: ";
	infile>>num_states;
	vector<vector<int>> dfa(num_states);
	// cout<<"Enter "<<num_sym<<" symbols for the DFA: "<<endl;
	for (i = 0; i < num_sym; ++i)
	{
		infile>>ch;
		sym.push_back(ch);
	}
	// cout<<"Enter DFA matrix: "<<endl;
	for(i=0;i<num_states;i++)
	{
		// cout<<"From q"<<i<<": "<<endl;
		for (j = 0; j < num_sym; ++j)
		{
			// cout<<"\tOn "<<sym[j]<<": ";
			infile>>x;
			dfa[i].push_back(x);
		}
	}
	//print_matrix(dfa,num_states,num_sym);
	infile.close();
	int choice,stop=0;
	string str;
	while(!stop)
	{
		cout<<"1.check string \n2.stop\nEnter choice: ";
		cin>>choice;
		if(choice==1)
		{
			cout<<"Enter a string: ";
			cin>>str;
			x=accepts(dfa,sym,num_states,num_sym,str);
			if (x==1)
			{
				cout<<"Accepted"<<endl;
			}
			else{
				cout<<"Not accepted"<<endl;
			}
		}
		else{
			stop=1;
		}
	}
	

	return 0;
}