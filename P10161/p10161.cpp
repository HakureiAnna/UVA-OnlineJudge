#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data {
	int n;
	int id;
	int x;
	int y;
};

bool compareId(Data a, Data b) {
	return a.id < b.id;
}

bool compareN(Data a, Data b) {
	return a.n < b.n;
}

void printList(vector<Data> *db) {
	vector<Data>::iterator itor;
	for (itor = db->begin(); itor != db->end(); ++itor) {
		/*
		cout << itor->n << ", " << itor->id << ", "
			<< itor->x << ", " << itor->y << endl;
		*/
		cout << itor->x << ' ' << itor->y << endl;
	}
}

int main() {
	int x = 1, y = 1,
		next_y = 2, next_x = 1,
		state = 0,
		k = 1, n,
		id = 0,
		diff;
	Data data;
	data.x = 0;
	data.y = 0;
	vector<Data> db;
	
	while (1) {
		cin >> n;
		if (!n)
			break;
		data.id = id;
		data.n = n;	
		db.push_back(data);
		++id;				
	}
	sort(db.begin(), db.end(), compareN);
	
	x = 1;
	y = 1;
	next_y = 2;
	next_x = 1;
	k = 1;
	state = 0;
	id = 0;
	n = db.size();
		
	while (id < n) {
		/*
		if (k == db[id].n) {
			db[id].x = x;
			db[id].y = y;
			++id;
			if (id == n) 
				break;
		}
		*/
		switch (state) {
		case 0:
			/*
			++y;
			++k;
			if (y == next_y) {
				++state;
				++next_x;
			}
			*/
			diff = next_y - y;
			if (k + diff >= db[id].n) {
				diff = db[id].n - k;
				y += diff;
				db[id].y = y;
				db[id].x = x;
				++id;
				k += diff;
			} else {
				y = next_y;
				++next_x;
				k += diff;
				++state;
			}
			break;
		case 1:
			/*
			++x;
			++k;
			if (x == next_x) {
				++state;
			}
			*/
			diff = next_x - x;
			if (k + diff >= db[id].n) {
				diff = db[id].n - k;
				db[id].y = y;
				x += diff;
				db[id].x = x;
				++id;
				k += diff;
			} else {
				x = next_x;
				k += diff;
				++state;
			}
			break;
		case 2:
			/*
			--y;
			++k;
			if (y == 1) {
				next_x++;
				++state;
			}
			*/
			diff = y - 1;
			if (k + diff >= db[id].n) {
				diff = db[id].n - k;
				y -= diff;
				db[id].y = y;
				db[id].x = x;
				++id;
				k += diff;
			} else {
				y = 1;
				++next_x;
				k += diff;
				++state;
			}
			break;
		case 3:
			/*
			++x;	
			++k;		
			if (x == next_x) {
				++next_y;
				++state;
			}
			*/
			diff = next_x - x;
			if (k + diff >= db[id].n) {
				diff = db[id].n - k;
				db[id].y = y;
				x += diff;
				db[id].x = x;
				++id;
				k += diff;
			} else {
				x = next_x;
				k += diff;
				++next_y;
				++state;
			}
			break;
		case 4:
			/*
			++y;
			++k;
			if (y == next_y) {
			 ++state;
			}
			*/			
			diff = next_y - y;
			if (k + diff >= db[id].n) {
				diff = db[id].n - k;
				y += diff;
				db[id].y = y;
				db[id].x = x;
				++id;
				k += diff;
			} else {
				y = next_y;
				k += diff;
				++state;
			}
			break;
		case 5:
			/*
			--x;
			++k;
			if (x == 1) {
				state = 0;
				++next_y;
			}
			*/			
			diff = x - 1;
			if (k + diff >= db[id].n) {
				diff = db[id].n - k;
				x -= diff;
				db[id].y = y;
				db[id].x = x;
				++id;
				k += diff;
			} else {
				x = 1;
				++next_y;
				k += diff;
				state = 0;
			}
			break;
		}
		//++k;
	}
	
	sort(db.begin(), db.end(), compareId);
	printList(&db);
	return 0;
}