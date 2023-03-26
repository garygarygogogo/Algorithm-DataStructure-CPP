#include<iostream>
using namespace std;
#define Maxsize 2000

class  HashTable
{
public:
	HashTable();//constructor
	int Hash(char value[]);//hash func
	int search(char value[], int &pos, int &times);//search func
	int insert(char value[]);//insert func
	void recreate();//reconstructor
	~ HashTable();//deconstructor

private:
	char** m_elem;
	int m_size;
};

 HashTable:: HashTable()
{
	 this->m_size = Maxsize;
	 this->m_elem = new char* [this->m_size];
	 for (int i = 0; i < this->m_size; i++) this->m_elem[i] = NULL;

}

 int HashTable::Hash(char value[])
 {
	 int code = 0;
	 for (size_t i = 0; i < strlen(value); i++)//unsigned index for char array
	 {
		 code = (code * 256 + 128 + value[i]) % this->m_size;//opened addressing
	 }
	 return code;
 }

 int HashTable::search(char value[], int& pos, int& times)
 {
	 pos = Hash(value);
	 times = 0;
	 while (this->m_elem[pos] != NULL && strcmp(this->m_elem[pos], value) != 0)
	 {
		 times++;
		 if (times < this->m_size) pos = (pos + 1) % this->m_size;//linear probing
		 else return 0;
	 }
	 if (this->m_elem[pos] != NULL && strcmp(this->m_elem[pos], value) == 0) return 1;//value found
	 else return 0;
 }

 int HashTable::insert(char value[])
 {
	 int pos, times;
	 if (search(value, pos, times)) return 2;//value already exists
	 else if (times < this->m_size / 2)
	 {
		 this->m_elem[pos] = new char[strlen(value)+1];
		 strcpy(this->m_elem[pos], value);
		 return 1;//done
	 }
	 else
	 {
		 recreate();
		 insert(value);
		 return 0;//reconstruct hash table and done
	 }
 }
 void HashTable::recreate()
 {
	 char** temp_elem = new char*[this->m_size];
	 int i;
	 for (i = 0; i < this->m_size; i++)
	 {
		 if (this->m_elem[i])
		 {
			 temp_elem[i] = new char[strlen(this->m_elem[i]) + 1];
			 strcpy(temp_elem[i], this->m_elem[i]);
		 }
		 else temp_elem[i] = NULL;
	 }
	 for (i = 0; i < this->m_size; i++)
	 {
		 if (this->m_elem[i]) delete[]this->m_elem[i];
	 }
	 delete[]this->m_elem;
	 int temp_size = this->m_size;
	 this->m_size = this->m_size * 2;
	 this->m_elem = new char*[this->m_size];
	 for (i = 0; i < this->m_size; i++)  this->m_elem[i] = NULL;
	 for (i = 0; i < temp_size; i++) 
	 {
		 if (temp_elem[i]) insert(temp_elem[i]);
	 }
	 for (i = 0; i < temp_size; i++)
	 {
		 if (temp_elem[i]) delete[]temp_elem[i];
	 }
	 delete[]temp_elem;
 }

 HashTable::~ HashTable()
{
	 for (int i = 0; i < this->m_size; i++) {
		 if (this->m_elem[i]) delete []this->m_elem[i];
	 }
	 delete[]this->m_elem;
}