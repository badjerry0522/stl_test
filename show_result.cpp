#include "show_result.h"
#include<iostream>
#include<iomanip>
using namespace std;
void show_result(double type,double total_insert,double total_query,double total_sort,double M,double num_query){
    if(type==0){ //vector
        //cout<<fixed<<setprecision(4);
        cout<<"vector"<<endl;
        cout<<setprecision(10);
		cout <<"insert:  "<< (total_insert) << "    "<< (total_insert) / M << "    "  << M / (total_insert) << "    ";
		//cout <<  total_query << "    " <<setiosflags(ios::left)<< total_query / num_query << "    " << num_query / total_query << "    " << endl;
		cout <<"sort:    "<< (total_sort) << "    " << (total_sort) / M << "    " << M / (total_sort) << "    " << endl;
    }
    else if(type==1){//queue
        cout<<"queue"<<endl;
        cout<<fixed<<setprecision(4);
		cout <<"insert:  "<< (total_insert) << "    "<< (total_insert) / M << "    "  << M / (total_insert) << "    ";
		//cout <<  total_query << "    " <<setiosflags(ios::left)<< total_query / num_query << "    " << num_query / total_query << "    " << endl;
		cout <<"sort:    "<< (total_sort) << "    " << (total_sort) / M << "    " << M / (total_sort) << "    " << endl;
    }
    else if(type==2){//set
        cout<<"set"<<endl;
        cout<<fixed<<setprecision(4);
		cout <<"insert:  "<< (total_insert) << "    "<< (total_insert) / M << "    "  << M / (total_insert) << "    ";
		cout <<  total_query << "    " <<setiosflags(ios::left)<< total_query / num_query << "    " << num_query / total_query << "    " << endl;
		//cout <<"sort:    "<< (total_sort) << "    " << (total_sort) / M << "    " << M / (total_sort) << "    " << endl;
    }
    else if(type==3){//list
        cout<<"list"<<endl;
        cout<<fixed<<setprecision(4);
		cout <<"insert:  "<< (total_insert) << "    "<< (total_insert) / M << "    "  << M / (total_insert) << "    ";
		//cout <<  total_query << "    " <<setiosflags(ios::left)<< total_query / num_query << "    " << num_query / total_query << "    " << endl;
		cout <<"sort:    "<< (total_sort) << "    " << (total_sort) / M << "    " << M / (total_sort) << "    " << endl;
    }
    else if(type==4){//map
        cout<<"map"<<endl;
        cout<<fixed<<setprecision(4);
		cout <<"insert:  "<< (total_insert) << "    "<< (total_insert) / M << "    "  << M / (total_insert) << "    ";
		cout <<  total_query << "    " <<setiosflags(ios::left)<< total_query / num_query << "    " << num_query / total_query << "    " << endl;
		//cout <<"sort:    "<< (total_sort) << "    " << (total_sort) / M << "    " << M / (total_sort) << "    " << endl;
    }
}