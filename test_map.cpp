// test_list.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<list>
#include<ctime>
#include<set>
#include<map>
#include<random>#pragma GCC optimize(3,"Ofast","inline")
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
double insert() {
	cout << "insert begin" << endl;
	clock_t St, End;
	//cout << s[0] << endl;
	St = clock();
	for (int i = 0; i < M; i++) {
		mp[s[i]]=s1[i];
	}
	End = clock();
	//cout << q[1] << endl;
	return (double)(End - St) / CLOCKS_PER_SEC;
}
double query() {
	cout << "query begin" << endl;
	clock_t St, End;
	map<int, int>::iterator it;
	int ans;
	e.seed(time(NULL));
	St = clock();
	for (int i = 0; i < num_query; i++) {
		it = mp.find(s[e()%M]);
		//cout << it->second<< endl;
	}
	End = clock();
	return (double)(End - St) / CLOCKS_PER_SEC;
}
double vector_sort() {
	clock_t St, End;
	St = clock();
	//l.sort();
	End = clock();
	return (double)(End - St) / CLOCKS_PER_SEC;
}
int main() {
	while (((double)M / 1024 / 1024 * 4) >= 0.125) {
		cout << (double)M / 1024 / 1024 * 4 << "MB:" << endl;

		double total_insert = 0;
		double total_query = 0;
		double total_sort = 0;
		for (int i = 0; i < 5; i++) {
			generate();
			total_insert += insert();
			total_query += query();
			//	total_sort += vector_sort();
			mp.clear();
			map<int,int> empty;
			swap(mp, empty);
			free(s), free(s1);
		}
		cout << "insert total time:" << total_insert / 5 << "s   " << total_insert / 5 / M << "sec per insert" << "   " << M / total_insert / 5 << "insert per sec" << endl;
		cout << "query total time:" << total_query / 5 << "s   " << total_query / 5 / num_query << "sec per query   " << num_query / total_query / 5 << "query per sec" << endl;
		//cout << "sort total time:" << total_sort / 5 << "s   " << total_sort / 5 / M << "sec per sort   " << M / total_sort / 5 << "sort per sec" << endl;

		M /= 2;
	}
	return 0;
}
