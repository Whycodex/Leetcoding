class Solution {
public:
    string pushDominoes(string dominoes) {
        int r=-1;
        for(int i=0;i<dominoes.length();i++){
            if(dominoes[i]=='L'){
                if(r==-1){
                    for(int j=i-1;j>=0&&dominoes[j]=='.';j--){
                        dominoes[j]='L';
                    }
                }
                else{
                    for(int j=r+1,k=i-1;j<k;j++,k--){
                        dominoes[j]='R';
                        dominoes[k]='L';
                    }
                    r=-1;
                }
            }
            else if(dominoes[i]=='R'){
                if(r!=-1){
                    for(int j=r+1;j<i;j++){
                        dominoes[j]='R';
                    }
                }
                r=i;
            }
        }
        if(r!=-1){
            for(int j=r+1;j<dominoes.length();j++){
                dominoes[j]='R';
            }
        }
        return dominoes;
    }
};