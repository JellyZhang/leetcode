class Solution {
public:
    bool isnum(string s,bool canbeempty,bool cannegative){
        if(s.size()==0) return canbeempty;
        for(int i=0;i<s.size();i++){
            if( i==0 && s[i]=='-'){
                if(s.size() >=2 && cannegative)continue;
                else return false;
            }
            if(s[i]<'0'||s[i]>'9')return false;
        }
        return true;
    }
    bool isNumber(string s) {
        if(s.size()==0)return false;
        int i,start=-1,indexofp=-1,indexofe=-1,last=-1;
        bool flag=true;
        for(i=0;i<s.size();i++){
            if(s[i]==' '){
                if(flag==false){
                    int k=i;
                    while(k<s.size()){
                        if(s[k]!=' ')return false;
                        k++;
                    }
                }
                else continue;
            }
            if(flag){
                flag=false;
                start=i;
            }
            if(s[i]=='.'){
                if(indexofp!=-1)return false;
                indexofp=i;
            }
            else if(s[i]=='e'||s[i]=='E'){
                if(indexofe!=-1)return false;
                indexofe=i;
            }
            if(s[i]!=' ')last=i;
        }
        //cout<<start<<" "<<indexofp<<" "<<indexofe<<" "<<last<<endl;
        if(start == -1) return false;

        if(indexofp == -1 && indexofe == -1){
            
            return isnum(s.substr(start,last-start+1),false,true);
        }
        else if(indexofp == -1){
            return isnum(s.substr(start,indexofe-start),false,true) && isnum(s.substr(indexofe+1,last-indexofe),false,true);
        }
        else if(indexofe == -1){
            if(last-start==0)return false;
            //cout<<isnum(s.substr(start,indexofp-start),true)<<endl;
            //cout<<isnum(s.substr(indexofp+1,last-indexofp),true)<<endl;
            return isnum(s.substr(start,indexofp-start),true,true) && isnum(s.substr(indexofp+1,last-indexofp),true,false);
        }
        else {
            if(indexofe < indexofp)return false;
            if(indexofp-start + indexofe-indexofp -1 ==0)return false;
            return isnum(s.substr(start,indexofp-start),true,true)
                && isnum(s.substr(indexofp+1,indexofe-indexofp-1),true,false)
                && isnum(s.substr(indexofe+1,last-indexofe),false,true);
        }

    }
};
