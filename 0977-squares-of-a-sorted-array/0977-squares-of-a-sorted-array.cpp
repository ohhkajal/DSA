class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int n=a.size();
        vector<int> neg;
        vector<int> pos;
        for(int i=0;i<n;i++){
            if(a[i]<0)
            neg.push_back(a[i]);
            else
            pos.push_back(a[i]);

        }
        if(neg.size()==0){
            for(int i=0;i<pos.size();i++)
            pos[i]=pos[i]*pos[i];
            return pos;
        }
        if(pos.size()==0){
            for(int i=0;i<neg.size();i++)
                neg[i]=neg[i]*neg[i];
                reverse(neg.begin(),neg.end());
                return neg;
        }
            int i=0;
            int j=0;
            int id=0;
            int k=neg.size();
            int m=pos.size();
            vector<int> res(k+m);
            for(int i=0;i<k;i++)
            neg[i]=neg[i]*neg[i];
            reverse(neg.begin(),neg.end());
            for(int i =0;i<m;i++)
            pos[i]=pos[i]*pos[i];
            while(i<k && j<m){
                if(neg[i]<=pos[j]){
                    res[id++]=neg[i++];
                    }
                    else{
                        res[id++]=pos[j++];
                
                    }
                }
                while(j<m)
                    res[id++]=pos[j++];
                    
                
                while(i<k)
                    res[id++]=neg[i++];
                    
                
                return res;
            }
     
};