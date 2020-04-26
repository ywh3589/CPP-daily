#include <iostream>
#include <list>
#include <string>

using namespace std;

class HashTable{
private:
	static const int HashGroup = 10;
	list<pair<int, string>> table[HashGroup];
public:
	bool isEmpty() const;
	int hashNum(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	//int getHashNumber(int key);
	void printTable();
};

bool HashTable::isEmpty() const{

	int sum = 0;
	for(int i = 0; i < HashGroup; i++){
		sum += table[i].size();
	}

	if(sum == 0)
		return true;
	
	return false;
}

int HashTable::hashNum(int key){
	int result = key % HashGroup;
	return result;
}

void HashTable::insertItem(int key, string name){

	int num = hashNum(key);
	
	auto& cell = table[num];
	auto bItr = begin(cell);
	bool keyExists = false;

	for(;bItr!=end(cell); bItr++){
		if(bItr->first == key){
			keyExists = true;
			bItr->second = name;
			cout << "already existing" << endl;
			break;
		}
	}

	if(!keyExists)
		cell.emplace_back(key, name);


	return ; 
}
 
void HashTable::removeItem(int key){
	int num = hashNum(key);
	
	auto& cell = table[num];
	auto bItr = begin(cell);
	bool keyExists = false;

	for(; bItr!=end(cell); bItr++){
		if(key==bItr->first){
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "pair removed" << endl;
			break;
		}
	}

	if(!keyExists){
		cout << "key not found" << endl;
	}

	return;
}

void HashTable::printTable(){

	for(int i{}; i< HashGroup; i++){
		if(table[i].size() == 0) continue;

		auto bItr = table[i].begin();
		for(; bItr!=table[i].end(); bItr++){
			cout << "[INFO] Key: " << bItr->first << "value: " << bItr->second << endl;
		}
	}

	return;
}



int main(){

	HashTable HT;

	if(HT.isEmpty()){
		cout << "Correct answer, good job.";
	} else {
		cout << "Oh oh we need to check out code" << endl;
	}

	HT.insertItem(905, "Jim");
	HT.insertItem(201, "Tom");
	HT.insertItem(332, "Bob");
	HT.insertItem(124, "Sally");
	HT.insertItem(107, "Sandy");
	HT.insertItem(929, "Barb");
	HT.insertItem(928, "Rob");
	HT.insertItem(928, "Rick");

	HT.printTable();

	HT.removeItem(332);
	HT.removeItem(100);

	if(HT.isEmpty()){
		cout << "Oh oh we need to check out code";
	} else {
		cout << "Correct answer, good job." << endl;
	}

	return 0;
}