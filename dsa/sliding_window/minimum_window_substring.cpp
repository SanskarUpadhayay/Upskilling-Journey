string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n<m){
            return "";
        }   
        int l=0,r=0;
        int ans=INT_MAX;
        int st=-1,ed=-1;
        unordered_map<char,int> t_freq;
        unordered_map<char,int> s_freq;
        for(int i=0;i<m;i++){
            t_freq[t[i]]++;
            s_freq[s[r]]++;
            r++;
        }
        
        while(r<n){
            s_freq[s[r]]++;
            //verify if we got a substring satisfying the condition
            bool flag = true;
            for(auto x:t_freq){
                if(s_freq[x.first] != x.second){
                    flag=false;
                    break;
                }
            }
            if(flag){
                while(flag){
                    for(auto x:t_freq){
                        if(s_freq[x.first] != x.second){
                            flag=false;
                            break;
                        }
                    }
                    if(ans>(r-l+1)){
                        ans=r-l+1;
                        st=l;
                        ed=r;
                    }
                s_freq[s[l]]--;
                l++;
            }
            r++;
            }
        }
        string res="";
        for(int i=st;i<=ed;i++){
            res.push_back(s[i]);
        }
        return res;
    }

    