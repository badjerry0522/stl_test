// test_vector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<set>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<random>
#include<sys/time.h>
#include"show_result.h"
#pragma GCC optimize(3,"Ofast","inline")
#define num_query 100000000
using namespace std;
uint64_t M = 1024 * 1024 * 1024 / 16;
set<int> q;
default_random_engine e;
int* s;
void generate() {
	e.seed(time(NULL));
	s = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++) s[i] = e() % M;
}
uint64_t insert() {
	struct timeval St,End;
	gettimeofday(&St,NULL);
	for (int i = 0; i < M; i++) q.insert(s[i]);
	gettimeofday(&End,NULL);
	return (uint64_t)((End.tv_sec-St.tv_sec)*1000000+End.tv_usec-St.tv_usec);
}
uint64_t query() {
	struct timeval St,End;
	int ans;
	e.seed(time(NULL));
	set<int>::iterator it;
	gettimeofday(&St,NULL);
	for (int i = 0; i < M; i++) it = q.find(s[e()%M]);
	gettimeofday(&End,NULL);
	return (uint64_t)((End.tv_sec-St.tv_sec)*1000000+End.tv_usec-St.tv_usec);
}
uint64_t vector_sort() {
	clock_t St=0, End=0;
	//St = clock();
	//sort(q.begin(), q.end());
	//End = clock();
	//vector<int>::iterator it;
	//for (it=q.begin(); it!=q.end(); it++) cout << *it << endl;
	//cout << q[1] << endl;
	return (uint64_t)(End - St);
}
int main()
{
	while (((double)M / 1024 / 1024 * 4) >= 0.125) {
		cout << (double)M / 1024 / 1024 * 4 << "MB:" << endl;

		uint64_t total_insert = 0;
		uint64_t total_query = 0;
		uint64_t total_sort = 0;
		generate();
		cout << "generate complete" << endl;
		total_insert += insert();
		total_query += query();
		//	total_sort += vector_sort();
		q.clear();
		set<int> empty;
		swap(q, empty);
		cout<<"total_insert="<<total_insert<<" "<<"total_query="<<total_query<<" "<<"total_sort="<<total_sort<<endl;

		double type=2;//set stands for 2
		show_result((double)type,(double)total_insert/1000000,
		            (double)total_query/1000000,(double)total_sort/1000000,
					(double)M,(double)num_query);
		M /= 2;
	}
	return 0;
}
