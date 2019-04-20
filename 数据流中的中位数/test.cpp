class Solution {
public:
    void Insert(int num)
    {
        if(((max_heap.size()+min_heap.size())&1)==0)
        {
            if(!max_heap.empty()&&num<max_heap[0])
            {
                max_heap.push_back(num);
                push_heap(max_heap.begin(),max_heap.end(),less<int>());
                num=max_heap[0];
                pop_heap(max_heap.begin(),max_heap.end(),less<int>());
                max_heap.pop_back();
            }
            min_heap.push_back(num);
            push_heap(min_heap.begin(),min_heap.end(),greater<int>());
        }
        else{
            if(!min_heap.empty()&&num>min_heap[0])
            {
                min_heap.push_back(num);
                push_heap(min_heap.begin(),min_heap.end(),greater<int>());
                num=min_heap[0];
                pop_heap(min_heap.begin(),min_heap.end(),greater<int>());
                min_heap.pop_back();
            }
            max_heap.push_back(num);
            push_heap(max_heap.begin(),max_heap.end(),less<int>());
        }
    }

    double GetMedian()
    {
        size_t size=max_heap.size()+min_heap.size();
        if(size==0)
        {
            return 0.0;
        }
        if((size&1)==0)
        {
            return (double)(((double)max_heap[0]+(double)min_heap[0])/2);
        }
        else{
            return (double)min_heap[0];
        }
    }
private:
    vector<int> max_heap;
    vector<int> min_heap;
};