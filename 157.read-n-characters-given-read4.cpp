// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int index = 0;
        char t[5];
        int flag = 1;
        while(n>0){
            int cnt = read4(t);
            if(!cnt)
                break;
            if(n<cnt){
                cnt = n;
                n = -1;
            }
            else{
                n-=cnt;
            }
            for(int i=0;i<cnt;++i){
                buf[index++] = t[i];
            }
        }
        buf[index]='\0';
        //cout<<index-1<<endl;
        return index;
    }
};
