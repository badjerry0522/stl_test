// test_list.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<list>
#include<ctime>
#include<set>
#include<map>
#include"show_result.h"
#include<random>
#include<sys/time.h>
#pragma GCC optimize(3,"Ofast","inline")
#define num_query 100000000
using namespace std;
int M = 1024 * 1024 * 1024 / 16;
map<int, int> mp;
default_random_engine e;
int* s;
int* s1;
void generate() {
	e.seed(time(NULL));
	s = (int*)malloc(sizeof(int) * M);
	s1 = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++) {
		s1[i] = e() % M;
		s[i] = e() % M;
	}
}
uint64_t insert() {
	struct timeval St,End;
	gettimeofday(&St,NULL);
	for (int i = 0; i < M; i++) {
		mp[s[i]]=s1[i];
	}
	gettimeofday(&End,NULL);
	return (uint64_t)((End.tv_sec-St.tv_sec)*1000000+End.tv_usec-St.tv_usec);
}
uint64_t query() {
	struct timeval St,End;
	map<int, int>::iterator it;
	int ans;
	e.seed(time(NULL));
	gettimeofday(&St,NULL);
	for (int i = 0; i < num_query; i++) {
		it = mp.find(s[e()%M]);
		//cout << it->second<< endl;
	}
	gettimeofday(&End,NULL);
	return (uint64_t)((End.tv_sec-St.tv_sec)*1000000+End.tv_usec-St.tv_usec);
}
uint64_t vector_sort() {
	clock_t St, End;
	St = clock();
	//l.sort();
	End = clock();
	return (uint64_t)(End - St) / CLOCKS_PER_SEC;
}
int main() {
	while (((double)M / 1024 / 1024 * 4) >= 0.125) {
		cout << (double)M / 1024 / 1024 * 4 << "MB:" << endl;

		uint64_t total_insert = 0;
		uint64_t total_query = 0;
		uint64_t total_sort = 0;
		generate();
		total_insert += insert();
		total_query += query();
		//	total_sort += vector_sort();
		mp.clear();
		map<int,int> empty;
		swap(mp, empty);
		free(s), free(s1);
		double type=4;
		show_result((double)type,(double)total_insert/1000000,
		            (double)total_query/1000000,(double)total_sort/1000000,
					(double)M,(double)num_query);
		M /= 2;
	}
	return 0;
}
