//Packet Collision

//A network user attempted to send multiple data packets with frame size 'k' at the same time. Due to a network fault, all packets in each frame with a higher sequence number crashed. To resend the packet, the sender must now find the maximum sequence number data packet in each frame with size 'k'.

#include <iostream>
#include <deque>

using namespace std;

void printKMax(int arr[], int n, int k) {
    deque<int> q;
    for(int i=0;i<=n-k;i++) {
        int max =arr[i];
        
        for(int j=1; j<k;j++) {
            if(arr[i+j] > max) 
            max =arr[i+j];
        }
        cout << max << " ";
    }
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i=0;i<n;i++) 
    cin >> arr[i];
    
    int k;
    cin >>k;
    
    printKMax(arr,n,k);
    
    return 0 ;
}