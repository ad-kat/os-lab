#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Page {
    int page_number;
    int last_used;
    bool is_in_memory;
    Page(int page_number) {
        this->page_number = page_number;
        last_used = -1;
        is_in_memory = false;
    }
};

vector<Page> pages;
vector<int> memory;

void init_pages(int num_pages) {
    cout<<"enter the pages:";int n;
    for (int i = 0; i < num_pages; i++) {
            cin>>n;
        pages.push_back(n);
    }
}

void print_memory() {
    cout << "Memory: ";
    for (int i = 0; i < memory.size(); i++) {
        cout << memory[i] << " ";
    }
    cout << endl;
}

int replaced() {
    int lu = pages.size();
    int page_number = -1;
    for (int i = 0; i < memory.size(); i++)
        {
        for (int j = 0; j < pages.size(); j++)
         {
            if (pages[j].page_number == memory[i] && pages[j].last_used < lu)
            {
                lu = pages[j].last_used;
                page_number = memory[i];
            }
        }
    }
    return page_number;
}

void update_last_used(int page_number) {
    for (int i = 0; i < pages.size(); i++) {
        if (pages[i].page_number == page_number) {
            pages[i].last_used = pages.size();
            break;
        }
    }
}

void lru(int num_frames) {
    memory.clear();
    int num_page_faults = 0;
    for (int i = 0; i < pages.size(); i++) {
        if (!pages[i].is_in_memory)
            {
            num_page_faults++;
            if (memory.size() < num_frames) {
                memory.push_back(pages[i].page_number);
            } else {
                int page_number = replaced();
                for (int j = 0; j < pages.size(); j++) {
                    if (pages[j].page_number == page_number) {
                        pages[j].is_in_memory = false;
                        break;
                    }
                }
                memory.erase(find(memory.begin(), memory.end(), page_number));
                memory.push_back(pages[i].page_number);
            }
            pages[i].is_in_memory = true;
        } else {
            update_last_used(pages[i].page_number);
        }
        print_memory();
    }
    cout << "LRU: number of page faults = " << num_page_faults << endl;
}

int main() {
    int num_pages, num_frames;
    cout << "Enter the number of pages: ";
    cin >> num_pages;
    init_pages(num_pages);
    cout << "Enter the number of frames: ";
    cin >> num_frames;
    lru(num_frames);
    return 0;
}
