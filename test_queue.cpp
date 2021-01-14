// test_vector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<random>
#include<sys/time.h>
#include<queue>
#include "show_result.h"
#pragma GCC optimize(3,"Ofast","inline")
#define num_query 100000000
using namespace std;
int M = 1024 * 1024 * 1024 / 8;
queue<int> q;
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
	for (int i = 0; i < M; i++) q.push(s[i]);
	gettimeofday(&End,NULL);
	return (uint64_t)((End.tv_sec-St.tv_sec)*1000000+End.tv_usec-St.tv_usec);
}
uint64_t query() {
	struct timeval St,End;
	int* s1 = (int*)malloc(sizeof(int) * num_query);
	srand(time(NULL));
	for (int i = 0; i < num_query; i++) {
		s1[i] = rand() % M;
		//	cout << s1[i] << endl;
	}
	int ans;
	gettimeofday(&St,NULL);
	//for (int i = 0; i < M; i++) ans = q[s1[i]];
	gettimeofday(&End,NULL);
	return (uint64_t)((End.tv_sec-St.tv_sec)*1000000+End.tv_usec-St.tv_usec);
}
uint64_t vector_sort() {
	clock_t St, End;
	St = clock();
	//sort(q.begin(), q.end());
	End = clock();
	//vector<int>::iterator it;
	//for (it=q.begin(); it!=q.end(); it++) cout << *it << endl;
	//cout << q[1] << endl;
	return (double)(End - St) / CLOCKS_PER_SEC;
}
int main(int argc,char *argv[])	
{
	//M = atoi(argv[1]);
	while (((double)M / 1024 / 1024 * 4) >= 0.125) {
		cout << (double)M / 1024 / 1024 * 4 << "MB:" << endl;

		uint64_t total_insert = 0;
		uint64_t total_query = 0;
		uint64_t total_sort = 0;
		generate();
		total_insert += insert();
		//	total_query += query();
		//	total_sort += vector_sort();
		queue<int> empty;
		swap(empty, q);
		cout<<"total_insert="<<total_insert<<" "<<"total_query="<<total_query<<" "<<"total_sort="<<total_sort<<endl;
		double type=1;//queue stands for 1
		show_result((double)type,(double)total_insert/1000000,
		            (double)total_query/1000000,(double)total_sort/1000000,
					(double)M,(double)num_query);
		M /= 2;
	}
	return 0;
}
