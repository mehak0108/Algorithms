//Search in rotated sorted array Leetcode

class Solution {
public:
    int search(vector<int>& A, int k) {
        
        int n = A.size();
        int lo = 0, hi = n-1;
        
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if(A[mid]==k) return mid;
            else if(A[mid]>=A[lo])
            {
                if(A[mid]>=k && A[lo]<=k) hi = mid-1;
                else lo = mid+1;
            }
            else
            {
                if(A[mid]<=k && A[hi]>=k) lo = mid+1;
                else hi = mid-1;
            }
        }
        
        return -1;
    }
};