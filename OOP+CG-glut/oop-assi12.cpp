#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){

    typedef map<string,int> mapType;
    mapType popMap;

    popMap.insert(pair<string, int>("Maharashtra", 7026357));
    popMap.insert(pair<string, int>("Rajasthan", 6578936));
    popMap.insert(pair<string, int>("Karanataka", 6678993));
    popMap.insert(pair<string, int>("Goa", 589032));
    popMap.insert(pair<string, int>("West Bengal", 6676291));

    mapType::iterator iter;

    cout<<"*****Population of states in India*****\n";
    cout<<"\n Size of population map is: "<<popMap.size()<<"\n";
    string state_name;
    cout<<"\n Enter name of the state :";
    cin>>state_name;

    iter = popMap.find(state_name);
    if( iter!= popMap.end() ){
        cout<<state_name<<"'s population is "
        <<iter->second ;
    }else{
        cout<<"Key is not population map"<<"\n";
        popMap.clear();
    }

    return 0;
}
