
class Solution {
public:
    static const int MAXN = 205;
    int f[MAXN];
    int getFather(int x){
        if(f[x]!=x)
            f[x] = getFather(f[x]);
        return f[x];
    }
    int findCircleNum(vector<vector<int>>& M) {
        for(int i=0;i<MAXN;++i){
            f[i] = i;
        }
        int n = M.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<=i-1;j++){
                if(M[i][j]){
                    f[getFather(j)] = i;
                }
            }
        }
        set<int>s;
        for(int i=0;i<n;++i){
            s.insert(getFather(i));
        }
        return s.size();
    }
};
