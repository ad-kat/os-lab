#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void print_frame(vector<int> frames,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<frames[i]<<"\t";
    }
    cout<<endl;
}
int fifo(vector<int> refstr, int num_frames)
{
    int num_faults = 0;
    vector<int> frames(num_frames, -1); // initialize frames to -1 (empty)

    int next_frame = 0; // next available frame to replace
    for (int i = 0; i < refstr.size(); i++)
    {
        int page = refstr[i];
        if (find(frames.begin(), frames.end(), page) == frames.end()) // page fault
        {
            frames[next_frame] = page;
            next_frame = (next_frame + 1) % num_frames; // increment next available frame (wrap around)
            num_faults++;
        }
        print_frame(frames,frames.size());
    }

    return num_faults;
}


int optimal(vector<int> refstr, int num_frames)
{
    int num_faults = 0;
    vector<int> frames(num_frames, -1); // initialize frames to -1 (empty)

    for (int i = 0; i < refstr.size(); i++)
    {
        int page = refstr[i];
        if (find(frames.begin(), frames.end(), page) == frames.end()) // page fault
        {
            if (frames[i] == -1) // empty frame available
            {
                frames[i] = page;
            }
            else // replace a frame
            {
                int farthest = -1;
                int farthest_idx = -1;
                for (int j = 0; j < num_frames; j++)
                {
                    int page_idx = find(refstr.begin() + i, refstr.end(), frames[j]) - refstr.begin();
                    if (page_idx == refstr.size()) // page never used again
                    {
                        farthest_idx = j;
                        break;
                    }
                    if (page_idx > farthest)
                    {
                        farthest = page_idx;
                        farthest_idx = j;
                    }
                }
                frames[farthest_idx] = page;
            }
            num_faults++;
        }
        print_frame(frames,frames.size());
    }

    return num_faults;
}

int main()
{
    int num_frames, num_pages;
    cout << "Enter the number of frames to allocate: ";
    cin >> num_frames;
    cout << "Enter the number of pages in the reference string: ";
    cin >> num_pages;
    vector<int> refstr(num_pages);
    cout << "Enter the page reference string: ";
    for (int i = 0; i < num_pages; i++)
    {
        cin >> refstr[i];
    }

    int fifo_faults = fifo(refstr, num_frames);
    int optimal_faults = optimal(refstr, num_frames);

    cout << "FIFO page faults: " << fifo_faults << endl;
    cout << "Optimal page faults: " << optimal_faults << endl;

    return 0;
}
