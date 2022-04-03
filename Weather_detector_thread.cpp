#include<iostream>
#include<string>
#include<thread>
#include<map>
using namespace std;

/*

Lets say my application is depending on third party api of weather.
Unfortunately sometimes that API takes long time to give response which results in degrading user experince.
So here I can create one thread which will fetch data from that API and store it in local storage.
This thread is independent on other threads and run simulateneously.
It will help to display data fastly without any degrading user experience.

Here I don't have any API that will fetch data for me so I have created some dummy data of
temperatures that will keep increasing .
*/

void function1(map<string,int> forecastMap){
    for(int i=0;i<100;i++){
        for(auto &item:forecastMap){
            item.second++;
            cout<<item.first <<" - "<<item.second<<endl;
        }
        cout<<endl;
        this_thread::sleep_for(1000ms);
    }
}
int main(){

    map<string,int> forecastMap = {
        {"Pune",35},
        {"Mumbai",33},
        {"Sydney",21}
    };

    thread t1(function1,forecastMap);
    t1.join();
}