
#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;

void sort(int *p, int s){
    int t;
    for(int k = s-1; k > 1; k--){
        for(int i = 0; i < k; i++){
            if(p[i] >= p[i+1]){
                t = p[i];
                p[i] = p[i+1];
                p[i+1] = t;
            }
        }
    }
}



int main(){
    //int d[] = {1, 3, 2, 9, 21, 12, 9, 1, 8, 4, 5, 7, 11}; /// 13

    srand( (unsigned)time(NULL));

    const int max = 20;

    int d[max];
    int l[max];
    int c[max];

    int no1, no2, no3;

    for(int s = 0; s < max; s++){
        no1 = rand() % 100;
        no2 = rand() % 100;
        no3 = rand() % 100;
        d[s] = no1;
        l[s] = no2;
        c[s] = no3;
    }

    int num = rand()%100;


    cout << num << endl;

    sort(d, max);
    sort(l, max);
    sort(c, max);

    for(int i = 0; i < max; i++){
        cout << d[i] << ' ';
    }

    cout << endl;

    for(int i = 0; i < max; i++){
        cout << l[i] << ' ';
    }

    cout << endl;

    for(int i = 0; i < max; i++){
        cout << c[i] << ' ';
    }

    cout << endl;

    auto start = std::chrono::high_resolution_clock::now();


    for(int i = 0; i < 1000; i++){

        int x = 0;
        int y = 0;
        int z = 0;

        while(x < max && y < max && z < max){
            if(d[x] < l[y]){
                x++;
            } else if(l[y] < c[z]){
                y++;
            } else if(c[z] < d[x]){
                z++;
            } else {
                break;
            }
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);

    cout << duration.count() << endl;

    /// start of the mess

      auto start1 = std::chrono::high_resolution_clock::now();
    
    for(int i = 0; i < 1000; i++){

    int x = 0;
    int y = 0;
    int z = 0;

    while(x < max && y < max && z < max){
        if(d[x] < l[y]){
            x++;
        } else if(d[x] > l[y]){
            y++;
        } else{
            while(c[z] < d[x] && z < max){
                z++;
            }
            if(c[z] == d[x]){
                break;
            } else {
                x++;
                y++;
            }
        }

    }
    }

    auto stop1 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1-start1);

    cout << duration1.count() << endl;
   
   
}