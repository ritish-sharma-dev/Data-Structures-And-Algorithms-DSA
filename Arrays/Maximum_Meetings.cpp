// Coding Ninjas : Maximum Meetings




// TC : O(n + nlogn + n)
// AS : O(3*n)
// SC : O(3*n + n)
class Data {
    public:
    int start, end, pos;
};

bool comp(Data v1, Data v2){
    return v1.end < v2.end;
}


int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<Data> arr(n);
    for (int i=0; i<n; i++){
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i+1;
    }

    sort(arr.begin(), arr.end(), comp);

    int cnt = 1;
    int free = arr[0].end;
    vector<int> ans;
    ans.push_back(arr[0].pos);
    for (int j=1; j<n; j++){
        if (arr[j].start > free){
            cnt++;
            free = arr[j].end;
            ans.push_back(arr[j].pos);
        }
    }
    return cnt;

}