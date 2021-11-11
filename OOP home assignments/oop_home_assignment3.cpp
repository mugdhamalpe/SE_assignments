// Name: Mugdha Malpe

//  Home  Assignment  3

/*Write  a  C++  program  to  have  an  array  initialized  with  10  integer  values and  a  array  pointer.  Accept  a  number  from  user  and  traverse  the  array  using the pointer to check whether the number is present in the array.*/

#include  <bits/stdc++.h> 
using  namespace  std;
int main(){
	int  arr[10]  =  {24,  4,  7,  67,  89,  45,  33,  12,  56,  9};
	int  len_arr  =  sizeof(arr)/sizeof(arr[0]); int  number;
	cout<<"Enter  the  number:  "<<endl; cin>>number;
	int  total=0;
	int  *  last_element  =  arr  +  (len_arr-1);

	for  (int  *  ptr  =  arr;  (last_element  -  ptr)  >=  0  ;  ++ptr)
	{
		if(number  ==  *ptr){ total  +=  1;
		}
	}

	if(total != 0){
		cout<<"Yes,  the  entered  number  is  present  in  the  array.";
	}
	else{
		cout<<"Sorry,  the  entered  element  not  found  in  the  array.";
	}
	return  0;
}
