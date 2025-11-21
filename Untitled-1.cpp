#include<bits/stdc++.h>
using namespace std;
class Segment Tree{
	private:
	vector<int>Segtree;
	public:
	SegmentTree(int n)
	{
		SegTree.resize(4*n);
	}
	void BuildSegTree(int Index,int start,int end,vector<int>&A)
	{
		if(start==end)
		{
			SegTree[Index] = A[start];
		}
		int mid = (start + end) / 2;
		BuildSegTree(2*Index + 1,start,mid,A);
		BuildSegTree(2*Index + 2,mid+1,end,A);
		
		SegTree[Index] = SegTree[2*Index + 1] + SegTree[2*Index + 2];


	}
};
int RangeSum(int Q1,int Q2,int Index,int start,int end,vector<int>&SegTree)
{
	if(Q1 <= start && Q2 >= end)
	{
		return SegTree[Index];
	}
	if(Q1 > end || Q2 < start)
	{
		return 0;
	}
	int mid = (start + end) / 2;
	int left = RangeSum(Q1,Q2,2*Index + 1,start,mid,SegTree);
	int right = RangeSum(Q1,Q2,2*Index + 2,mid+1,end,SegTree);
	return left+ right;
}
