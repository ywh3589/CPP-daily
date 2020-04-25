//hash table

#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class HashTable{
private:
	static const int hasGroup = 10;
	list<pair<int, string>> table[hasGroup];
public:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	string searchTable(int key);
	void printTable();
};

bool HashTable::isEmpty() const{

	int sum = 0;
	for(int i = 0 ; i < hasGroup; i++){
		sum += table[i].size();
	}

	if(!sum)
		return true;
	return false;
}

int HashTable::hashFunction(int key){
	return key % hasGroup;
}

void HashTable::insertItem(int key, string value){
	//어떤 table을 돌아야 하는 지 알아야하니까, has 값을 내놓고
	int hashValue = hashFunction(key);
	// 해당하는 value의 table을 돌 iterator를 만들고
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;

	//해당 table을 돌면서 
	for(; bItr != end(cell); bItr++){
		if(bItr->first == key){
			keyExists = true;
			bItr->second = value;
			cout << "key exists, value has been replaced." << endl;
			break;
		}
	}

	if(!keyExists){
		cell.emplace_back(key, value);
	}

	return;
}

void HashTable::removeItem(int key){
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;

	for(; bItr != end(cell); bItr++){
		if(bItr->first == key){
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "[INFO] Pair removed" << endl;
			break;
		}
	}

	if(!keyExists){
		cout << "[warning] key not found. pair not removed" << endl;
	}

	return;
}


void HashTable::printTable(){
	for(int i{}; i < hasGroup; i++){
		if(table[i].size() == 0) continue;
		auto bItr = table[i].begin();
		for(; bItr!=table[i].end(); bItr++){
			cout << "[INFO] Key:" << bItr->first << "Value:" <<bItr->second << endl;
		}
	}

	return;

}


int main(){

	HashTable HT;

	if(HT.isEmpty()){
		cout << "Correct answer" << endl;
	}
	else{
		cout << "oh oh we need to check out code " << endl;
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
		cout << " oh oh we need to check out code";
	}
	else{
		cout << "correct answer, good job" << endl;
	}

	return 0;
}