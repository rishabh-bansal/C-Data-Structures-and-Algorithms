/*

Author-Krishan singh karki
Algorithm name-Suffix tree for finding longest common subsequence
this is suffix tree data structure implementation in c++ for finding the 
common subsequence between two strings

*/

/*
HACKTOBERFEST
*/

#include<bits/stdc++.h>
using namespace std;

struct suffix//creating structure name suffix
{
	struct suffix*  m[26];//creating mapping for the 26 small latters alphabet
	int end=0;//0 means not a leaf node  and 1 means it is a leaf node
	
};
struct suffix * BuildSuffixTree(struct suffix * root,string s, int start, int size){
	if(start==size&&root==NULL){//cheking if this is last char of string and that node does not exist already
		struct suffix *temp;
		temp=(struct suffix*)malloc(sizeof(struct suffix));//dynamically allocating memory
		temp->end=1;
		root=temp;
	}
	else if(start==size){//cheking if this is last char of string but node exist already 

	}
	else if(root!=NULL){//cheking for this is not last char in string and node for that char does not exist
		//cout<<s;
		root->end=0;
		root->m[s[start]-'a']=BuildSuffixTree( root->m[s[start]-'a'], s, start+1, size );//recursivly calling child node

	}
	else {// finally cheking for this is not last char but that char node exist already
		struct suffix *temp;
		temp=(struct suffix*)malloc(sizeof(struct suffix));
		temp->end=1;
		root=temp;
		root->m[s[start]-'a']=BuildSuffixTree( root->m[s[start]-'a'], s, start+1, size );

	}
	
	return root;
}
int longestCommonSubstr(struct suffix * root, string s, int start, int len,  int size){
	
	int answer;
	 if(root==NULL){
		return len-1;
	}
	else
	{
		answer=longestCommonSubstr(root->m[s[start]-'a'], s , start+1 , len+1 , size);
	}

	return answer;
}

int main(){
	struct suffix *root = NULL;

	//dynamcally alocating the first root node
	root=(struct suffix*)malloc(sizeof(struct suffix));
	root->end=1;

	string s1;
	cout<<"Enter your first string : ";
	cin>>s1;

	int n=s1.length();
	for(int i=0;i<n;i++)
	root=BuildSuffixTree(root,s1,i,n);

	cout<<endl<<"Enter your second string : ";
	string s2;
	cin>>s2;

	int longestLength=0;//initializing longest length with 0

	for(int i=0;i<s2.length();i++)
	longestLength=max(longestLength, longestCommonSubstr(root, s2 ,i , 0 , s1.length() ) );

	cout<<endl<<"Longest common length present between two string is: "<<longestLength<<endl;


}
