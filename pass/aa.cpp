    #include <iostream>  
    #include <cstdio>  
    #include <cmath>  
    #include <vector>  
    #include <algorithm>  
      
    using namespace std;  
      
    typedef long long lint;  
      
    lint N,K;  
    int P;  
      
    lint lpower(lint n, lint p){  
        if(n == 1) return 1;  
        int factor = n;  
        for(int i = 1; i < p; i++) n *= factor;  
        return n;  
    }  
      
    vector<int> finalFactor;  
    int nowSum = 0;  
      
    bool dfs(lint N, int cur, vector<int>& factors){  
        if(cur == K){  
            if(N == 0){  
                int sum = 0;  
                for(int i = 0; i < factors.size(); i++){  
                    sum += factors[i];  
                }  
                if(sum >= nowSum){  
                    finalFactor = factors;  
                    nowSum = sum;  
                }  
                return true;  
            }else return false;  
        }  
        lint upper = sqrt((double)N);  
        lint lower = cur > 0 ? factors[cur - 1] : 1;  
        for(lint i = lower; i <= upper; i++){  
            lint res = lpower(i,P);  
            if(N >= res){  
                factors[cur] = i;  
                dfs(N-res,cur+1,factors);  
            }else{  
                return false;  
            }  
        }  
        return true;  
    }  
      
    int main()  
    {  
        cin >> N >> K >> P;  
        vector<int> factors(K);  
        dfs(N,0,factors);  
        reverse(finalFactor.begin(),finalFactor.end());  
        if(finalFactor.size() == K){  
            printf("%d = ",N);  
            printf("%d^%d",finalFactor[0],P);  
            for(int i = 1; i < finalFactor.size(); i++){  
                printf(" + %d^%d",finalFactor[i],P);  
            }  
        }else{  
            cout << "Impossible";  
        }  
        cout << endl;  
      
        return 0;  
    }  
