#include<iostream>
#include<cstdlib>
using namespace std;

int main(int argc,char *argv[]){
    int sum=0;
    double avg=0;

    if(argc<=1){
        cout << "Please input numbers to find average.";
    }else {
        for(int i=1;i<argc;i++){ // atoi(argv[0]) = 0 so i = 0 works too!
        sum += atoi(argv[i]); 
        }
    avg = sum/(argc-1);
    cout << "---------------------------------" << endl;
    cout << "Average of " << argc-1 << " numbers = " << avg << endl;
    cout << "---------------------------------" << endl;
    }
    return 0;
}
