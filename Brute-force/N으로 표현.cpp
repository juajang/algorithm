#include <string>
#include <vector>

using namespace std;

int ans = 8;

void calc(int N, int number, int now, int cnt){
    if(cnt>8 || cnt>ans) return;
    if(now == number) {
        if(cnt < ans) ans = cnt;
        return;
    }
    int n = N;
    for(int i=0; i<8-cnt; i++){
        n = n + 10*i*N;
        if(n) calc(N, number, now/n, cnt+i+1);
        if(now) calc(N, number, n/now, cnt+i+1);
        calc(N, number, now*n, cnt+i+1);
        calc(N, number, now+n, cnt+i+1);
        calc(N, number, n - now, cnt+i+1);
        calc(N, number, now-n, cnt+i+1);
    }
}

int solution(int N, int number) {
    calc(N, number, 0, 0);
    return ans > 8 ? -1 : ans;
}