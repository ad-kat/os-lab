#include <iostream>
#include <vector>
using namespace std;

const int memsize = 10000;
int memory[memsize];

struct MemoryBlock {
    int saddr;
    int size;
    MemoryBlock(int saddr, int size) {
        this->saddr = saddr;
        this->size = size;
    }
};

vector<MemoryBlock> freeb;
vector<MemoryBlock> usedb;

void init_memory() {
    MemoryBlock block(0, memsize);
    freeb.push_back(block);
}

void print_memory() {
    for (int i = 0; i < usedb.size(); i++) {
        cout << "Used Block " << i << ": saddr=" << usedb[i].saddr << ", size=" << usedb[i].size << endl;
    }
    for (int i = 0; i < freeb.size(); i++) {
        cout << "Free Block " << i << ": saddr=" << freeb[i].saddr << ", size=" << freeb[i].size << endl;
    }
}

void firstf(int size) {
    int i;
    for (i = 0; i < freeb.size(); i++) {
        if (freeb[i].size >= size) {
            break;
        }
    }

    if (i >= freeb.size()) {
        cout << "Allocation failed: no suitable block found\n";
        return;
    }

    MemoryBlock block = freeb[i];
    int saddr = block.saddr;
    block.saddr += size;
    block.size -= size;

    if (block.size == 0) {
        freeb.erase(freeb.begin() + i);
    } else {
        freeb[i] = block;
    }

    MemoryBlock used_block(saddr, size);
    usedb.push_back(used_block);

    cout << "Allocated " << size << " bytes starting at address " << saddr << endl;
}

void bestf(int size) {
    int i, best_i = -1;
    for (i = 0; i < freeb.size(); i++) {
        if (freeb[i].size >= size) {
            if (best_i == -1 || freeb[i].size < freeb[best_i].size) {
                best_i = i;
            }
        }
    }

    if (best_i == -1) {
        cout << "Allocation failed: no suitable block found\n";
        return;
    }

    MemoryBlock block = freeb[best_i];
    int saddr = block.saddr;
    block.saddr += size;
    block.size -= size;

    if (block.size == 0) {
        freeb.erase(freeb.begin() + best_i);
    } else {
        freeb[best_i] = block;
    }

    MemoryBlock used_block(saddr, size);
    usedb.push_back(used_block);

    cout << "Allocated " << size << " bytes starting at address " << saddr << endl;
}

int main() {
    cout<<"Memory size of this system is:"<<memsize<<endl;
    init_memory();int n;
    cout<<"enter 1 for first fit.\nenter 2 for best fit.\n"<<"enter choice:";int ch;cin>>ch;
    cout<<"enter -1 when done."<<endl;
    switch(ch)
    {
        case 1:
            do{
                    cout<<"enter size:";cin>>n;
                    if(n!=-1)
                        firstf(n);
            }while(n!=-1);
                break;
        case 2:
            do{
                    cout<<"enter size:";cin>>n;
                    if(n!=-1)
                        bestf(n);
            }while(n!=-1);
                break;

        default: cout<<"Invalid choice";
                 return 0;
    }
    print_memory();
    return 0;
}
