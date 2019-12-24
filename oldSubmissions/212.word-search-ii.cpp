class Trie{
public:
    vector<Trie*>nxt;
    bool isend;
    Trie(){
        nxt.assign(26,NULL);
        isend = false;
    }
    void insert(const string& word){
        Trie* p = this;
        for(const char &ch:word){
            if(!p->nxt[ch-'a']){
                p->nxt[ch-'a'] = new Trie();
            }
            p = p->nxt[ch-'a'];
        }
        p->isend = true;
    }
};
class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int m;
    int n;
    Trie* trie;
    void dfs(vector<vector<char>>& board,int x,int y,set<string>&ans,string& selected,Trie* p,vector<vector<int>>&visited){
        if(p->isend){
            ans.insert(selected);
        }
        for(int i=0;i<4;++i){
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(0<=tx && tx<m && 0<=ty && ty<n && !visited[tx][ty] &&p->nxt[board[tx][ty]-'a']){
                selected.push_back(board[tx][ty]);
                visited[tx][ty]=1;
                //cout<<"move to "<<board[tx][ty]<<endl;
                dfs(board,tx,ty,ans,selected,p->nxt[board[tx][ty]-'a'],visited);
                selected.pop_back();
                visited[tx][ty]=0;
            }
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        if(!m)
            return {};
        n = board[0].size();
        if(!n)
            return {};
        set<string> ans;
        trie = new Trie();
        for(string& word:words){
            trie->insert(word);
        }
        string selected;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                Trie* p = trie;
                if(p->nxt[board[i][j]-'a']){
                    //cout<<"start at "<<board[i][j]<<endl;
                    p = p->nxt[board[i][j]-'a'];
                    selected.push_back(board[i][j]);
                    visited[i][j]=1;
                    dfs(board,i,j,ans,selected,p,visited);
                    visited[i][j]=0;
                    selected.pop_back();
                }
            }
        }
        vector<string>res(ans.begin(),ans.end());
        return res;
    }
};
