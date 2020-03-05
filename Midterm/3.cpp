#include <iostream>

using namespace std;

int main(){
    int n, k, minNumber;
    cin >> n >> k;
    int someArr[n];
    minNumber = n;
    for(int i=0; i<n; i++){
        cin >> someArr[i];
    }
    for(int i=n-1; i>=0; i--){ //i-index of the end
        for(int j=0; j<n; j++){ //j-index of the beginning
            int sumOfElements = 0;
            for(int m=j; m<=i; m++){ //m-current index
            sumOfElements += someArr[m];
            if (sumOfElements>=k && m-j<minNumber) minNumber = m-j+1;
            }
        }
    }

    cout << minNumber;
    return 0;
}
