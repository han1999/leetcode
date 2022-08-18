// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1, r=n;
        int ans;
        while (l<=r){
            /*
            不是return ans, 是return l
            用n=5, bad=4举例, 
            l=1, r=5 mid=3 ans=0
            l=4, r=5, 这是左右均是badVersion， 而ans此时是0
            */
            cout<<"l: "<<l<<" r:"<<r<<endl;
            if (isBadVersion(l) && isBadVersion(r)) return l;
            int mid=l+(r-l)/2;
            if (isBadVersion(mid)){
                ans=mid;
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
        return ans;
    }
};
